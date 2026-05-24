#include <iostream>
using namespace std;

class Point
{

private:
    double xx, yy;

public:
    Point() : xx(0), yy(0) {}
    Point(double a, double b) : xx(a), yy(b) {}
    double getx(){
        return xx;
    }
    double gety(){
        return yy;
    }
    void show()
    {
        cout << "Point : (" << xx << ", " << yy << ")" << endl;
    }
};

class Line
{
private:
    Point p1, p2;

public:
    Line() : p1(0, 0), p2(0, 0){
        cout << "Line : (" << p1.getx()<<", "<<p1.gety()<<") to ("<<p2.getx()<<", "<<p2.gety()<<") is created."<<endl;
    }
    Line(double a,double b,double c,double d):p1(a,b),p2(c,d){
        cout << "Line : (" << p1.getx()<<", "<<p1.gety()<<") to ("<<p2.getx()<<", "<<p2.gety()<<") is created."<<endl;
    }
    Line(Point a,Point b):p1(a),p2(b){
        cout << "Line : (" << p1.getx()<<", "<<p1.gety()<<") to ("<<p2.getx()<<", "<<p2.gety()<<") is created."<<endl;
    }
    ~Line(){
        cout << "Line : (" << p1.getx()<<", "<<p1.gety()<<") to ("<<p2.getx()<<", "<<p2.gety()<<") is erased."<<endl;
    }

    void show(){
        cout << "Line : (" << p1.getx()<<", "<<p1.gety()<<") to ("<<p2.getx()<<", "<<p2.gety()<<")"<<endl;
    }
    
};

// ================================AppendCode================================
int main()
{
    char c;
    int num, i;
    double x1, x2, y1, y2;
    Point p(1, -2), q(2, -1), t;
    t.show();
    std::cin >> num;
    for (i = 1; i <= num; i++)
    {
        std::cin >> x1 >> c >> y1 >> x2 >> c >> y2;
        Line line(x1, y1, x2, y2);
        line.show();
    }
    Line l1(p, q), l2(p, t), l3(q, t), l4(t, q);
    l1.show();
    l2.show();
    l3.show();
    l4.show();
}