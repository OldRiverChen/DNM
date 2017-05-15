#include "SeriesGeneration.h"
#include "Series.h"
#include "data\SeriesData.h"
#include "..\util\Log.h"
#include "data\BatchData.h"
#include "..\metrics\IMetric.h"
#include "..\metrics\algorithms\IDynamicAlgorithm.h"
#include "..\metrics\algorithms\IRecomputation.h"
#include "..\util\Util.h"
#include "data\MetricData.h"
#include "..\series\SeriesStats.h"
#include "..\io\filesystem\Dir.h"
#include "..\generators\updates\batch\BatchSanitizationStats.h"
#include "..\generators\updates\batch\BatchSanitization.h"

/*
private
*/
BatchData* SeriesGeneration::computeInitialData(Series *series, Algorithms* algorithms)
{
	// generate graph
	Log::info("    generating graph");
	series->setGraph(series->getGraphGenerator()->generate());//生成初始的图

	for (vector<IMetric*>::iterator iter = series->getMetrics()->begin(); iter != series->getMetrics()->end(); iter++)//获取Metrics，如度分布，聚类系数等
	{
		Metric* m = (Metric*)(*iter);
		m->setGraph(series->getGraph());
	}
	// generate first batch
	Log::info("    initial data");
	BatchData* initialData = new BatchData(series->getGraph()->getTimestamp(),0,4, series->getMetrics()->size(), series->getMetrics()->size());
	initialData = computeInitialMetrics(series, initialData, algorithms);//计算其初始的Metrics,如度分布，聚类系数等
	return initialData;
}
BatchData* SeriesGeneration::computeInitialMetrics(Series *series, BatchData* initialData, Algorithms* algorithms)
{
	// initial computation of all metrics
	for (vector<IMetric*>::iterator iter = series->getMetrics()->begin(); iter != series->getMetrics()->end(); iter++)
	{
		IMetric* im = (*iter);
		bool success = false;
		if (im->instanceOf("IDynamicAlgorithm"))/*instanceof<IDynamicAlgorithm>(im)*/
		{
			IDynamicAlgorithm* ida = (IDynamicAlgorithm*)im;
			Metric* m = (Metric*)ida;
			success = m->init();
		}
		else if (im->instanceOf("IRecomputation"))/*instanceof<IRecomputation>(im)*/
		{
			IRecomputation* ir = (IRecomputation*)im;
			Metric* m = (Metric*)ir;
			success = m->recompute();
		}
		else {
			Log::error("unknown metric type: " + ((Metric*)im)->getName()+",SeriesGeneration::computeInitialMetrics");
			exit(1);
		}
		if (success)
		{
			Metric* m = (Metric*)im;
			// get data
			MetricData* data = m->getData();

			// add metric to batch
			initialData->getMetrics()->add(data->getName(),data);
		}

	}
	return initialData;
}
bool SeriesGeneration::compareMetrics(Series* series)//比较Metrics
{
	bool ok = true;
	//for (int i = 0; i < series->getMetrics()->size(); i++)
	//{
	//	for (int j = i + 1; j < series->getMetrics()->size(); j++)
	//	{
	//		if (i == j) {
	//			continue;
	//		}
	//		if (!(series->getMetrics()->at(i)->isComparableTo(series->getMetrics()->at(j))))
	//			continue;

	//	}
	//}
	return ok;
}

BatchData* SeriesGeneration::computeNextBatch(Series *series, Algorithms* algorithms)
{
	// generate next batch
	Batch* b = series->getBatchGenerator()->generate(series->getGraph());
	Log::info("    " + b->toString());

	// check applicability to batch
	//不用

	// apply before batch
	//不用


	BatchSanitizationStats* sanitizationStats = NULL;
	bool GENERATION_BATCH_SANITIZATION = true;
	if (GENERATION_BATCH_SANITIZATION) {
		sanitizationStats = BatchSanitization::sanitize(b);//清洗batch b 中不合法的增删边操作，
		if (sanitizationStats->getTotal() > 0) {
			Log::info("      " + sanitizationStats->toString());
			Log::info("      => " + b->toString());
		}
	}
	//图进行更新并计算metric
	int removedNodes = SeriesGeneration::applyNRs(series,algorithms,b->getNodeRemovals());
	int removedEdges = SeriesGeneration::applyERs(series, algorithms,b->getEdgeRemovals());
	int addedNodes = SeriesGeneration::applyNAs(series, algorithms, b->getNodeAdditions());
	int addedEdges = SeriesGeneration::applyEAs(series, algorithms, b->getEdgeAdditions());

	series->getGraph()->setTimestamp(b->getTo());

	// apply after batch
	for (vector<IAfterBatch*>::iterator iter = algorithms->afterBatch->begin(); iter != algorithms->afterBatch->end(); iter++)
	{
		IAfterBatch* m = *iter;
		m->applyAfterBatch(b);
	}

	// compute
	for (vector<IRecomputation*>::iterator iter = algorithms->recomputation->begin(); iter != algorithms->recomputation->end(); iter++)
	{
		IRecomputation* ir = *iter;
		Metric* m = (Metric*)ir;
		m->recompute();
	}
	BatchData* batchData = new BatchData(b, sanitizationStats, 5, 5,
		series->getMetrics()->size(), series->getMetrics()->size());
	batchData->getValues()->add(SeriesStats::addedNodes, new Value(SeriesStats::addedNodes, addedNodes));
	batchData->getValues()->add(SeriesStats::removedNodes, new Value(SeriesStats::removedNodes, removedNodes));
	batchData->getValues()->add(SeriesStats::addedEdges, new Value(SeriesStats::addedEdges, addedEdges));
	batchData->getValues()->add(SeriesStats::removedEdges, new Value(SeriesStats::removedEdges, removedEdges));


	return batchData;
}

