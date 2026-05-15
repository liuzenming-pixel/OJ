#include <iostream>
#include <iomanip>
using namespace std;

class Point
{

private:
    double x, y;

public:
    static int count;
    static int sum;
    Point() : x(0), y(0)
    {
        count++;
        sum++;
    }
    Point(double a) : x(a), y(a)
    {
        count++;
        sum++;
    }
    Point(double a, double b) : x(a), y(b)
    {
        count++;
        sum++;
       
    }
    Point(const Point &p):x(p.x),y(p.y){
        count++;
        sum++;
    }

    void show()
    {
        cout << "Point : (" << setprecision(16) << x << ", " << y << ")" << endl;
    }

    
    ~Point()
    {
        count--;
    }
    friend void showPoint(const Point &p1, const Point &p2, const Point &p3);
    static void showCounter();
    static void showSumOfPoint();
};

int Point::count = 0;
int Point::sum = 0;


void showPoint(const Point &p1, const Point &p2, const Point &p3)
{
    cout << "Point : (" << setprecision(16) << p1.x << ", " << p1.y << ")" << endl;

    cout << "Point : (" << setprecision(16) << p2.x << ", " << p2.y << ")" << endl;

    cout << "Point : (" << setprecision(16) << p3.x << ", " << p3.y << ")" << endl;
}

void Point::showCounter(){
    cout << "Current : " << count << " points." << endl;
}
void Point::showSumOfPoint()
    {
        cout << "In total : " << sum << " points." << endl;
    }


int main()
{
    char c;
    double a, b;
    Point q;
    while (std::cin >> a >> c >> b)
    {
        Point p(a, b);
        p.show();
        p.showCounter();
    }
    q.showSumOfPoint();
    Point q1(q), q2(1);
    Point::showCounter();
    showPoint(q1, q2, q);
    Point::showSumOfPoint();
}