//
// Created by Alex Wu on 2020/11/13.
//

#include "Employees.h"

//构造函数实现
Employees::Employees(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

//显示员工信息
void Employees::showWorkerInfo(){
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成经理交给的任务" << endl;
}
//获取员工岗位名称
string Employees::getDeptName(){
    return string("员工");
}