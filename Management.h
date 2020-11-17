//
// Created by Alex Wu on 2020/11/12.
//

#ifndef WORKERMANAGEMENTSYSTEM_MANAGEMENT_H
#define WORKERMANAGEMENTSYSTEM_MANAGEMENT_H

#include <iostream>
using namespace std;


class Management {
public:
    //构造函数
    Management();

    //用户菜单
    void ShowMenu();
    //退出系统
    void exitSystem();


    //析构函数
    ~Management();

};


#endif //WORKERMANAGEMENTSYSTEM_MANAGEMENT_H
