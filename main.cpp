#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>

#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "tcp_connection.h"
#include "tcp_server.h"
using boost::asio::ip::tcp;


int main(int argc, char *argv[])
{
    int port;
    
    try
    {
        std::istringstream iss( argv[1] );
            if (iss >> port)
            {
            boost::asio::io_context io_context;
                tcp_server server(io_context,port);
                io_context.run();
            }
            else{
                    std::cout<<"Please eenter a port number\n";
            }
    }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
