#include "tcp_connection.h"
#include "kafkamessage.cpp"
#include "VariableService.h"
using boost::asio::ip::tcp;
void tcp_connection::start()
  {
    message_ = "Received\n";
    boost::array<char, 456> buf;
    boost::system::error_code error;
    std::string topic = "default";
    std::string KafkaAddress = "localhost:9092";

    size_t len = socket_.read_some(boost::asio::buffer(buf), error);
    std::cout<<"length of read string:"<<len<<std::endl; 
      
    std::cout.write(buf.data(), len);
    std::string message;
    for(int i = 0; i < len-1; ++i) {
        message += buf[i];
        
    }
    std::cout<<"string output:"<< message<<std::endl;
    if(const char* env_p = std::getenv("KAFKA_OUTPUT_TOPIC")){
        std::cout << "Your topic is: " << env_p << '\n';
        topic = env_p;

    }
    //KAFKAADDRESS
    if(const char* env_c = std::getenv("KAFKAADDRESS")){
        std::cout << "Your kafka address is: " << env_c << '\n';
        KafkaAddress = env_c;

    }
    message_ = "sending to topic "+ topic + " on kafka at url "+ KafkaAddress;
    
    if(VariableService::Instance()->kafkaenabled()){
        SendKafkaMessage(message,VariableService::Instance()->Kafkaaddress(),std::to_string(VariableService::Instance()->Port()));
    }
    
    std::cout<<"done"<<std::endl;

    boost::asio::async_write(socket_, boost::asio::buffer(message_),
        boost::bind(&tcp_connection::handle_write, shared_from_this(),
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }
  
  
  tcp::socket& tcp_connection::socket()
  {
    return socket_;
  }
