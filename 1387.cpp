#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
    int h, m, s;

public:
    Time inputTime()
    {
        int hh, mm, ss;
        cin >> hh >> mm >> ss;
        h = hh;
        m = mm;
        s = ss;
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
    Time t;
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; ++i)
        t.inputTime().showTime();
}