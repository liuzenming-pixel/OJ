#include <iostream>
#include <iomanip>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point() : x(0), y(0)
    {
        cout << "Point : (" << setprecision(16) << x
             << ", " << y << ") is created." << endl;
    }
    Point(double a, double b) : x(a), y(b)
    {
        cout << "Point : (" << setprecision(16) << x
             << ", " << y << ") is created." << endl;
    }
    Point(double a) : x(a), y(a)
    {
        cout << "Point : (" << setprecision(16) << x
             << ", " << y << ") is created." << endl;
    }
    Point(const Point &p) : x(p.x), y(p.y)
    {
        cout << "Point : (" << setprecision(16) << x
             << ", " << y << ") is copied." << endl;
    }
    ~Point()
    {
        cout << "Point : (" << setprecision(16) << x
             << ", " << y << ") is erased." << endl;
    }
    void show()
    {
        cout << "Point : (" << setprecision(16) << x
             << ", " << y << ")" << endl;
    }
    friend void showPoint(Point p);
    friend void showPoint(Point p1, Point p2, Point p3);
};

void showPoint(Point p)
{
    cout << "Point : (" << setprecision(16) << p.x << ", " << p.y << ")" << endl;
}
void showPoint(Point p1, Point p2, Point p3)
{

    cout << "Point : (" << setprecision(16) << p1.x << ", " << p1.y << ")" << endl;

    
    cout << "Point : (" << setprecision(16) << p2.x << ", " << p2.y << ")" << endl;

    
    cout<<"Point : ("<<setprecision(16)<<p3.x<<", "<<p3.y<<")"<<endl;

}

int main()
{
    char c;
    double a, b;
    Point q;
    while (std::cin >> a >> c >> b)
    {
        Point p(a, b);
        showPoint(p);
    }
    Point q1(q), q2(1);
    showPoint(q1, q2, q);
}