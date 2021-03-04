#include <iostream>
#include "employee.h"
using namespace std;

int main()
{
    Employee x1(3, 15000), x2, x3(5, 50000), x4(2, 10000); //构建四个员工对象
    x2.setGrade(4);                                        //设定一些信息
    x2.setPay(30000);
    x3.setEmpNo(7);
    x4.setEmpNo(5);
    x1.getInformation(); //输出各员工信息
    x2.getInformation();
    x3.getInformation();
    x4.getInformation();
    return 0;
}