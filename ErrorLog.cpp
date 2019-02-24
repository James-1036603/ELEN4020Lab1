#include "ErrorLog.h"
ErrorLog::ErrorLog(): outFile("Log.txt", std::ofstream::out)
{
	
}

void ErrorLog::logError(const std::string &Error)
{//Logs passed message to log file
	outFile<<Error<<'\n';	
	std::cout<<"Error occurred. Please check Log.txt."<<std::endl;
}