int SeriesGeneration::applyNAs(Series* series, Algorithms* algorithms, vector<NodeAddition*>* updates)
{
	int counter = 0;
	for (vector<NodeAddition*>::iterator iter = updates->begin(); iter != updates->end(); iter++)
	{
		NodeAddition* u = *iter;

	}
	if (updates != nullptr)
	{
		delete updates;
		updates = nullptr;
	}

	return counter;
}
int SeriesGeneration::applyNRs(Series* series, Algorithms* algorithms, vector<NodeRemoval*>* updates)
{
	int counter = 0;

	for (vector<NodeRemoval*>::iterator iter = updates->begin(); iter != updates->end(); iter++)
	{
		NodeRemoval* u = *iter;

	}
	if (updates != nullptr)
	{
		delete updates;
		updates = nullptr;
	}


	return counter;
}
int SeriesGeneration::applyEAs(Series* series, Algorithms* algorithms, vector<EdgeAddition*>* updates)
{
	int counter = 0;

	for (vector<EdgeAddition*>::iterator iter = updates->begin(); iter != updates->end(); iter++)
	{
		EdgeAddition* u = *iter;
		for (vector<IBeforeEA*>::iterator iter = algorithms->beforeUpdateEA->begin(); iter != algorithms->beforeUpdateEA->end(); iter++)//计算更新操作之前的Metric
		{
			IBeforeEA* m = *iter;
			if (!m->applyBeforeUpdate(u))
			{
				Log::error("could not apply before update " + u->toString()
					+ " to metric " + m->getTrueInstanceName());
			}
		}
		if (!u->apply(series->getGraph())) 
		{
			Log::error("could not apply update " + u->toString()
				+ " (BUT metric before update already applied)");
			continue;
			
		}
		cout << "EdgeAddition: " << u->getEdge()->asString() << endl;
		counter++;
		for (vector<IAfterEA*>::iterator iter = algorithms->afterUpdateEA->begin(); iter != algorithms->afterUpdateEA->end(); iter++)//计算更新操作之后的Metric
		{
			IAfterEA* m = *iter;
			if (!m->applyAfterUpdate(u))
			{
				Log::error("could not apply after update " + u->toString()
					+ " to metric " + m->getTrueInstanceName());
			}
		}

	}
	if (updates != nullptr)
	{
		delete updates;
		updates = nullptr;
	}

	return counter;
}
int SeriesGeneration::applyERs(Series* series, Algorithms* algorithms, vector<EdgeRemoval*>* updates)
{
	int counter = 0;

	for (vector<EdgeRemoval*>::iterator iter = updates->begin(); iter != updates->end(); iter++)
	{
		EdgeRemoval* u = *iter;
		for (vector<IBeforeER*>::iterator iter = algorithms->beforeUpdateER->begin(); iter != algorithms->beforeUpdateER->end(); iter++)//计算更新操作之前的Metric
		{
			IBeforeER* m = *iter;
			if (!m->applyBeforeUpdate(u))
			{
				Log::error("could not apply before update " + u->toString()
					+ " to metric " + m->getTrueInstanceName());
			}
		}
		if (!u->apply(series->getGraph()))//更新图
		{
			Log::error("could not apply update " + u->toString()
				+ " (BUT metric before update already applied)");
			continue;
		}
		cout << "EdgeRemoval: " << u->getEdge()->asString() << endl;
		counter++;
		for (vector<IAfterER*>::iterator iter = algorithms->afterUpdateER->begin(); iter != algorithms->afterUpdateER->end(); iter++)//计算更新操作之后的Metric
		{
			IAfterER* m = (IAfterER*)*iter;
			if (!m->applyAfterUpdate(u))
			{
				Log::error("could not apply after update " + u->toString()
					+ " to metric " + m->getTrueInstanceName());
			}
		}

	}
	if (updates != nullptr)
	{
		delete updates;
		updates = nullptr;
	}

	return counter;
}

