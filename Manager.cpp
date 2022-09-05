#include "Manager.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "path.h"

using std::cout, std::cin, std::endl, std::string, std::vector, std::map, std::pair, std::make_pair, std::ifstream, std::ofstream, std::ios;

void Manager::addStudent()
{
    int stuNumber;
    cout << "请输入要增加的学生人数：";
    cin >> stuNumber;

    Student stu;

    for (int i = 1; i <= stuNumber; ++i)
    {
        cout << "请输入第 " << i << " 名学生的信息" << endl;
        stu.setInfo(1);
        if (this->StdList.find(stuNumber) == this->StdList.end())
        {
            cout << "学号输入重复，重复学号为：" << stuNumber << endl;
            continue;
        }
        this->StdList.insert(make_pair(stu.getNumber(), stu));
    }

    cout << "增加完成\n"
         << endl;
}

void Manager::changeStudent()
{
    int stuNumber = 0;
    char choose = '0';
    cout << "1. 单个修改\n2. 多个修改\n";
    cin >> choose;

    if (choose == '1')
    {
        cout << "请输入要修改学生的学号: " << endl;
        cin >> stuNumber;
        if (this->StdList.find(stuNumber) == StdList.end())
        {
            cout << "错误学号" << endl;
            return;
        }
        else if (stuNumber > 0)
        {
            this->StdList[stuNumber].showInfo(1);
            char choose;
            cout << endl
                 << "1. 姓名" << endl
                 << "2. 提交状态" << endl
                 << "3, 提醒状态" << endl
                 << "请输入要修改的选项：" << endl;
            cin >> choose;
            if (choose > '3' || choose < '1')
            {
                cout << "选项错误" << endl;
                return;
            }
            this->StdList[stuNumber].setInfo(choose - '0' + 2);
            cout << "修改完成" << endl;
        }
    }
    else if (choose == '2')
    {
        char choose = '0';

        cout << "1. 设定已提交" << endl
             << "2. 设定已提醒" << endl
             << "3. 清空提交状态" << endl
             << "4. 清空提醒状态" << endl
             << "请输入要修改的选项：";
        cin >> choose;

        if (choose > '4' || choose < '1')
        {
            cout << "选项错误" << endl;
            return;
        }
        cout << "请输入要修改学生的学号(输入0结束修改): " << endl;

        if (choose == '3' || choose == '4')
        {
            for (map<int, Student>::iterator it = this->StdList.begin(); it != this->StdList.end(); ++it)
            {
                it->second.setInfo(choose - '0' + 3);
            }
            cout << "修改完成" << endl;
            return;
        }

        cout << "请输入要修改的学生学号: ";
        while (true)
        {
            cin >> stuNumber;
            if (!stuNumber)
            {
                cout << "修改完毕" << endl;
                return;
            }
            if (this->StdList.find(stuNumber) == StdList.end())
            {
                cout << "错误学号: " << stuNumber << endl;
                continue;
            }
            else if (stuNumber > 0 && stuNumber <= 64)
            {
                this->StdList[stuNumber].showInfo();
                cout << endl;
                this->StdList[stuNumber].setInfo(choose - '0' + 3);
            }
        }
    }
    else
    {
        cout << "选项输入错误" << endl;
        return;
    }
}

void Manager::deleteStudent()
{
    cout << "1. 通过名字删除" << endl
         << "2. 通过学号删除(按0停止)" << endl;

    char choose;
    cin >> choose;

    if (choose == '1')
    {
        string name;
        cout << "输入要删除的学生姓名：";
        cin >> name;
        for (map<int, Student>::iterator it = this->StdList.begin(); it != this->StdList.end(); ++it)
        {
            if (it->second.getName() == name)
            {
                it->second.showInfo();
                this->StdList.erase(it);
                cout << "\n删除完毕" << endl;
                return;
            }
        }
    }
    else if (choose == '2')
    {
        int stuNumber;
        cout << "请输入学号：";
        while (true)
        {
            cin >> stuNumber;
            if (!stuNumber)
            {
                cout << "删除完毕" << endl;
                return;
            }
            if (this->StdList.find(stuNumber) == StdList.end())
            {
                cout << "错误学号: " << stuNumber << endl;
                continue;
            }
            else if (stuNumber > 0)
            {
                this->StdList[stuNumber].showInfo();
                cout << endl;
                this->StdList.erase(stuNumber);
            }
        }
    }
    else
    {
        cout << "选项错误" << endl;
        return;
    }
}

void Manager::showStudent()
{
    char choose;
    cout << "1. 查看全部同学" << endl
         << "2. 查看未提交" << endl
         << "3. 查看已提醒" << endl
         << "请输入查找的选项：";
    cin >> choose;

    if (choose == '1')
    {
        for (map<int, Student>::iterator it = this->StdList.begin(); it != this->StdList.end(); ++it)
        {
            it->second.showInfo(1);
            cout << endl;
        }
    }
    else if (choose == '2')
    {
        for (map<int, Student>::iterator it = this->StdList.begin(); it != this->StdList.end(); ++it)
        {
            if (!it->second.getSubmit())
            {
                it->second.showInfo();
                cout << endl;
            }
        }
    }
    else if (choose == '3')
    {
        for (map<int, Student>::iterator it = this->StdList.begin(); it != this->StdList.end(); ++it)
        {
            if (it->second.getCall())
            {
                it->second.showInfo();
                cout << endl;
            }
        }
    }
    else
    {
        cout << "选项错误" << endl;
        return;
    }
    cout << "显示完毕" << endl;
    return;
}

void Manager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out | ios::trunc);

    for (map<int, Student>::iterator it = this->StdList.begin(); it != this->StdList.end(); ++it)
    {
        ofs << it->first << ","
            << it->second.getName() << ","
            << it->second.getSubmit() << ","
            << it->second.getCall() << "," << endl;
    }
    cout << "保存完毕" << endl;
    ofs.close();

    return;
}

void Manager::load()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        ifs.close();
        this->save();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "数据为空" << endl;
        ifs.close();
        return;
    }
    ifs.putback(ch);

    string data;
    vector<string> buf;
    Student stu;

    while (ifs >> data)
    {
        int pos = -1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);
            if (pos == -1)
            {
                break;
            }
            buf.push_back(data.substr(start, pos - start));
            start = pos + 1;
        }
        stu.setNumber(atoi(buf[0].c_str()));
        stu.setName(buf[1]);
        stu.setSubmit(atoi(buf[2].c_str()));
        stu.setCalled(atoi(buf[3].c_str()));
        buf.clear();

        this->StdList.insert(make_pair(stu.getNumber(), stu));
    }
    cout << "加载完毕" << endl;
}

Manager::Manager(/* args */)
{
    this->StdList.clear();
    this->load();
}

Manager::~Manager()
{
    this->save();
    this->StdList.clear();
}