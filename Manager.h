#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include "Student.h"

class Manager
{
private:
    std::map<int,Student> StdList;

public:
    Manager(/* args */);

    //创建学生
    void addStudent();

    //修改学生信息
    void changeStudent();

    //删除学生
    void deleteStudent();

    //显示学生
    void showStudent();

    //保存文件
    void save();

    //加载文件
    void load();

    ~Manager();
};



#endif