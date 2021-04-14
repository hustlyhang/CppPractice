#include <iostream>
using namespace std;

class A{
    int A_a = 0;

public:
    A(int a):A_a(a){};
    ~A(){};
};

class B{
public:
    B(int b):B_b(b){};
    ~B(){};
private:
    int B_b = 0;
};

template <typename T>
void fun(T& t) {
    if (typeid(A) == typeid(t)) {
        cout<<"is A"<<endl;
    }
    else if (typeid(B) == typeid(t)) {
        cout<<"is B"<<endl;
    }
}

int main(){
    A a(19);
    B b(1);
    if (typeid(A) == typeid(B)) {
        cout<<"A is equal B"<<endl;
    }
    else {
        cout<<"A is not equal B"<<endl;
    }

    fun(a);
    fun(b);



    return 0;
}