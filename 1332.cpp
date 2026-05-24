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
    double getx() const { return xx; }
    double x() const { return xx; }
    double gety() const { return yy; }
    double y() const { return yy; }

    void setx(double t) { xx = t; }
    void sety(double t) { yy = t; }
    void show() { cout << "Point : (" << xx << ", " << yy << ")" << endl; }

    void showNoEndOfLine() const
    {
        cout << "Point : (" << xx << ", " << yy << ")"; 
    }
};

class Line
{
private:
    Point p1, p2;

public:
    Line() : p1(0, 0), p2(0, 0) { cout << "Line : (" << p1.getx() << ", " << p1.gety() << ") to (" << p2.getx() << ", " << p2.gety() << ") is created." << endl; }
    Line(double a, double b, double c, double d) : p1(a, b), p2(c, d) { cout << "Line : (" << p1.getx() << ", " << p1.gety() << ") to (" << p2.getx() << ", " << p2.gety() << ") is created." << endl; }
    Line(Point &x, Point &y) : p1(x), p2(y)
    {
        cout << "Line : (" << p1.getx() << ", " << p1.gety() << ") to (" << p2.getx() << ", " << p2.gety() << ") is created." << endl;
    }
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
    Line &setLine(Line &l)
    {
        p1.setx(l.p1.getx());
        p1.sety(l.p1.gety());
        p2.setx(l.p2.getx());
        p2.sety(l.p2.gety());
        return *this;
    }
    void setStart(Point &p)
    {
        p1.setx(p.getx());
        p1.sety(p.gety());
    }
    void setEnd(Point &p)
    {
        p2.setx(p.getx());
        p2.sety(p.gety());
    }
    Line &setLine(Point &p11, Point &p22)
    {
        p1.setx(p11.getx());
        p1.sety(p11.gety());
        p2.setx(p22.getx());
        p2.sety(p22.gety());

        return *this;
    }
    const Point &start() const
    {
        
        return p1;
    }

    const Point &end() const
    {
        return p2;
    }
    void show() const { cout << "Line : (" << p1.getx() << ", " << p1.gety() << ") to (" << p2.getx() << ", " << p2.gety() << ")" << endl; }
};

// ================================AppendCode================================
void showLineCoordinate(const Line &line)
{
    std::cout << "Line : ";
    std::cout << "(" << line.start().x() << ", " << line.start().y() << ")";
    std::cout << " to ";
    std::cout << "(" << line.end().x() << ", " << line.end().y() << ")";
    std::cout << std::endl;
}

void showLinePoint(const Line &line)
{
    std::cout << "Line : ";
    line.start().showNoEndOfLine();
    std::cout << " to ";
    line.end().showNoEndOfLine();
    std::cout << std::endl;
}

void showLine(const Line &line)
{
    line.show();
}

int main()
{
    int num, i;
    Point p(1, -2), q(2, -1), t;
    t.show();
    std::cin >> num;
    Line line[num + 1];
    for (i = 1; i <= num; i++)
    {
        line[i].readLine();
        showLine(line[i]);
    }
    // cout << "=====================111========================" << endl;

    Line l1(p, q), l2(p, t), l3(q, t), l4(l1);

    // cout << "=====================222========================" << endl;

    showLineCoordinate(l1);
    showLinePoint(l2);
    showLinePoint(l3.setLine(l1));
    showLineCoordinate(l4.setLine(t, q));

    // cout << "=====================333========================" << endl;

    line[0].setStart(t);
    line[0].setEnd(q);
}
