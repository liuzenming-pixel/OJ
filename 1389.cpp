#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
    int h, m, s;

public:
    Time() : h(0), m(0), s(0) {}
    Time(int hh, int mm, int ss) : h(hh), m(mm), s(ss) {}
    Time(const Time &a) : h(a.h), m(a.m), s(a.s)
    {
        // cout << "There was a call to the copy constructor : " << h << ',' << m << ',' << s << endl;
    }
    Time getTime()
    {
        return *this;
    }
    Time inputTime()
    {
        int hh, mm, ss;
        cin >> hh >> mm >> ss;
        h = hh;
        m = mm;
        s = ss;
        return *this;
    }
    Time &setTime(int a, int b, int c)
    {
        h = a;
        m = b;
        s = c;
        return *this;
    }
    Time &setTime(Time &t)
    {
        h = t.h;
        m = t.m;
        s = t.s;
        return *this;
    }
    int panduan()
    {
        if (s >= 60 || s < 0)
        {
            return 0;
        }
        else if (m >= 60 || m < 0)
        {
            return 0;
        }
        else if (h >= 24 || h < 0)
        {
            return 0;
        }
        else return 1;
    }
    void showTime()
    {
        if(panduan()){
        cout << setfill('0') << setw(2) << h;
        cout << ":";
        cout << setfill('0') << setw(2) << m;
        cout << ":";
        cout << setfill('0') << setw(2) << s;
        cout << endl;}
        else
        cout<<"Time error"<<endl;
    }
    int hour()
    {
        return h;
    }
    int minute()
    {
        return m;
    }
    int second()
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
};

// ================================AppendCode================================

int main()
{
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