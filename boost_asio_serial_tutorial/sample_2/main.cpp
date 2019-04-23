#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

void writeHandle(const boost::system::error_code &e, const std::size_t bytes) {

	std::cout << "Bytes Written: " << bytes << std::endl;

}

void readHandle(const boost::system::error_code& e, const std::size_t bytes) {
	
	std::cout << "Bytes Read: " << bytes << ": " << std::endl;

}

int main(int argc, char* argv[]) {

	try {

		boost::asio::io_context io;

		boost::asio::serial_port serial(io, "COM4");

		serial.set_option(boost::asio::serial_port_base::baud_rate(115200));
		serial.set_option(boost::asio::serial_port_base::character_size(8));
		serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
		serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

		std::string data{ "Hello World!\r\n" };

		boost::asio::async_write(serial, boost::asio::buffer(data), boost::bind(writeHandle, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

		boost::asio::streambuf buf{ };

		boost::asio::async_read_until(serial, buf, "\n", boost::bind(readHandle, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

		io.run();

		const char* bufPtr = boost::asio::buffer_cast<const char*>(buf.data());
		
		std::cout << bufPtr;		

		serial.close();

	}
	catch (boost::system::error_code &e) {

		std::cout << e << std::endl;

		return 1;

	}
	   
    return 0;
}