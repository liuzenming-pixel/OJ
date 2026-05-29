#include <iostream>
using namespace std;

// 定义字符类
class Character
{
private:
    char c; // 唯一的私有数据成员
public:
    // 重载输入运算符 >>
    friend istream &operator>>(istream &in, Character &ch)
    {
        in >> ch.c;
        return in;
    }

    // 重载输出运算符 <<
    friend ostream &operator<<(ostream &out, const Character &ch)
    {
        out << ch.c;
        return out;
    }

    // 重载 + 运算符：当前字符之后第n个字符
    Character operator+(int n) const
    {
        Character res;
        // 计算偏移后的ASCII码，取模26实现a-z循环
        int offset = (this->c - 'a' + n) % 26;
        // 处理负数取模的情况（保证结果为正）
        if (offset < 0)
            offset += 26;
        res.c = 'a' + offset;
        return res;
    }

    // 重载 - 运算符：当前字符之前第n个字符
    Character operator-(int n) const
    {
        Character res;
        // 计算偏移后的ASCII码，取模26实现z-a循环
        int offset = (this->c - 'a' - n) % 26;
        // 处理负数取模的情况
        if (offset < 0)
            offset += 26;
        res.c = 'a' + offset;
        return res;
    }
};

// ================================AppendCode================================
int main()
{
    int cases, data;
    Character ch;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> ch;
        cin >> data;
        cout << (ch + data) << " " << (ch - data) << endl;
    }
}