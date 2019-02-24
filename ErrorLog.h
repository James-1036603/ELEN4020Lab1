#ifndef ERRORLOG_H
#define ERRORLOG_H
#include <string>
#include <fstream>
#include <iostream>

class ErrorLog
{//Logs errors to log file
public:
	ErrorLog();	
	~ErrorLog() 
	{
		outFile.close();
	};
	
	void logError(const std::string &Error);
private:
	std::ofstream outFile;
};

#endif // ERRORLOG_H
