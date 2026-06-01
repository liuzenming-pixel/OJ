#include <iostream>
#include <iomanip>
using namespace std;
class Time
{
private:
    int h, m, s;
    int p;

public:
    Time(int a = 0, int b = 0, int c = 0) : h(a), m(b), s(c) {}
    Time inputTime()
    {
        cin >> h >> m >> s;
        return *this;
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
    Time &setTime(int a, int b, int c)
    {
        h = a;
        m = b;
        s = c;
        return *this;
    }
    Time operator+(int a)
    {
        if (p)
        {
            Time res(h, m, s + a);
            res.zhengli();
            return res;
        }
        return *this;
    }
    Time operator-(int a)
    {
        if (p)
        {
            Time res(h, m, s - a);
            res.zhengli();
            return res;
        }
        return *this;
    }
    Time &operator+=(int a)
    {
        if (p)
        {
            setTime(h, m, s + a);
            zhengli();
            return *this;
        }
        return *this;
    }
    Time &operator-=(int a)
    {
        if (p)
        {
            setTime(h, m, s - a);
            zhengli();
            return *this;
        }
        return *this;
    }
    Time &operator++()
    {
        if (p)
        {
            *this += 1;
            return *this;
        }
        return *this;
    }
    Time operator++(int)
    {
        if (p)
        {
            Time temp = *this;
            *this += 1;
            return temp;
        }
        return *this;
    }
    Time &operator--()
    {
        if (p)
        {
            *this -= 1;
            return *this;
        }
        return *this;
    }
    Time operator--(int)
    {
        if (p)
        {
            Time temp = *this;
            *this -= 1;
            return temp;
        }
        return *this;
    }

    friend istream &operator>>(istream &in, Time &t);
    friend ostream &operator<<(ostream &out, const Time &t);
};
istream &operator>>(istream &in, Time &t)
{
    in >> t.h >> t.m >> t.s;
    if (t.s >= 0 && t.s < 60 && t.m >= 0 && t.m < 60 && t.h >= 0 && t.h < 24)
        t.p = 1;

    else
        t.p = 0;

    return in;
}
ostream &operator<<(ostream &out, const Time &t)
{

    if (t.p == 1)
    {
        out << right << setw(2) << setfill('0') << t.h << ":" << setw(2) << t.m << ":" << setw(2) << t.s;
    }
    else
    {
        out << left << setw(8) << setfill(' ') << "error!!!";
    }
    return out;
}

// ================================AppendCode================================
int main()
{
    Time t;
    int cases;
    cin >> cases;
    cout << setw(8) << left << "++t" << " ";
    cout << setw(8) << left << "--t" << " ";
    cout << setw(8) << left << "t" << " ";
    cout << setw(8) << left << "t--" << " ";
    cout << setw(8) << left << "t++" << " ";
    cout << setw(8) << left << "t" << right << endl;
    for (int i = 1; i <= cases; ++i)
    {
        cin >> t;
        cout << (++t) << " ";
        cout << (--t) << " ";
        cout << t << " ";
        cout << t-- << " ";
        cout << t++ << " ";
        cout << t << endl;
    }
}