#include <iostream>
#include <algorithm>

using namespace std;
template <class T>
class Array
{
private:
    T *data;
    int length;

public:
    Array(int a)
    {
        data = new T[a];
        length = a;
    }
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
    int size() const
    {
        return length;
    }
    T &operator[](int index)
    {
        return data[index];
    }
    ~Array()
    {
        if (data != NULL)
        {
            delete[] data;
        }
    }
    void put(int n)
    {
        T *temp = new T[length];
        for (int i = 0; i < length; i++)
        {
            temp[i] = data[i];
        }
        sort(temp, temp + length, greater<T>());

        // 确定输出个数：取 n 和 数组长度 的较小值
        int printNum = (n < length) ? n : length;

        // 按格式输出
        for (int i = 0; i < printNum; i++)
        {
            if (i == 0)
                cout << temp[i];
            else
                cout << " " << temp[i];
        }
        cout << endl;

        // 释放临时数组内存
        delete[] temp;
    }
};

// ================================AppendCode================================
int main()
{
    int cases, len;
    cin >> cases;
    for (int ca = 1; ca <= cases; ca++)
    {
        cin >> len;
        if (ca % 3 == 0)
        {
            Array<char> chr_arr(len);
            for (int i = 0; i < chr_arr.size(); i++)
                cin >> chr_arr[i];
            chr_arr.put(10);
        }
        if (ca % 3 == 1)
        {
            Array<int> int_arr(len);
            for (int i = 0; i < int_arr.size(); i++)
                cin >> int_arr[i];
            int_arr.put(10);
        }
        if (ca % 3 == 2)
        {
            Array<double> dbl_arr(len);
            for (int i = 0; i < dbl_arr.size(); i++)
                cin >> dbl_arr[i];
            dbl_arr.put(10);
        }
    }
}