#include <iostream>
#include <iomanip>
using namespace std;
// ====================================================================================
class Date
{
private:
    int year, month, day;

public:
    Date(int a = 1, int b = 1, int c = 1) : year(a), month(b), day(c)
    {
        cout << "CREATE Date : (" << year << ", " << month << ", " << day << ")" << endl;
    }
    Date(const Date &t) : year(t.year), month(t.month), day(t.day)
    {

        cout << "COPY   Date : (" << year << ", " << month << ", " << day << ")" << endl;
    }
    void showDate()
    {

        cout << setfill('0') << setw(4) << year << "-" << setw(2) << month << "-" << setw(2) << day;
    }
    void setDate(int a = -1, int b = -1, int c = -1)
    {
        if (a != -1)
            year = a;
        if (b != -1)
            month = b;
        if (c != -1)
            day = c;
    }
    int getyear() const
    {
        return year;
    }
    int getmonth() const
    {
        return month;
    }
    int getday() const
    {
        return day;
    }
};

// ==================================================================
class Time
{
private:
    int hour, minute, second;

public:
    Time(int a = 0, int b = 0, int c = 0) : hour(a), minute(b), second(c)
    {
        cout << "CREATE Time : (" << hour << ", " << minute << ", " << second << ")" << endl;
    }
    Time(const Time &t) : hour(t.hour), minute(t.minute), second(t.second)
    {
        cout << "COPY   Time : (" << hour << ", " << minute << ", " << second << ")" << endl;
    }
    void showTime()
    {

        cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
    }
    void setTime(int a = -1, int b = -1, int c = -1)
    {
        if (a != -1)
            hour = a;
        if (b != -1)
            minute = b;
        if (c != -1)
            second = c;
    }
    int gethour() const
    {
        return hour;
    }
    int getminute() const
    {
        return minute;
    }
    int getsecond() const
    {
        return second;
    }
};

// ==================================================================================
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
             << d.getday() << ") ("
             << t.gethour() << ", "
             << t.getminute() << ", "
             << t.getsecond() << ")"
             << endl;
    }
    DateTime(const Date &date, const Time &time) : t(time), d(date)
    {
        cout << "CREATE DateTime : ("
             << d.getyear() << ", "
             << d.getmonth() << ", "
             << d.getday() << ") ("
             << t.gethour() << ", "
             << t.getminute() << ", "
             << t.getsecond() << ")"
             << endl;
    }

    DateTime(const DateTime &a) : d(a.d), t(a.t)
    {
        cout << "COPY   DateTime : ("
             << d.getyear() << ", " << d.getmonth() << ", " << d.getday() << ") ("
             << t.gethour() << ", " << t.getminute() << ", " << t.getsecond() << ")"
             << endl;
    }
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
    int year() const
    {
        return d.getyear();
    }
    int month() const
    {
        return d.getmonth();
    }
    int day() const
    {
        return d.getday();
    }
    int hour() const
    {
        return t.gethour();
    }
    int minute() const
    {
        return t.getminute();
    }
    int second() const
    {
        return t.getsecond();
    }
    void year(int a)
    {
        d.setDate(a, -1, -1);
    }
    void month(int a)
    {
        d.setDate(-1, a, -1);
    }
    void day(int a)
    {
        d.setDate(-1, -1, a);
    }
    void hour(int a)
    {
        t.setTime(a, -1, -1);
    }
    void minute(int a)
    {
        t.setTime(-1, a, -1);
    }
    void second(int a)
    {
        t.setTime(-1, -1, a);
    }
};

// ================================AppendCode================================
int main()
{
    const Date date(1000, 10, 10), dt(date);
    // cout << "================================================================================" << endl;

    const Time time(1, 1, 1), tm(time);
    // cout << "================================================================================" << endl;

    DateTime date_time(dt, tm);
    const DateTime cnt(date_time);

    // cout << "================================================================================" << endl;
    cout << "DateTime : " << cnt.year() << " " << cnt.month() << " " << cnt.day();
    cout << " " << cnt.hour() << " " << cnt.minute() << " " << cnt.second();
    cout << endl;
    int cases;
    cin >> cases;
    for (int ca = 0; ca < cases; ca++)
    {
        int year, month, day;
        cin >> year >> month >> day;
        int hour, minute, second;
        cin >> hour >> minute >> second;
        date_time.year(year);
        date_time.month(month);
        date_time.day(day);
        date_time.hour(hour);
        date_time.minute(minute);
        date_time.second(second);
        date_time.showDateTime();
        cout << endl;
    }
}