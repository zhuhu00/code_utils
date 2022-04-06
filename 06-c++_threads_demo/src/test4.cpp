/*
 * @Description: thread test4
 1. lock() unlock() 死锁
 2. unique_lock() 死锁
 */

#include <iostream>
#include <thread>   // 多线程头文件
#include <list>
#include <mutex>  // 线程锁
using namespace std;

#define USE_LOCK_UNLOCK
//#define USE_UNIQUELOCK

class DealData
{
public:
    void putInData()
    {
        for (int i = 0; i < 1000; i++) //运行次数
        {
#ifdef USE_LOCK_UNLOCK
            myMutex1.lock();
            myMutex2.lock();
            cout << "putInData有数据: " << i << endl;
            dataQuene.push_back(i);
            myMutex1.unlock();
            myMutex2.unlock();
#endif // USE_LOCK_UNLOCK


 #ifdef USE_UNIQUELOCK
            unique_lock<mutex> goldenLock(myMutex1);
            unique_lock<mutex> silverLock(myMutex2);
            cout << "putInData有数据: " << i << endl;
            dataQuene.push_back(i);
#endif // USE_UNIQUELOCK
        }
    }

    void takeOutData()
    {
        while (1)
        {
#ifdef USE_LOCK_UNLOCK
            myMutex1.lock();
            myMutex2.lock();
            if (!dataQuene.empty())
            {
                cout << "takeOutData有数据: " << dataQuene.front() << endl;
                dataQuene.pop_front();
            }
            myMutex1.unlock();
            myMutex2.unlock();
#endif // USE_LOCK_UNLOCK

#ifdef USE_UNIQUELOCK
            unique_lock<mutex> silverLock(myMutex2);
            unique_lock<mutex> goldenLock(myMutex1);
            if (!dataQuene.empty())
            {
                cout << "takeOutData有数据: " << dataQuene.front() << endl;
                dataQuene.pop_front();
            }
#endif // USE_UNIQUELOCK

        }
    }

private:
    std::list<int> dataQuene;
    std::mutex myMutex1;
    std::mutex myMutex2;

};

int main()
{
    //std::list<int> dataQuene;

    //1. 创建并开启线程,线程入口是 putInData和takeOutData
    DealData myData;
    thread putThread(&DealData::putInData, ref(myData));
    thread takeThread(&DealData::takeOutData, ref(myData));

    takeThread.join();
    putThread.join();


    return 1;
}

