#include <iostream>
using namespace std;

class Simple
{

private:
    int num;

public:
    Simple() : num(0) { cout << "Simple " << num << " is created." << endl; }
    Simple(int x) : num(x) { cout << "Simple " << num << " is created." << endl; }
    ~Simple() { cout << "Simple " << num << " is erased." << endl; }
    Simple(const Simple &p) : num(p.num) { cout << "Simple " << num << " is copied." << endl; }
    Simple& setMem(int x){
        num=x;
        return *this;
    }
    int getMem(){
        return num;
    }
    void print(){
        cout<<num<<endl;
    }
};

int main()
{
    int m;
    cin >> m;
    Simple s1, s2(m);
    Simple s3;
    s3.setMem(m).print();
    s3.setMem(m + 1);
    cout << s3.getMem() << endl;
    Simple s4(s3);
    s4.print();
    return 0;
}