#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int M;
    while(cin>>M)
    {
        map<string , int> bill;
        string name; int n;
        for(int i=0; i<M; i++)
        {
            cin>>name>>n;
            bill[name]+=n;
            //bill.insert(make_pair(name,n));
        }
        map<string , int>::iterator p;
        for(p=bill.begin(); p!=bill.end(); p++)
        cout<<p->first<<":"<<p->second<<endl;
    }
}