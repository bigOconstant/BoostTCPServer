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
#include <librdkafka/rdkafka.h>
#include <librdkafka/rdkafkacpp.h>
#include "VariableService.h"

using boost::asio::ip::tcp;


int main(int argc, char *argv[])
{
 

  VariableService::Instance()->Instance()->setValues(argc,argv);
  
   
  try
  {
    boost::asio::io_context io_context;
    tcp_server server(io_context);
    io_context.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
