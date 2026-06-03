#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
int main()
{
    int N;
    while(cin>>N)
    {
        double temp;
        char arr;
        stack<double> num;
        cin>>temp;
        num.push(temp);
        for(int i=1; i<N; i++)
        {
            cin>>arr>>temp;
            if(arr=='+')
            num.push(temp);
 
            if(arr=='-')
            num.push(-temp);
 
            if(arr=='*')
            {
            // 原理：1+2*3= 原是栈顶为2， 现将3与2相乘删除栈顶2，把乘积存为栈顶
                temp=num.top()*temp;//将输入的数与栈中的栈顶数相乘
                num.pop();//将原栈顶数删除
                num.push(temp);//用temp替换为栈顶
            }
        }
        cin>>arr;//输入最后的“=”。
        double sum=0;
        while(!num.empty())
        {
            sum+=num.top();
            num.pop();
        }
        cout<<setprecision(2)<<fixed<<sum<<endl;
    }
}