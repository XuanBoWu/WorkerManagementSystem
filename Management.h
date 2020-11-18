//
// Created by Alex Wu on 2020/11/12.
//

#ifndef WORKERMANAGEMENTSYSTEM_MANAGEMENT_H
#define WORKERMANAGEMENTSYSTEM_MANAGEMENT_H

#include <iostream>
#include <fstream>
#include "Worker.h"
#include "Employees.h"
#include "Manager.h"
#include "Boss.h"

#define FILENAME "empFile.txt"


using namespace std;


class Management {
private:
    //文件存在标志
    bool m_FileIsEmpty;
    //员工数组指针
    Worker ** m_EmpArray;
    //员工人数
    int m_EmpNum;
public:
    //构造函数
    Management();

    //用户菜单
    void ShowMenu();
    //退出系统
    void exitSystem();
    //添加职工信息
    void add_Emp();
    //往文件写入
    void save();
    //统计文件中的人数
    int get_EmpNum();
    //初始化职工数组
    void init_Emp();
    //显示职工
    void show_Emp();
    //职工是否存在函数
    int IsExist(int id);
    //删除职工
    void del_Emp();
    //析构函数
    ~Management();

};


#endif //WORKERMANAGEMENTSYSTEM_MANAGEMENT_H
