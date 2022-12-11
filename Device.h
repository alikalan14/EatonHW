#pragma once

#include "Measurement.h"
#include "Observer.h"

#include <memory>
#include <string>
#include <vector>

class DeviceBase
{
public:
	DeviceBase(std::string name, std::unique_ptr<MeasurementBase> measurement);
	virtual ~DeviceBase();

	virtual void connect(std::weak_ptr<ObserverBase> observer);
	virtual void disconnect(std::weak_ptr<ObserverBase> observer);
	virtual void notify() = 0;

	std::string name() const;
	void setName(std::string name);

	const MeasurementBase& measurement() const;

protected:
	std::string name_;
	std::unique_ptr<MeasurementBase> measurement_;
	std::vector<std::weak_ptr<ObserverBase>> observers_;
};

class DeviceType1 : public DeviceBase
{
public:
	DeviceType1(std::string name, std::unique_ptr<MeasurementBase> measurement);

	virtual void notify() override;
};

class DeviceType2 : public DeviceBase
{
public:
	DeviceType2(std::string name, std::unique_ptr<MeasurementBase> measurement);

	virtual void notify() override;
};