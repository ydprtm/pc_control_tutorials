// camera_server.cpp : Defines the entry point for the console application.
//

#include "sync_server.h"

int main()
{

	cv::VideoCapture camera(0);

	if(!camera.isOpened()) 
	{
		return -1;
	}
	else {
		std::cout << "Camera is opened." << std::endl;
	}

	sync_server server(9601);
	
	while (true) 
	{

		server.connect();

		cv::Mat frame;

		camera >> frame;

		if (frame.empty()) {
			continue;
		}

		server.sendFrames(frame);

		server.close();

	}

	return 0;
}

