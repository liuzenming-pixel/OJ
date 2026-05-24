#include <iostream>
using namespace std;

class Point
{
private:
    double xx, yy;

public:
    static int sum;
    static int total;
    Point() : xx(0), yy(0)
    {
        sum++;
        total++;
    }
    Point(double a, double b) : xx(a), yy(b)
    {
        sum++;
        total++;
    }
    Point(const Point &p) : xx(p.xx), yy(p.yy)
    {
        sum++;
        total++;
    }
    ~Point() { sum--; }

    void setx(double t) { xx = t; }
    void sety(double t) { yy = t; }

    static void showSum();
    static void showCounter();
};

class Line
{
private:
    Point p1, p2;

public:
    static int sum;
    static int total;
    Line() : p1(0, 0), p2(0, 0)
    {
        sum++;
        total++;
    }
    Line(Point &a, Point &b) : p1(a), p2(b)
    {
        sum++;
        total++;
    }
    Line(const Line &l) : p1(l.p1), p2(l.p2)
    {
        sum++;
        total++;
    }
    ~Line() { sum--; }

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

    static void showSum();
    static void showCounter();
};
int Point::sum = 0;
int Point::total = 0;
int Line::sum = 0;
int Line::total = 0;

void Point::showCounter()
{
    cout << "Current : " << sum << " points." << endl;
}
void Point::showSum()
{
    cout << "In total : " << total << " points." << endl;
}

void Line::showCounter()
{
    cout << "Current : " << sum << " lines." << endl;
}
void Line::showSum
()
{
    cout << "In total : " << total << " lines." << endl;
}

// ================================AppendCode================================
int main()
{
    int num, i;
    Point p(1, -2), q(2, -1), t;
    t.showCounter();
    t.showSum();
    std::cin >> num;
    Line line[num + 1];
    for (i = 1; i <= num; i++)
    {
        Line *l1, l2;
        l1->showCounter();
        l1->showSum();
        l1 = new Line(p, q);
        line[i].readLine();
        p.showCounter();
        p.showSum();
        delete l1;
        l2.showCounter();
        l2.showSum();
        q.showCounter();
        q.showSum();
    }
    Line l1(p, q), l2(p, t), l3(q, t), l4(l1);
    Line::showCounter();
    Line::showSum();
    Point::showCounter();
    Point::showSum();
    Line *l = new Line[num];
    l4.showCounter();
    l4.showSum();
    delete[] l;
    t.showCounter();
    t.showSum();
}