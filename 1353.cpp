#include <iostream>
#include <string>
#include <map>
#include<iterator>
using namespace std;
int main()
{
    string str1;
    string str2;
    map<string,string>f;
    int n;
    while(cin>>n)
    {
        f.clear();
        for(int i=0;i<n;i++)
        {
            cin>>str1>>str2;
            f[str2]=str1;
        }
        cin>>n;
        for(int j=0;j<n;j++)
        {
            string str;
            cin>>str;
            if(f.count(str)!=0 )
                cout <<f[str]<< endl;
            else
                cout<<"eh"<<endl;
        }
    }
    return 0;
}
