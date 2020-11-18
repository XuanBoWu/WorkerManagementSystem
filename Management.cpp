//
// Created by Alex Wu on 2020/11/12.
//

#include "Management.h"


void Management::ShowMenu(){
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void Management::exitSystem(){
    cout << "欢迎下次使用。" << endl;
    system("pause");
//    exit(0);
}

//添加员工信息
void Management::add_Emp() {
    cout << "输入要添加职工数量：";
    int addNum;
    cin >> addNum;
    cout<< "----------------------------" << endl;

    if(addNum > 0){
        int newSize = addNum + this->m_EmpNum;
        Worker ** newSpace = new Worker*[newSize];

        if(this->m_EmpArray != NULL){
            for(int i = 0 ; i < m_EmpNum ; i++){
                newSpace[i] = m_EmpArray[i];
            }
        }

        for(int i = 0 ; i < addNum ; i++){
            int id;
            string name;
            int dSelect;

            cout << "添加第" << i+1 << "个新职工的编号：";
            cin >> id;

            cout << "添加第" << i+1 << "个新职工的姓名：";
            cin >> name;


            cout << "1 - 普通职工" << endl;
            cout << "2 - 经理" << endl;
            cout << "3 - 老板" << endl;
            cout << "请选择新职工的职位：" ;
            do{
                cin >> dSelect;
                if(dSelect > 3 || dSelect < 1)
                    cout << "输入有误请重新输入：";
            } while (dSelect > 3 || dSelect < 1);



            Worker * worker = NULL;

            switch (dSelect) {
                case 1 :
                    worker = new Employees(id, name, dSelect);
                    break;
                case 2 :
                    worker = new Manager(id, name, dSelect);
                    break;
                case 3 :
                    worker = new Boss(id, name, dSelect);
                    break;
                default:
                    cout << "输入有误。" << endl;
                    break;
            }

            newSpace[this->m_EmpNum + i] = worker;
            cout<< "----------------------------" << endl;
        }

        delete m_EmpArray;
        m_EmpArray = newSpace;
        this->m_FileIsEmpty = false;
        m_EmpNum = newSize;
        cout << "成功添加" << addNum << "个职工！" <<endl;
        //保存到文件中

        this->save();
    } else {
        cout << "输入错误" << endl;
    }



    system("pause");
    system("cls");

}
//文件写入函数
void Management::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for(int i = 0 ; i < this->m_EmpNum ; i++){
        ofs << this->m_EmpArray[i]->m_Id << " "
        << this->m_EmpArray[i]->m_Name << " "
        << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

//统计文件中的人数
int Management::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while(ifs >> id && ifs >> name && ifs >> dId){
        num++;
    }
    return num;
}

//初始化职工数组
void Management::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int index = 0;
    while( ifs >> id && ifs >> name && ifs >> dId){
        Worker * worker = NULL;

        switch (dId) {
            case 1 :
                worker = new Employees(id, name, dId);
                break;
            case 2 :
                worker = new Manager(id, name, dId);
                break;
            case 3 :
                worker = new Boss(id, name, dId);
                break;
            default:
                cout << "输入有误。" << endl;
                break;
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}



//显示职工
void Management::show_Emp(){
    if(this->m_FileIsEmpty){
        cout << "记录为空！" << endl;
        system("pause");
        system("cls");
        return ;
    } else {
        for(int i = 0 ; i < this->m_EmpNum ; i++){
            this->m_EmpArray[i]->showWorkerInfo();
        }
    }
    system("pause");
    system("cls");
}


//职工编号是否存在函数
int Management::IsExist(int id){
    int index = -1;
    if(this->m_FileIsEmpty){
        cout << "记录为空！" << endl;
        return index;
    }

    for(int i = 0 ; i < this->m_EmpNum ; i++){
        if(this->m_EmpArray[i]->m_Id == id){
            index = i;
            break;
        }
    }
    return index;
}

//职工姓名是否存在函数
int Management::IsExist(string name){
    int index = -1;
//    Worker * result = NULL;
    if(this->m_FileIsEmpty){
        cout << "记录为空！" << endl;
        return index;
    }

    for(int i = 0 ; i < this->m_EmpNum ; i++){
        if(this->m_EmpArray[i]->m_Name == name){
            index = i;
            break;
        }
    }
    return index;
}


//删除职工
void Management::del_Emp(){
    if(this->m_FileIsEmpty){
        cout << "记录为空！" << endl;
        system("pause");
        system("cls");
        return ;
    }
    int del_Id;

    cout << "输入要删除的职工编号：";
    cin >> del_Id;
    int index = this->IsExist(del_Id);
    if(index != -1){ //职工存在，删除该职工
        for(int i = index ; i < this->m_EmpNum ; i++){
            this->m_EmpArray[i] = this->m_EmpArray[i+1];
        }
        this->m_EmpNum--;
        this->save(); //数据同步到文件中
        cout << "删除成功。" << endl;
    } else {
        cout << "删除失败，没有该职工信息。" << endl;
    }

    system("pause");
    system("cls");
}

//修改职工信息
void Management::mod_Emp(){
    if(this->m_FileIsEmpty){
        cout << "记录为空！" << endl;
        system("pause");
        system("cls");
        return ;
    }
    int id;
    cout << "请输入要更改的职工编号:";
    cin >> id;
    int index = this->IsExist(id);

    if(index != -1){
        delete this->m_EmpArray[index];
        int id;
        string name;
        int dSelect;

        cout << "输入职工的编号：";
        cin >> id;

        cout << "输入职工的姓名：";
        cin >> name;


        cout << "1 - 普通职工" << endl;
        cout << "2 - 经理" << endl;
        cout << "3 - 老板" << endl;
        cout << "请选择职工的职位：" ;
        do{
            cin >> dSelect;
            if(dSelect > 3 || dSelect < 1)
                cout << "输入有误请重新输入：";
        } while (dSelect > 3 || dSelect < 1);



        Worker * worker = NULL;

        switch (dSelect) {
            case 1 :
                worker = new Employees(id, name, dSelect);
                break;
            case 2 :
                worker = new Manager(id, name, dSelect);
                break;
            case 3 :
                worker = new Boss(id, name, dSelect);
                break;
            default:
                cout << "输入有误。" << endl;
                break;
        }
        this->m_EmpArray[index] = worker;
        this->save();
        cout << "更改成功。" << endl;
    } else {
        cout << "查无此人。" << endl;
    }



    system("pause");
    system("cls");
}

//查找职工
void Management::find_Emp(){
    if(this->m_FileIsEmpty){
        cout << "记录为空！" << endl;
        system("pause");
        system("cls");
        return ;
    }
    cout << "1 - 按编号查找" << endl;
    cout << "2 - 按姓名查找" << endl;
    cout << "请选择查找方式：";
    int select;
    do{
        cin >> select;

        if(select == 1){
            int id;
            cout << "请输入要查找的职工编号:";
            cin >> id;
            int index = this->IsExist(id);
            if(index != -1){
                cout << "查找成功：";
                cout << "职工编号为：" << this->m_EmpArray[index]->m_Id << " 职工信息如下：" << endl;
                this->m_EmpArray[index]->showWorkerInfo();
            } else {
                cout << "查找失败，查无此人" << endl;
            }
        } else if(select == 2){
            string name;
            cout << "请输入要查找的职工姓名:";
            cin >> name;
            int index = this->IsExist(name);
            if(index != -1){
                cout << "查找成功：";
                cout << "职工编号为：" << this->m_EmpArray[index]->m_Id << " 职工信息如下：" << endl;
                this->m_EmpArray[index]->showWorkerInfo();
            } else {
                cout << "查找失败，查无此人" << endl;
            }

        } else {
            cout << "输入错误请重新输入：";
        }
    } while (! (select == 1 || select == 2));

    system("pause");
    system("cls");
}


//排序职工
void Management::sort_Emp(){
    if(this->m_FileIsEmpty){
        cout << "记录为空！" << endl;
        system("pause");
        system("cls");
        return ;
    }

    cout << "1 - 按职工编号升序排列" << endl;
    cout << "2 - 按职工编号降序排列" << endl;
    cout << "请选择排序方式：";
    int select;
    cin >> select;

    for(int i = 0 ; i < this->m_EmpNum ; i++){
        int minOrMax = i;
        for(int j = i + 1 ; j < this->m_EmpNum; j++){
            if(select==1){
                if(this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id){
                    minOrMax = j;
                }
            } else if(select==2){
                if(this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id){
                    minOrMax = j;
                }
            }

        }

        if(i != minOrMax){
            Worker * temp = this->m_EmpArray[i];
            this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
            this->m_EmpArray[minOrMax] = temp;
        }
    }

    cout << "排序完成。结果如下：" << endl;
    this->save();
    this->show_Emp();

    system("pause");
    system("cls");
}

//清空职工信息
void Management::clean_File(){
    if(this->m_FileIsEmpty){
        cout << "记录已经为空！" << endl;
        system("pause");
        system("cls");
        return ;
    }

    cout << "确认清空？" << endl;
    cout << "输入（yes or no）:";
    string select;

    cin >> select;
    if(select == "yes"){
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if(this->m_EmpArray != NULL){
            for(int i = 0 ; i < this->m_EmpNum ; i++){
                if(this->m_EmpArray[i] != NULL){
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete [] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "职工信息清除完成。" << endl;
    } else{
        cout << "取消职工信息清除，返回系统。" << endl;
    }

    system("pause");
    system("cls");
}

//构造函数的实现
Management::Management() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    //如果文件不存在
    if( !ifs.is_open() ){
//        cout << "文件不存在。" << endl;
        //初始化员工人数
        this->m_EmpNum = 0;
        //初始化员工数组指针
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;//初始化文件为空标志
        ifs.close();
        return ;
    }
    //文件存在且为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
//        cout << "文件为空。" << endl;
        //初始化员工人数
        this->m_EmpNum = 0;
        //初始化员工数组指针
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;//初始化文件不为空标志
        ifs.close();
        return ;
    }
    //文件存在不为空
    int num = this->get_EmpNum();
//    cout << "职工人数为" << num << "人" << endl;
    this->m_EmpNum = num;
    //开辟空间
    this->m_EmpArray = new Worker * [this->m_EmpNum];
    this->init_Emp();
}


//析构函数的实现
Management::~Management() {
    if(this->m_EmpArray != NULL){
        delete [] this->m_EmpArray;
        m_EmpArray  = NULL;
    }
}