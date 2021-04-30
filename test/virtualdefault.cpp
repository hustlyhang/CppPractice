#include <iostream>
using namespace std;

class E {
  public:
    virtual void func(int i = 0) {
        cout<<"E::func()\t"<<i<<endl;
    }  
};

class F : public E{
    public:
        virtual void func(int i = 1) {
            cout<<"F::func()\t"<<i<<endl;
        }
};

void test(){
    E* a = new F;
    a->func();

}

int main(){

    test();


    return 0;
}


