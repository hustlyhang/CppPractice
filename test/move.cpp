#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class MyString {
  public:
    static size_t CCtor; //统计调用拷贝构造函数的次数
    // static size_t CCtor; //统计调用拷贝构造函数的次数
  public:
    // 构造函数
    MyString(const char *cstr = 0) {
        if (cstr) {
            m_data = new char[strlen(cstr) + 1];
            strcpy(m_data, cstr);
        } else {
            m_data = new char[1];
            *m_data = '\0';
        }
    }

    // 拷贝构造函数
    //? const MyString &str 常量左值引用可以接受右值，可以少一次拷贝构造
    MyString(const MyString &str) {
        CCtor++;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }

    // 移动构造函数
    MyString(MyString &&str): m_data(str.m_data) {
        str.m_data = nullptr;
    }

    // 拷贝赋值函数 =号重载
    MyString &operator=(const MyString &str) {
        if (this == &str) // 避免自我赋值!!
            return *this;

        delete[] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }

    // 移动赋值函数 =号重载
    //? MyString &&str 右值引用
    MyString &operator=(MyString &&str) {
        if (this == &str) // 避免自我赋值!!
            return *this;

        delete[] m_data;
        m_data = str.m_data;
        str.m_data = nullptr; //不再指向之前的资源了
        return *this;
    }

    ~MyString() { delete[] m_data; }

    char *get_c_str() const { return m_data; }

  private:
    char *m_data;
};

size_t MyString::CCtor = 0;

int main() {
    vector<MyString> vecStr;
    vecStr.reserve(
        1000); //先分配好1000个空间，不这么做，调用的次数可能远大于1000
    for (int i = 0; i < 1000; i++) {
        MyString tmp("hello");
        vecStr.push_back(move(tmp));
        //! 虽然tmp是一个左值，但是它的生命周期很短，
        //! 所以通过move来将其变为右值，然后就可以调用mystring中的移动构造函数了
        //! 将自己的指针指向别人的资源，然后将别人的指针修改为nullptr
    }
    cout << MyString::CCtor << endl;

    return 0;
}