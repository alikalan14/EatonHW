#pragma once

#include <ostream>
#include <string>

class MeasurementBase
{
public:
	virtual ~MeasurementBase();

	virtual std::string toString() const = 0;
};


class MeasurementType1 : public MeasurementBase
{
public:
	MeasurementType1(std::size_t bettery_level);

	virtual std::string toString() const override;

private:
	std::size_t battery_level_;
};

class MeasurementType2 : public MeasurementBase
{
public:
	MeasurementType2(int voltage);

	virtual std::string toString() const override;

private:
	int voltage_;
};
