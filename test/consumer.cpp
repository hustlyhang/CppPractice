#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>



std::mutex _mtx;
std::condition_variable _cv_not_full;
std::condition_variable _cv_not_empty;

const int max_queue_size_10 = 10;

enum
{
	// 总生产数目
	cnt_total_10 = 10,
};


template<typename T>
struct repo_
{
	// 用作互斥访问缓冲区
	std::mutex				_mtx_queue;

	// 缓冲区最大size
	unsigned int			_count_max_queue_10 = 10;

	// 缓冲区
	std::queue<T>			_queue;

	// 缓冲区没有满，通知生产者继续生产
	std::condition_variable _cv_queue_not_full;

	// 缓冲区不为空，通知消费者继续消费
	std::condition_variable _cv_queue_not_empty;



	// 用于生产者之间的竞争
	std::mutex				_mtx_pro;
	// 计算当前已经生产了多少数据了
	unsigned int			_cnt_cur_pro = 0;


	// 用于消费者之间的竞争
	std::mutex				_mtx_con;
	// 计算当前已经消费多少数据了
	unsigned int			_cnt_cur_con = 0;


	repo_(const unsigned int count_max_queue = 10) :_count_max_queue_10(count_max_queue)
		, _cnt_cur_con(0)

	{
		;
	}

	repo_(const repo_&instance) = delete;
	repo_& operator = (const repo_& instance) = delete;
	repo_(const repo_&&instance) = delete;
	repo_& operator = (const repo_&& instance) = delete;

};

template <typename T>
using repo = repo_<T>;





//----------------------------------------------------------------------------------------

// 生产者生产数据
template <typename T>
void thread_produce_item(const int &thread_index, repo<T>& param_repo, const T& repo_item)
{
	std::unique_lock<std::mutex> lock(param_repo._mtx_queue);

	// 1. 生产者只要发现缓冲区没有满， 就继续生产
	param_repo._cv_queue_not_full.wait(lock, [&] { return param_repo._queue.size() < param_repo._count_max_queue_10; });

	// 2. 将生产好的商品放入缓冲区
	param_repo._queue.push(repo_item);

	// log to console
	std::cout << "生产者" << thread_index << "生产数据：" << repo_item << "\n";

	// 3. 通知消费者可以消费了
	//param_repo._cv_queue_not_empty.notify_one();
	param_repo._cv_queue_not_empty.notify_one();
}


//----------------------------------------------------------------------------------------
// 消费者消费数据

template <typename T>
T thread_consume_item(const int thread_index, repo<T>& param_repo)
{
	std::unique_lock<std::mutex> lock(param_repo._mtx_queue);

	// 1. 消费者需要等待【缓冲区不为空】的信号
	param_repo._cv_queue_not_empty.wait(lock, [&] {return !param_repo._queue.empty(); });

	// 2. 拿出数据
	T item;
	item = param_repo._queue.front();
	param_repo._queue.pop();

	std::cout << "消费者" << thread_index << "从缓冲区中拿出一组数据:" << item << std::endl;

	// 3. 通知生产者，继续生产
	param_repo._cv_queue_not_full.notify_one();

	return item;
}


//----------------------------------------------------------------------------------------

/**
*  @ brief: 生产者线程
*  @ thread_index - 线程标识，区分是哪一个线程
*  @ count_max_produce - 最大生产次数
*  @ param_repo - 缓冲区
*  @ return - void

*/
template< typename T >
void thread_pro(const int thread_index, const int count_max_produce, repo<T>* param_repo)
{
	if (nullptr == param_repo || NULL == param_repo)
		return;
	

	while (true)
	{
		bool is_running = true;

		{
			// 用于生产者之间竞争
			std::unique_lock<std::mutex> lock(param_repo->_mtx_pro);

			// 缓冲区没有满，继续生产
			if (param_repo->_cnt_cur_pro < cnt_total_10)
			{
				thread_produce_item<T>(thread_index, *param_repo, param_repo->_cnt_cur_pro);
				++param_repo->_cnt_cur_pro;
			}
			else
				is_running = false;
		}

		std::this_thread::sleep_for(std::chrono::microseconds(16));
		if (!is_running)
			break;
	}
}



/**
*  @ brief: 消费者线程
*  @ thread_index - 线程标识，区分线程
*  @ param_repo - 缓冲区
*  @ return - void

*/
template< typename T >
void thread_con(const int thread_index, repo<T>* param_repo)
{
	if (nullptr == param_repo || NULL == param_repo)
		return;

	while (true)
	{
		bool is_running = true;
		{
			std::unique_lock<std::mutex> lock(param_repo->_mtx_con);
			// 还没消费到指定的数目，继续消费
			if (param_repo->_cnt_cur_con < cnt_total_10)
			{
				thread_consume_item<T>(thread_index, *param_repo);
				++param_repo->_cnt_cur_con;
			}
			else
				is_running = false;

		}

		std::this_thread::sleep_for(std::chrono::microseconds(16));

		// 结束线程
		if ((!is_running))
			break;
	}
}


// 入口函数
//----------------------------------------------------------------------------------------

int main(int argc, char *argv[], char *env[])
{
	// 缓冲区
	repo<int> repository;
	// 线程池
	std::vector<std::thread> vec_thread;

	// 生产者
	vec_thread.push_back(std::thread(thread_pro<int>, 1, cnt_total_10, &repository));
	vec_thread.push_back(std::thread(thread_pro<int>, 2, cnt_total_10, &repository));

	// 消费者
	vec_thread.push_back(std::thread(thread_con<int>, 1, &repository));
	vec_thread.push_back(std::thread(thread_con<int>, 2, &repository));



	for (auto &item : vec_thread)
	{
		item.join();
	}

	return 0;
}
