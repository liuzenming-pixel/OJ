#include <iostream>
#include <cstdlib>

using namespace std;

class Fract
{
private:
    int n, m;
    // 求最大公约数（用于约分）
    int gcd(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // 约分 + 处理符号（负号只放最前面）
    void simplify()
    {
        // 分子为 0，直接让分母 = 1
        if (n == 0)
        {
            m = 1;
            return;
        }

        // 求最大公约数
        int g = gcd(n, m);
        n /= g;
        m /= g;

        // 符号统一：负号只给分子，分母永远为正
        if (m < 0)
        {
            n = -n;
            m = -m;
        }
    }

public:
    Fract(int x, int y) : n(x), m(y) { simplify(); }
    void show()
    {

        // 1. 分子为 0，直接输出 0
        if (n == 0)
        {
            cout << 0;
        }
        // 2. 分母为 1，只输出分子
        else if (m == 1)
        {
            cout << n;
        }
        // 3. 正常分数 a/b

        else
        {

            cout << n << "/" << m;
        }
        // 换行
        cout << endl;
    }
};

// ================================AppendCode================================
#include <cstdio>
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        Fract fr(n, m);
        fr.show();
    }
}