#include <iostream>
#include <string>
using namespace std;

class STU
{
private:
    string name;  // 姓名
    string number;// 学号
    int score;    // 成绩
    
    // 静态成员变量：用来计数，是第几个学生
    static int count;

public:
    // 1. 构造函数
    STU(string n, string num, int s)
    {
        name = n;
        number = num;
        score = s;
    }

    // 2. id函数：返回计数
    int id()
    {
        count++;       // 每创建一个对象，计数+1
        return count;
    }

    // 3. show函数：按格式输出
    void show()
    {
        cout << "{ " << name << " " << number << " " << score << " }" << endl;
    }
};

// 静态成员变量必须在类外初始化！！！（最重要）
int STU::count = 0;




// ================================AppendCode================================
int main()
{
    string name, number;
    int score;
    while(cin >> name >> number >> score)
    {
        STU stu(name, number, score);
        cout << stu.id() << ", ";
        stu.show();
    }
}