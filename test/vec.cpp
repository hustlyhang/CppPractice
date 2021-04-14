#include <string>
#include <iostream>
using namespace std;
/*
    * 自己实现简单的vector类
    * 注意主要 有 当前元素个数，总的容量，初始容量， 以及一个指针，指向分配的一块地址。
    * 构造函数，要初始化 thesize, thecapacity, 以及data指针
    * 复制构造函数 注意使用memcpy函数
    * 重载赋值函数、下标运算符函数
    * 重新分配函数（重要）容量的扩增
    * push_back函数 每次要判断容量和当前元素个数， 容量不够的话要进行扩容
    *
*/

template<class T>
class vec {
public:
    //* 构造函数
    vec(int size = 0) : theSize(size), theCapacity(size + INIT_CAPACITY) {
        cout<<"进入构造函数"<<endl;
        //? 调用构造函数时，需要分配地址
        data = new T[theCapacity];
    }
    
    //* 复制构造函数
    vec(const vec& other): theSize(0), theCapacity(0), data(nullptr) {
        theSize = other.theSize;
        theCapacity = other.theCapacity;
        data = new T[theCapacity];
        //? 内存拷贝
        memcpy(data, other.data, theSize* sizeof(T));
    }

    //* 重载赋值函数
    vec& operator = (const vec& other) {
        cout << "进入重载赋值运算符函数" << endl;
        //? 判断是不是同一个对象
        if (this == &other) return *this;
        else {
            //? 删除原数据
            delete [] data;
            //? 重新分配
            theSize = other.theSize;
            theCapacity = other.theCapacity;
            data = new T[theCapacity];

            //memcpy(data, other.data, sizeof(T)*theSize);

            for (int i = 0; i < theSize; i++)
			{
				data[i] = other.data[i];
			}
			return *this;
        }
    }

    //* 重载下标运算符
    T& operator [](int index) {
        if (index >= theSize) cerr << "超出数组边界" << endl;
        return data[index];
    }

    //* 重新分配空间
    void reServe(int newCapacity) {
        cout<<"重新分配空间"<<endl;
        if (newCapacity <= theCapacity) return;
        theCapacity = newCapacity;

        //? 先用一个临时指针存储原来数组位置
        T* tmp = data;
        data = new T[theCapacity];
        memcpy(data, tmp, theSize*sizeof(T));
        delete [] tmp;
    }
    

    void push_back(T value)
	{
		cout << "进入push_back函数" << endl;
		if (theCapacity==theSize)
		{
			reServe(2 * theCapacity + 1);
		}
		data[theSize++] = value;
	}

    void pop_back() {
        if (theSize == 0) {
            cerr<<"数组为空"<<endl;
            return;
        }
        theSize--;
    }

    int size() 
	{
		return theSize;
	}

	int capacity()
	{
		return theCapacity;
	}
    
    void assign(int num,T value)
	{
		if (num >= theCapacity)
		{
			reServe(theCapacity * 2 + 1);
		}
		theSize = 0;//若是之前assign了少于num的值被覆盖，多于num的值还在，但是theSize使我们访问不到，就好像不在了一样。
		for (int i=0; i < num; i++)
		{
			data[i] = value;
			theSize++;
		}
	}

    T* get_address()
	{
		return data;
	}

	T at(int index)
	{
		if (index >= theSize)
		{
			cerr << "超出边界" << endl;
			return -1;
		}
		return data[index];
	}
	T& back()
	{
		return data[theSize - 1];
	}
	T& begin()
	{
		return data[0];
	}

	~vec() {
		cout<<"进入析构，释放空间"<<endl;
		if (data != NULL)
		{
			cout<<"this.data address:"<<data<<endl;
			delete[] data;
		}
	}

private:
    const int INIT_CAPACITY = 5;    //! 每次扩展vec时增加的大小
    int theSize;                    //! 当前vec已用大小
    int theCapacity;                //! 总大小
    T* data;                        //! 数组指针
public:
    T* iterator;
};



int main()
{
	vec<int> v1;
	cout <<"size:"<< v1.size() << endl;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	cout<<"v1 size:"<<v1.size()<<"  v1 capacity:"<<v1.capacity()<<"  v1 address:"<<&v1<< "  v1.data address:" <<v1.get_address()<<endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << "===============" << endl;
	vec<int> v2(v1);
	cout << "v2 size:" << v2.size() << "  v2 capacity:" << v2.capacity() << "  v2 address:" << &v2 << "  v2.data address:" <<v2.get_address()<< endl;
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	cout << "===============" << endl;
	vec<int> v3;
	v3= v1;
	cout << "v3 size:" << v3.size() << "  v3 capacity:" << v3.capacity() << "  v3 address:" << &v3 << "  v3.data address:" <<v3.get_address()<< endl;
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	//cout << "============TEST====FUNC===============" << endl;
	//hn_vector<int> v4;
	//v4.assign(7, 100);
	//for (int i = 0; i < v4.size(); i++)
	//{
	//	cout << v4[i] << " ";
	//}
	//cout << endl;
	//v4.assign(6, 66);
	//cout << "v4 size:" << v4.size() << "  v4 capacity:" << v4.capacity() << "  v4 address:" << &v4 << "  v4.data address:" << v4.get_address() << endl;
	//for (int i = 0; i <= v4.size(); i++)
	//{
	//	cout << v4[i] << " ";
	//}
	//cout << endl;
	//cout << "at func:"<<v4.at(5)<<endl;
	//cout << "back func:" << v4.back() << endl;
	//cout << "begin func:" << v4.begin() << endl;
}