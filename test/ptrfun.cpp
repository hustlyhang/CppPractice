#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double cal_m1(int lines) {
    return 0.05*lines;
}

double cal_m2(int lines) {
    return 0.5*lines;
}


void estimate(int lines, double(*pf)(int)) {
    cout<<(*pf)(lines)<<endl;
}

const double* f1(const double a[], int n);
const double* f2(const double [], int n); 
const double* f3(const double* , int n); 

typedef const double*(*pf)(const double*, int);


int main() {

    // int lines = 10;
    // estimate(lines, cal_m1);
    // estimate(lines, cal_m2);
    double a[3] = {12.1, 3.4, 4.5};

    pf p1 = f1;
    cout << "Pointer 1 : " << p1(a, 3) << " : " << *(p1(a, 3)) << endl;
    cout << "Pointer 1 : " << (*p1)(a, 3) << " : " << *((*p1)(a, 3)) << endl;

    const double* (*parray[3])(const double *, int) = {f1, f2, f3}; // 声明一个指针数组，存储三个函数的地址
    cout << "Pointer array : " << parray[2](a, 3) << " : " << *(parray[2](a, 3)) << endl;
    cout << "Pointer array : " << parray[2](a, 3) << " : " << *(parray[2](a, 3)) << endl;
    cout << "Pointer array : " << (*parray[2])(a, 3) << " : " << *((*parray[2])(a, 3)) << endl;

    return 0;
}

const double* f1(const double a[], int n){
    return a;
}
const double* f2(const double a[], int n){
    return a + 1;
}
const double* f3(const double* a, int n){
    return a + 2;
}
