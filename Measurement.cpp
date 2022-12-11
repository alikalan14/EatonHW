#include "Measurement.h"

MeasurementBase::~MeasurementBase() = default;

MeasurementType1::MeasurementType1(std::size_t bettery_level)
	: battery_level_{ bettery_level }
{}

std::string MeasurementType1::toString() const
{
	return "Battery Level: " + std::to_string(battery_level_);
}

MeasurementType2::MeasurementType2(int voltage)
	: voltage_{ voltage }
{}

std::string MeasurementType2::toString() const
{
	return "Voltage: " + std::to_string(voltage_);
}