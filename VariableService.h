#ifndef VARIABLESERVICE_H
#define VARIABLESERVICE_H

#include <iostream>
#include <string>
#include <sstream>
class VariableService
{
public:
    static VariableService* Instance();
    void setValues(int count, char *argv[]);
    int Port();
private:
    VariableService(VariableService const&) {}; // private copy constructor
	VariableService();
    VariableService& operator=(VariableService const&) {}; //assignment operator is private
	static VariableService* m_pInstance;
    std::string _topic;
    int _port;
    
    bool portFound = false;
    bool topicFound = false;
    
};


#endif // TCP_CONNECTION_H
