#include <algorithm>

#include "Device.h"

namespace
{
	void notify(const std::vector<std::weak_ptr<ObserverBase>>& observers, DeviceBase& device)
	{
		const auto message{ "From " + device.name() + "-> " + device.measurement().toString() };
		for (const auto& observer : observers)
		{
			if (auto ptr{ observer.lock() })
			{
				ptr->update(message);
			}
			else
			{
				device.disconnect(observer);
			}
		}
	}
}

DeviceBase::DeviceBase(std::string name, std::unique_ptr<MeasurementBase> measurement)
	: name_{ std::move(name) }, measurement_{ std::move(measurement) }
{}

DeviceBase::~DeviceBase() = default;

void DeviceBase::connect(std::weak_ptr<ObserverBase> observer)
{
	observers_.push_back(std::move(observer));
}

void DeviceBase::disconnect(std::weak_ptr<ObserverBase> observer)
{
	const auto iter
	{
		std::find_if
		(
			observers_.begin(), observers_.end(),
			[&observer](const auto& elem)
			{
				return observer.expired() || (!elem.expired() && !observer.expired() && elem.lock() == observer.lock());
			}
		)
	};
	if (iter != observers_.end())
	{
		observers_.erase(iter);
	}
}

std::string DeviceBase::name() const
{
	return name_;
}

void DeviceBase::setName(std::string name)
{
	name_ = std::move(name);
}

const MeasurementBase& DeviceBase::measurement() const
{
	return *measurement_;
}

DeviceType1::DeviceType1(std::string name, std::unique_ptr<MeasurementBase> measurement)
	: DeviceBase{ std::move(name), std::move(measurement) }
{}

void DeviceType1::notify()
{
	::notify(observers_, *this);
}

DeviceType2::DeviceType2(std::string name, std::unique_ptr<MeasurementBase> measurement)
	: DeviceBase{ std::move(name), std::move(measurement) }
{}

void DeviceType2::notify()
{
	::notify(observers_, *this);
}
