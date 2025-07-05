#include "gn_xtgl.h"
#include "ui_gn_xtgl.h"
#include "xtgl_xl.h"
#include"zdgl.h"
#include"lcgl.h"
gn_xtgl::gn_xtgl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gn_xtgl)
{
    ui->setupUi(this);
     setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    connect(ui->PB1,&QPushButton::clicked,this,&gn_xtgl::onPB1);
    connect(ui->PB2,&QPushButton::clicked,this,&gn_xtgl::onPB2);
    connect(ui->PB3,&QPushButton::clicked,this,&gn_xtgl::onPB3);


}

gn_xtgl::~gn_xtgl()
{
    delete ui;
}

void gn_xtgl::onPB1()
{
    this->hide();
    zdgl *an=new zdgl;
    connect(an,&zdgl::destroyed,this,&gn_xtgl::show);
    an->show();
}


void gn_xtgl::onPB2()
{this->hide();
    lcgl *an=new lcgl;
   connect(an,&lcgl::destroyed,this,&gn_xtgl::show);
    an->show();

}


void gn_xtgl::onPB3()
{this->hide();
    xtgl_xl *an=new xtgl_xl;
    connect(an,&xtgl_xl::destroyed,this,&gn_xtgl::show);
    an->show();

}

