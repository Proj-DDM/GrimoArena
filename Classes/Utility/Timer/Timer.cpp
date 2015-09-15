#include "Timer.h"
#include "cocos2d.h"
namespace MyUtil{
	Timer::Timer(int _time) : mTime(_time)
	{
	}

	Timer::Timer() : mTime(0), mIsStart(false), mIsStop(true)
	{

	}

	Timer::Timer(int _time, bool _isStart, bool _isStop) :
		mTime(_time), mIsStart(_isStart), mIsStop(_isStop)
	{
	}

	Timer::~Timer()
	{
	}

	void Timer::update()
	{
		if (mIsStart&&!mIsStop)
		{
			this->mTime += 1;
		}
	}


	void Timer::pause()
	{
		mIsStop = true;
	}

	void Timer::resume()
	{
		mIsStop = false;
	}

	void Timer::reset()
	{
		mIsStop = false;
		mIsStart = false;
		mTime = 0;
	}

	void Timer::begin()
	{
		mIsStart = true;
	}

	int Timer::getTime()
	{
		return mTime;
	}

	int Timer::getSecond()
	{
		auto director = cocos2d::Director::getInstance();
		float fps = director->getFrameRate();
		int a = 0;
		if (fps != NULL)
			return mTime / fps;

		return mTime / 60;
	}

	Timer Timer::operator + (int _time) const
	{
		return Timer(mTime + _time, mIsStart, mIsStop);
	}

	Timer Timer::operator ++ (int)
	{
		this->mTime += 1;

		return Timer(mTime, mIsStart, mIsStop);
	}
}
