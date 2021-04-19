#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void RunCode(int &&m) { cout << "rvalue ref" << endl; }
void RunCode(int &m) { cout << "lvalue ref" << endl; }
void RunCode(const int &&m) { cout << "const rvalue ref" << endl; }
void RunCode(const int &m) { cout << "const lvalue ref" << endl; }

// 这里利用了universal
// references，如果写T&,就不支持传入右值，而写T&&，既能支持左值，又能支持右值
template <typename T> void perfectForward(T &&t) { RunCode(forward<T>(t)); }

template <typename T> void notPerfectForward(T &&t) { RunCode(t); }

int main() {
    int a = 0;
    int b = 0;
    const int c = 0;
    const int d = 0;

    notPerfectForward(a);       // lvalue ref
    notPerfectForward(move(b)); // lvalue ref
    notPerfectForward(c);       // const lvalue ref
    notPerfectForward(move(d)); // const lvalue ref

    cout << endl;
    perfectForward(a);       // lvalue ref
    perfectForward(move(b)); // rvalue ref
    perfectForward(c);       // const lvalue ref
    perfectForward(move(d)); // const rvalue ref
}