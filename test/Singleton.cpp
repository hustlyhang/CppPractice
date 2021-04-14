#include <iostream>
#include <mutex>
//#include <pthread.h>
using namespace std;

//mutex m;


/*************************懒汉版*************************************/
class Singleton{
private:
    static Singleton* instance;
    Singleton(){cout<<"construct！"<<endl;};
    ~Singleton(){cout<<"destruct!"<<endl;};
    //? 拷贝构造函数和拷贝赋值函数都需要声明为私有
    Singleton(const Singleton&);
    Singleton& operator = (const Singleton& a);
public:
    static Singleton* get() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

//? 初始化静态成员
Singleton* Singleton::instance = nullptr;
/*
    * 懒汉模式存在内存泄漏的问题，因为析构函数不会被调用，声明为私有
    * 可以使用智能指针或者使用静态的嵌套类对象
*/

/*************************懒汉版**静态的嵌套类对象*避免内存泄漏************************************/
class Singleton1{
private:
    static Singleton1* instance1;
    Singleton1(){cout<<"construct！"<<endl;};
    ~Singleton1(){cout<<"destruct!"<<endl;};
    Singleton1(const Singleton1& a);
    Singleton1& operator =(const Singleton1& a);

    //? 注意这儿没有static
    class deleter{
    public:
        deleter(){};
        ~deleter(){
            cout<<"in deleter"<<endl;
            if (Singleton1::instance1) {
                delete Singleton1::instance1;
            }
        };
    }; 
    static deleter Deleter;
public:
    static Singleton1* get() {
        //? 线程安全 双检测锁DCL
        if (instance1 == nullptr) {
            //lock_guard<mutex> lock(m);//? 基于作用域加锁，超出作用域自动解锁
            if (instance1 == nullptr) {
                instance1 = new Singleton1();
            }
        }
        
        return instance1;
    }
};
//? 初始化静态成员
Singleton1* Singleton1::instance1 = nullptr;
/*
    * 在程序运行结束时，系统会调用静态成员的析构函数该析构函数会删除单例的唯一实例。使用这种方法释放单例对象有以下特征：
    * 在单例类内部定义专有的嵌套类。
    * 在单例类内定义私有的专门用于释放的静态成员。
    todo 利用程序在结束时析构全局变量的特性，选择最终的释放时机。

*/
/**************************************最好的懒汉模式*********************************************************/
class Singleton2{
private:
    Singleton2(){cout<<"construct!"<<endl;};
    ~Singleton2(){};
    Singleton2(const Singleton2&);
	Singleton2& operator=(const Singleton2&);
public:
    static Singleton2& get() {
        static Singleton2 instance2;
        return instance2;
    }
};

/*************************************饿汉模式*********************************************************/
class Singleton3{
private:
    static Singleton3 instance3;
    Singleton3(){cout<<"construct!"<<endl;};
    ~Singleton3(){};
    Singleton3(const Singleton&){};
    Singleton3& operator=(const Singleton3&) {};

public:
    static Singleton3& get() {
        return instance3;
    }
};

Singleton3 Singleton3::instance3;


void test1(){
    Singleton1* instance1 = Singleton1::get();
    Singleton1* instance2 = Singleton1::get();
    return;
}
void test2(){
    Singleton2& isntance1 = Singleton2::get();
    Singleton2& isntance2 = Singleton2::get();

    return;
}
void test3(){
    Singleton3& isntance1 = Singleton3::get();
    Singleton3& isntance2 = Singleton3::get();

    return;
}
int main() {
    // Singleton* instance = Singleton::get();
    // Singleton* instance2 = Singleton::get();

    //test1();
    test3();

    return 0;
}