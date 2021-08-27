# Learn
- [ostringstream](https://blog.csdn.net/qq1987924/article/details/7671154)
  - sstream库定义了三种类：istringstream、ostringstream和stringstream，分别用来进行流的输入、输出和输入输出操作。
  - 使用string对象来代替字符数组。这样可以避免缓冲区溢出的危险。而且，传入参数和目标对象的类型被自动推导出来，即使使用了不正确的格式化符也没有危险。
---
- [unique_ptr](https://blog.csdn.net/qq_19895789/article/details/116102762)
  - 首先要知道unique_ptr和shared_ptr的自定义deleter方式并不一样，unique_ptr为了优化开销需要提供deleter的类型。
    ```C++
    struct FileCloserStruct {
		void operator()(FILE* fp) const {
			if (fp != nullptr) {
				fclose(fp);
			}
		}
	};
 
	void FileCloserFunc(FILE* fp) {
		if (fp != nullptr) {
			fclose(fp);
		}
	}
 
	auto FileCloserLambda = [](FILE* fp) {
		if (fp != nullptr) {
			fclose(fp);
		}
	};
 
	int main() {
 
		std::unique_ptr<FILE, FileCloserStruct> uptr1(fopen("test_file.txt", "w"));
		std::cout << sizeof(uptr1) << std::endl;// 4
 
		std::unique_ptr<FILE, void(*)(FILE*)> uptr2(fopen("test_file1.txt", "w"), FileCloserFunc);
		std::cout << sizeof(uptr2) << std::endl;// 8
 
		std::unique_ptr<FILE, std::function<void(FILE*)>> uptr3(fopen("test_file2.txt", "w"), FileCloserLambda);
		std::cout << sizeof(uptr3) << std::endl;// 48
 
		std::unique_ptr<FILE, decltype(FileCloserLambda)> uptr4(fopen("test_file3.txt", "w"), FileCloserLambda);
		std::cout << sizeof(uptr4) << std::endl;// 4
 
		return 0;
	}
    ```
-----
- [std::bind](https://www.jianshu.com/p/82407fb43475)
  - bind函数接受一个可调用对象，生成一个新的可调用对象来适配原对象。
  - [bind包装成员函数](https://blog.csdn.net/albertsh/article/details/99845666)
-----
- [std::function](https://www.jianshu.com/p/4ea00ee0dabd)
  - 我们可以使用std::function将不同类型的可调用对象共享同一种调用形式。
------  
- 运算符重载
  - https://www.jb51.net/article/72424.htm
  - [运算符重载](https://www.cnblogs.com/Mayfly-nymph/p/9034936.html#:~:text=%E4%BD%9C%E4%B8%BA%E5%8F%8B%E5%85%83%E5%87%BD%E6%95%B0%E9%87%8D%E8%BD%BD%20%E8%80%8C%E5%AF%B9%E4%BA%8E%E7%AC%AC%E4%BA%8C%E7%A7%8D%E5%BD%A2%E5%BC%8F%E7%9A%84%E9%87%8D%E8%BD%BD%EF%BC%9A,%E5%8F%8B%E5%85%83%E5%87%BD%E6%95%B0%EF%BC%88%E5%8F%8B%E5%85%83%E5%87%BD%E6%95%B0%E5%88%99%E6%98%AF%E6%8C%87%E6%9F%90%E4%BA%9B%E8%99%BD%E7%84%B6%E4%B8%8D%E6%98%AF%E7%B1%BB%E6%88%90%E5%91%98%E5%8D%B4%E8%83%BD%E5%A4%9F%E8%AE%BF%E9%97%AE%E7%B1%BB%E7%9A%84%E6%89%80%E6%9C%89%E6%88%90%E5%91%98%E7%9A%84%E5%87%BD%E6%95%B0%EF%BC%89%E8%BF%9B%E8%A1%8C%E9%87%8D%E8%BD%BD%EF%BC%8C%E9%82%A3%E4%B9%88%E5%AE%83%E5%B0%B1%E4%B8%8D%E5%AD%98%E5%9C%A8this%E6%8C%87%E9%92%88%E4%BA%86%EF%BC%8C%E6%89%80%E4%BB%A5%E9%9C%80%E8%A6%81%E5%AE%9A%E4%B9%89%E4%B8%A4%E4%B8%AA%E5%8F%82%E6%95%B0%E6%9D%A5%E8%BF%90%E7%AE%97%EF%BC%88%E5%AF%B9%E4%BA%8E%E5%8F%8C%E7%9B%AE%E8%BF%90%E7%AE%97%E7%AC%A6%EF%BC%89%EF%BC%8C%20%E8%80%8C%E5%8F%8B%E5%85%83%E5%87%BD%E6%95%B0%E7%9A%84%E5%AE%9E%E7%8E%B0%E5%8F%AF%E4%BB%A5%E5%9C%A8%E5%A4%96%E9%9D%A2%E5%AE%9A%E4%B9%89%EF%BC%8C%E4%BD%86%E5%BF%85%E9%A1%BB%E5%9C%A8%E7%B1%BB%E5%86%85%E9%83%A8%E5%A3%B0%E6%98%8E%20%E3%80%82)
-----
- tuple	元组，当模板函数需要超过 1 个变长参数时，使用tuple效果明显。  
  - https://www.cnblogs.com/gudushishenme/archive/2013/09/22/3332582.html  
  - https://www.cnblogs.com/xueqiuqiu/articles/12955797.html  
-----
- initializer_list
  -	https://blog.csdn.net/fengxinlinux/article/details/72614874
-----
- std::index_sequence<I...>
  - https://blog.csdn.net/dboyguan/article/details/51706357
-----
- 变长参数
  -	https://bygeek.cn/2018/09/28/variable-arguments-in-c-c/
-----
- 调用惯例
  -	https://bygeek.cn/2018/09/05/what-is-calling-convention/
-----
- [std::decay](https://blog.csdn.net/luoshabugui/article/details/109853418)
  - #include<type_traits>
  - 用以移除类型中的一些特性，比如引用、常量、volatile
  - 对类型 T 应用左值到右值、数组到指针及函数到指针隐式转换，移除 cv 限定符，并定义结果类型为成员 typedef type
-----
- std::bind  
  - 用来将可调用对象与其参数一起进行绑定。绑定后的结果可以使用 std::function进行保存，并延迟调用到任何我们需要的时候。
  - 将可调用对象与其参数一起绑定成一个仿函数。
  - 将多元（参数个数为 n， n>1）可调用对象转成一元或者（ n-1）元可调用对象，即只绑定部分参数。  
-----
- std::enable_if
  - 只有当第一个模板参数为 true 时，type 才有定义，否则使用 type 会产生编译错误。	
  - `template <bool Cond, class T = void> struct enable_if;`
------
- [int (*a)[]; int (*a)(int)](https://www.cnblogs.com/xiaojingang/p/4451089.html)
  - 指针数组和数组指针
-------
- [形参包](https://zh.cppreference.com/w/cpp/language/parameter_pack)
  - 模板形参包是接受零或更多模板实参（非类型、类型或模板）的模板形参。函数模板形参包是接受零或更多函数实参的函数形参。至少有一个形参包的模板被称作变参模板。
  - 例子
	```C++
	template<class ...Us> void f(Us... pargs) {}
	template<class ...Ts> void g(Ts... args) {
		f(&args...);		// “&args...” 是包展开
					// “&args” 是其模式
	}
	g(1, 0.2, "a");		// Ts... args 展开成 int E1, double E2, const char* E3
				// &args... 展开成 &E1, &E2, &E3
				// Us... 展开成 int* E1, double* E2, const char** E3    
	```
  - 展开场所  
    - 函数实参列表
    - 有括号初始化器
    - 花括号包围的初始化器
    - 模板实参列表
    - 函数形参列表
    - 模板形参列表
    - 基类说明符与成员初始化器列表
    - Lambda 捕获
    - sizeof... 运算符
    - 动态异常说明
    - 对齐说明符...
  - 例子
    ```C++
	template<typename... Ts> void func(Ts... args){
		const int size = sizeof...(args) + 2;
		int res[size] = {1,args...,2};
		// 因为初始化器列表保证顺序，所以这可用于按顺序对包的每个元素调用函数：
		int dummy[sizeof...(Ts)] = { (std::cout << args, 0)... };
		std::cout<<std::endl;
		for (auto x : dummy) std::cout<<x<<' ';
	}

	int main() {
		func(1,2,3,4);
		return 0;
	}

	// 1234
	// 0 0 0 0 
	```