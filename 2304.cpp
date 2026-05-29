#include <iostream>
// 用于开平方sqrt函数
#include <cmath>
using namespace std;

// 定义Point类
class Point
{
private:
    double x; // 横坐标
    double y; // 纵坐标
public:
    // 带参构造函数：初始化坐标
    Point(double x_, double y_)
    {
        x = x_;
        y = y_;
    }

    // 重载减法运算符 - ：计算两个点之间的距离，返回double类型
    double operator-(const Point &other) const
    {
        // 横坐标差值
        double dx = this->x - other.x;
        // 纵坐标差值
        double dy = this->y - other.y;
        // 两点间距离公式
        return sqrt(dx * dx + dy * dy);
    }
};

// ================================AppendCode================================
int main()
{
    Point p1(10, 10);
    double x, y;
    while (cin >> x >> y)
    {
        Point p2(x, y);
        cout << p2 - p1 << endl;
    }
    return 0;
}