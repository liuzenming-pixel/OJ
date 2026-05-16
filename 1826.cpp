#include <iostream>

using namespace std;
class CharGraph
{

private:
    int n;
    char c;

public:
    CharGraph(int x, int y) : n(x), c(y) {}
    void print()
    {
        if (n > 0)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << c;
                }
                cout << endl;
            }
            
        }
        else if (n==0){
            cout<<endl;
        }
        else
        {
            n *= -1;
            for (int i = n; i > 0; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    cout << c;
                }
                cout << endl;
            }
            
        }
    }
};
int main()
{
    int cases, n;
    char c;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> n >> c;
        CharGraph cGraph(n, c);
        cGraph.print();
    }
    return 0;
}