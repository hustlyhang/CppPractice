
#include <iostream>
using namespace std;

class A final{
public:
    A(){};
    virtual void fun() final {};
};


class B : public A{
public:
    B(){};
    void fun() {
        cout<<"in B"<<endl;
    }
};

//? 默认构造函数

class test{
public:
    test(int a): a(a){

    };
    test() = default;
private:
    int a;
};

constexpr int size(){return 3;};
int size2(){return 3;};
//int a[size2()];