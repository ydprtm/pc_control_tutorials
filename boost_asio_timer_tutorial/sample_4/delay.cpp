#include "delay.hpp"

Delay::Delay(boost::asio::io_context& io) :
	_t(io)
{

}

void Delay::delay(const int& time) {

	_t.expires_after(boost::asio::chrono::seconds(time));

	_t.async_wait(boost::bind(&Delay::timerElapsed, this, boost::asio::placeholders::error));

}



void Delay::timerElapsed(const boost::system::error_code& e) {

	std::cout << "Timer Elapsed" << std::endl;

}


