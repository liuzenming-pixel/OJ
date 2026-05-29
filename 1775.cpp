#include <iostream>
using namespace std;
class Person
{
private:
    char *name;
    int age;

public:
    Person() : name("no name"), age(0)
    {
        cout << "A person whose name is \"" << name << "\" and age is " << age << " is created!" << endl;
    }
    Person(char *namee, int agee) : name(namee), age(agee)
    {
        cout << "A person whose name is \"" << name << "\" and age is " << age << " is created!" << endl;
    }
    Person(const Person &t)
    {
        age = t.age;
        name = t.name;
        cout << "A person whose name is \"" << name << "\" and age is " << age << " is cloned!" << endl;
    }
    ~Person()
    {
        cout << "A person whose name is \"" << name << "\" and age is " << age << " is erased!" << endl;
    }
    void showPerson()
    {
        cout << "This person is \"" << name << "\" whose age is " << age << "." << endl;
    }
    Person &setName(char *namee)
    {
        name = namee;
        return *this;
    }
    Person &setAge(int agee)
    {
        age = agee;
        return *this;
    }
};

// ================================AppendCode================================
int main()
{
    int cases;
    char str[80];
    int age;

    Person noname, Tom("Tom", 16), anotherTom(Tom);
    cin >> cases;
    for (int ca = 0; ca < cases; ca++)
    {
        cin >> str >> age;
        Person newPerson(str, age);
        newPerson.showPerson();
    }
    anotherTom.setName(str).setAge(18);
    anotherTom.showPerson();
    noname.showPerson();
    return 0;
}