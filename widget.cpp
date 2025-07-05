#include "widget.h"
#include "ui_widget.h"
#include "User.h"
#include<fstream>
#include<sstream>
#include<QMessageBox>
#include"gongn.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    connect(ui->PBC,&QPushButton::clicked,this,&QWidget::close);
    connect(ui->PBD,&QPushButton::clicked,this,&Widget::deyz);

}

Widget::~Widget()
{
    delete ui;
}
void Widget::deyz(){
    bool f=false;
    User an ;
    ifstream infile("mima.txt");
    string s;
    getline(infile,s);
    stringstream ss(s);
    string z,mima;
    ss>>z>>mima;
    an.set_use(z);
    an.set_pa(mima);

    if(ui->passw->text().toStdString()==an.get_pa()&&ui->user->text().toStdString()==an.get_use()){
        f=true;
    }
    if(f){
         QMessageBox::information(this,"登陆提示","登陆成功");
        gongn *un=new gongn;
         this->hide();
        connect(un,&gongn::destroyed,this,&Widget::show);
        un->show();


    }
    else{

        QMessageBox::information(this,"登陆提示","账号或密码错误");}
}


