#include <iostream>

using namespace std;
class Cx
{
    private:
    int a,b;
    public:
    Cx(){}
    Cx(int a,int b):a(0),b(0){}
    void re(int n){
        a=n;
    }
    void im(int n){
        b=n;
    }
    void print(){
        cout<<"("<<a<<","<<b<<")"<<endl;
    }


};

// ========AppendCode========
int main()
{
    Cx cc;
    int a, b;
    cin >> a >> b;
    cc.re(a);
    cc.im(b);
    cc.print();
}