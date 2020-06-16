#include <iostream>

#include <ctime>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}
int main(int argc, char **argv) {
     try
  {
    boost::asio::io_context io_context;

    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 14));

    for (;;)
    {
      tcp::socket socket(io_context);
      acceptor.accept(socket);

      std::cout<<"sending message!"<<std::endl;
      std::string message = make_daytime_string();
      
      boost::array<char, 256> buf;
      boost::system::error_code error;

      size_t len = socket.read_some(boost::asio::buffer(buf), error);
      std::cout<<"length of read string:"<<len<<std::endl;      
        
      std::cout.write(buf.data(), len);

      boost::system::error_code ignored_error;
      boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
