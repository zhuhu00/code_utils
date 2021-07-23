/*
 * @Description: thread, join(), detach()的使用
 */
//文件名：test.cpp
#include<iostream>
#include<thread>
#include<vector>

using namespace std;

void putInData(){
     cout << "putInData 子进程 id 为 :" << this_thread::get_id()<<endl;
     for(int i=0; i< 100; i++){
         cout<< "putInData 子线程: "<< i << endl;
     }
}

int main(){
    cout << "主线程为 :"<< this_thread::get_id()<<endl;
    thread putThread(putInData);

    if (putThread.joinable()){
        putThread.join();
        // putThread.detach();
    }
    // std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "子线程结束"<<endl;
    cout << "main线程结束"<<endl;
    return 0;

}
