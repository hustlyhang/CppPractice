/*readerAndWriter.cpp*/
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mutex>
#include <iostream>
#include <condition_variable>

using namespace std;
 
int buffer_has_item = 0;
mutex m;
condition_variable cv;
 
 
void writer_function(){
	while(1){
		unique_lock<mutex> ul(m);
		if(buffer_has_item==1){
			cv.wait(ul);
		}
        buffer_has_item = 1;
        cv.notify_all();
        cout<<"Write once! " <<endl;
	}
}
void reader_function(){
	while(1){
		unique_lock<mutex> ul(m);
		if(buffer_has_item==0){
			cv.wait(ul);
		}
        buffer_has_item = 0;
        cv.notify_all();
		cout<<"Read once !"<<endl;
	}
}
int main(void){
	thread r(reader_function);
    thread w(writer_function);

    r.join();
    w.join();

	return 0;
}