#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>

#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "tcp_connection.h"

/**
 * @todo write docs
 */

using boost::asio::ip::tcp;

class tcp_server
{
    
public:
    tcp_server(boost::asio::io_context& io_context,int port)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
    {
        start_accept();
    }
private:
    void start_accept();
    void handle_accept(tcp_connection::pointer new_connection,
    const boost::system::error_code& error);
    tcp::acceptor acceptor_;
    
};

#endif // TCP_SERVER_H
