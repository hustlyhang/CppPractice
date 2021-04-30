#include <iostream>

using namespace std;

class Base{
public:
    Base(){
        cout<<"Base default!"<<endl;
    };
    Base(int _b){
        b = _b;
        cout<<"Base!"<<endl;
    }
    void show(){
        cout<<"b = "<<b<<endl;
    }
private:
    int b;
};

class Derive : public Base{
public:
    // Derive():Base(10){
    //     cout<<"Derive!"<<endl;
    // }
    Derive(){
        Base(10);
    }
};

int main(){

    Base* B = new Derive();
    B->show();

    return 0;
}