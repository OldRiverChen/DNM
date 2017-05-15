#include "Log.h"

const string Log::debugPrefix = "debug: ";
const string Log::warningPrefix = "warn: ";
const string Log::errorPrefix = "error: ";
const string Log::infoPrefix = "~";
LogLevel Log::loglevel = Info;

string Log::enumToString(LogLevel ll)
{
	string rs;
	switch (ll)
	{
	case Off:
		rs = "off";
		break;
	case Error:
		rs = "error";
		break;
	case Warn:
		rs = "warn";
		break;
	case Info:
		rs = "info";
		break;
	case Debug:
		rs = "debug";
		break;
	}
	return rs;
}