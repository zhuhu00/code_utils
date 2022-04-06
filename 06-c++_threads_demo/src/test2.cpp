/*
 * @Description: 1. 代码锁住共享数据后,其他操作共享的数据会锁住,等待解锁
 2. 锁的生命周期

 代码中包含
 */
#include<iostream>
#include<thread>//多线程头文件
#include<vector>
#include<mutex>//互斥锁头文件
#include<list>

using namespace std;

//设置模式
#define THREAD_BY_CLASS
#define USE_MUTEX

#ifdef THREAD_BY_FUNCTION
// 函数创建线程
std::list<int> dataQuene;
mutex myMutex;
void putInData()
{
    for (int i = 0; i < 1000; i++) //数字增大可增加冲突改了
    {
#ifdef USE_MUTEX
        myMutex.lock();
        cout << "putInData 有数据:" << i << endl;
        dataQuene.push_back(i);
        myMutex.unlock();
#else
        cout << "putInData 有数据ss:" << i << endl;
        dataQuene.push_back(i);
#endif 
    }
}

void takeOutData()
{
    //for (int i = 0; i < 100; i++) // 会导致不能完全取出所有数据
    while (1)
    {
        if (!dataQuene.empty())
        {
#ifdef USE_MUTEX
            myMutex.lock();
            cout << "takeOutData 取出一个数据:" << dataQuene.front() << endl;
            dataQuene.pop_front();
            myMutex.unlock();
#else
            cout << "takeOutData 取出一个数据(unlock):" << dataQuene.front() << endl;
            dataQuene.pop_front();
#endif 
        }
        else
        {
            //std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}
#endif 


#ifdef THREAD_BY_CLASS
// 类创建多线程
class DealData
{
public:
    void putInData()
    {
        cout << "putInData id is "<<this_thread::get_id()<<"sss=====SSS"<<endl;
        for (int i = 0; i < 100; i++)
        {
#ifdef USE_MUTEX
            myMutex.lock();
            cout << "putInData 有数据:" << i << endl;
            dataQuene.push_back(i);
            myMutex.unlock();
#else
            cout << "putInData 有数据(未使用mutex)" << i << endl;
            dataQuene.push_back(i);
#endif 
        }
        cout<<"putInData end"<<endl;
    }

    void takeOutData()
    {
        cout << "takeOutData id is "<<this_thread::get_id()<<endl;
        for (int i = 0; i < 100; i++) // 会导致不能完全取出数据
        // while(1)
        {
            if (!dataQuene.empty())
            {
#ifdef USE_MUTEX
                myMutex.lock();
                cout << "takeOutData 子线程取出:" << dataQuene.front() << endl;
                dataQuene.pop_front();
                myMutex.unlock();
#else
                cout << "takeOutData 子线程取出(未使用mutex):" << dataQuene.front() << endl;
                dataQuene.pop_front();
#endif 
            }
            else
            {
                // std::this_thread::sleep_for(std::chrono::milliseconds(1));
                // cout << "dataQuene is empty"<<endl;
            }
        }
    }
private:
    std::list<int> dataQuene;
    mutex myMutex;

};
#endif 

int main(){
    // 1. 创建并开启线程,使用putInData和takeOutData函数
    DealData myData;
    thread putThread(&DealData::putInData, ref(myData));
    thread takeThread(&DealData::takeOutData, ref(myData));
    putThread.join();
    takeThread.join();


    cout<<"thead end!"<<endl;
    return 0;
}