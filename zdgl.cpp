#include "zdgl.h"
#include "ui_zdgl.h"
#include"Station.h"
#include<fstream>
#include<sstream>
#include<QString>
#include"gn_seek.h"
#include<QMessageBox>
#include"zj.h"
int g=10;
extern vector<Station> v_s;
extern int seek_id;
zdgl::zdgl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::zdgl)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    connect(ui->pb_seek,&QPushButton::clicked,this,&zdgl::seek);
    connect(ui->shangye,&QPushButton::clicked,this,&zdgl::shangye);
    connect(ui->xiaye,&QPushButton::clicked,this,&zdgl::xiaye);
    connect(ui->baocun,&QPushButton::clicked,this,&zdgl::baocun);
    connect(ui->PB_zj,&QPushButton::clicked,this,&zdgl::zengjia);
    connect(ui->pbsx,&QPushButton::clicked,this,&zdgl::sx);
    ifstream inf("zd.txt");
    if (!inf.is_open()) {

        qDebug() << "文件打开失败，请检查路径和权限";
        return;
    }
    string s;
    getline(inf,s);
    while(getline(inf,s)){
        for(auto &c:s){
            if(c==','){
                c=' ';
            }
        }
        stringstream ss(s);
        int a,b;
        string u1,u2,u3,u4,u5,c;

        ss>>a>>u1>>u2>>b>>u3>>u4>>u5>>c;
        v_s.emplace_back(a,b,c,-1,"","","");
    }
    inf.close();

        ui->L11->setText(QString::number(v_s[0].get_id()));
        ui->L12->setText(QString::number(v_s[0].get_l()));
        ui->L13->setText(QString::fromStdString(v_s[0].get_mc()));
        ui->L21->setText(QString::number(v_s[1].get_id()));
        ui->L22->setText(QString::number(v_s[1].get_l()));
        ui->L23->setText(QString::fromStdString(v_s[1].get_mc()));
        ui->L31->setText(QString::number(v_s[2].get_id()));
        ui->L32->setText(QString::number(v_s[2].get_l()));
        ui->L33->setText(QString::fromStdString(v_s[2].get_mc()));
        ui->L41->setText(QString::number(v_s[3].get_id()));
        ui->L42->setText(QString::number(v_s[3].get_l()));
        ui->L43->setText(QString::fromStdString(v_s[3].get_mc()));
        ui->L51->setText(QString::number(v_s[4].get_id()));
        ui->L52->setText(QString::number(v_s[4].get_l()));
        ui->L53->setText(QString::fromStdString(v_s[4].get_mc()));
        ui->L61->setText(QString::number(v_s[5].get_id()));
        ui->L62->setText(QString::number(v_s[5].get_l()));
        ui->L63->setText(QString::fromStdString(v_s[5].get_mc()));
        ui->L71->setText(QString::number(v_s[6].get_id()));
        ui->L72->setText(QString::number(v_s[6].get_l()));
        ui->L73->setText(QString::fromStdString(v_s[6].get_mc()));
        ui->L81->setText(QString::number(v_s[7].get_id()));
        ui->L82->setText(QString::number(v_s[7].get_l()));
        ui->L83->setText(QString::fromStdString(v_s[7].get_mc()));
        ui->L91->setText(QString::number(v_s[8].get_id()));
        ui->L92->setText(QString::number(v_s[8].get_l()));
        ui->L93->setText(QString::fromStdString(v_s[8].get_mc()));
        ui->L101->setText(QString::number(v_s[9].get_id()));
        ui->L102->setText(QString::number(v_s[9].get_l()));
        ui->L103->setText(QString::fromStdString(v_s[9].get_mc()));


}