/*
public:
*/

SeriesData* SeriesGeneration::generate(Series* series, int runs, int batches, bool compare, bool aggregate, bool write, long batchGenerationTime)
{
	Log::infoSep();
	Log::info("generating series");
	Log::infoSep();
	Log::info("gg="+ series->getGraphGenerator()->getDescription());
	Log::info("bg=" + series->getBatchGenerator()->getDescription());
	if (aggregate)
		Log::info("ag = enabled");
	else
		Log::info("ag = disabled");
	Log::info("r  = files");
	Log::info("b  = files");
	Log::info("p  = " + series->getDir());
	if (batchGenerationTime > 0)
		Log::info("t  = " + batchGenerationTime + string(" msec / batch"));
	string buff("");
	for (vector<IMetric*>::iterator iter = series->getMetrics()->begin(); iter != series->getMetrics()->end(); iter++)
	{
		Metric* m = (Metric*)(*iter);
		cout << series->getMetrics()->size() << endl;
		if (buff.size() > 0)
			buff.append("\n     ");
		buff.append(m->getDescription());
	}
	Log::info("m  = " + buff);
	// reset rand per series
	if (series->getRandomSeedReset() == Eachseries) {
		series->resetRand();
	}
	// generate all runs
	for (int r = 0; r < runs; r++) {
		// reset rand per batch / run
		if (series->getRandomSeedReset() == Eachrun)
		{
			series->resetRand();
		}
		// generate run
		SeriesGeneration::generateRun(series, r, batches, compare, write, batchGenerationTime);
	}
	// read series data structure for aggregation
	SeriesData* sd = SeriesData::read(series->getDir(), series->getName(),false,false);
	return NULL;
}

RunData* SeriesGeneration::generateRun(Series* series, int run, int batches, bool compare, bool write, long batchGenerationTime)
{
	/*
	* compile lists of different algorithm types
	*/
	Algorithms* algorithms = new Algorithms(series->getMetrics());
	for (vector<IMetric*>::iterator iter = series->getMetrics()->begin(); iter != series->getMetrics()->end(); iter++)
	{
		Metric* m = (Metric*)(*iter);
		m->reset();
	}

	// list of structure batches
	vector<BatchData*>* structBatches = new vector<BatchData*>();
	Log::infoSep();
	Log::info("run " + to_string(run) + " (" + to_string(batches) + " batches)");
	// set zip flags
	boolean zippedBatches = false;
	boolean zippedRuns = false;
	// reset batch generator
	series->getBatchGenerator()->reset();

	// reset rand per batch
	if (series->getRandomSeedReset() == Eachbatch)
	{
		series->resetRand();
	}

	// generate initial data
	BatchData* initialData = SeriesGeneration::generateInitialData(series, algorithms);

	if (compare) {//没啥用
		SeriesGeneration::compareMetrics(series);
	}
	if (write) {
		string dir = series->getDir();
		long long timestamp = initialData->getTimestamp();
		string wdir = Dir::getBatchDataDir(dir, run, timestamp);
		initialData->writeIntelligent(wdir);
	}
	// add init batch-structure
	structBatches->push_back(initialData->cloneStructure());

	// generate batch data
	for (int i = 0; i < batches; i++)
	{
		if (!series->getBatchGenerator()->isFurtherBatchPossible(series->getGraph()))
		{
			Log::info("    no further batch possible (generated " + to_string(i) + " of " + to_string(batches) + ")");
			break;
		}

		// * live display simulation
		long long batchGenerationStart = LogSystemTime::_getTime();//获取系统时间,相当于java System.currentTimeMillis();

		// reset rand per batch
		if (series->getRandomSeedReset() == Eachbatch) {
			series->resetRand();
		}

		BatchData* batchData = SeriesGeneration::generateNextBatch(series, algorithms);

		// compute labels
		//不用

		if (compare) {
			SeriesGeneration::compareMetrics(series);
		}

		if (write) {
			if (batchGenerationTime > 0) {

			}
			else {
				// write
				string dir = series->getDir();
				long long timestamp = batchData->getTimestamp();
				string wdir = Dir::getBatchDataDir(dir, run, timestamp);
				batchData->writeIntelligent(wdir);
			}
		}
		// add structure batch to list
		structBatches->push_back(batchData->cloneStructure());

	}
	// return structure run without data
	return new RunData(run, structBatches);
}
BatchData* SeriesGeneration::generateInitialData(Series *series, Algorithms* algorithms)
{
	BatchData* initialData = computeInitialData(series, algorithms);
	
	// add values
	Value* randomSeed = new Value("randomSeed", series->getSeed());
	initialData->getValues()->add(randomSeed->getName(), randomSeed);

	// these values are not present in the initialdata and added for gui
	// purposes only
	initialData->getValues()->add(SeriesStats::nodesToAdd,new Value(SeriesStats::nodesToAdd, 0.0));
	initialData->getValues()->add(SeriesStats::addedNodes,new Value(SeriesStats::addedNodes, 0.0));
	initialData->getValues()->add(SeriesStats::nodesToRemove,new Value(SeriesStats::nodesToRemove, 0.0));
	initialData->getValues()->add(SeriesStats::removedNodes,new Value(SeriesStats::removedNodes, 0.0));
	initialData->getValues()->add(SeriesStats::edgesToAdd,new Value(SeriesStats::edgesToAdd, 0.0));
	initialData->getValues()->add(SeriesStats::addedEdges,new Value(SeriesStats::addedEdges, 0.0));
	initialData->getValues()->add(SeriesStats::edgesToRemove,new Value(SeriesStats::edgesToRemove, 0.0));
	initialData->getValues()->add(SeriesStats::removedEdges,new Value(SeriesStats::removedEdges, 0.0));


	initialData->getValues()->add(SeriesStats::deletedNodeAdditions,new Value(SeriesStats::deletedNodeAdditions, 0.0));
	initialData->getValues()->add(SeriesStats::deletedEdgeAdditions,new Value(SeriesStats::deletedEdgeAdditions, 0.0));
	initialData->getValues()->add(SeriesStats::deletedNodeRemovals,new Value(SeriesStats::deletedNodeRemovals, 0.0));
	initialData->getValues()->add(SeriesStats::deletedEdgeRemovals,new Value(SeriesStats::deletedEdgeRemovals, 0.0));
	

	initialData->getValues()->add(SeriesStats::nodes,new Value(SeriesStats::nodes, series->getGraph()->getNodeCount()));
	initialData->getValues()->add(SeriesStats::edges,new Value(SeriesStats::edges, series->getGraph()->getEdgeCount()));


	return initialData;
}

