#ifndef __QUEUES_H__
#define __QUEUES_H__
#include <queue>
#include <thread>
#include "../util/Semaphore.h"

template <typename T, int size>
class Queue
{
public:

	T pop()
	{
		sem_lo.wait();
		auto item = queue_.front();
		queue_.pop();
		sem_hi.notify();
		return item;
	}

	void pop(T& item)
	{
		sem_lo.wait();
		item = queue_.front();
		count--;
		queue_.pop();
		sem_hi.notify()
	}

	void push(const T& item)
	{
		sem_hi.wait();
		queue_.push(item);
		sem_lo.notify();
	}

private:
	std::queue<T> queue_;
	Semaphore sem_lo{ 0 }, sem_hi{ size };
};
#endif
