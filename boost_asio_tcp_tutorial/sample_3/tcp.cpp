#include "tcp.hpp"

boost::shared_ptr<Connection> Connection::create(boost::asio::io_context& io_context) {
	return boost::shared_ptr<Connection>(new Connection(io_context));
}

boost::asio::ip::tcp::socket& Connection::socket()
{
	return socket_;
}

void Connection::start()
{

	boost::asio::async_read_until(socket_, m_buffer, '\n',
		boost::bind(&Connection::readHandle, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

}

Connection::Connection(boost::asio::io_context& io_context) :
	socket_(io_context) {
}

void Connection::readHandle(const boost::system::error_code& e,
	size_t bytes)
{

	boost::asio::const_buffer input = m_buffer.data();

	std::string message(boost::asio::buffers_begin(input),
		boost::asio::buffers_begin(input) + input.size());

	std::cout << message << std::endl;

}


Server::Server(boost::asio::io_context & io_context, int port)
	: io_context_(io_context),
	acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
	start_accept();
}

void Server::start_accept()
{
	boost::shared_ptr<Connection> new_connection = Connection::create(io_context_);

	acceptor_.async_accept(new_connection->socket(), boost::bind(&Server::acceptHandle, this, new_connection, boost::asio::placeholders::error));
}

void Server::acceptHandle(boost::shared_ptr<Connection> new_connection,
	const boost::system::error_code & error)
{
	if (!error)
	{
		new_connection->start();
	}

	start_accept();
}
