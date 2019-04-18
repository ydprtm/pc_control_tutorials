#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

class Delay {

public:
	
	Delay(boost::asio::io_context &io) {

		_t = new boost::asio::steady_timer(io);
		_strand = new boost::asio::io_context::strand(io);
		
	}

	void delay(const int &time) {

		_t->expires_after(boost::asio::chrono::seconds(time));

		_t->async_wait(_strand->wrap(boost::bind(&Delay::timerElapsed, this, boost::asio::placeholders::error)));

	}


private:

	void timerElapsed(const boost::system::error_code &e) {

		std::cout << "Timer Elapsed" << std::endl;

	}

	boost::asio::steady_timer *_t;
	boost::asio::io_context::strand *_strand;

};

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