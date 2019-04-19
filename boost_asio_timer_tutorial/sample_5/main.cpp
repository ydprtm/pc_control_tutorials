#include "main.hpp"
#include "main.hpp"

int main(int argc, char* argv[]) {

	try {

		boost::asio::io_context io;

		Delay timer(io);

		timer.delay(5);

		std::cout << "Timer Started" << std::endl;

		boost::thread t(boost::bind(&boost::asio::io_context::run, &io));

		io.run();

		t.join();

	} catch (boost::system::system_error& e) {
		std::cout << e.what() << std::endl;
	}
	
    return 0;
}