
#include <iostream>
using namespace std;

class Copyable {
  public:
    Copyable() {}
    Copyable(const Copyable &o) { cout << "Copied" << endl; }
};
Copyable ReturnRvalue() {
    return Copyable(); //返回一个临时对象
}
void AcceptVal(Copyable a) {}
void AcceptRef(const Copyable &a) {}

int main() {
    cout << "pass by value: " << endl;
    //? ReturnRvalue()会返回一个临时对象，然后
    /*
        * 期望中AcceptVal(ReturnRvalue())需要调用两次拷贝构造函数，一次在ReturnRvalue()函数中，
        * 构造好了Copyable对象，返回的时候会调用拷贝构造函数生成一个临时对象，在调用AcceptVal()时，
        * 又会将这个对象拷贝给函数的局部变量a，一共调用了两次拷贝构造函数。而AcceptRef()的不同在于形参
        * 是常量左值引用，它能够接收一个右值，而且不需要拷贝。
        * 而实际的结果是，不管哪种方式，一次拷贝构造函数都没有调用！
    */
    AcceptVal(ReturnRvalue()); // 应该调用两次拷贝构造函数
    cout << "pass by reference: " << endl;
    AcceptRef(ReturnRvalue()); //应该只调用一次拷贝构造函数

    return 0;
}
