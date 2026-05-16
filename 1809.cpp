#include <iostream>
using namespace std;
class Demo
{
private:
    int n;

public:
    Demo() : n(0)
    {
        cout << "A data " << n << " is created!" << endl;
    }
    Demo(int x) : n(x)
    {
        cout << "A data " << n << " is created!" << endl;
    }

    ~Demo()
    {
        cout << "A data " << n << " is erased!" << endl;
    }
    void show(){
        cout<<"This is data "<<n<<endl;
    }
};

int main()
{
    Demo tmp(10), tmp2;
    int d;
    cin >> d;
    Demo tmp3(d);

    tmp.show();
    tmp2.show();
    tmp3.show();
    return 0;
}