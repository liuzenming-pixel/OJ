#include <iostream>
using namespace std;
#include <iomanip>
class Time
{
private:
    int h, m, s;

public:
    Time(int a=0, int b=0, int c=0) : h(a), m(b), s(c) {}
    Time(const Time &t) : h(t.h), m(t.m), s(t.s) {}

    int hour()const
    {
        return h;
    }
    int minute()const
    {
        return m;
    }
    int second()const
    {
        return s;
    }
    void hour(int t)
    {
        h = t;
    }
    void minute(int t)
    {
        m = t;
    }
    void second(int t)
    {
        s = t;
    }
    Time &setTime(int a, int b, int c)
    {
        h = a;
        m = b;
        s = c;
        return *this;
    }
    Time &setTime(const Time &t)
    {
        h = t.h;
        m = t.m;
        s = t.s;
        return *this;
    }
    const Time &getTime()const
    {
        return *this;
    }
    Time inputTime()
    {
        cin >> h >> m >> s;
        return *this;
    }
    int panduan()const
    {
        // 合法返回1，不合法返回0
        return (s >= 0 && s < 60) && (m >= 0 && m < 60) && (h >= 0 && h < 24);
    }
    void showTime()const
    {
        if (panduan())
        {
            cout << setw(2) << setfill('0') << h << ":" << setw(2) << m << ":" << setw(2) << s << endl;
        }
        else
        {
            cout << "Time error" << endl;
        }
    }
};

// ================================AppendCode================================
int main()
{
    cout << "Constant test output :" << endl;
    const Time c;
    const Time cc(1, 2, 3);
    const Time ccc(23, 60, 60);
    cout << setw(2) << setfill('0') << c.hour() << ":";
    cout << setw(2) << setfill('0') << c.minute() << ":";
    cout << setw(2) << setfill('0') << c.second() << endl;
    cc.getTime().showTime();
    ccc.showTime();

    cout << "\nTest data output :" << endl;
    Time t;
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; ++i)
    {
        if (i % 4 == 0)
        {
            int hour, minute, second;
            cin >> hour >> minute >> second;
            Time tt(hour, minute, second);
            tt.showTime();
        }
        if (i % 4 == 1)
        {
            int hour, minute, second;
            cin >> hour >> minute >> second;
            t.setTime(hour, minute, second).showTime();
        }
        if (i % 4 == 2)
            t.inputTime().showTime();
        if (i % 4 == 3)
        {
            int hour, minute, second;
            cin >> hour >> minute >> second;
            t.hour(hour);
            t.minute(minute);
            t.second(second);
            t.showTime();
        }
    }
}
