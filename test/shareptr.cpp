#include <memory>
#include <string>
#include <iostream>
using namespace std;


shared_ptr<string> p1;
shared_ptr<string> p2;



int main() {
    p1 = make_shared<string>("hello");
    auto q(p1);
    p2 = p1;
    cout<<"p1 count = " <<p1.use_count()<<endl;

    p1 = make_shared<string>("new");
    cout<<"p1 count = " <<p1.use_count()<<endl;

    if (p1) {
        cout<<"share_ptr ²»Îª¿Õ"<<endl;
        
        cout<<"*p1 = "<<*p1<<endl;
    }
    else {
        cout<<"share_ptr Îª¿Õ"<<endl;
        *p1 = "hi";
        cout<<"*p1 = "<<*p1<<endl;
    }


    return 0;
}