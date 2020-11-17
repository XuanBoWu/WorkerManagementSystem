//
// Created by Alex Wu on 2020/11/13.
//

#ifndef WORKERMANAGEMENTSYSTEM_BOSS_H
#define WORKERMANAGEMENTSYSTEM_BOSS_H

#include <iostream>
#include "Worker.h"
using namespace std;

class Boss: public Worker{
public:
    //构造函数
    Boss(int id, string name, int dId);


    //显示老板信息
    virtual void showWorkerInfo();
    //获取老板岗位名称
    virtual string getDeptName();
};


#endif //WORKERMANAGEMENTSYSTEM_BOSS_H
