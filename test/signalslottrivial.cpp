#include <iostream>
using namespace std;
/*
    参数包，调用sizeof...可以判断参数包的大小
*/

// template<typename... ARGS>
// void g(ARGS... args) {
//     cout<<"sizeof(ARGS) = "<<sizeof...(ARGS)<<endl;
//     cout<<"sizeof(args) = "<<sizeof...(args)<<endl;
// }
// template<typename T>
// ostream& print(ostream& os, T& t) {
//     return os<<t;
// }
// template<typename T, typename... ARG>
// ostream& print(ostream& os, const T& t, const ARG&... arg) {
//     os<<t<<',';
//     return print(os, arg ...);
// }


int main(){

    print(cout, 1, 1, 2);
    g(1, 'C', "sss");


    return 0;
}
