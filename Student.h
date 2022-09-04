#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    int m_Number;
    std::string m_Name;
    bool m_Is_Submit;
    bool m_Is_Called;

public:
    Student(/* args */);

    //设置信息
    void setInfo(int choose = 1);

    void setNumber(int num);

    void setName(std::string name);

    void setSubmit(bool is_submit);
    
    void setCalled(bool is_call);

    //显示信息
    void showInfo(int flag = 0);

    //获取学号
    int getNumber();

    //获取姓名
    std::string getName();

    //获取提交状态
    bool getSubmit();

    //获取提醒状态
    bool getCall();

    ~Student();
};

#endif