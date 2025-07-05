#include "gn_lc_seek.h"
#include "Train.h"
#include "ui_gn_lc_seek.h"
#include<fstream>
#include<QMessageBox>
extern vector<Train> v_t;
extern string seek_bm;
int lc_xb;
gn_lc_seek::gn_lc_seek(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gn_lc_seek)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    for(unsigned int i=0;i<=v_t.size()-1;i++){
        if(v_t[i].get_b()==seek_bm){
            lc_xb=i;
            break;
        }
    }
    connect(ui->pb1,&QPushButton::clicked,this,&gn_lc_seek::fh);
    connect(ui->pb2,&QPushButton::clicked,this,&gn_lc_seek::sc1);
    ui->lineEdit->setText(QString::fromStdString(seek_bm));
    ui->lineEdit_2->setText(QString::fromStdString(v_t[lc_xb].get_d()));
    ui->lineEdit_3->setText(QString::number(v_t[lc_xb].get_yn()));
}
void gn_lc_seek::fh(){
    this->close();
}
void gn_lc_seek::sc1(int a){
    a=lc_xb;
    v_t[a].set_b("-1");
    vector<Train> v_t1;
    for(auto&it:v_t){
        if(it.get_b()!="-1"){
            v_t1.push_back(it);
        }
    }
    v_t.clear();
    v_t=v_t1;
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
    QMessageBox::information(this,"提示","删除成功");


}


gn_lc_seek::~gn_lc_seek()
{
    delete ui;
}