void zdgl::seek(){

    QString s=ui->sou->text();
    seek_id=s.toInt();
    bool f=false;
    for(auto & it:v_s){
        if(it.get_id()==seek_id){
            f=true;
            break;
        }

    }
    if(f==false){
        QMessageBox::information(this,"警告","请输入正确ID");
        return;
    }
   /* ui->L11->clear();
    ui->L12->clear();
    ui->L13->clear();
    ui->L21->clear();
    ui->L22->clear();
    ui->L23->clear();
    ui->L31->clear();
    ui->L32->clear();
    ui->L33->clear();
    ui->L41->clear();
    ui->L42->clear();
    ui->L43->clear();
    ui->L51->clear();
    ui->L52->clear();
    ui->L53->clear();
    ui->L61->clear();
    ui->L62->clear();
    ui->L63->clear();
    ui->L71->clear();
    ui->L72->clear();
    ui->L73->clear();
    ui->L81->clear();
    ui->L82->clear();
    ui->L83->clear();
    ui->L91->clear();
    ui->L92->clear();
    ui->L93->clear();
    ui->L101->clear();
    ui->L102->clear();
    ui->L103->clear();*/
    this->hide();
    gn_seek *an=new gn_seek;
    connect(an,&zdgl::destroyed,this,&gn_seek::show);
    an->show();

}
void zdgl::sx(){
    ui->L11->setText(QString::number(v_s[0].get_id()));
    ui->L12->setText(QString::number(v_s[0].get_l()));
    ui->L13->setText(QString::fromStdString(v_s[0].get_mc()));
    ui->L21->setText(QString::number(v_s[1].get_id()));
    ui->L22->setText(QString::number(v_s[1].get_l()));
    ui->L23->setText(QString::fromStdString(v_s[1].get_mc()));
    ui->L31->setText(QString::number(v_s[2].get_id()));
    ui->L32->setText(QString::number(v_s[2].get_l()));
    ui->L33->setText(QString::fromStdString(v_s[2].get_mc()));
    ui->L41->setText(QString::number(v_s[3].get_id()));
    ui->L42->setText(QString::number(v_s[3].get_l()));
    ui->L43->setText(QString::fromStdString(v_s[3].get_mc()));
    ui->L51->setText(QString::number(v_s[4].get_id()));
    ui->L52->setText(QString::number(v_s[4].get_l()));
    ui->L53->setText(QString::fromStdString(v_s[4].get_mc()));
    ui->L61->setText(QString::number(v_s[5].get_id()));
    ui->L62->setText(QString::number(v_s[5].get_l()));
    ui->L63->setText(QString::fromStdString(v_s[5].get_mc()));
    ui->L71->setText(QString::number(v_s[6].get_id()));
    ui->L72->setText(QString::number(v_s[6].get_l()));
    ui->L73->setText(QString::fromStdString(v_s[6].get_mc()));
    ui->L81->setText(QString::number(v_s[7].get_id()));
    ui->L82->setText(QString::number(v_s[7].get_l()));
    ui->L83->setText(QString::fromStdString(v_s[7].get_mc()));
    ui->L91->setText(QString::number(v_s[8].get_id()));
    ui->L92->setText(QString::number(v_s[8].get_l()));
    ui->L93->setText(QString::fromStdString(v_s[8].get_mc()));
    ui->L101->setText(QString::number(v_s[9].get_id()));
    ui->L102->setText(QString::number(v_s[9].get_l()));
    ui->L103->setText(QString::fromStdString(v_s[9].get_mc()));

}

