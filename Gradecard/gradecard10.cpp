#include<iostream>
#include<string>
using namespace std;
class student{
	public:
	int stdID;
	string stdName;
	void getpersonalDetails()
	{
		cout<<"Enter Student ID :";
		cin>>stdID;
		cout<<"Enter student name :";
		cin>>stdName;
	}
	void putpersonalDetails()
	{
		cout<<"The student ID is :"<<stdID<<endl;
		cout<<"The student name is :"<<stdName<<endl;
	}
	
};

class teacher{
	public:
	int trID;
	string trName;
	void getpersonalDetails()
	{
		cout<<"Enter teacher ID :";
		cin>>trID;
		cout<<"Enter teacher name :";
		cin>>trName;
	}
	void putpersonalDetails()
	{
		cout<<"The teacher ID is :"<<trID<<endl;
		cout<<"The teacher name is :"<<trName<<endl;
	}
	
};

class gradeCard{
	public:
	int stdID,trID,intm1,intm2,asmark1,asmark2,tint,endsem,total;
	float gpa;
	void enterMarks()
	{
		cout<<"Enter student ID :";
		cin>>stdID;
		cout<<"Enter teacher ID :";
		cin>>trID;
		cout<<"Enter internal marks 1:";
		cin>>intm1;
		cout<<"Enter internal marks 2:";
		cin>>intm2;
		cout<<"Enter asmark1 :";
		cin>>asmark1;
		cout<<"Enter asmark2 :";
		cin>>asmark2;
		tint=intm1+intm2+asmark1+asmark2;
		cout<<"Enter endsem marks :";
		cin>>endsem;
		total=tint+endsem;
		compute();
	}
	void compute()
	{
		if(total>90)
			gpa=10;
		else if(80<total&&total<90)
			gpa=9;
		if(70<total&&total<80)
			gpa=8;
	}
	void viewGradecard()
	{
		cout<<"Student ID :"<<stdID<<endl;
		cout<<"Marks :"<<total<<endl;
		cout<<"GPA :"<<gpa<<endl;
	}
};

gradeCard gd[10];

int main()
{
	int i;
	teacher tr1;
	student st[10];
	for(i=0;i<10;i++)
	{
		st[i].getpersonalDetails();
		st[i].putpersonalDetails();
	}
	tr1.getpersonalDetails();
	tr1.putpersonalDetails();
	for(i=0;i<10;i++)
	{
		gd[i].enterMarks();
		gd[i].viewGradecard();
	}
}
		
