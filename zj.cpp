#include "zj.h"
#include "ui_zj.h"
#include"Station.h"
#include<QMessageBox>
#include<fstream>
extern vector<Station> v_s;
zj::zj(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::zj)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->PB_baocun,&QPushButton::clicked,this,&zj::baocun);
    connect(ui->pb1,&QPushButton::clicked,this,&zj::fh);
}

void zj:: baocun(){
    QString a1=ui->L1->text();
    QString a2=ui->L2->text();
    QString a3=ui->L3->text();
    int z_id=a1.toInt();
    int z_lx=a2.toInt();
    string z_mc=a3.toStdString();
    for(auto &it:v_s){
        if(z_id==it.get_id()){
            QMessageBox::information(this,"提示","ID重复");
            return;
        }
        if(z_mc==it.get_mc()){
            QMessageBox::information(this,"提示","名称重复");
            return;
        }

    }
    v_s.emplace_back(z_id,z_lx,z_mc,-1,"","","");
    ofstream ouf("zd.txt");
    if(!ouf.is_open()){
        qDebug()<<"打开失败";
        return ;
    }
    ouf<<"zdid,,,lxid,,,ysfsbm,zdmc"<<endl;
    for(auto &it:v_s){
        string a1="NULL",a2="NULL",a3="NULL",a4="NULL",a5="1";
        ouf<<it.get_id()<<","<<a1<<","<<a2<<","<<it.get_l()<<","<<a3<<","<<a4<<","<<a5<<","<<it.get_mc()<<endl;
    }
    ouf.close();
    QMessageBox::information(this,"提示","添加成功");

}
void zj::fh(){
    this->close();

}
zj::~zj()
{
    delete ui;
}
