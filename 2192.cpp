#include <iostream>
#include <iomanip>
using namespace std;
class Data
{
private:
    int numint;
    double numdouble;
    int type;

public:
    Data()
    {
        type = 2;
        cout << "A default object is created." << endl;
    }
    Data(int a) : numint(a)
    {
        type = 0;
        cout << "An integer object " << numint << " is created." << endl;
    }
    Data(double a) : numdouble(a)
    {
        type = 1;
        cout << "A double object " << a << " is created." << endl;
    }
    ~Data()
    {
        if (type == 1)
        {
            cout << "The double object " << numdouble << " is erased." << endl;
        }
        else if (type == 0)
        {
            cout << "The integer object " << numint << " is erased." << endl;
        }
        else
        {
            cout << "The default object is erased." << endl;
        }
    }
};

// ================================AppendCode================================
int main()
{
    Data d1;
    int i;
    cin >> i;
    Data d2(i);
    double d;
    cin >> d;
    Data d3(d);
    return 0;
}