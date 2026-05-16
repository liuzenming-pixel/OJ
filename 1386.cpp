#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
private:
    int hh, mm, ss;

public:
    Time() : hh(0), mm(0), ss(0) {}
    Time(int h, int m, int s) : hh(h), mm(m), ss(s) {}
    void hour(int h)
    {
        hh = h;
    }
    void minute(int m)
    {
        mm = m;
    }
    void second(int s)
    {
        ss = s;
    }

    int hour()
    {
        return hh;
    }
    int minute()
    {
        return mm;
    }
    int second()
    {
        return ss;
    }

    void showTime()
    {
        cout << setfill('0');
        cout << setw(2) << hh << ":" << setw(2) << mm << ":" << setw(2) << ss << endl;
    }
};

int main()
{
    Time t;
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; ++i)
    {
        int hour, minute, second;
        cin >> hour >> minute >> second;
        t.hour(hour);
        t.minute(minute);
        t.second(second);
        cout << setw(2) << setfill('0') << t.hour() << ":";
        cout << setw(2) << setfill('0') << t.minute() << ":";
        cout << setw(2) << setfill('0') << t.second() << endl;
    }
}