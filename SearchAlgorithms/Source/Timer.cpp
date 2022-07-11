#include "Timer.h"

Timer::Timer()
: m_timePoint{ clock_type::now() }
{
}

Timer::~Timer()
{
}

double Timer::GetElapsedTime() const
{
	return std::chrono::duration_cast<second_type>(
		clock_type::now() - m_timePoint).count();
}

void Timer::Reset()
{
	m_timePoint = clock_type::now();
}
