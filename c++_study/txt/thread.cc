#include "thread.h"



namespace my_util
{
	ThreadPool::ThreadPool(int threadNum)
		: m_running(false)
	{
		if (threadNum <= 0)
		{
			threadNum = 1;
		}
		else if (threadNum > MAX_THREAD_NUM)
		{
			threadNum = MAX_THREAD_NUM;
		}
		for (int i = 0; i < threadNum; i++)
		{
			m_threads.push_back(std::thread(&ThreadPool::threadFunc, this));
		}
	}

	ThreadPool::~ThreadPool()
	{
		stop();
	}

	void ThreadPool::start()
	{
		m_running = true;
	}

	void ThreadPool::stop()
	{
		{
			std::unique_lock<std::mutex> lock(m_mutex);
			m_running = false;
			m_cond.notify_all();
		}
		for (auto& thread : m_threads)
		{
			thread.join();
		}
	}

	void ThreadPool::addTask(std::function<void()> task)
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		m_tasks.push(task);
		m_cond.notify_one();
	}

	void ThreadPool::threadFunc()
	{
		while (m_running)
		{
			std::function<void()> task;
			{
				std::unique_lock<std::mutex> lock(m_mutex);
				if (!m_tasks.empty())
				{
					task = m_tasks.front();
					m_tasks.pop();
				}
				else
				{
					m_cond.wait(lock);
					continue;
				}
			}
			task();
		}
	}
} // namespace my_util