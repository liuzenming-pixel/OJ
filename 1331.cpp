#include <iostream>
using namespace std;

class Point
{
private:
    double xx, yy;

public:
    Point() : xx(0), yy(0) { cout << "Point : (" << xx << ", " << yy << ") is created." << endl; }
    Point(double a, double b) : xx(a), yy(b) { cout << "Point : (" << xx << ", " << yy << ") is created." << endl; }
    Point(const Point &p) : xx(p.xx), yy(p.yy) { cout << "Point : (" << xx << ", " << yy << ") is copied." << endl; }
    ~Point() { cout << "Point : (" << xx << ", " << yy << ") is erased." << endl; }
    double getx() { return xx; }
    double gety() { return yy; }
    void setx(double t) { xx = t; }
    void sety(double t) { yy = t; }
    void show() { cout << "Point : (" << xx << ", " << yy << ")" << endl; }
};

class Line
{
private:
    Point p1, p2;

public:
    Line() : p1(0, 0), p2(0, 0) { cout << "Line : (" << p1.getx() << ", " << p1.gety() << ") to (" << p2.getx() << ", " << p2.gety() << ") is created." << endl; }
    Line(double a, double b, double c, double d) : p1(a, b), p2(c, d) { cout << "Line : (" << p1.getx() << ", " << p1.gety() << ") to (" << p2.getx() << ", " << p2.gety() << ") is created." << endl; }
    Line(Point &x, Point &y) : p1(x), p2(y) { cout << "Line : (" << p1.getx() << ", " << p1.gety() << ") to (" << p2.getx() << ", " << p2.gety() << ") is created." << endl; }
    Line(const Line &l) : p1(l.p1), p2(l.p2)
    {
        cout << "Line : (" << p1.getx() << ", " << p1.gety() << ") to (" << p2.getx() << ", " << p2.gety() << ") is copied." << endl;
    }
    ~Line() { cout << "Line : (" << p1.getx() << ", " << p1.gety() << ") to (" << p2.getx() << ", " << p2.gety() << ") is erased." << endl; }
    void SetLine(double a, double b, double c, double d)
    {
        p1.setx(a);
        p1.sety(b);
        p2.setx(c);
        p2.sety(d);
    }
    void readLine()
    {
        char c;
        double x1, x2, y1, y2;
        std::cin >> x1 >> c >> y1 >> x2 >> c >> y2;
        SetLine(x1, y1, x2, y2);
    }
    Line& setLine(Line &l)
    {
        p1.setx(l.p1.getx());
        p1.sety(l.p1.gety());
        p2.setx(l.p2.getx());
        p2.sety(l.p2.gety());
        return *this;
    }
    Line& setLine(Point &p11, Point &p22)
    {
        p1.setx(p11.getx());
        p1.sety(p11.gety());
        p2.setx(p22.getx());
        p2.sety(p22.gety());

        return *this;
    }

    void show() { cout << "Line : (" << p1.getx() << ", " << p1.gety() << ") to (" << p2.getx() << ", " << p2.gety() << ")" << endl; }
};

// ================================AppendCode================================
int main()
{
    int num, i;
    Point p(1, -2), q(2, -1), t;
    t.show();
    std::cin >> num;
    Line line[num];
    for (i = 0; i < num; i++)
    {
        line[i].readLine();
        line[i].show();
    }
    // cout<<"=====================111========================"<<endl;
    Line l1(p, q), l2(p, t), l3(q, t), l4(l1);
    // cout << "======================222====================" << endl;
    l1.show();
    l2.setLine(l1).show();
    l3.show();
    l4.setLine(t, q).show();
    // cout << "======================333====================" << endl;
}