#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
class Point
{
private:
    double _x, _y;
    int id;
 
    static int counter; // 当前存在的对象数
    static int sum;
 
    static int pos;
public:
    Point() : _x(0), _y(0)
    {
        counter++;
        sum++;
        id = ++pos;
    }
    Point(double x) : _x(x), _y(x)
    {
        counter++;
        sum++;
        id = ++pos;
    }
    Point(double x, double y) : _x(x), _y(y)
    {
        counter++;
        sum++;
        id = ++pos;
    }
    Point(const Point& p) : _x(p._x), _y(p._y)
    {
        counter++;
        sum++;
        id = ++pos;
    }
    ~Point()
    {
        counter--;
    }
    void show() const
    {
        cout << setprecision(16)
             << "Point[" << id << "] : ("
             << _x << ", " << _y << ")" << endl;
    }
    static void showCounter()
    {
        cout << "Current : " << counter << " points." << endl;
    }
    static void showSumOfPoint()
    {
        cout << "In total : " << sum << " points." << endl;
    }
    double x() const
    {
        return _x;
    }
    double y() const
    {
        return _y;
    }
    double x(double x)
    {
        if (x > _x)
            _x = x;
        return x;
    }
    double y(double y)
    {
        _y = y;
        return _y;
    }
    double getX() const
    {
        return _x;
    }
    double getY() const
    {
        return _y;
    }
    double setX(double x)
    {
        _x = x;
        return _x;
    }
    double setY(double y)
    {
        _y = y;
        return _y;
    }
    Point& setPoint(double x, double y)
    {
        _x = x;
        _y = y;
        return *this;
    }
};
int Point::counter = 0;
int Point::sum = 0;
int Point::pos = 0;




// ==================Append Code==================
void ShowPoint(Point p)
{
    cout<<std::setprecision(16)<<"Point : ("<<p.x()<<", "<<p.y()<<")"<<endl;
}
 
void ShowPoint(double x, double y)
{
    Point p(x, y);
    cout<<std::setprecision(16)<<"Point : ("<<p.x()<<", "<<p.y()<<")"<<endl;
}
 
void ShowPoint(Point &p, double x, double y)
{
    cout<<std::setprecision(16)<<"Point : ("<<p.x(x)<<", "<<p.x(y)<<")"<<endl;
}
 
int main()
{
    int l(0);
    char c;
    double a, b;
    Point pt[60];
    while(std::cin>>a>>c>>b)
    {
        if(a == b)
            ShowPoint(pt[l].setPoint(a, b));
        if(a > b)
            ShowPoint(a, b);
        if(a < b)
            ShowPoint(pt[l], a, b);
        l++;
    }
    Point p(a), q(b);
    ShowPoint(q);
    double x(0), y(0);
    for(int i = 0; i < l; i++)
        x += pt[i].getX(), y -= pt[i].getY();
    ShowPoint(pt[l].setX(x), pt[l].setY(y));
    cout<<"==========gorgeous separator=========="<<endl;
    for(int i = 0; i <= l; i++)
        pt[i].show();
    q.setPoint(q.x() - p.x() + a, q.y() - p.y() + b).show();
    q.show();
    cout<<"==========gorgeous separator=========="<<endl;
    p.showSumOfPoint();
}