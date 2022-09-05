#include "Manager.h"
#include <iostream>

int main()
{
    using std::cout, std::cin, std::endl;
    system("chcp 65001");
    system("cls");

    Manager mg;
    int choose = 0;

    while (true)
    {
        cout << "1. 增加学生信息" << endl
             << "2. 删除同学信息" << endl
             << "3. 修改同学信息" << endl
             << "4. 显示同学信息" << endl;
        cout << "请输入选项(输入0退出): ";
        cin >> choose;

        switch (choose)
        {
        case 0:
            mg.save();
            cout << "欢迎下次使用" << endl;
            system("pause");
            exit(0);
        case 1:
            mg.addStudent();
            system("pause");
            system("cls");
            break;
        case 2:
            mg.deleteStudent();
            system("pause");
            system("cls");
            break;
        case 3:
            mg.changeStudent();
            system("pause");
            system("cls");
            break;
        case 4:
            mg.showStudent();
            system("pause");
            system("cls");
            break;
        default:
            cout << "输入错误" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}