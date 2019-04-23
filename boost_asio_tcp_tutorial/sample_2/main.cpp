#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/asio.hpp>

int main(int argc, char* argv[]) {

	try {

		boost::asio::io_context io;

		boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> end_points(boost::asio::ip::tcp::v4(), 9601);

		boost::asio::basic_socket_acceptor<boost::asio::ip::tcp> acceptor(io, end_points);
		
		bool loop{ true };

		while (loop) {

			boost::asio::basic_stream_socket<boost::asio::ip::tcp> socket(io);

			acceptor.accept(socket);

			try {

				boost::asio::streambuf readBuffer;

				boost::asio::read_until (socket, readBuffer, '\n');

				boost::asio::const_buffer input = readBuffer.data();

				std::string message(boost::asio::buffers_begin(input),
					boost::asio::buffers_begin(input) + input.size());

				std::cout << message << std::endl;

			}
			catch (std::exception& e) {

				std::cout << e.what() << std::endl;

			}
						
		}

		acceptor.close();

	}
	catch (std::exception& e) {

		std::cout << e.what() << std::endl;

		return 1;
	}
	   
    return 0;
}