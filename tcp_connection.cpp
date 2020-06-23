#include <boost/array.hpp>
#include "VariableService.h"
#include "tcp_connection.h"
#include "kafkamessage.cpp"


  void tcp_connection::start()
  {
    message_ = "Recieved\n";

    boost::array<char, 456> buf;
    boost::system::error_code error;

    size_t len = socket_.read_some(boost::asio::buffer(buf), error);
    std::cout<<"length of read string:"<<len<<std::endl; 
      
    std::cout.write(buf.data(), len);
    std::string message;
    for(int i = 0; i < len-1; ++i) {
        message += buf[i];
        
    }
    std::cout<<"message:"<<message<<std::endl;
    if(VariableService::Instance()->kafkaenabled()){
        SendKafkaMessage(message,VariableService::Instance()->Kafkaaddress(),VariableService::Instance()->Topic());
    }

    boost::asio::async_write(socket_, boost::asio::buffer(message_),
        boost::bind(&tcp_connection::handle_write, shared_from_this(),
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }