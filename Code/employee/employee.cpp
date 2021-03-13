#include <iostream>
#include "employee.h"
using namespace std;

static int num = 1; //默认编号递增

Employee::Employee()
{
    individualEmpNo = num++;
    grade = 1;
    accumPay = 5000;
}

Employee::Employee(int g, int a) : grade(g), accumPay(a)
{
    individualEmpNo = num++;
}

Employee::~Employee()
{
    cout << "欢迎使用，再见！" << endl;
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