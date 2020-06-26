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
    std::string Topic();
    std::string Kafkaaddress();
    std::string Replymessage();
    std::string SASLUsername();
    std::string SASLPassword();
    bool kafkaenabled();
    bool SASLenabled();
private:
    VariableService(VariableService const&) {}; // private copy constructor
	VariableService();
    void ShowUsage(char *appName);
    void CheckInputExitIfRequiredNotAvailable();
    //VariableService& operator=(VariableService const&) {}; //assignment operator is private
	static VariableService* m_pInstance;
    
    std::string _topic;
    int _port;
    std::string _kafkaaddress;
    std::string _replymessage;
    std::string _SASL_username;
    std::string _SASL_password;
    
    bool portFound = false;
    bool topicFound = false;
    bool kafkaaddressFound = false;
    
};


#endif // TCP_CONNECTION_H


