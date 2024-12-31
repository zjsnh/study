#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace my_util {

#define NUM 10

	// 用于存储线程信息
	struct threads_ {
		std::thread tid_;  // C++11线程
		std::string name_;
	};

	// 线程池类
	template <class T>
	class ThreadPool {
	public:
		// 构造函数，指定线程数
		ThreadPool(size_t num = NUM)
			: threads_(num) {
		}

		// 启动线程池
		void start() {
			int num = threads_.size();
			for (int i = 0; i < num; i++) {
				threads_[i].tid_ = std::thread(&ThreadPool<T>::handle_task, this);
			}
		}

		// 推送任务
		void push(const T& task) {
			{
				std::lock_guard<std::mutex> lock(mutex_);
				task_.push(task);
			}
			cond_.notify_one();  // 通知等待线程有新任务
		}

		// 获取任务并处理
		T pop() {
			T task = task_.front();
			task_.pop();
			return task;
		}

		// 静态获取线程池指针
		static ThreadPool<T>*& get_pointer() {
			if (tp == nullptr) {
				std::lock_guard<std::mutex> lock(static_mutex);
				if (tp == nullptr) {
					tp = new ThreadPool<T>();
				}
			}
			return tp;
		}

		// 处理任务的静态函数
		static void handle_task(ThreadPool<T>* this_) {
			while (true) {
				std::unique_lock<std::mutex> lock(this_->mutex_);
				// 当任务队列为空时，等待任务
				while (this_->task_.empty()) {
					this_->cond_.wait(lock);
				}

				T task = this_->pop();
				lock.unlock();

				task();  // 执行任务
			}
		}

		// 禁止拷贝和赋值
		ThreadPool(const ThreadPool<T>&) = delete;
		ThreadPool<T>& operator=(const ThreadPool<T>&) = delete;

		// 析构函数
		~ThreadPool() {
			for (auto& thread : threads_) {
				if (thread.tid_.joinable()) {
					thread.tid_.join();  // 等待线程结束
				}
			}
		}

	private:
		std::vector<threads_> threads_;  // 线程列表
		std::queue<T> task_;             // 任务队列

		std::mutex mutex_;               // 互斥锁
		std::condition_variable cond_;   // 条件变量

		static ThreadPool<T>* tp;        // 静态线程池指针
		static std::mutex static_mutex;  // 静态互斥锁
	};

	// 初始化静态成员
	template <class T>
	ThreadPool<T>* ThreadPool<T>::tp = nullptr;

	template <class T>
	std::mutex ThreadPool<T>::static_mutex;

}
