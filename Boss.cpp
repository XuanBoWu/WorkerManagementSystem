//
// Created by Alex Wu on 2020/11/13.
//

#include "Boss.h"
//构造函数实现
Boss::Boss(int id, string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

//显示老板信息
void Boss::showWorkerInfo(){
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：管理公司所有事务" << endl;
}
//获取老板岗位名称
string Boss::getDeptName(){
    return string("老板");
}