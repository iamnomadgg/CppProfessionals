#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
/***
* Creates a std::tm structure from raw date.
*
* \param year (must be 1900 or greater)
* \param month months since January – [1, 12]
* \param day day of the month – [1, 31]
* \param minutes minutes after the hour – [0, 59]
* \param seconds seconds after the minute – [0, 61](until C++11) / [0, 60] (since C++11)
*
* Based on http://en.cppreference.com/w/cpp/chrono/c/tm
*/
std::tm CreateTmStruct(int year, int month, int day, int hour, int minutes, int seconds) {
    struct tm tm_ret = {0};
    tm_ret.tm_sec = seconds;
    tm_ret.tm_min = minutes;
    tm_ret.tm_hour = hour;
    tm_ret.tm_mday = day;
    tm_ret.tm_mon = month - 1;
    tm_ret.tm_year = year - 1900;
    return tm_ret;
}

int get_days_in_year(int year) {
    using namespace std;
    using namespace std::chrono;
    // We want results to be in days
    typedef duration<int, ratio_multiply<hours::period, ratio<24> >::type> days;
    // Create start time span
    std::tm tm_start = CreateTmStruct(year, 1, 1, 0, 0, 0);
    auto tms = system_clock::from_time_t(std::mktime(&tm_start));
    // Create end time span
    std::tm tm_end = CreateTmStruct(year + 1, 1, 1, 0, 0, 0);
    auto tme = system_clock::from_time_t(std::mktime(&tm_end));
    // Calculate time duration between those two dates
    auto diff_in_days = std::chrono::duration_cast<days>(tme - tms);
    return diff_in_days.count();
}

int main()
{
    for ( int year = 2000; year <= 2016; ++year )
    std::cout << "There are " << get_days_in_year(year) << " days in " << year << "\n";
}