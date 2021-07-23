/*
 * @Description: 
 1. lock(),unlock()成对使用,
 2. lock_guard()的使用
 3. std::adopt_lock()
 4. std::defer_lock
 5. std::try_to_lock
 6. std::unique_lock::release
 7. 转移互斥锁所有权
 */

#include <iostream>
#include <thread>   // 多线程头文件
#include <list>
#include <mutex>  // 互斥锁头文件
#include <pthread.h>
using namespace std;

//#define USE_LOCK_UNLOCK
//#define USE_LOCKGUARD
//#define USE_UNIQUELOCK
//#define USE_ADOPTLOCK     //已经提前 lock  
//#define USE_DEFER_LOCK    //互斥量没有lock,不能提前lock,只能后面lock
//#define USE_TRY_TO_LOCK   //尝试lock(不能提前lock),lock失败会返回,防止阻塞
//#define USE_RELEASE         //解除所有权
#define USE_MOVE            //转移所有权
class DealData
{
public:
    void putInData()
    {
        for (int i = 0; i < 1000; i++) //1000次操作
        {
#ifdef USE_LOCK_UNLOCK
            myMutex.lock();
            cout << "putInData有数据: " << i << endl;
            dataQuene.push_back(i);
            myMutex.unlock();
#endif // USE_LOCK_UNLOCK

#ifdef USE_LOCKGUARD
            lock_guard<mutex> dataGuard(myMutex);
            cout << "putInData 有数据(guard): " << i << endl;
            dataQuene.push_back(i);

#endif // USE_LOCKGUARD

#ifdef USE_UNIQUELOCK
            unique_lock<mutex> dataOutUnique(myMutex);
            cout << "putInData有数据(uniquelock): " << i << endl;
            dataQuene.push_back(i);
#endif // USE_UNIQUELOCK

#ifdef USE_ADOPTLOCK
            myMutex.lock(); // 使用std::adopt_lock 必须先要进行lock
            unique_lock<mutex> dataControl(myMutex, std::adopt_lock);
            cout << "putInData有数据(adoptlock): " << i << endl;
            dataQuene.push_back(i);
#endif // USE_ADOPTLOCK

#ifdef USE_DEFER_LOCK
            unique_lock<mutex> dataControl(myMutex, std::defer_lock); // std::defer_lock 使得myMutex没有加锁

            myMutex.lock();
            // 处理共享代码
            cout << "putInData 有数据(defer_lock): " << i << endl;
            dataQuene.push_back(i);
            
            myMutex.unlock();
            // 处理非共享代码
            // ....

            // 使用try_lock功能类似try_to_lock
        //    if (myMutex.try_lock() == true)
        //    {
        //        // 如果锁住了
        //        cout << "putInData 有数据: " << i << endl;
        //        dataQuene.push_back(i);
        //}
        //    else
        //    {
        //        // 如果没有锁住
        //        cout << "putInData有数据(没锁):" << i << endl;
        //    }
#endif // USE_DEFER_LOCK

#ifdef USE_TRY_TO_LOCK
            unique_lock<mutex> dataControl(myMutex, std::try_to_lock); // 使用std::try_to_lock之前不能lock,否则lock会出两次错
            if (dataControl.owns_lock())
            {
                // 如果拿回了锁
                cout << "putInData有数据: " << i << endl;
                dataQuene.push_back(i);
            }
            else
            {
                // 没有锁
                cout << "putInData有数据(没有锁): " << i << endl;
            }
#endif // USE_TRY_TO_LOCK


#ifdef USE_RELEASE
            // 把dataControl和myMutex绑定在一起, dataControl有myMutex的控制权
            unique_lock<mutex> dataControl(myMutex);

            // 释放了dataControl的控制权,由pControl接管
            std::mutex* pControl = dataControl.release();

            cout << "putInData有数据: " << i << endl;
            dataQuene.push_back(i);

            pControl->unlock();
            // 非共享数据
            //....

#endif // USE_RELEASE

#ifdef USE_MOVE          
            unique_lock<mutex> dataControl1(myMutex);
            //unique_lock<mutex> dataControl2(dataControl1);            // 不能复制所有权
            unique_lock<mutex> dataControl2(std::move(dataControl1));   // 可以移动所有权

            cout << "putInData有数据: " << i << endl;
            dataQuene.push_back(i);
#endif // USE_MOVE
        }
    }

    void takeOutData()
    {
        while (1)
        {
            bool res = haveDta();
        }
    }

    // 为了演示lock()和unlock()成对的重要性
    bool haveDta()
    {
#ifdef USE_LOCK_UNLOCK
        myMutex.lock();
        if (!dataQuene.empty())
        {
            cout << "takeOutData取出数据: " << dataQuene.front() << endl;
            dataQuene.pop_front();
            myMutex.unlock();   // 成对
            return true;
        }
        myMutex.unlock();
        return false;
#endif // USE_LOCK_UNLOCK

#ifdef USE_LOCKGUARD
        {
            lock_guard<mutex> dataOutGuard(myMutex);
            if (!dataQuene.empty())
            {
                cout << "takeOutData 取出数据: " << dataQuene.front() << endl;
                dataQuene.pop_front();
                return true;
            }
            return false;
        }
        // xxxx
        //...
#endif // USE_LOCKGUARD

#ifdef USE_UNIQUELOCK
        unique_lock<mutex> dataOutUnique(myMutex);
        if (!dataQuene.empty())
        {
            cout << "takeOutData 取出数据: " << dataQuene.front() << endl;
            dataQuene.pop_front();
            return true;
        }
        return false;
#endif // USE_UNIQUELOCK


#ifdef USE_TRY_TO_LOCK

        unique_lock<mutex> dataControl(myMutex); 

        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // sleep 1ms等待会导致放数据线程被拖累

        if (!dataQuene.empty())
        {
            cout << "takeOutData 取出数据: " << dataQuene.front() << endl;
            dataQuene.pop_front();
            return true;
        }
        return false;
#endif // USE_TRY_TO_LOCK

        // DEFAULT
        unique_lock<mutex> dataOutUnique(myMutex);
        if (!dataQuene.empty())
        {
            cout << "takeOutData 取出数据：　" << dataQuene.front() << endl;
            dataQuene.pop_front();
            return true;
        }
        return false;

    }
private:
    std::list<int> dataQuene;
    mutex myMutex;

};

int main()
{
    //std::list<int> dataQuene;
    
    //使用putInData和takeOutData测试数据
    DealData myData;
    thread putThread(&DealData::putInData, ref(myData));
    thread takeThread(&DealData::takeOutData, ref(myData));

    takeThread.join();
    putThread.join();


    return 1;
}

