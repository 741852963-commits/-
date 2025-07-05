#include "xl_zengjia.h"
#include "ui_xl_zengjia.h"
#include"Line.h"
#include<QMessageBox>
#include<fstream>
extern vector<Line> v_l;
xl_zengjia::xl_zengjia(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::xl_zengjia)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    connect(ui->pb1,&QPushButton::clicked,this,&xl_zengjia::fh);
    connect(ui->PB_baocun,&QPushButton::clicked,this,&xl_zengjia::baocun);

}

xl_zengjia::~xl_zengjia()
{
    delete ui;
}
void xl_zengjia ::baocun(){
    int s1=ui->l11->text().toInt();
     int s2=ui->l12->text().toInt();
      int s3=ui->l13->text().toInt();
       int s4=ui->l14->text().toInt();
        int  s5=ui->l15->text().toInt();
         int  s6=ui->l16->text().toInt();
          int  s7=ui->l17->text().toInt();
           int  s8=ui->l18->text().toInt();
           int  s9=ui->l19->text().toInt();
           Line2 a(s3,s2,s4,s5,s6,s7,s8,s9);
           vector<Line2> vt=v_l[s1].get_s();
           for(auto it:vt){
               if(it.get_xlzdid()==s3){
                   QMessageBox::information(this,"警告","重复添加");
                   return;
               }

           }
           v_l[s1].set_sj(a);
           ofstream ouf("xl.txt");
           if(!ouf.is_open()){
               qDebug()<<"打开失败";
               return ;
           }
           ouf<<"yyxlbm,zdid,xlzdid,Q_zdid,yqzdjjl,H_zdid,ysjl,xldm,sfytk"<<endl;
           ouf<<"运营线路编码,站点id,线路站点id,上一站id,运营线路站间距离 ,下一站id,运输距离,线路代码,是否要停靠"<<endl;
           for(auto it=v_l.begin();it!=v_l.end();it++){
               if(it->get_b()!=0)
                   for(auto &it2:it->get_s()){
                       ouf<<it->get_b()<<","<<it2.get_zdid()<<","<<it2.get_xlzdid()<<","<<it2.get_szid()<<","<<it2.get_zdjj()<<","<<it2.get_xzid()<<","<<it2.get_ysjl()<<","<<it2.get_xldm()<<","<<it2.get_sfty()<<endl;
                   }
           }
           ouf.close();
           QMessageBox::information(this,"提示","添加成功");


}
void xl_zengjia::fh(){
    this->close();

}
