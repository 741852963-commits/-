#include "lcgl.h"
#include "ui_lcgl.h"
#include"Train.h"
#include<fstream>
#include<sstream>
#include<QMessageBox>
#include"gn_lc_seek.h"
#include"lc_zj.h"
extern vector<Train> v_t;
extern string seek_bm;
int pg=10;
lcgl::lcgl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::lcgl)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    connect(ui->pb_seek,&QPushButton::clicked,this,&lcgl::seek);
    connect(ui->shangye,&QPushButton::clicked,this,&lcgl::shangye);
    connect(ui->xiaye,&QPushButton::clicked,this,&lcgl::xiaye);
    connect(ui->baocun,&QPushButton::clicked,this,&lcgl::baocun);
    connect(ui->PB_zj,&QPushButton::clicked,this,&lcgl::zengjia);
    connect(ui->pbsx,&QPushButton::clicked,this,&lcgl::sx);


    ui->L11_2->setText(QString::fromStdString(v_t[0].get_b()));
    ui->L12_2->setText(QString::fromStdString(v_t[0].get_d()));
    ui->L13_2->setText(QString::number(v_t[0].get_yn()));
    ui->L21_2->setText(QString::fromStdString(v_t[1].get_b()));
    ui->L22_2->setText(QString::fromStdString(v_t[1].get_d()));
    ui->L23_2->setText(QString::number(v_t[1].get_yn()));
    ui->L31_2->setText(QString::fromStdString(v_t[2].get_b()));
    ui->L32_2->setText(QString::fromStdString(v_t[2].get_d()));
    ui->L33_2->setText(QString::number(v_t[2].get_yn()));
    ui->L41_2->setText(QString::fromStdString(v_t[3].get_b()));
    ui->L42_2->setText(QString::fromStdString(v_t[3].get_d()));
    ui->L43_2->setText(QString::number(v_t[3].get_yn()));
    ui->L51_2->setText(QString::fromStdString(v_t[4].get_b()));
    ui->L52_2->setText(QString::fromStdString(v_t[4].get_d()));
    ui->L53_2->setText(QString::number(v_t[4].get_yn()));
    ui->L61_2->setText(QString::fromStdString(v_t[5].get_b()));
    ui->L62_2->setText(QString::fromStdString(v_t[5].get_d()));
    ui->L63_2->setText(QString::number(v_t[5].get_yn()));
    ui->L71_2->setText(QString::fromStdString(v_t[6].get_b()));
    ui->L72_2->setText(QString::fromStdString(v_t[6].get_d()));
    ui->L73_2->setText(QString::number(v_t[6].get_yn()));
    ui->L81_2->setText(QString::fromStdString(v_t[7].get_b()));
    ui->L82_2->setText(QString::fromStdString(v_t[7].get_d()));
    ui->L83_2->setText(QString::number(v_t[7].get_yn()));
    ui->L91_2->setText(QString::fromStdString(v_t[8].get_b()));
    ui->L92_2->setText(QString::fromStdString(v_t[8].get_d()));
    ui->L93_2->setText(QString::number(v_t[8].get_yn()));
    ui->L101_2->setText(QString::fromStdString(v_t[9].get_b()));
    ui->L102_2->setText(QString::fromStdString(v_t[9].get_d()));
    ui->L103_2->setText(QString::number(v_t[9].get_yn()));
}
void lcgl::shangye(int a){
    a=pg;
    if(a-10<0){
        QMessageBox::information(this,"警告","已是第一页");
        return;
    }
    ui->L11_2->setText(QString::fromStdString(v_t[a-10].get_b()));
    ui->L12_2->setText(QString::fromStdString(v_t[a-10].get_d()));
    ui->L13_2->setText(QString::number(v_t[a-10].get_yn()));
    ui->L21_2->setText(QString::fromStdString(v_t[a-9].get_b()));
    ui->L22_2->setText(QString::fromStdString(v_t[a-9].get_d()));
    ui->L23_2->setText(QString::number(v_t[a-9].get_yn()));
    ui->L31_2->setText(QString::fromStdString(v_t[a-8].get_b()));
    ui->L32_2->setText(QString::fromStdString(v_t[a-8].get_d()));
    ui->L33_2->setText(QString::number(v_t[a-8].get_yn()));
    ui->L41_2->setText(QString::fromStdString(v_t[a-7].get_b()));
    ui->L42_2->setText(QString::fromStdString(v_t[a-7].get_d()));
    ui->L43_2->setText(QString::number(v_t[a-7].get_yn()));
    ui->L51_2->setText(QString::fromStdString(v_t[a-6].get_b()));
    ui->L52_2->setText(QString::fromStdString(v_t[a-6].get_d()));
    ui->L53_2->setText(QString::number(v_t[a-6].get_yn()));
    ui->L61_2->setText(QString::fromStdString(v_t[a-5].get_b()));
    ui->L62_2->setText(QString::fromStdString(v_t[a-5].get_d()));
    ui->L63_2->setText(QString::number(v_t[a-5].get_yn()));
    ui->L71_2->setText(QString::fromStdString(v_t[a-4].get_b()));
    ui->L72_2->setText(QString::fromStdString(v_t[a-4].get_d()));
    ui->L73_2->setText(QString::number(v_t[a-4].get_yn()));
    ui->L81_2->setText(QString::fromStdString(v_t[a-3].get_b()));
    ui->L82_2->setText(QString::fromStdString(v_t[a-3].get_d()));
    ui->L83_2->setText(QString::number(v_t[a-3].get_yn()));
    ui->L91_2->setText(QString::fromStdString(v_t[a-2].get_b()));
    ui->L92_2->setText(QString::fromStdString(v_t[a-2].get_d()));
    ui->L93_2->setText(QString::number(v_t[a-2].get_yn()));
    ui->L101_2->setText(QString::fromStdString(v_t[a-1].get_b()));
    ui->L102_2->setText(QString::fromStdString(v_t[a-1].get_d()));
    ui->L103_2->setText(QString::number(v_t[a-1].get_yn()));
    pg-=10;

}
void lcgl::xiaye(int a){
    a=pg;
    ui->L11_2->setText(QString::fromStdString(v_t[a].get_b()));
    ui->L12_2->setText(QString::fromStdString(v_t[a].get_d()));
    ui->L13_2->setText(QString::number(v_t[a].get_yn()));
    ui->L21_2->setText(QString::fromStdString(v_t[a+1].get_b()));
    ui->L22_2->setText(QString::fromStdString(v_t[a+1].get_d()));
    ui->L23_2->setText(QString::number(v_t[a+1].get_yn()));
    ui->L31_2->setText(QString::fromStdString(v_t[a+2].get_b()));
    ui->L32_2->setText(QString::fromStdString(v_t[a+2].get_d()));
    ui->L33_2->setText(QString::number(v_t[a+2].get_yn()));
    ui->L41_2->setText(QString::fromStdString(v_t[a+3].get_b()));
    ui->L42_2->setText(QString::fromStdString(v_t[a+3].get_d()));
    ui->L43_2->setText(QString::number(v_t[a+3].get_yn()));
    ui->L51_2->setText(QString::fromStdString(v_t[a+4].get_b()));
    ui->L52_2->setText(QString::fromStdString(v_t[a+4].get_d()));
    ui->L53_2->setText(QString::number(v_t[a+4].get_yn()));
    ui->L61_2->setText(QString::fromStdString(v_t[a+5].get_b()));
    ui->L62_2->setText(QString::fromStdString(v_t[a+5].get_d()));
    ui->L63_2->setText(QString::number(v_t[a+5].get_yn()));
    ui->L71_2->setText(QString::fromStdString(v_t[a+6].get_b()));
    ui->L72_2->setText(QString::fromStdString(v_t[a+6].get_d()));
    ui->L73_2->setText(QString::number(v_t[a+6].get_yn()));
    ui->L81_2->setText(QString::fromStdString(v_t[a+7].get_b()));
    ui->L82_2->setText(QString::fromStdString(v_t[a+7].get_d()));
    ui->L83_2->setText(QString::number(v_t[a+7].get_yn()));
    ui->L91_2->setText(QString::fromStdString(v_t[a+8].get_b()));
    ui->L92_2->setText(QString::fromStdString(v_t[a+8].get_d()));
    ui->L93_2->setText(QString::number(v_t[a+8].get_yn()));
    ui->L101_2->setText(QString::fromStdString(v_t[a+9].get_b()));
    ui->L102_2->setText(QString::fromStdString(v_t[a+9].get_d()));
    ui->L103_2->setText(QString::number(v_t[a+9].get_yn()));
    pg+=10;
}
void lcgl::baocun(){
    QString a11= ui->L11_2->text();
    QString a12=ui->L12_2->text();
    QString a13=ui->L13_2->text();
    QString a21=ui->L21_2->text();
    QString a22=ui->L22_2->text();
    QString a23=ui->L23_2->text();
    QString a31=ui->L31_2->text();
    QString a32=ui->L32_2->text();
    QString a33=ui->L33_2->text();
    QString a41= ui->L41_2->text();
    QString a42=ui->L42_2->text();
    QString a43= ui->L43_2->text();
    QString a51=ui->L51_2->text();
    QString a52=ui->L52_2->text();
    QString a53= ui->L53_2->text();
    QString a61=ui->L61_2->text();
    QString a62= ui->L62_2->text();
    QString a63= ui->L63_2->text();
    QString a71=ui->L71_2->text();
    QString a72= ui->L72_2->text();
    QString a73= ui->L73_2->text();
    QString a81= ui->L81_2->text();
    QString a82= ui->L82_2->text();
    QString a83= ui->L83_2->text();
    QString a91=ui->L91_2->text();
    QString a92= ui->L92_2->text();
    QString a93= ui->L93_2->text();
    QString a101= ui->L101_2->text();
    QString a102= ui->L102_2->text();
    QString a103= ui->L103_2->text();
    for(unsigned int i=0;i<=v_t.size()-1;i++){
        if(a11.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a12.toStdString());
            v_t[i].set_yn(a13.toInt());
        }
        if(a21.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a22.toStdString());
            v_t[i].set_yn(a23.toInt());
        }
        if(a31.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a32.toStdString());
            v_t[i].set_yn(a33.toInt());
        }
        if(a41.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a42.toStdString());
            v_t[i].set_yn(a43.toInt());
        }
        if(a51.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a52.toStdString());
            v_t[i].set_yn(a53.toInt());
        }
        if(a11.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a12.toStdString());
            v_t[i].set_yn(a13.toInt());
        }
        if(a61.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a62.toStdString());
            v_t[i].set_yn(a63.toInt());
        }
        if(a71.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a72.toStdString());
            v_t[i].set_yn(a73.toInt());
        }
        if(a81.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a82.toStdString());
            v_t[i].set_yn(a83.toInt());
        }
        if(a91.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a92.toStdString());
            v_t[i].set_yn(a93.toInt());
        }
        if(a101.toStdString()==v_t[i].get_b()){
            v_t[i].set_d(a102.toStdString());
            v_t[i].set_yn(a103.toInt());
        }
    }
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
    QMessageBox::information(this,"提示","保存成功");
}
void lcgl::sx(){
    ui->L11_2->setText(QString::fromStdString(v_t[0].get_b()));
    ui->L12_2->setText(QString::fromStdString(v_t[0].get_d()));
    ui->L13_2->setText(QString::number(v_t[0].get_yn()));
    ui->L21_2->setText(QString::fromStdString(v_t[1].get_b()));
    ui->L22_2->setText(QString::fromStdString(v_t[1].get_d()));
    ui->L23_2->setText(QString::number(v_t[1].get_yn()));
    ui->L31_2->setText(QString::fromStdString(v_t[2].get_b()));
    ui->L32_2->setText(QString::fromStdString(v_t[2].get_d()));
    ui->L33_2->setText(QString::number(v_t[2].get_yn()));
    ui->L41_2->setText(QString::fromStdString(v_t[3].get_b()));
    ui->L42_2->setText(QString::fromStdString(v_t[3].get_d()));
    ui->L43_2->setText(QString::number(v_t[3].get_yn()));
    ui->L51_2->setText(QString::fromStdString(v_t[4].get_b()));
    ui->L52_2->setText(QString::fromStdString(v_t[4].get_d()));
    ui->L53_2->setText(QString::number(v_t[4].get_yn()));
    ui->L61_2->setText(QString::fromStdString(v_t[5].get_b()));
    ui->L62_2->setText(QString::fromStdString(v_t[5].get_d()));
    ui->L63_2->setText(QString::number(v_t[5].get_yn()));
    ui->L71_2->setText(QString::fromStdString(v_t[6].get_b()));
    ui->L72_2->setText(QString::fromStdString(v_t[6].get_d()));
    ui->L73_2->setText(QString::number(v_t[6].get_yn()));
    ui->L81_2->setText(QString::fromStdString(v_t[7].get_b()));
    ui->L82_2->setText(QString::fromStdString(v_t[7].get_d()));
    ui->L83_2->setText(QString::number(v_t[7].get_yn()));
    ui->L91_2->setText(QString::fromStdString(v_t[8].get_b()));
    ui->L92_2->setText(QString::fromStdString(v_t[8].get_d()));
    ui->L93_2->setText(QString::number(v_t[8].get_yn()));
    ui->L101_2->setText(QString::fromStdString(v_t[9].get_b()));
    ui->L102_2->setText(QString::fromStdString(v_t[9].get_d()));
    ui->L103_2->setText(QString::number(v_t[9].get_yn()));

}
void lcgl::seek(){
    QString s=ui->sou->text();
    string a=s.toStdString();
    seek_bm=a;
    bool f=false;
    for(auto &it:v_t){
        if(it.get_b()==a){
            f=true;
            break;
        }
    }
    if(!f){
        QMessageBox::information(this,"警告","请输入正确列车编码");
        return;
    }
    if(f){
        this->hide();
        gn_lc_seek *an=new gn_lc_seek;
        connect(an,&gn_lc_seek::destroyed,this,&lcgl::show);
        an->show();
    }

}
void lcgl::zengjia(){
    this->hide();
    lc_zj *an=new lc_zj;
    connect(an,&lc_zj::destroyed,this,&lcgl::show);
    an->show();


}

lcgl::~lcgl()
{
    delete ui;
}
