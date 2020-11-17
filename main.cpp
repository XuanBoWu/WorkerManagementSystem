#include <iostream>
#include "Management.h"
#include "Worker.h"
#include "Employees.h"
#include "Manager.h"
#include "Boss.h"

using namespace std;

void test01(){
    //测试员工类
    Worker *worker = NULL;
    worker = new Employees(1, "张三", 1);
    worker->showWorkerInfo();
    delete worker;

    //测试经理类
    worker = new Manager(2, "王五", 2);
    worker->showWorkerInfo();
    delete worker;

    //测试员工类
    worker = new Boss(3, "赵柳", 3);
    worker->showWorkerInfo();
    delete worker;

}

int main() {
    Management mg;
    int choose = 8;

    while (true){
        //显示菜单
        mg.ShowMenu();
        cout << "请输入选择：";
        cin >> choose;

        switch (choose) {
            case 0://退出系统
                mg.exitSystem();
                break;
            case 1://添加职工
                break;
            case 2://显示职工
                break;
            case 3://删除职工
                break;
            case 4://修改职工
                break;
            case 5://查找职工
                break;
            case 6://排序职工
                break;
            case 7://清空文件
                break;
            default:
                system("clear");
                break;
        }

    }

    system("pause");

    return 0;
}
