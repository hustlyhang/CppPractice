#include <iostream>

using namespace std;

class base{
public:
    int a;
    virtual void fun() {
    };
};

class derive : public base{
    int b;
};

int main() {


    base b;
    derive d;

    cout<<"sizeof(base)"<<sizeof(b)<<endl;
    cout<<"sizeof(derive)"<<sizeof(d)<<endl;






    return 0;
}