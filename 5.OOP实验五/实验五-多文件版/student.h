#ifndef __STUDENT_H
#define __STUDENT_H
#include "m_head.h"

class Student {
private:
	string name;
	int gender;
	ll id;
	int bir_year;
	int bir_mon;
	int bir_day;
	string address;
	int score[7];
public:
	Student();
	Student(string , int , ll , int , int , int , string , int , int , int , int , int , int );
	Student(const Student&);
	string getname();
	string getadd();
	int getgender();
	void getbirthday();
	void getscore() ;
};


void Student_test();

#endif

