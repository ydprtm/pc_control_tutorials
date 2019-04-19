#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>


class SerialPort {
public:

	SerialPort(boost::asio::io_context& io, std::string& device) :
		port(io, device),
		readBuffer(),
		writeBuffer()
	{

		port.set_option(boost::asio::serial_port_base::baud_rate(115200));
		port.set_option(boost::asio::serial_port_base::character_size(8));
		port.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
		port.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
		
	}

	void asyncWrite(std::string& message) {

		std::ostream output(&writeBuffer);

		output << message;
		
		boost::asio::async_write(port, writeBuffer.data(), boost::bind(&SerialPort::writeHandle, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

	}

	void asyncRead(std::string* message) {

		boost::asio::async_read_until(port, readBuffer, "\n", boost::bind(&SerialPort::readHandle, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred, message));

	}

	void close() {

		port.close();

	}

private:

	void writeHandle(const boost::system::error_code& e, std::size_t bytes) {

		boost::asio::const_buffer output = writeBuffer.data();

		std::string message(boost::asio::buffers_begin(output),
			boost::asio::buffers_begin(output) + output.size());

		std::cout << "Message Written: " << message << std::endl;

	}

	void readHandle(const boost::system::error_code& e, std::size_t byes, std::string *message) {
		
		boost::asio::const_buffer input = readBuffer.data();

		*message = std::string(boost::asio::buffers_begin(input),
			boost::asio::buffers_begin(input) + input.size());
					
		std::cout << "Message Read: " << *message << std::endl;

	}

	boost::asio::serial_port port;

	boost::asio::streambuf readBuffer;
	boost::asio::streambuf writeBuffer;

};



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
	catch (boost::system::error_code &e) {
		std::cout << e << std::endl;
		return 1;
	}
	   
    return 0;
}