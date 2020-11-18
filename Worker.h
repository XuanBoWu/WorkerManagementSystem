//
// Created by Alex Wu on 2020/11/13.
//

#ifndef WORKERMANAGEMENTSYSTEM_WORKER_H
#define WORKERMANAGEMENTSYSTEM_WORKER_H
#include <iostream>
using namespace std;
class Worker {
    friend class Management;
public:

    virtual void showWorkerInfo() = 0;
    virtual string getDeptName() = 0;
    virtual ~Worker(){

    }

protected:
    int m_Id;
    string m_Name;
    int m_DeptId;

};


#endif //WORKERMANAGEMENTSYSTEM_WORKER_H