BatchData* SeriesGeneration::generateNextBatch(Series* series, Algorithms* algorithms)
{
	// compute next batchdata
	BatchData* batchData = computeNextBatch(series, algorithms);
	// add values
	batchData->getValues()->add(SeriesStats::nodesToAdd, new Value(SeriesStats::nodesToAdd, batchData->getBatch()->getNodeAdditionsCount()));
	batchData->getValues()->add(SeriesStats::nodesToRemove, new Value(SeriesStats::nodesToRemove, batchData->getBatch()->getNodeRemovalsCount()));

	batchData->getValues()->add(SeriesStats::edgesToAdd, new Value(SeriesStats::edgesToAdd, batchData->getBatch()->getEdgeAdditionsCount()));
	batchData->getValues()->add(SeriesStats::edgesToRemove, new Value(SeriesStats::edgesToRemove, batchData->getBatch()->getEdgeRemovalsCount()));

	batchData->getValues()->add(SeriesStats::deletedNodeAdditions, new Value(SeriesStats::deletedNodeAdditions, batchData->getSanitizationStats()->getDeletedNodeAdditions()));
	batchData->getValues()->add(SeriesStats::deletedEdgeAdditions, new Value(SeriesStats::deletedEdgeAdditions, batchData->getSanitizationStats()->getDeletedEdgeAdditions()));
	batchData->getValues()->add(SeriesStats::deletedNodeRemovals, new Value(SeriesStats::deletedNodeRemovals, batchData->getSanitizationStats()->getDeletedNodeRemovals()));
	batchData->getValues()->add(SeriesStats::deletedEdgeRemovals, new Value(SeriesStats::deletedEdgeRemovals, batchData->getSanitizationStats()->getDeletedEdgeRemovals()));
	batchData->getValues()->add(SeriesStats::randomSeed, new Value(SeriesStats::randomSeed, series->getSeed()));

	// release batch
	batchData->releaseBatch();
	// add nodes/edges count
	batchData->getValues()->add(SeriesStats::nodes,new Value(SeriesStats::nodes, series->getGraph()->getNodeCount()));
	batchData->getValues()->add(SeriesStats::edges, new Value(SeriesStats::edges, series->getGraph()->getEdgeCount()));

	// add metric data
	for (vector<IMetric*>::iterator iter = series->getMetrics()->begin(); iter != series->getMetrics()->end(); iter++)
	{
		IMetric* im = *iter;
		Metric* m = (Metric*)im;
		// get data
		MetricData* data = m->getData();
		// add extra values for distributions,
		//默认是不用加

		// add extra values for nodevaluelists
		//默认是不用加

		// add metric to batch
		batchData->getMetrics()->add(data->getName(),data);
	}

	return batchData;
}