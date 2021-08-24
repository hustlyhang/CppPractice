# Learn
- [ostringstream](https://blog.csdn.net/qq1987924/article/details/7671154)
  - sstream库定义了三种类：istringstream、ostringstream和stringstream，分别用来进行流的输入、输出和输入输出操作。
  - 使用string对象来代替字符数组。这样可以避免缓冲区溢出的危险。而且，传入参数和目标对象的类型被自动推导出来，即使使用了不正确的格式化符也没有危险。
---
- [unique_ptr](https://blog.csdn.net/qq_19895789/article/details/116102762)
  - 首先要知道unique_ptr和shared_ptr的自定义deleter方式并不一样，unique_ptr为了优化开销需要提供deleter的类型。
    ```
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
