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
    void setDate(int a, int b, int c)
    {
        year = a;
        month = b;
        day = c;
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
    void setTime(int a, int b, int c)
    {
        hour = a;
        minute = b;
        second = c;
    }
};
class DateTime
{
private:
    Date d;
    Time t;

public:
    DateTime(Date date, Time time) : d(date), t(time) {}
    DateTime(int a, int b, int c, int d, int e, int f) : d(a, b, c), t(d, e, f) {}
    void showDateTime()
    {
        d.showDate();
        cout<<" ";
        t.showTime();
    }
    DateTime &setDateTime(int a, int b, int c, int h, int m, int s)
    {
        d.setDate(a, b, c);
        t.setTime(h, m, s);
        return *this;
    }
};

// ================================AppendCode================================
int main()
{
    Date date(1000, 10, 10);
    Time time(1, 1, 1);
    DateTime date_time(date, time);
    date_time.showDateTime();
    cout << endl;
    int cases, flag = 0;
    cin >> cases;
    for (int ca = 0; ca < cases; ca++)
    {
        int year, month, day;
        cin >> year >> month >> day;
        int hour, minute, second;
        cin >> hour >> minute >> second;
        if (flag == 0)
        {
            flag = 1;
            DateTime dt(year, month, day, hour, minute, second);
            dt.showDateTime();
        }
        else if (flag == 1)
        {
            flag == 0;
            date_time.setDateTime(year, month, day, hour, minute, second).showDateTime();
        }
        cout << endl;
    }
}
