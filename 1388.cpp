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
    Time(const Time &a) : h(a.h), m(a.m), s(a.s) {
        cout<<"There was a call to the copy constructor : "<<h<<','<<m<<','<<s<<endl;
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
    Time& setTime(int a, int b, int c)
    {
        h = a;
        m = b;
        s = c;
        return *this;
    }
    Time& setTime(Time &t)
    {
        h = t.h;
        m = t.m;
        s = t.s;
        return *this;
    }
    void showTime()
    {
        cout << setfill('0') << setw(2) << h;
        cout << ":";
        cout << setfill('0') << setw(2) << m;
        cout << ":";
        cout << setfill('0') << setw(2) << s;
        cout << endl;
    }
};
// ================================AppendCode================================
int main()
{
    cout << "Copy constructor test output :" << endl;
    Time t;
    Time tt(t);
    Time ttt(1, 2, 3);
    Time tttt(ttt.getTime());
    cout << "\nTest data output :" << endl;

    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; ++i)
    {
        if (i % 2 == 0)
        {
            int hour, minute, second;
            cin >> hour >> minute >> second;
            t.setTime(hour, minute, second).showTime();
        }
        if (i % 2 == 1)
        {
            int hour, minute, second;
            cin >> hour >> minute >> second;
            Time tt(hour, minute, second);
            t.setTime(tt).showTime();
        }
    }
}