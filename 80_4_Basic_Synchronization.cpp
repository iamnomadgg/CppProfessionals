#include <future>
#include <iostream>

std::mutex m1;
void worker() {
std::lock_guard<std::mutex> guard(m1); // Acquires a lock on the mutex
// Synchronized code here
} // the mutex is automatically released when guard goes out of scope

std::mutex m2;
void worker() {
// by default, constructing a unique_lock from a mutex will lock the mutex
// by passing the std::defer_lock as a second argument, we
// can construct the guard in an unlocked state instead and
// manually lock later.
std::unique_lock<std::mutex> guard(m2, std::defer_lock);
// the mutex is not locked yet!
guard.lock();
// critical section
guard.unlock();
// mutex is again released
}

int main()
{
	return 0;
}