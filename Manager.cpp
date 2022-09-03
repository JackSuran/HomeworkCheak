#include "Manager.h"
#include <iostream>

using std::cout, std::cin, std::endl, std::string, std::map, std::pair, std::make_pair;

void Manager::addStudent(){
    int stuNumber;
    cout << "请输入要增加的学生人数：";
    cin >> stuNumber;

    Student stu;

    for(int i = 1; i <= stuNumber; ++i){
        cout<< "请输入第 "<<i<<" 名学生的信息"<<endl;
        stu.setInfo();
        if(this->StdList.find(stuNumber)!=this->StdList.end()){
            cout << "学号输入重复，重复学号为："<< stuNumber << endl;
            continue;
        }
        this->StdList.insert(make_pair(stu.getNumber(),stu));
    }

    cout<<"增加完成\n"<<endl;
}

void Manager::changeStudent(){
    int stuNumber = 0;
    int choose = 0;
    cout <<"1. 单个修改\n2. 多个修改\n";
    cin >> choose;

    if(choose == 1){
        cout << "请输入要修改学生的学号: "<<endl;
        cin >> stuNumber;
        if(this->StdList.find(stuNumber) == StdList.end()){
            cout<<"错误学号"<<endl;
            return;
        }
        else if(stuNumber > 0 && stuNumber <=64){
            this->StdList[stuNumber].showInfo(1);
            int choose;
            cout<<"请输入要修改的选项："<<endl
            <<"1. 姓名"<<endl
            <<"2. 提交状态"<<endl
            <<"3, 提醒状态"<<endl;
            if(choose > 3 || choose < 1){
                cout << "选项错误" <<endl;
                return;
            }
            this->StdList[stuNumber].setInfo(choose + 2);
        }
    }
    if(choose == 2){
        int choose = 0;
        cout<<"请输入要修改的选项："<<endl
        <<"1. 设定已提交"<<endl
        <<"2. 设定已提醒"<<endl
        <<"3. 清空提交状态"<<endl
        <<"4. 清空提醒状态"<<endl;
        if(choose > 4 || choose < 1){
            cout << "选项错误" <<endl;
            return;
        }
        cout << "请输入要修改学生的学号(输入0结束修改): "<<endl;

        if(choose == 3 || choose == 4){
            for(map<int,Student>::iterator it = this->StdList.begin(); it != this->StdList.end(); ++it){
                it->second.setInfo(choose + 3);
            }
            cout <<"修改完成"<<endl;
            return;
        }

        while(true){
            cin >> stuNumber;
            if(!stuNumber){
                cout << "修改完毕" << endl;
                return;
            }
            if(this->StdList.find(stuNumber) == StdList.end()){
                cout<<"错误学号: "<< stuNumber <<endl;
                continue;
            }
            else if(stuNumber > 0 && stuNumber <=64){
                this->StdList[stuNumber].showInfo(1);
                this->StdList[stuNumber].setInfo(choose + 3);
            }
        }
    }
}

void Manager::deleteStudent(){
    
}