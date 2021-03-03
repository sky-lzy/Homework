#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

static int num = 1;

class Employee
{
private:
    int individualEmpNo;
    int grade;
    int accumPay;
public:
    Employee();
    Employee(int g, int a);
    void setEmpNo(int i);
    void setGrade(int g);
    void setPay(int a);
    void getInformation();
};

Employee::Employee()
{
    individualEmpNo = ++num;
    grade = 1;
    accumPay = 5000;
}

Employee::Employee(int g, int a) : grade(g), accumPay(a)
{
    individualEmpNo = ++num;
}

void Employee::setEmpNo(int i)
{
    individualEmpNo = i;
}

void Employee::setGrade(int g)
{
    grade = g;
}

void Employee::setPay(int a)
{
    accumPay = a;
}

void Employee::getInformation()
{
    cout << "IndividualEmpNo = " << individualEmpNo << endl
         << "Grade = " << grade << endl
         << "AccumPay = " << accumPay << endl;
}

#endif