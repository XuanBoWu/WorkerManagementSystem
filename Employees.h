//
// Created by Alex Wu on 2020/11/13.
//

#ifndef WORKERMANAGEMENTSYSTEM_EMPLOYEES_H
#define WORKERMANAGEMENTSYSTEM_EMPLOYEES_H
#include <iostream>
#include "Worker.h"
using namespace std;


class Employees: public Worker {
public:
    //构造函数
    Employees(int id, string name, int dId);
    //显示员工信息
    virtual void showWorkerInfo();
    //获取员工岗位名称
    virtual string getDeptName();

};


#endif //WORKERMANAGEMENTSYSTEM_EMPLOYEES_H
