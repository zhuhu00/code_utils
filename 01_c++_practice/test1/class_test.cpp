// C++的类的一些测试

#include<iostream>

using namespace std;

class Student
{
private:
    char *m_name;
    int m_age;
    float m_score;
    /* data */
public:
    Student(char *m_name,int m_age,float m_score);
    ~Student();
    void show();
};

Student::Student(char *name,int age,float score):m_name(name), m_age(age),m_score(score)
{
}

Student::~Student()
{
}

void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}

int main(){
    Student stu("huge",14,92.0f);
    stu.show();
    //或者是这种指针的方式
    Student *pstu=new Student("haha", 13, 99.0f);
    pstu->show();
    return 0;
}