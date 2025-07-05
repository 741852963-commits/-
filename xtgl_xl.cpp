#include "xtgl_xl.h"
#include "ui_xtgl_xl.h"
#include<QMessageBox>
#include<fstream>
#include<sstream>
#include"Line.h"
#include"Line2.h"
#include"xl_zengjia.h"
#include"xl_seek.h"
extern vector<Line> v_l;
int pg2=3;
int xlnum=1;
int s1,s2;
xtgl_xl::xtgl_xl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::xtgl_xl)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    connect(ui->pb_seek,&QPushButton::clicked,this,&xtgl_xl::seek);
    connect(ui->shangye,&QPushButton::clicked,this,&xtgl_xl::shangye);
    connect(ui->xiaye,&QPushButton::clicked,this,&xtgl_xl::xiaye);
    connect(ui->PB_zj,&QPushButton::clicked,this,&xtgl_xl::zengjia);
    connect(ui->pbsx,&QPushButton::clicked,this,&xtgl_xl::sx);
    connect(ui->pbqh,&QPushButton::clicked,this,&xtgl_xl::qh);
    ifstream inf("xl.txt");
    if (!inf.is_open()) {

        qDebug() << "文件打开失败，请检查路径和权限";
        return;
    }
    string s;
    getline(inf,s);
    getline(inf,s);
    while(getline(inf,s)){
        for(auto &c:s){
            if(c==','){
                c=' ';
            }
        }
        stringstream ss(s);
        int a1,a2,a3,a4,a5,a6,a7,a8,a9;
        ss>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9;
        Line2 a(a3,a2,a4,a5,a6,a7,a8,a9);
        v_l[a1].set_b(a1);
        v_l[a1].set_sj(a);
    }
    inf.close();
    ui->l11->setText(QString::number(v_l[1].get_b()));
    ui->l12->setText(QString::number(v_l[1].get_s()[0].get_zdid()));
    ui->l13->setText(QString::number(v_l[1].get_s()[0].get_xlzdid()));
    ui->l14->setText(QString::number(v_l[1].get_s()[0].get_szid()));
    ui->l15->setText(QString::number(v_l[1].get_s()[0].get_zdjj()));
    ui->l16->setText(QString::number(v_l[1].get_s()[0].get_xzid()));
    ui->l17->setText(QString::number(v_l[1].get_s()[0].get_ysjl()));
    ui->l18->setText(QString::number(v_l[1].get_s()[0].get_xldm()));
    ui->l19->setText(QString::number(v_l[1].get_s()[0].get_sfty()));
    ui->l21->setText(QString::number(v_l[1].get_b()));
    ui->l22->setText(QString::number(v_l[1].get_s()[1].get_zdid()));
    ui->l23->setText(QString::number(v_l[1].get_s()[1].get_xlzdid()));
    ui->l24->setText(QString::number(v_l[1].get_s()[1].get_szid()));
    ui->l25->setText(QString::number(v_l[1].get_s()[1].get_zdjj()));
    ui->l26->setText(QString::number(v_l[1].get_s()[1].get_xzid()));
    ui->l27->setText(QString::number(v_l[1].get_s()[1].get_ysjl()));
    ui->l28->setText(QString::number(v_l[1].get_s()[1].get_xldm()));
    ui->l29->setText(QString::number(v_l[1].get_s()[1].get_sfty()));
    ui->l31->setText(QString::number(v_l[1].get_b()));
    ui->l32->setText(QString::number(v_l[1].get_s()[2].get_zdid()));
    ui->l33->setText(QString::number(v_l[1].get_s()[2].get_xlzdid()));
    ui->l34->setText(QString::number(v_l[1].get_s()[2].get_szid()));
    ui->l35->setText(QString::number(v_l[1].get_s()[2].get_zdjj()));
    ui->l36->setText(QString::number(v_l[1].get_s()[2].get_xzid()));
    ui->l37->setText(QString::number(v_l[1].get_s()[2].get_ysjl()));
    ui->l38->setText(QString::number(v_l[1].get_s()[2].get_xldm()));
    ui->l39->setText(QString::number(v_l[1].get_s()[2].get_sfty()));

}
void xtgl_xl::seek(){
     s1=ui->sou->text().toInt();
     s2=ui->sou2->text().toInt();

    bool f=false;
    for(auto &it:v_l){
        if(it.get_b()==s1){
            f=true;
            break;
        }
    }
    if(!f){
         QMessageBox::information(this,"警告","没有该线路编码");
        return ;
    }
    if(f){
        bool f2=false;
        for(auto &it:v_l[s1].get_s()){
            if(it.get_xlzdid()==s2){
                f2=true;
                break;
            }

        }
        if(!f2){
            QMessageBox::information(this,"警告","没有该线路id");
            return ;

        }
        if(f2){
            this->hide();
            xl_seek *an=new xl_seek;
            connect(an,&xl_seek::destroyed,this,&xtgl_xl::show);
            an->show();
        }

    }


}
void xtgl_xl::shangye(int a){
    a=pg2;
    if(a-3<0){
        QMessageBox::information(this,"警告","已是第一页");
        return;
    }
    ui->l11->setText(QString::number(v_l[xlnum].get_b()));
    ui->l12->setText(QString::number(v_l[xlnum].get_s()[a-3].get_zdid()));
    ui->l13->setText(QString::number(v_l[xlnum].get_s()[a-3].get_xlzdid()));
    ui->l14->setText(QString::number(v_l[xlnum].get_s()[a-3].get_szid()));
    ui->l15->setText(QString::number(v_l[xlnum].get_s()[a-3].get_zdjj()));
    ui->l16->setText(QString::number(v_l[xlnum].get_s()[a-3].get_xzid()));
    ui->l17->setText(QString::number(v_l[xlnum].get_s()[a-3].get_ysjl()));
    ui->l18->setText(QString::number(v_l[xlnum].get_s()[a-3].get_xldm()));
    ui->l19->setText(QString::number(v_l[xlnum].get_s()[a-3].get_sfty()));
    ui->l21->setText(QString::number(v_l[xlnum].get_b()));
    ui->l22->setText(QString::number(v_l[xlnum].get_s()[a-2].get_zdid()));
    ui->l23->setText(QString::number(v_l[xlnum].get_s()[a-2].get_xlzdid()));
    ui->l24->setText(QString::number(v_l[xlnum].get_s()[a-2].get_szid()));
    ui->l25->setText(QString::number(v_l[xlnum].get_s()[a-2].get_zdjj()));
    ui->l26->setText(QString::number(v_l[xlnum].get_s()[a-2].get_xzid()));
    ui->l27->setText(QString::number(v_l[xlnum].get_s()[a-2].get_ysjl()));
    ui->l28->setText(QString::number(v_l[xlnum].get_s()[a-2].get_xldm()));
    ui->l29->setText(QString::number(v_l[xlnum].get_s()[a-2].get_sfty()));
    ui->l31->setText(QString::number(v_l[xlnum].get_b()));
    ui->l32->setText(QString::number(v_l[xlnum].get_s()[a-1].get_zdid()));
    ui->l33->setText(QString::number(v_l[xlnum].get_s()[a-1].get_xlzdid()));
    ui->l34->setText(QString::number(v_l[xlnum].get_s()[a-1].get_szid()));
    ui->l35->setText(QString::number(v_l[xlnum].get_s()[a-1].get_zdjj()));
    ui->l36->setText(QString::number(v_l[xlnum].get_s()[a-1].get_xzid()));
    ui->l37->setText(QString::number(v_l[xlnum].get_s()[a-1].get_ysjl()));
    ui->l38->setText(QString::number(v_l[xlnum].get_s()[a-1].get_xldm()));
    ui->l39->setText(QString::number(v_l[xlnum].get_s()[a-1].get_sfty()));
    pg2-=3;


}
void xtgl_xl::xiaye(int a){
    a=pg2;
    ui->l11->setText(QString::number(v_l[xlnum].get_b()));
    ui->l12->setText(QString::number(v_l[xlnum].get_s()[a].get_zdid()));
    ui->l13->setText(QString::number(v_l[xlnum].get_s()[a].get_xlzdid()));
    ui->l14->setText(QString::number(v_l[xlnum].get_s()[a].get_szid()));
    ui->l15->setText(QString::number(v_l[xlnum].get_s()[a].get_zdjj()));
    ui->l16->setText(QString::number(v_l[xlnum].get_s()[a].get_xzid()));
    ui->l17->setText(QString::number(v_l[xlnum].get_s()[a].get_ysjl()));
    ui->l18->setText(QString::number(v_l[xlnum].get_s()[a].get_xldm()));
    ui->l19->setText(QString::number(v_l[xlnum].get_s()[a].get_sfty()));
    ui->l21->setText(QString::number(v_l[xlnum].get_b()));
    ui->l22->setText(QString::number(v_l[xlnum].get_s()[a+1].get_zdid()));
    ui->l23->setText(QString::number(v_l[xlnum].get_s()[a+1].get_xlzdid()));
    ui->l24->setText(QString::number(v_l[xlnum].get_s()[a+1].get_szid()));
    ui->l25->setText(QString::number(v_l[xlnum].get_s()[a+1].get_zdjj()));
    ui->l26->setText(QString::number(v_l[xlnum].get_s()[a+1].get_xzid()));
    ui->l27->setText(QString::number(v_l[xlnum].get_s()[a+1].get_ysjl()));
    ui->l28->setText(QString::number(v_l[xlnum].get_s()[a+1].get_xldm()));
    ui->l29->setText(QString::number(v_l[xlnum].get_s()[a+1].get_sfty()));
    ui->l31->setText(QString::number(v_l[xlnum].get_b()));
    ui->l32->setText(QString::number(v_l[xlnum].get_s()[a+2].get_zdid()));
    ui->l33->setText(QString::number(v_l[xlnum].get_s()[a+2].get_xlzdid()));
    ui->l34->setText(QString::number(v_l[xlnum].get_s()[a+2].get_szid()));
    ui->l35->setText(QString::number(v_l[xlnum].get_s()[a+2].get_zdjj()));
    ui->l36->setText(QString::number(v_l[xlnum].get_s()[a+2].get_xzid()));
    ui->l37->setText(QString::number(v_l[xlnum].get_s()[a+2].get_ysjl()));
    ui->l38->setText(QString::number(v_l[xlnum].get_s()[a+2].get_xldm()));
    ui->l39->setText(QString::number(v_l[xlnum].get_s()[a+2].get_sfty()));
    pg2+=3;

}
void xtgl_xl::zengjia(){
    this->hide();
    xl_zengjia *an=new xl_zengjia;
    connect(an,&xl_zengjia::destroyed,this,&xtgl_xl::show);
    an->show();



}
void xtgl_xl::sx(){
    ui->l11->setText(QString::number(v_l[1].get_b()));
    ui->l12->setText(QString::number(v_l[1].get_s()[0].get_zdid()));
    ui->l13->setText(QString::number(v_l[1].get_s()[0].get_xlzdid()));
    ui->l14->setText(QString::number(v_l[1].get_s()[0].get_szid()));
    ui->l15->setText(QString::number(v_l[1].get_s()[0].get_zdjj()));
    ui->l16->setText(QString::number(v_l[1].get_s()[0].get_xzid()));
    ui->l17->setText(QString::number(v_l[1].get_s()[0].get_ysjl()));
    ui->l18->setText(QString::number(v_l[1].get_s()[0].get_xldm()));
    ui->l19->setText(QString::number(v_l[1].get_s()[0].get_sfty()));
    ui->l21->setText(QString::number(v_l[1].get_b()));
    ui->l22->setText(QString::number(v_l[1].get_s()[1].get_zdid()));
    ui->l23->setText(QString::number(v_l[1].get_s()[1].get_xlzdid()));
    ui->l24->setText(QString::number(v_l[1].get_s()[1].get_szid()));
    ui->l25->setText(QString::number(v_l[1].get_s()[1].get_zdjj()));
    ui->l26->setText(QString::number(v_l[1].get_s()[1].get_xzid()));
    ui->l27->setText(QString::number(v_l[1].get_s()[1].get_ysjl()));
    ui->l28->setText(QString::number(v_l[1].get_s()[1].get_xldm()));
    ui->l29->setText(QString::number(v_l[1].get_s()[1].get_sfty()));
    ui->l31->setText(QString::number(v_l[1].get_b()));
    ui->l32->setText(QString::number(v_l[1].get_s()[2].get_zdid()));
    ui->l33->setText(QString::number(v_l[1].get_s()[2].get_xlzdid()));
    ui->l34->setText(QString::number(v_l[1].get_s()[2].get_szid()));
    ui->l35->setText(QString::number(v_l[1].get_s()[2].get_zdjj()));
    ui->l36->setText(QString::number(v_l[1].get_s()[2].get_xzid()));
    ui->l37->setText(QString::number(v_l[1].get_s()[2].get_ysjl()));
    ui->l38->setText(QString::number(v_l[1].get_s()[2].get_xldm()));
    ui->l39->setText(QString::number(v_l[1].get_s()[2].get_sfty()));
    pg2=3;
    xlnum=1;


}
void xtgl_xl::qh(){
    if(xlnum>111){xlnum=0;}
    xlnum++;
    ui->l11->setText(QString::number(v_l[xlnum].get_b()));
    ui->l12->setText(QString::number(v_l[xlnum].get_s()[0].get_zdid()));
    ui->l13->setText(QString::number(v_l[xlnum].get_s()[0].get_xlzdid()));
    ui->l14->setText(QString::number(v_l[xlnum].get_s()[0].get_szid()));
    ui->l15->setText(QString::number(v_l[xlnum].get_s()[0].get_zdjj()));
    ui->l16->setText(QString::number(v_l[xlnum].get_s()[0].get_xzid()));
    ui->l17->setText(QString::number(v_l[xlnum].get_s()[0].get_ysjl()));
    ui->l18->setText(QString::number(v_l[xlnum].get_s()[0].get_xldm()));
    ui->l19->setText(QString::number(v_l[xlnum].get_s()[0].get_sfty()));
    ui->l21->setText(QString::number(v_l[xlnum].get_b()));
    ui->l22->setText(QString::number(v_l[xlnum].get_s()[1].get_zdid()));
    ui->l23->setText(QString::number(v_l[xlnum].get_s()[1].get_xlzdid()));
    ui->l24->setText(QString::number(v_l[xlnum].get_s()[1].get_szid()));
    ui->l25->setText(QString::number(v_l[xlnum].get_s()[1].get_zdjj()));
    ui->l26->setText(QString::number(v_l[xlnum].get_s()[1].get_xzid()));
    ui->l27->setText(QString::number(v_l[xlnum].get_s()[1].get_ysjl()));
    ui->l28->setText(QString::number(v_l[xlnum].get_s()[1].get_xldm()));
    ui->l29->setText(QString::number(v_l[xlnum].get_s()[1].get_sfty()));
    ui->l31->setText(QString::number(v_l[xlnum].get_b()));
    ui->l32->setText(QString::number(v_l[xlnum].get_s()[2].get_zdid()));
    ui->l33->setText(QString::number(v_l[xlnum].get_s()[2].get_xlzdid()));
    ui->l34->setText(QString::number(v_l[xlnum].get_s()[2].get_szid()));
    ui->l35->setText(QString::number(v_l[xlnum].get_s()[2].get_zdjj()));
    ui->l36->setText(QString::number(v_l[xlnum].get_s()[2].get_xzid()));
    ui->l37->setText(QString::number(v_l[xlnum].get_s()[2].get_ysjl()));
    ui->l38->setText(QString::number(v_l[xlnum].get_s()[2].get_xldm()));
    ui->l39->setText(QString::number(v_l[xlnum].get_s()[2].get_sfty()));
    pg2=3;

}


xtgl_xl::~xtgl_xl()
{
    delete ui;
}
