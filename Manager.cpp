//
// Created by Alex Wu on 2020/11/13.
//

#include "Manager.h"
//构造函数实现
Manager::Manager(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

//显示经理信息
void Manager::showWorkerInfo(){
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}
//获取经理岗位名称
string Manager::getDeptName(){
    return string("经理");
}