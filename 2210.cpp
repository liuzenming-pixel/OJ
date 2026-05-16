#include <iostream>

using namespace std;
class SpecialPrime
{
public:
    static bool judge(int value)
    {
        // 回文
        int t = value;
        int rev = 0;
        while(t>0){
            rev=rev*10+t%10;
            t/=10;
        }
        if(rev!=value){
            return false;
        }
        // 素数
        if(value<2) return false;
        for(int i=2;i*i<=value;i++){
            if(value%i==0)
            return false;
        }
        return true;


    }
};

int main()
{
    int m, n, i;
    cin >> m >> n;
    for (i = m; i < n; i++)
    {
        if (SpecialPrime::judge(i))
            cout << i << endl;
    }
    return 0;
}