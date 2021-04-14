#include <Windows.h>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

using namespace std;

class MultiThreadProduceConsume {
  private:
    //! 需要两个条件变量，当生产了材料后要通知消费者消费，消费后要通知生产者生产
    condition_variable produce_msgQueue;
    condition_variable consume_msgQueue;
    mutex mtx;

    //! 线程池，存放生产线程和消费线程
    vector<std::thread> tpool;

  private:
    //! 用于存放生产的材料
    queue<int> item_buff;
    //! 整个队列的长度
    const int buffsize;
    //! 生产的材料的编号
    static int item_id;
    //! 生产线程和消费线程的个数
    int c_no, p_no;

  private:
    void producItem() {
        while (true) {
            std::unique_lock<mutex> lck(mtx);
            while (item_buff.size() == buffsize) {
                produce_msgQueue.wait(lck);
            }
            Sleep(10);
            item_id = item_id++ % buffsize;
            item_buff.push(item_id);
            cout << "product item id: " << item_id << endl;

            consume_msgQueue.notify_all();
            //lck.unlock();
        }
    }
    void consumeItem() {
        while (true) {
            std::unique_lock<mutex> lck(mtx);
            while (item_buff.empty()) {
                cout << "wait product" << endl;
                consume_msgQueue.wait(lck);
            }
            Sleep(10);
            cout << "customer id : " << this_thread::get_id() << endl;
            cout << "consume Item id: " << item_buff.front() << endl;
            item_buff.pop();
            produce_msgQueue.notify_one();
            //lck.unlock();
        }
    }

  public:
    //? 初始化
    MultiThreadProduceConsume(int size = 10, int pno = 1, int cno = 5) : buffsize(size), p_no(pno), c_no(cno){};

    void run() {
        //? 将生产者和消费者线程加入到线程池中
        productTask();
        customerTask();
        //? 然后让主线程等待线程池中的线程
        for (auto &i : tpool) {
            i.join();
        }
    }

    //! 注意线程用类成员函数作为参数时初始化方法
    void productTask() {
        for (int i = 0; i < p_no; i++) {
            tpool.emplace_back(
                thread(&MultiThreadProduceConsume::producItem, this));
        }
    }
    void customerTask() {
        for (int i = 0; i < c_no; i++) {
            tpool.emplace_back(
                thread(&MultiThreadProduceConsume::consumeItem, this));
        }
    }
};
int MultiThreadProduceConsume::item_id = 0;

int main() {
    MultiThreadProduceConsume t;
    t.run();
    system("pause");
    return 0;
}
