#include<iostream>
#include<string.h>
using namespace std;

class People
{
private:
int age;
char sex;
public:
void setAge(int a){
    age=a;
}
void setSex(char b){
    sex=b;
}
void printInfo(){
cout<<"age:"<<age<<",sex:"<<sex<<endl;
}


};


// ========AppendCode========
int main()
{
    People Tom, Mary;
    int ageTom,ageMary;
    char sexTom,sexMary;
    cin>>ageTom>>sexTom;
    cin>>ageMary>>sexMary;
    Tom.setAge(ageTom);
    Mary.setAge(ageMary);
    Tom.setSex(sexTom);
    Mary.setSex(sexMary);
    Tom.printInfo();
    Mary.printInfo();
    return 0;
}