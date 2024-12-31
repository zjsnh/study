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

	// ���ڴ洢�߳���Ϣ
	struct threads_ {
		std::thread tid_;  // C++11�߳�
		std::string name_;
	};

	// �̳߳���
	template <class T>
	class ThreadPool {
	public:
		// ���캯����ָ���߳���
		ThreadPool(size_t num = NUM)
			: threads_(num) {
		}

		// �����̳߳�
		void start() {
			int num = threads_.size();
			for (int i = 0; i < num; i++) {
				threads_[i].tid_ = std::thread(&ThreadPool<T>::handle_task, this);
			}
		}

		// ��������
		void push(const T& task) {
			{
				std::lock_guard<std::mutex> lock(mutex_);
				task_.push(task);
			}
			cond_.notify_one();  // ֪ͨ�ȴ��߳���������
		}

		// ��ȡ���񲢴���
		T pop() {
			T task = task_.front();
			task_.pop();
			return task;
		}

		// ��̬��ȡ�̳߳�ָ��
		static ThreadPool<T>*& get_pointer() {
			if (tp == nullptr) {
				std::lock_guard<std::mutex> lock(static_mutex);
				if (tp == nullptr) {
					tp = new ThreadPool<T>();
				}
			}
			return tp;
		}

		// ��������ľ�̬����
		static void handle_task(ThreadPool<T>* this_) {
			while (true) {
				std::unique_lock<std::mutex> lock(this_->mutex_);
				// ���������Ϊ��ʱ���ȴ�����
				while (this_->task_.empty()) {
					this_->cond_.wait(lock);
				}

				T task = this_->pop();
				lock.unlock();

				task();  // ִ������
			}
		}

		// ��ֹ�����͸�ֵ
		ThreadPool(const ThreadPool<T>&) = delete;
		ThreadPool<T>& operator=(const ThreadPool<T>&) = delete;

		// ��������
		~ThreadPool() {
			for (auto& thread : threads_) {
				if (thread.tid_.joinable()) {
					thread.tid_.join();  // �ȴ��߳̽���
				}
			}
		}

	private:
		std::vector<threads_> threads_;  // �߳��б�
		std::queue<T> task_;             // �������

		std::mutex mutex_;               // ������
		std::condition_variable cond_;   // ��������

		static ThreadPool<T>* tp;        // ��̬�̳߳�ָ��
		static std::mutex static_mutex;  // ��̬������
	};

	// ��ʼ����̬��Ա
	template <class T>
	ThreadPool<T>* ThreadPool<T>::tp = nullptr;

	template <class T>
	std::mutex ThreadPool<T>::static_mutex;

}
