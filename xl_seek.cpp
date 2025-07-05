#include "xl_seek.h"
#include "ui_xl_seek.h"
#include"Line.h"
#include<QMessageBox>
#include<fstream>
extern int s1;
extern int s2;
extern vector<Line> v_l;
xl_seek::xl_seek(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::xl_seek)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    connect(ui->pb1,&QPushButton::clicked,this,&xl_seek::fh);
    connect(ui->pb2,&QPushButton::clicked,this,&xl_seek::sc);
    int xb_1=0;
    vector<Line2> vt=v_l[s1].get_s();
    for(unsigned int i=0; i<vt.size();i++){
        if(vt[i].get_xlzdid()==s2){
            xb_1=i;
            break;

        }
    }
    ui->l11->setText(QString::number(v_l[s1].get_b()));
    ui->l12->setText(QString::number(v_l[s1].get_s()[xb_1].get_zdid()));
    ui->l13->setText(QString::number(v_l[s1].get_s()[xb_1].get_xlzdid()));
    ui->l14->setText(QString::number(v_l[s1].get_s()[xb_1].get_szid()));
    ui->l15->setText(QString::number(v_l[s1].get_s()[xb_1].get_zdjj()));
    ui->l16->setText(QString::number(v_l[s1].get_s()[xb_1].get_xzid()));
    ui->l17->setText(QString::number(v_l[s1].get_s()[xb_1].get_ysjl()));
    ui->l18->setText(QString::number(v_l[s1].get_s()[xb_1].get_xldm()));
    ui->l19->setText(QString::number(v_l[s1].get_s()[xb_1].get_sfty()));
}
void xl_seek::fh(){
    this->close();

}
void xl_seek::sc(){
 vector<Line2> vt=v_l[s1].get_s();
    for(auto it=vt.begin();it!=vt.end();it++){
     if(it->get_xlzdid()==s2){
            vt.erase(it);
         break;
     }
    }
    v_l[s1].set_s(vt);
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
    QMessageBox::information(this,"提示","删除成功");


}

xl_seek::~xl_seek()
{
    delete ui;
}
