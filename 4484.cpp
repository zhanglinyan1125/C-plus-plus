


#include<iostream>
using namespace std;
#include<cstring>
//#include "StuTeacher.h"



class Person  
{
public:
	Person(char[10]);
	virtual ~Person();
	void f();
	void Disp();
protected:
	char name[10];
};



//#include "Person.h"
//#include "StuTeacher.h"
class Student: virtual public Person   
{
public:
	Student(char[10],int);
	void Disp();
	virtual ~Student();
	friend void StuTeacher::Edit(Student&,int);
protected:
	int score;
};






//#include "Person.h"
//#include "Student.h"
class Teacher: virtual public Person
{
public:
	Teacher(char[10],char[10]);
	void Disp();
	virtual ~Teacher();
protected:
	char title[10];
};



//#include "Person.h"
//#include "Student.h"
//#include "Teacher.h"
//#include "Person"
class StuTeacher: public Student,public Teacher
{
public:
	StuTeacher(char[10],int,char[10],int);
	void Disp();
	virtual ~StuTeacher();
	void Edit(Student&,int);
protected:
	int age;
};






//#include "Person.h"


Person::Person(char n[10])
{
	strcpy(name,n);

}

/*void Person::Disp()
{

}*/

Person::~Person()
{

}



//#include "Student.h"


Student::Student(char n[10],int s):Person(n)
{
	score=s;
}

void Student::Disp()
{
	cout<<name<<","<<score<<endl;
}

Student::~Student()
{

}



//#include "Teacher.h"


Teacher::Teacher(char n[10],char t[10]):Person(n)
{
	strcpy(title,t);
}

void Teacher::Disp()
{
	cout<<name<<","<<title<<endl;
}



Teacher::~Teacher()
{

}


//#include "StuTeacher.h"



StuTeacher::StuTeacher(char n[10],int s,char t[10],int a):Person(n),Student(n,s),Teacher(n,t)
{
	age=a;
}

void StuTeacher::Disp()
{
	cout<<name<<","<<score<<","<<title<<","<<age;
}

void StuTeacher::Edit(Student&p,int b)
{
	p.score=b;
}

StuTeacher::~StuTeacher()
{

}





void f(Person &g)
{
	g.Disp();
}


int main()

{

    char name[10],title[10];

    int score,age;

    cin>>name>>score;

    Student s(name,score);

    cin>>name>>title;

    Teacher t(name,title);

    cin>>name>>score>>title>>age;

    StuTeacher st(name,score,title,age);

    f(s);

    f(t);

    f(st);

    st.Edit(s,90);

    s.Disp();

    return 0;

}
