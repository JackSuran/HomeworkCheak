#include "Student.h"

#include <iostream>

using std::cout, std::cin, std::endl, std::string;

void Student::setInfo(int choose)
{
    switch (choose)
    {
    case 1:
    case 2:
        cout << "请输入学生学号：";
        cin >> this->m_Number;
        if (choose != 1)
            break;
    case 3:
        cout << "请输入学生姓名：";
        cin >> this->m_Name;
        break;
    case 4:
        this->m_Is_Submit = true;
        break;
    case 5:
        this->m_Is_Called = true;
        break;
    case 6:
        this->m_Is_Submit = false;
        break;
    case 7:
        this->m_Is_Called = false;
        break;
    default:
        cout << "错误选项" << endl;
        break;
    }
}

void Student::setNumber(int number)
{
    this->m_Number = number;
}
void Student::setName(string name)
{
    this->m_Name = name;
}
void Student::setSubmit(bool is_submit)
{
    this->m_Is_Submit = is_submit;
}
void Student::setCalled(bool is_call)
{
    this->m_Is_Called = is_call;
}

void Student::showInfo(int flag)
{
    cout << "学号：" << this->m_Number
         << " 姓名：" << this->m_Name;
    if (flag == 1)
    {
        cout << " 是否提交：" << this->m_Is_Submit
             << " 是否提醒：" << this->m_Is_Called;
    }
}

int Student::getNumber()
{
    return this->m_Number;
}

string Student::getName()
{
    return this->m_Name;
}

bool Student::getSubmit()
{
    return this->m_Is_Submit;
}

bool Student::getCall()
{
    return this->m_Is_Called;
}

Student::Student() : m_Number(0), m_Name("张三"), m_Is_Submit(false), m_Is_Called(false)
{
}

Student::~Student()
{
}