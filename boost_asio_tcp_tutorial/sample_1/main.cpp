#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/asio.hpp>

int main(int argc, char* argv[]) {

	try {

		boost::asio::io_context io;

		boost::asio::ip::tcp::resolver resolver(io);

		boost::asio::ip::tcp::resolver::query query("127.0.0.1", "9601");

		boost::asio::ip::tcp::resolver::results_type end_point = resolver.resolve(query);

		boost::asio::ip::tcp::socket socket(io);

		boost::asio::connect(socket, end_point);

		bool loop{ true };

		std::string message{ "Hello World!\r\n" };
				   
		boost::asio::const_buffer buffer = boost::asio::buffer(message);

		try {

			boost::asio::write(socket, buffer);

		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	   
    return 0;
}