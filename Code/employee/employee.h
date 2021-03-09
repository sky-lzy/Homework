#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

static int num = 1; //默认编号递增

class Employee //定义Employee类
{
private:
    int individualEmpNo; //员工编号
    int grade;           //员工等级
    int accumPay;        //员工工资
public:
    Employee();             //默认构造函数
    Employee(int g, int a); //构造员工
    ~Employee();            //析构函数
    void setEmpNo(int i);   //设定编号
    void setGrade(int g);   //设定等级
    void setPay(int a);     //设定工资
    void getInformation();  //获取信息
};

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

#endif