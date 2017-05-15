#ifndef _UNDIRECTEDMOTIFSMAPPING_H_

#define _UNDIRECTEDMOTIFSMAPPING_H_

#include <string>
#include <iostream>
#include <vector>
#include <set>
/**
*
* this class provides a light-weight mapping from adjacency matrix keys to
* motif index. in contrast to UndirectedMotifs, no instances of
* UndirectedMotif, UndirectedMotifs, or UndirectedAdjacencyMatrix are created.
*
* the mapping consists of an int array. its index is considered as the key of
* adjacency matrices and the value stored as the respective motif index. the
* value of adjacency matrix keys that represent unconnected graphs is 0, i.e.,
* an invalid motif index.
*
* this class provides functionalities similar to UndirectedMotifs but decreases
* memory consumption and mapping lookup.
*
* the mapping can be stored info a file and later read from it which removes
* the runtime complexity of performing isomorphism checks before obtaining a
* mapping.
*
*/
using namespace std;

class UndirectedMotifsMapping
{
public:
	const static string nodesPre;
	const static string maxKeyPre;
	const static string motifsPre;
	const static string sep;
private:
	int nodes;
	vector<int>* mapping;
	int motifs;
public:
	int getNodes();
	vector<int>* getMapping();
	int getMotifsCount();
	int getAmsCount();
	int getMotif(int key);
	/**
	* for each motif, identified by its index, the smallest key of all
	* adjacency matrices of that isomorphism class is returned.
	*
	* @return representative adjacency matrix key for each motif
	*/
	vector<int>* getRepresentatives();
public:
	/**
	*
	* initialization of all parameters, no further processing is reuired (in
	* contrast to the related representation in UndirectedMotifs).
	*
	* @param nodes
	*            size of the graphs
	* @param motifs
	*            total number of motifs
	* @param mapping
	*            mapping of adjacency matrix keys to motif index
	*/
	UndirectedMotifsMapping(int nodes, int motifs, vector<int>*x mapping);
};

#endif