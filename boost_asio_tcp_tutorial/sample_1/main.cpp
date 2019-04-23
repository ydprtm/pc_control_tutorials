#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char* argv[]) {

	try {

		boost::asio::io_context io;

		//boost::asio::ip::tcp::resolver resolver(io);
		boost::asio::ip::basic_resolver<boost::asio::ip::tcp> resolver(io);

		//boost::asio::ip::tcp::resolver::query query("127.0.0.1", "9601");
		boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> query("127.0.0.1", "9601");

		//boost::asio::ip::tcp::resolver::results_type end_point = resolver.resolve(query);
		boost::asio::ip::basic_resolver_results<boost::asio::ip::tcp> end_point = resolver.resolve(query);

		//boost::asio::ip::tcp::socket socket(io);
		boost::asio::basic_stream_socket<boost::asio::ip::tcp> socket(io);

		boost::asio::connect(socket, end_point);

		std::string message{ "Hello World!\r\n" };
				   
		boost::asio::const_buffer buffer = boost::asio::buffer(message);

		try {

			boost::asio::write(socket, buffer);

		}
		catch (std::exception& e) {

			std::cout << e.what() << std::endl;

		}

		socket.close();
	
	}
	catch (std::exception &e) {

		std::cout << e.what() << std::endl;
		return 1;

	}
	   
    return 0;
}