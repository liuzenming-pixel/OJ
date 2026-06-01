#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
    Date(int a = 0, int b = 0, int c = 0) : year(a), month(b), day(c) {}
    void showDate()
    {

        cout << setfill('0') << year << "-" << setw(2) << month << "-" << setw(2) << day;
    }
};
class Time
{
private:
    int hour, minute, second;

public:
    Time(int a = 0, int b = 0, int c = 0) : hour(a), minute(b), second(c) {}
    void showTime()
    {

        cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
    }
};

// ================================AppendCode================================
int main()
{
    int cases;
    cin >> cases;
    for (int ca = 0; ca < cases; ca++)
    {
        int year, month, day;
        cin >> year >> month >> day;
        Date date(year, month, day);
        date.showDate();
        cout << " ";
        int hour, minute, second;
        cin >> hour >> minute >> second;
        Time time(hour, minute, second);
        time.showTime();
        cout << endl;
    }
}