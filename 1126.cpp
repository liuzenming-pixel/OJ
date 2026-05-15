#include <iostream>
#include <iomanip>
using namespace std;

class Point
{
private:
    double xx, yy;

public:
    static int sum;
    static int tol;
    Point() : xx(0), yy(0) { sum++; }
    Point(double a, double b) : xx(a), yy(b) { sum++; }

    void show() const
    {
        cout << "Point[" << sum << "] : (" << xx << ", " << yy << ")" << endl;
    }
    void showSumOfPoint() const
    {
    }

    double x() const
    {
        return xx;
    }
    double y() const
    {
        return yy;
    }
    double x(double a)
    {
        xx = a;
        return xx;
    }
    double y(double a)
    {
        yy = a;
        return yy;
    }
    Point setPoint(double a, double b)
    {
        xx = a;
        yy = b;
        return *this;
    }
    bool isEqual(const Point &p) const
    {
        if (xx == p.xx && yy == p.yy)
            return true;
        else
            return false;
    }

    Point copy(const Point &p)
    {
        xx = p.xx;
        yy = p.yy;
        return *this;
    }

    Point inverse()
    {
        double temp = xx;
        xx = yy;
        yy = temp;
        return *this;
    }
    Point inverse(Point p)
    {
        double temp = p.xx;
        p.xx = p.yy;
        p.yy = temp;
        return p;
    }
};
int Point::sum = 0;
int Point::tol = 0;

void ShowPoint(double a, double b)
{
    cout << "Point[" << Point::sum << "] : (" << a << ", " << b << ")" << endl;
}
void ShowPoint(Point p)
{
    cout << "Point[" << Point::sum << "] : (" << p.x() << ", " << p.y() << ")" << endl;
}
void ShowPoint(const Point &p)
{
    cout << "Point[" << Point::sum << "] : (" << p.x() << ", " << p.y() << ")" << endl;
}

int main()
{
    int l(0);
    char c;
    double a, b;
    Point p, q, pt[60];
    while (std::cin >> a >> c >> b)
    {
        if (a == b)
            p.copy(pt[l].setPoint(a, b));
        if (a > b)
            p.copy(pt[l].setPoint(a, b).inverse());
        if (a < b)
            p.inverse(pt[l].setPoint(a, b));
        if (a < 0)
            q.copy(p).inverse();
        if (b < 0)
            q.inverse(p).copy(pt[l]);
        pt[l++].show();
        p.show();
    }
    q.show();
    cout << "==========gorgeous separator==========" << endl;
    double x(0), y(0);
    for (int i = 0; i < l; i++)
        x += pt[i].x(), y -= pt[i].y();
    pt[l].x(y), pt[l].y(x);
    q.copy(pt[l]).show();
    for (int i = 0; i <= l; i++)
        pt[i].show();
    cout << "==========gorgeous separator==========" << endl;
    const Point const_point(3, 3);
    const_point.show();
    for (int i = 0; i <= l; i++)
    {
        if (const_point.isEqual(pt[i]))
        {
            ShowPoint(const_point);
            ShowPoint(const_point.x(), const_point.y());
            ShowPoint(Point(const_point.x(), const_point.y()));
        }
    }
    const_point.showSumOfPoint();
}
