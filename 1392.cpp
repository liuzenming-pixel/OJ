#include <iostream>
using namespace std;
#include <iomanip>
class Time
{
private:
    int h, m, s;

public:
    static int num;
    Time(int a = 0, int b = 0, int c = 0) : h(a), m(b), s(c) { num++; }
    Time(const Time &t) : h(t.h), m(t.m), s(t.s)
    {
        num++;
        cout<<"There was a call to the copy constructor : "<<h<<','<<m<<','<<s<<endl;
    }

    int hour() const
    {
        return h;
    }
    int minute() const
    {
        return m;
    }
    int second() const
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
    const Time &getTime() const
    {
        return *this;
    }
    Time inputTime()
    {
        cin >> h >> m >> s;
        return *this;
    }
    int panduan() const
    {
        // 合法返回1，不合法返回0
        return (s >= 0 && s < 60) && (m >= 0 && m < 60) && (h >= 0 && h < 24);
    }
    void showTime() const
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
    void showTime12Hour() const
    {

        if (panduan())
        {
            if (h == 12)
                cout << setw(2) << setfill('0') << 12 << ":" << setw(2) << m << ":" << setw(2) << s << " p.m." << endl;
            else if (h == 0)
                cout << setw(2) << setfill('0') << 12 << ":" << setw(2) << m << ":" << setw(2) << s << " a.m." << endl;
            else if (h > 12)
                cout << setw(2) << setfill('0') << h - 12 << ":" << setw(2) << m << ":" << setw(2) << s << " p.m." << endl;
            else
                cout << setw(2) << setfill('0') << h << ":" << setw(2) << m << ":" << setw(2) << s << " a.m." << endl;
        }
        else
        {

            cout << "Time error" << endl;
        }
    }
    static int getNumber();
    static void displayNumber();
};
int Time::num = 0;
void Time::displayNumber()
{
    cout << "Now, There is " << num << " object of Time." << endl;
}
int Time::getNumber()
{
    return num;
}

// ================================AppendCode================================
int main()
{
    cout << "Static member test output :" << endl;
    Time::displayNumber();
    Time t;
    t.displayNumber();
    Time tt(t);
    tt.displayNumber();
    Time ttt(1, 2, 3);
    ttt.displayNumber();
    Time tttt(ttt.getTime());
    tttt.displayNumber();
    int non_cases = Time::getNumber();

    cout << "\nTest data output :" << endl;
    int hour, minute, second;
    while (cin >> hour >> minute >> second)
    {
        Time t;
        t.setTime(hour, minute, second).showTime();
    }
    cout << t.getNumber() - non_cases << endl;
}
