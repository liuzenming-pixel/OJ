#include <iostream>
using namespace std;

class Array
{
private:
    int *data;
    int length;

public:
    Array() : data(NULL), length(0) {}
    void get(int a)
    {
        if (data != NULL)
        {
            delete[] data;
        }
        length = a;
        if (a == 0)
        {
            data = NULL;
            return;
        }
        data = new int[a];
        for (int i = 0; i < a; i++)
        {
            cin >> data[i];
        }
    }
    int size()
    {
        return length;
    }
    int& operator[](int index){
        return data[index];
    }
    ~Array(){
        if(data!=NULL){
            delete[] data;
        }
    }
};

// ================================AppendCode================================
int main()
{
    int cases;
    Array arr;
    cin >> cases;
    for (int ca = 1; ca <= cases; ca++)
    {
        int len;
        cin >> len;
        arr.get(len);
        for (int i = 0; i < arr.size(); i++)
            if (i + 1 == arr.size())
                cout << arr[i];
            else
                cout << arr[i] << " ";
        cout << endl;
    }
}
