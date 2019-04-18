#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

void timerHandle(const boost::system::error_code& e, boost::asio::steady_timer *t, int *count) {

	if (*count < 5) {

		std::cout << *count << std::endl;

		(*count)++;
		t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
		t->async_wait(boost::bind(timerHandle, boost::asio::placeholders::error, t, count));
		
	}
	else {

		std::cout << "Timer Elapsed" << std::endl;

	}
}

int main(int argc, char* argv[]) {

	try {

		boost::asio::io_context io;

		boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));

		int count{ 0 };

		t.async_wait(boost::bind(timerHandle, boost::asio::placeholders::error, &t, &count));

		std::cout << "Timer Started" << std::endl;

		io.run();

	}
	catch (boost::system::system_error& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}