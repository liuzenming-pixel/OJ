#include <iostream>

using namespace std;

class Data
{

    private:
    double n;
    public:
    Data():n(0){cout<<"Initialize a data "<<n<<endl;}
    Data(double b):n(b){cout<<"Initialize a data "<<n<<endl;}
    double getValue(){
        return n;
    }
    void showValue(){
        cout<<n<<endl;
    }
};

// ========AppendCode========
int main()
{
    Data data1;
    double d;
    cin >> d;
    Data data(d);
    cout << data.getValue() << endl;
    data.showValue();
}