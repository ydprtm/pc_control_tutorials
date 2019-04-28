#include "main.hpp"

int main(int argc, char* argv[]) {

	try {

		boost::asio::io_context io;

		SerialPort port(io, std::string( "COM4"));

		std::string writeMessage{ "Hello World!\r\n" };

		port.asyncWrite(writeMessage);
		
		std::string readMessage{};

		port.asyncRead(&readMessage);

		io.run();

		port.close();
	

	}
	catch (std::exception& e) {

		std::cout << e.what() << std::endl;

		return 1;

	}
	   
    return 0;
}