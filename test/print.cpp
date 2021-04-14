// /*用条件变量控制输出的字符，用ready来标记哪个线程来输出，当ready==0时，func1线程打印A，
// 如果不是1的话则阻塞在条件变量上等待，当func1线程打印完成后，给ready+1，让另一个线程打印B，以此类推*/
#include <condition_variable>
#include <iostream>
#include <thread>
using namespace std;

mutex mtx;
condition_variable cv;
int ready = 0;

void func1() {
    unique_lock<mutex> ul(mtx);
    int cnt = 0;
    while (cnt < 10) {
        while (ready != 0)
            cv.wait(ul);
        cout << "A"
             << " ";
        ready = 1;
        cnt++;
        cv.notify_all();
    }
}
void func2() {
    unique_lock<mutex> ul(mtx);
    int cnt = 0;
    while (cnt < 10) {
        while (ready != 1)
            cv.wait(ul);
        cout << "B"
             << " ";
        cnt++;
        ready = 2;
        cv.notify_all();
    }
}
void func3() {
    unique_lock<mutex> ul(mtx);
    int cnt = 0;
    while (cnt < 10) {
        while (ready != 2)
            cv.wait(ul);
        cout << "C"
             << " ";
        ready = 0;
        cnt++;
        cv.notify_all();
    }
}
int main() {
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);
    t1.join();
    t2.join();
    t3.join();

    return 0;
}

