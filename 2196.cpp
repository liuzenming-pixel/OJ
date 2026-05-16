#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
    char *name;

public:
    static int cnt;

    // 构造函数
    Computer(const char *s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
        cnt++;
    }

    // 拷贝构造函数
    Computer(const Computer &c)
    {
        name = new char[strlen(c.name) + 1];
        strcpy(name, c.name);
        cnt++;
    }

    // 析构函数
    ~Computer()
    {
        delete[] name;
    }

    // 修改名字
    Computer &setName(char *s)
    {
        delete[] name;

        name = new char[strlen(s) + 1];
        strcpy(name, s);

        return *this;
    }

    // 输出
    void print()
    {
        cout << name << endl;
    }

    // 获取对象个数
    static int getCnt()
    {
        return cnt;
    }
};

int Computer::cnt = 0;
int main()
{
    char str[101];
    cout << "1:" << Computer::getCnt() << " computers." << endl;
    Computer com1("Tom"), com2(com1);
    cout << "2:" << com2.getCnt() << " computer." << endl;
    cin >> str;
    com2.setName(str).print();
    com2.print();
    cout << "3:" << com2.getCnt() << " computer." << endl;
    return 0;
}