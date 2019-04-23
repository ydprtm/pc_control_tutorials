#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char* argv[]) {

	try {

		boost::asio::io_context io;

		boost::asio::tcp::resolver resolver(io);

		boost::asio::tcp::resolver::results_type end_point = resolver.resolve(boost::asio::tcp::ip_address("127.0.0.1"));

		
	}
	catch (boost::system::error_code &e) {
		std::cout << e << std::endl;
		return 1;
	}
	   
    return 0;
}