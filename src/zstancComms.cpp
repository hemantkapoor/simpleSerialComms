//============================================================================
// Name        : zstancComms.cpp
// Author      : Hemant Kapoor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <thread>
#include"comms/Comms.h"

int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	std::string serialPath =  R"(/dev/pts/19)";
	auto sp = std::make_shared<Comms>(serialPath);
	if(sp->startComms() == false)
	{
		std::cout<<__PRETTY_FUNCTION__<<" : Cannot access serial port\r\n";
		return -1;
	}
	//If here then we better spawn a thread
	std::thread thread_1(&Comms::processRead, sp);
	std::cout<<__PRETTY_FUNCTION__<<" : Serial port Running... Press q to quit\r\n";
	char option;
	while(option != 'q')
	{
		std::cin.get(option);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	//We are here so do graceful exit
	std::cout<<__PRETTY_FUNCTION__<<" : Closing Application\r\n";
	sp->stopRead();
	thread_1.join();

	return 0;
}
