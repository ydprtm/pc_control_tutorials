#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class Delay {

public:
	
	Delay(boost::asio::io_context &io) {

		_t = new boost::asio::steady_timer(io);

	}

	void delay(const int &time) {

		_t->expires_after(boost::asio::chrono::seconds(time));

		_t->async_wait(boost::bind(&Delay::timerElapsed, this, boost::asio::placeholders::error));

	}


private:

	void timerElapsed(const boost::system::error_code &e) {

		std::cout << "Timer Elapsed" << std::endl;

	}

	boost::asio::steady_timer *_t;

};

int main(int argc, char* argv[]) {

	try {

		boost::asio::io_context io;

		Delay timer(io);

		timer.delay(5);

		std::cout << "Timer Started" << std::endl;

		io.run();

	}
	catch (boost::system::system_error& e) {
		std::cout << e.what() << std::endl;
	}

    return 0;
}