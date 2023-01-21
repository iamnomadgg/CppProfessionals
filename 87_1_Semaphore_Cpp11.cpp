#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
using namespace std;

class Semaphore
{
public:
    Semaphore(int count_ = 0)
        : count(count_)
    {
    }
    inline void notify(int tid)
    {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        cout << "thread " << tid << " notify" << endl;
        // notify the waiting thread
        cv.notify_one();
    }
    inline void wait(int tid)
    {
        std::unique_lock<std::mutex> lock(mtx);
        while (count == 0)
        {
            cout << "thread " << tid << " wait" << endl;
            // wait on the mutex until notify is called
            cv.wait(lock);
            cout << "thread " << tid << " run" << endl;
        }
        count--;
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};

int main()
{
    Semaphore sem(1);
    thread s1([&]()
              {
    while(true) {
this_thread::sleep_for(std::chrono::seconds(5));
sem.wait( 1 );
} });

    thread s2([&]()
              {
while(true){
sem.wait( 2 );
} });

    thread s3([&]()
              {
while(true) {
this_thread::sleep_for(std::chrono::milliseconds(600));
sem.wait( 3 );
} });

    thread s4([&]()
              {
while(true) {
this_thread::sleep_for(std::chrono::seconds(5));
sem.notify( 4 );
} });

    s1.join();
    s2.join();
    s3.join();
    s4.join();
}