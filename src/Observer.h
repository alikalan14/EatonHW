#pragma once

#include <mutex>
#include <string>

class ObserverBase
{
public:
	virtual ~ObserverBase();
	virtual void update(const std::string& message_from_subject) = 0;
};

class ObserverMain : public ObserverBase
{
public:
	virtual void update(const std::string& message_from_subject) override;

private:
	std::size_t message_counter_;
	std::mutex mut_;
};
