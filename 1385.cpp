#include<iostream>
#include<iomanip>
using namespace std;
class Time{
private:
    int hh,mm,ss;


public:
Time(int h,int m,int s):hh(h),mm(m),ss(s){}

void showTime(){
    cout<<setfill('0');
    cout<<setw(2)<<hh<<":"<<setw(2)<<mm<<":"<<setw(2)<<ss<<endl;
}
};

int main()
{
    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        int hour, minute, second;
        cin>>hour>>minute>>second;
        Time t(hour, minute, second);
        t.showTime();
    }
}