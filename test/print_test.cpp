#include <thread>
#include <iostream>
#include <mutex>
#include <string>
#include <condition_variable>
using namespace std;

mutex mtx;
condition_variable cnd;
int ready = 0;

int cunt = 0;

void funca(string s){
    unique_lock<mutex> ul(mtx);
    while (cunt < 30) {
        while (ready != 0) {
            cnd.wait(ul);
        } 
        ready = 1;
        cout<<s<<endl;
        cunt++;
        cnd.notify_all();
    }
}
// void funcb(){
//     int cunt = 0;
//     unique_lock<mutex> ul(mtx);
//     while (cunt < 10) {
//         while (ready != 1) {
//             cnd.wait(ul);
//         } 
//         ready = 2;
//         cout<<"B"<<endl;
//         cunt++;
//         cnd.notify_all();

//     }
// }
// void funcc(){
//     int cunt = 0;
//     unique_lock<mutex> ul(mtx);
//     while (cunt < 10) {
//         while (ready != 2) {
//             cnd.wait(ul);
//         } 
//         ready = 0;
//         cout<<"C"<<endl;
//         cunt++;
//         cnd.notify_all();

//     }
// }


int main() {
    thread t1(funca, "A");
    thread t2(funca, "B");
    thread t3(funca, "C");

    t1.join();
    t2.join();
    t3.join();

    return 0;


}