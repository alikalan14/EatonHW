#include "Observer.h"

#include <iostream>

ObserverBase::~ObserverBase() = default;

void ObserverMain::update(const std::string& message)
{
	std::lock_guard<std::mutex> lg{ mut_ };
	std::cout << "Current counter: " << ++message_counter_ << " -------- Message: " << message << std::endl;
}