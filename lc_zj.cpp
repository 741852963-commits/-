#include "lc_zj.h"
#include "Train.h"
#include "ui_lc_zj.h"
#include<string>
#include<QMessageBox>
#include<fstream>
extern vector<Train> v_t;
lc_zj::lc_zj(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::lc_zj)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->PB_baocun,&QPushButton::clicked,this,&lc_zj::baocun);
    connect(ui->pb1,&QPushButton::clicked,this,&lc_zj::fh);
}
void lc_zj:: baocun(){
    QString a1=ui->L1->text();
    QString a2=ui->L2->text();
    QString a3=ui->L3->text();
    std::string lc_bm=a1.toStdString();
    std::string lc_dm=a2.toStdString();
    int lc_yn=a3.toInt();
    for(auto &it:v_t){
        if(lc_bm==it.get_b()){
            QMessageBox::information(this,"提示","编码重复");
            return;
        }
        if(lc_dm==it.get_d()){
            QMessageBox::information(this,"提示","代码重复");
            return;
        }

    }
    v_t.emplace_back(lc_bm,lc_dm,lc_yn);
    ofstream ouf("lc.txt");
    if(!ouf.is_open()){
        qDebug()<<"打开失败";
        return ;
    }
    ouf<<"lcbm,lcdm,lcyn"<<endl;
    for(auto &it:v_t){
        ouf<<it.get_b()<<","<<it.get_d()<<","<<it.get_yn()<<endl;
    }
    ouf.close();
    QMessageBox::information(this,"提示","添加成功");
}
void lc_zj::fh(){
    this->close();

}

lc_zj::~lc_zj()
{
    delete ui;
}
