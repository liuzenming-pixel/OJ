#include <iostream>
#include <set>
using namespace std;

int main()
{
    int num;
    while (true)
    {
        set<int> s1, s2;
        while (cin >> num && num != 0)
        {
            s1.insert(num);
        }
        if (!cin)
            break;
        while (cin >> num && num != 0)
        {
            s2.insert(num);
        }
        if (s1 == s2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}