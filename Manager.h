//
// Created by Alex Wu on 2020/11/13.
//

#ifndef WORKERMANAGEMENTSYSTEM_MANAGER_H
#define WORKERMANAGEMENTSYSTEM_MANAGER_H
#include <iostream>
#include "Worker.h"
using namespace std;

class Manager: public Worker{
public:
    //构造函数
    Manager(int id, string name, int dId);


    //显示经理信息
    virtual void showWorkerInfo();
    //获取经理岗位名称
    virtual string getDeptName();
};


#endif //WORKERMANAGEMENTSYSTEM_MANAGER_H
