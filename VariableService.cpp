#include "VariableService.h"


VariableService* VariableService::m_pInstance = NULL;
using std::cout;
using std::endl;


VariableService::VariableService()
{
    _topic = "";
    _port = 0;
    portFound = false;
    topicFound = false;
    
}


VariableService* VariableService::Instance()
{
	if (!m_pInstance) // Only allow one instance of class to be generated
	{
		m_pInstance = new VariableService();
	}
	return m_pInstance;
};

void VariableService::setValues(int count, char *argv[])
{
    
    
    for(int i = 1; i < count; ++i) {
        std::string current = argv[i];
                    if(current == "-topic" || current == "-t"){
                            if(count > i){
                                    this->_topic = argv[i+1];
                                    std::cout<<"topic:"<<_topic<<endl;
                                    ++i;//Skip over next iteration
                                    topicFound = true;

                            }
                    }else if ((current == "-port" || current == "-p") && count > i){
                        std::istringstream iss( argv[i+1] );
                        int temp_port;
                        if (iss >> temp_port){
                            _port = temp_port;
                            portFound = true;
                            ++i;

                        }else{
                                std::cout<<"Invalid Port \n";
                        }
                    }else if(current == "-h" || current == "-help"){
                        ShowUsage(argv[0]);
                        exit(1);
                    }
             }
             
             CheckInputExitIfRequiredNotAvailable( );
};

    void VariableService::ShowUsage(char *appName) {
        cout<<appName<<" + options"<<endl;
        cout<<"Options"<<endl;
        cout<<"-p or -port  <portnumber> "<<endl;
        cout<<"-t or -topic  <kafka topic> "<<endl;        
    }

void VariableService::CheckInputExitIfRequiredNotAvailable(){
    if(!this->portFound){
            cout<<"Port Number Required"<<endl;
            cout<<"Type -h or -help to see options"<<endl;
            exit(1);
    }
}

int VariableService::Port(){
        return _port;
}
    


