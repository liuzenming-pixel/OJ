#include <iostream>
#include <iomanip>
using namespace std;
class Time
{
private:
    int h, m, s;

public:
    Time(int a = 0, int b = 0, int c = 0) : h(a), m(b), s(c) {}
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
    void zhengli()
    {
        int total = h * 3600 + m * 60 + s;
        total %= 86400; // 一天86400秒
        if (total < 0)
            total += 86400;
        h = total / 3600;
        total %= 3600;
        m = total / 60;
        s = total % 60;
    }
    void showTime()
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
    Time &setTime(int a, int b, int c)
    {
        h = a;
        m = b;
        s = c;
        return *this;
    }
    Time operator+=(int a)
    {
        if (panduan())
        {
            setTime(h, m, s + a);
            zhengli();
            return *this;
        }
    }
    Time operator-=(int a)
    {
        if (panduan())
        {
            setTime(h, m, s- a);
            zhengli();
            return *this;
        }
    }
};

// ================================AppendCode================================
int main()
{
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; ++i)
    {
        Time t;
        t.inputTime();
        Time tt(t);
        int num;
        cin >> num;
        t += num;
        t.showTime();
        tt -= num;
        tt.showTime();
    }
}