void zdgl::xiaye(int a){
    a=g;
    ui->L11->setText(QString::number(v_s[a].get_id()));
    ui->L12->setText(QString::number(v_s[a].get_l()));
    ui->L13->setText(QString::fromStdString(v_s[a].get_mc()));
    ui->L21->setText(QString::number(v_s[a+1].get_id()));
    ui->L22->setText(QString::number(v_s[a+1].get_l()));
    ui->L23->setText(QString::fromStdString(v_s[a+1].get_mc()));
    ui->L31->setText(QString::number(v_s[a+2].get_id()));
    ui->L32->setText(QString::number(v_s[a+2].get_l()));
    ui->L33->setText(QString::fromStdString(v_s[a+2].get_mc()));
    ui->L41->setText(QString::number(v_s[a+3].get_id()));
    ui->L42->setText(QString::number(v_s[a+3].get_l()));
    ui->L43->setText(QString::fromStdString(v_s[a+3].get_mc()));
    ui->L51->setText(QString::number(v_s[a+4].get_id()));
    ui->L52->setText(QString::number(v_s[a+4].get_l()));
    ui->L53->setText(QString::fromStdString(v_s[a+4].get_mc()));
    ui->L61->setText(QString::number(v_s[a+5].get_id()));
    ui->L62->setText(QString::number(v_s[a+5].get_l()));
    ui->L63->setText(QString::fromStdString(v_s[a+5].get_mc()));
    ui->L71->setText(QString::number(v_s[a+6].get_id()));
    ui->L72->setText(QString::number(v_s[a+6].get_l()));
    ui->L73->setText(QString::fromStdString(v_s[a+6].get_mc()));
    ui->L81->setText(QString::number(v_s[a+7].get_id()));
    ui->L82->setText(QString::number(v_s[a+7].get_l()));
    ui->L83->setText(QString::fromStdString(v_s[a+7].get_mc()));
    ui->L91->setText(QString::number(v_s[a+8].get_id()));
    ui->L92->setText(QString::number(v_s[a+8].get_l()));
    ui->L93->setText(QString::fromStdString(v_s[a+8].get_mc()));
    ui->L101->setText(QString::number(v_s[a+9].get_id()));
    ui->L102->setText(QString::number(v_s[a+9].get_l()));
    ui->L103->setText(QString::fromStdString(v_s[a+9].get_mc()));
    g+=10;

}
void zdgl::shangye(int a){
    a=g;
    if(a-10<0){
        QMessageBox::information(this,"警告","已是第一页");
        return;
    }
    ui->L11->setText(QString::number(v_s[a-10].get_id()));
    ui->L12->setText(QString::number(v_s[a-10].get_l()));
    ui->L13->setText(QString::fromStdString(v_s[a-10].get_mc()));
    ui->L21->setText(QString::number(v_s[a-9].get_id()));
    ui->L22->setText(QString::number(v_s[a-9].get_l()));
    ui->L23->setText(QString::fromStdString(v_s[a-9].get_mc()));
    ui->L31->setText(QString::number(v_s[a-8].get_id()));
    ui->L32->setText(QString::number(v_s[a-8].get_l()));
    ui->L33->setText(QString::fromStdString(v_s[a-8].get_mc()));
    ui->L41->setText(QString::number(v_s[a-7].get_id()));
    ui->L42->setText(QString::number(v_s[a-7].get_l()));
    ui->L43->setText(QString::fromStdString(v_s[a-7].get_mc()));
    ui->L51->setText(QString::number(v_s[a-6].get_id()));
    ui->L52->setText(QString::number(v_s[a-6].get_l()));
    ui->L53->setText(QString::fromStdString(v_s[a-6].get_mc()));
    ui->L61->setText(QString::number(v_s[a-5].get_id()));
    ui->L62->setText(QString::number(v_s[a-5].get_l()));
    ui->L63->setText(QString::fromStdString(v_s[a-5].get_mc()));
    ui->L71->setText(QString::number(v_s[a-4].get_id()));
    ui->L72->setText(QString::number(v_s[a-4].get_l()));
    ui->L73->setText(QString::fromStdString(v_s[a-4].get_mc()));
    ui->L81->setText(QString::number(v_s[a-3].get_id()));
    ui->L82->setText(QString::number(v_s[a-3].get_l()));
    ui->L83->setText(QString::fromStdString(v_s[a-3].get_mc()));
    ui->L91->setText(QString::number(v_s[a-2].get_id()));
    ui->L92->setText(QString::number(v_s[a-2].get_l()));
    ui->L93->setText(QString::fromStdString(v_s[a-2].get_mc()));
    ui->L101->setText(QString::number(v_s[a-1].get_id()));
    ui->L102->setText(QString::number(v_s[a-1].get_l()));
    ui->L103->setText(QString::fromStdString(v_s[a-1].get_mc()));
    g-=10;
}
void zdgl::baocun(){
   QString a11= ui->L11->text();
    QString a12=ui->L12->text();
   QString a13=ui->L13->text();
    QString a21=ui->L21->text();
   QString a22=ui->L22->text();
    QString a23=ui->L23->text();
    QString a31=ui->L31->text();
    QString a32=ui->L32->text();
    QString a33=ui->L33->text();
   QString a41= ui->L41->text();
    QString a42=ui->L42->text();
   QString a43= ui->L43->text();
    QString a51=ui->L51->text();
    QString a52=ui->L52->text();
   QString a53= ui->L53->text();
    QString a61=ui->L61->text();
   QString a62= ui->L62->text();
   QString a63= ui->L63->text();
    QString a71=ui->L71->text();
   QString a72= ui->L72->text();
   QString a73= ui->L73->text();
   QString a81= ui->L81->text();
   QString a82= ui->L82->text();
  QString a83= ui->L83->text();
    QString a91=ui->L91->text();
   QString a92= ui->L92->text();
   QString a93= ui->L93->text();
   QString a101= ui->L101->text();
   QString a102= ui->L102->text();
   QString a103= ui->L103->text();
   for(unsigned int i=0;i<=v_s.size()-1;i++){
       if(a11.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a12.toInt());
           v_s[i].set_mc(a13.toStdString());
       }
       if(a21.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a22.toInt());
           v_s[i].set_mc(a23.toStdString());
       }
       if(a31.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a32.toInt());
           v_s[i].set_mc(a33.toStdString());
       }
       if(a41.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a42.toInt());
           v_s[i].set_mc(a43.toStdString());
       }
       if(a51.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a52.toInt());
           v_s[i].set_mc(a53.toStdString());
       }
       if(a11.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a12.toInt());
           v_s[i].set_mc(a13.toStdString());
       }
       if(a61.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a62.toInt());
           v_s[i].set_mc(a63.toStdString());
       }
       if(a71.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a72.toInt());
           v_s[i].set_mc(a73.toStdString());
       }
       if(a81.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a82.toInt());
           v_s[i].set_mc(a83.toStdString());
       }
       if(a91.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a92.toInt());
           v_s[i].set_mc(a93.toStdString());
       }
       if(a101.toInt()==v_s[i].get_id()){
           v_s[i].set_l(a102.toInt());
           v_s[i].set_mc(a103.toStdString());
       }

   }
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
  QMessageBox::information(this,"提示","保存成功");

}
void zdgl::zengjia(){
    this->hide();
    zj *an=new zj;
    connect(an,&zj::destroyed,this,&zdgl::show);
    an->show();


}

zdgl::~zdgl()
{
    delete ui;
}
