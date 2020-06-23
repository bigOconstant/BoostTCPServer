#include "tcp_server.h"

void tcp_server::start_accept()
  {
    tcp_connection::pointer new_connection =
      tcp_connection::create(io_context_);

    acceptor_.async_accept(new_connection->socket(),
        boost::bind(&tcp_server::handle_accept, this, new_connection,
          boost::asio::placeholders::error));
  }


void tcp_server::handle_accept(tcp_connection::pointer new_connection,
      const boost::system::error_code& error)
  {
    if (!error)
    {
      new_connection->start();
    }

    start_accept();
  }

