#include <iostream>
#include <string>
using namespace std;

template<typename T>
T Max(T a, T b) {
    if (a > b) return a;
    else return b;
}
//! 模板特化
//? 显示关键字template和一对尖括号<>，然后是函数模板特化的定义 该定义指出了返回值 、模板名、被用来特化模板的模板实参，以及函数参数表和函数体

typedef const char* CCP;
template <> CCP Max<CCP> (CCP a, CCP b) {
    return (strcmp(a, b) > 0 ? a : b);
}

//! 函数偏特化
template <typename T> void MM(int a, T b) {

}


//! 类特化
template <class T>
class all{

};
template <> class all<char*> {

};


//! 类偏特化
//! 主模板
template<class T1, class T2>
class nn{

};

//! 类偏特化,之前必须先定义主模板
template<class T> 
class nn<int, T> {

};

int main() {
    string s2("def");
    string s1("abc");
    CCP p = Max<CCP> ("abc", "def");
    string i = Max (s1, s2);
    cout<<p<<endl;
    cout<<i<<endl;

    return 0;
}