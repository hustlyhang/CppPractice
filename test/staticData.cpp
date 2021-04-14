#include <iostream>
using namespace std;


class StaticTest{
public:
    StaticTest(int a):A(a){
        B++;
    }
    static void print(StaticTest t);
private:
    int A;
    static int B;
};

void StaticTest::print(StaticTest t) {
    cout<<"t.A: "<<t.A<<endl;
    cout<<"StaticTest::B: "<<StaticTest::B<<endl;
    cout<<"t.B: "<<t.B<<endl;
}

int StaticTest::B = 0;

int main() {

    StaticTest a1(66);
    StaticTest::print(a1);
    StaticTest a2(77);
    StaticTest::print(a2);



    return 0;
}