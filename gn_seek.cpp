#include "gn_seek.h"
#include "ui_gn_seek.h"
#include"Station.h"
#include<fstream>
#include<QMessageBox>
extern vector<Station> v_s;
extern int seek_id;
int xb=0;
gn_seek::gn_seek(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gn_seek)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    for(unsigned int i=0;i<=v_s.size()-1;i++){
        if(v_s[i].get_id()==seek_id){
            xb=i;
            break;
        }
    }
    connect(ui->pb1,&QPushButton::clicked,this,&gn_seek::fh);
    connect(ui->pb2,&QPushButton::clicked,this,&gn_seek::sc);
    ui->lineEdit->setText(QString::number(seek_id));
    ui->lineEdit_2->setText(QString::number(v_s[xb].get_l()));
    ui->lineEdit_3->setText(QString::fromStdString(v_s[xb].get_mc()));
}
void gn_seek::fh(){
    this->close();

}
void gn_seek::sc(int a){
    a=xb;
   v_s[a].set_id(-1);
    vector<Station> v_s2;
   for(auto &it:v_s){
        if(it.get_id()!=-1){
           v_s2.push_back(it);
        }
   }
   v_s.clear();
   v_s=v_s2;
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
   QMessageBox::information(this,"提示","删除成功");
}
gn_seek::~gn_seek()
{
    delete ui;
}
