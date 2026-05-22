#include <iostream>
using namespace std;
#include<iomanip>
class CPLX
{
private:
    double a, b;

public:
    CPLX() : a(0), b(0)
    {
        cout << "CREATE(): "<<setprecision(16) << a << " " << b << endl;
    }
    CPLX(double x,double y) : a(x), b(y)
    {
        cout << "CREATE(): " << a << " " << b << endl;
    }

    ~CPLX()
    {
        cout << "RELEASE(): " <<setprecision(16)<< a << " " << b << endl;
    }
    void print(){
        cout<<"PRINT(): ("<<setprecision(16)<<a<<", "<<b<<"i)"<<endl;
    }
};

// ========AppendCode========
int main()
{
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; ++i)
    {
        double a, b;
        cin >> a >> b;
        cout << "=========================" << endl;

        CPLX cplx(a, b);
        cplx.print();
    }
    cout << "=========================" << endl;
}