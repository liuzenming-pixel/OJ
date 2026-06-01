#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
    Date(int a = 1, int b = 1, int c = 1) : year(a), month(b), day(c)
    {
        cout << "CREATE Date : (" << year << ", " << month << ", " << day << ")" << endl;
    }
    void showDate()
    {

        cout << setfill('0') << setw(4) << year << "-" << setw(2) << month << "-" << setw(2) << day;
    }
    void setDate(int a, int b, int c)
    {
        year = a;
        month = b;
        day = c;
    }
    int getyear()
    {
        return year;
    }
    int getmonth()
    {
        return month;
    }
    int getday()
    {
        return day;
    }
};
class Time
{
private:
    int hour, minute, second;

public:
    Time(int a = 0, int b = 0, int c = 0) : hour(a), minute(b), second(c)
    {
        cout << "CREATE Time : (" << hour << ", " << minute << ", " << second << ")" << endl;
    }
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
    int gethour()
    {
        return hour;
    }
    int getminute()
    {
        return minute;
    }
    int getsecond()
    {
        return second;
    }
};
class DateTime
{
private:
    Time t;
    Date d;
public:
    DateTime()
    {
        cout << "CREATE DateTime : ("
             << d.getyear() << ", "
             << d.getmonth() << ", "
             << d.getday() << ", "
             << t.gethour() << ", "
             << t.getminute() << ", "
             << t.getsecond() << ")"
             << endl;
    }
    DateTime(Date date, Time time) : t(time), d(date) {}
    DateTime(int a, int b, int c, int d, int e, int f) : d(a, b, c), t(d, e, f) {}
    void showDateTime()
    {
        d.showDate();
        cout << " ";
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
    DateTime date_time;
    date_time.showDateTime();
    cout << endl;
    int cases;
    cin >> cases;
    for (int ca = 0; ca < cases; ca++)
    {
        int year, month, day;
        cin >> year >> month >> day;
        int hour, minute, second;
        cin >> hour >> minute >> second;
        date_time.setDateTime(year, month, day, hour, minute, second);
        date_time.showDateTime();
        cout << endl;
    }
}