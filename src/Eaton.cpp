#include "Device.h"
#include "Observer.h"

#include <chrono>
#include <iostream>
#include <random>
#include <thread>


void simulator(DeviceBase& device)
{
	std::random_device randomDev;
	std::mt19937 rng{ randomDev() };
	std::uniform_int_distribution<std::mt19937::result_type> dist{ 0, 5 };

	while (true)
	{
		const auto num{ dist(rng) };
		std::this_thread::sleep_for(std::chrono::seconds{ num });
		device.notify();
	}
}


int main()
{
	using namespace std::chrono_literals;

	auto cp1{ std::make_unique<DeviceType1>("Cell phone 1", std::make_unique<MeasurementType1>(14)) };
	auto cp2{ std::make_unique<DeviceType1>("Cell phone 2", std::make_unique<MeasurementType1>(34)) };
	auto freezer{ std::make_unique<DeviceType2>("Freezer", std::make_unique<MeasurementType2>(220)) };

	auto messageReader{ std::make_shared<ObserverMain>() };

	cp1->connect(messageReader);
	cp2->connect(messageReader);
	freezer->connect(messageReader);


	std::thread th1{ simulator, std::ref(*cp1) };
	std::thread th2{ simulator, std::ref(*cp2) };
	std::thread th3{ simulator, std::ref(*freezer) };

	th1.detach();
	th2.detach();
	th3.detach();


	while (true)
	{
		std::this_thread::sleep_for(std::chrono::hours{ 24 });
	}
}
