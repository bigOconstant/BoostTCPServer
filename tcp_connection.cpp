#include "tcp_connection.h"

using boost::asio::ip::tcp;
void tcp_connection::start()
  {
    message_ = "Received\n";
    boost::array<char, 256> buf;
    boost::system::error_code error;

    size_t len = socket_.read_some(boost::asio::buffer(buf), error);
    std::cout<<"length of read string:"<<len<<std::endl; 
      
    std::cout.write(buf.data(), len);

    boost::asio::async_write(socket_, boost::asio::buffer(message_),
        boost::bind(&tcp_connection::handle_write, shared_from_this(),
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }
  
  
  tcp::socket& tcp_connection::socket()
  {
    return socket_;
  }
