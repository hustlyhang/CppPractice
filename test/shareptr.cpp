#include <memory>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;


shared_ptr<string> p1;
shared_ptr<string> p2;

unique_ptr<string> p3;

// unique_ptr可以指向数组
unique_ptr<int[]> p5 = make_unique<int[]>(10);
unique_ptr<int[]> p6(new int[100]);



void test(){
    shared_ptr<int[]> sp(new int[10]);

    if (sp.use_count() == 1) {
        shared_ptr<int[]> tmp = sp;
        if (sp.use_count() == 2) {
            cout<<"sp us_count = " <<2<<endl;
        }
        if (tmp.get() == sp.get()) {
            cout<<"*tmp == *sp"<<endl;
        }
    }
    if (sp.use_count() == 1) {
        cout<<"sp us_count = " <<1<<endl;
    }
    return;
}
int main() {
    // p1 = make_shared<string>("hello");
    // auto q(p1);
    // p2 = p1;
    // cout<<"p1 count = " <<p1.use_count()<<endl;

    // p1 = make_shared<string>("new");
    // cout<<"p1 count = " <<p1.use_count()<<endl;

    // if (p1) {
    //     cout<<"share_ptr 不为空"<<endl;
        
    //     cout<<"*p1 = "<<*p1<<endl;
    // }
    // else {
    //     cout<<"share_ptr 为空"<<endl;
    //     *p1 = "hi";
    //     cout<<"*p1 = "<<*p1<<endl;
    // }

    // p3 = make_unique<string>("hhhh");
    // auto p4 = move(p3);
    // if(p3 == nullptr) {
    //     cout<<"将 p3 移动到 p4"<<endl;
    //     cout<<"p4 = "<< *p4 <<endl;

    // };
    test();

    return 0;
}