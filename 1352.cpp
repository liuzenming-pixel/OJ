#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string s;

    while (getline(cin, s))
    {
        stack<char> st;
        bool ok = true;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '(')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }

        if (!st.empty())
            ok = false;

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}