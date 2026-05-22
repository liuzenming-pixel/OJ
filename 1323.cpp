
#include <iostream>

using namespace std;

class Person
{
private:
    int age;
    bool sex;

public:
    static int num;
    Person() : age(0), sex(0)
    {
        num++;
        cout << "The No." << num << " person, age=" << age << ",sex=";
        if (sex == 0)
            cout << "F";
        else
            cout << "M";
        cout << " is created!" << endl;
    }
    Person(int age, bool sex) : age(age), sex(sex)
    {
        num++;
        cout << "The No." << num << " person, age=" << age << ",sex=";
        if (sex == 0)
            cout << "F";
        else
            cout << "M";
        cout << " is created!" << endl;
    }
    Person(const Person &p) : age(p.age), sex(p.sex)
    {
        num++;
        cout << "The No." << num << " person, age=" << age << ",sex=";
        if (sex == 0)
            cout << "F";
        else
            cout << "M";
        cout << " is copyed!" << endl;
    }
    static void showNum(){
        cout<<"There are "<<num<<" persons are created!"<<endl;
    }
};
int Person::num = 0;

// ======AppendCode====
int main()
{
    int a;
    bool s;
    cin>>a>>s;
    Person p1(a,s);
    Person::showNum();
    Person p2(p1),p3,p4(p3);
    p2.showNum();
    return 0;
}