#include <iostream>
#include <string>
using namespace std;

class Thing
{
private:
    string a;

public:
    Thing()
    {
        cout << "A thing without name is created!" << endl;
    }
    Thing(string name) : a(name)
    {
        cout << "A thing named by " << a << " is created!" << endl;
    }
    Thing(const Thing &t)
    {
        a = t.a;
        if (a.empty())
        {
            cout << "A thing without name is copied!" << endl;
        }
        else
        {
            cout << "A thing named by " << a << " is copied!" << endl;
        }
    }
    ~Thing()
    {
        if(a.empty())
        {
            cout<<"A thing without name is erased!"<<endl;
        }
        else
        {
            cout << "A thing named by " << a << " is erased!" << endl;
        }
    };
};

// // ================================AppendCode================================
int main()
{
    string name;
    Thing Thing1, Thing2(Thing1);
    cin >> name;
    Thing Thing3(name);
    Thing Thing4(Thing3);
    return 0;
}
