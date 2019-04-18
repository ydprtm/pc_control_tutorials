#include <iostream>
#include <boost/asio.hpp>

void timerHandle(const boost::system::error_code& e) {

	std::cout << "Timer Elapsed" << std::endl;

}

int main(int argc, char* argv[]) {

	try {

		boost::asio::io_context io;

		boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

		t.async_wait(&timerHandle);

		std::cout << "Timer Started" << std::endl;

		io.run();

	} catch (boost::system::system_error& e) {
		std::cout << e.what() << std::endl;
	}
	
    return 0;
}