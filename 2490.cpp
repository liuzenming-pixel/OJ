#include<iostream>

using namespace std;


class Cx{
private:

int a,b;

public:
Cx():a(0),b(0){}
Cx(int x,int y):a(x),b(y){}

void re(int aa){
    a=aa;
}
void im(int bb){
    b=bb;
}
void print(){
    cout<<"("<<a<<","<<b<<")"<<endl;
}


};







int main()
{
    Cx c;
    c.print();
    c.im(1);
    c.print();
    c.re(2);
    c.print();
    cout << "====================" << endl;
    int a, b;
    cin >> a >> b;
    Cx cc(a, b);
    cc.print();
}