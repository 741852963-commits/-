#include "gongn.h"
#include "ui_gongn.h"
#include"gn_xtgl.h"
#include"fx.h"
gongn::gongn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gongn)
{
    ui->setupUi(this);
     setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    connect(ui->XTpB,&QPushButton::clicked,this,&gongn::onXTpB);
    connect(ui->SJpB,&QPushButton::clicked,this,&gongn::onSJpB);
    connect(ui->YCpB,&QPushButton::clicked,this,&gongn::onYCpB);
}

gongn::~gongn()
{
    delete ui;
}

void gongn::onXTpB()
{this->hide();
    gn_xtgl *an=new gn_xtgl;
    connect(an,&gn_xtgl::destroyed,this,&gongn::show);
    an->show();
}


void gongn::onSJpB()
{this->hide();
    fx *an=new fx;
    connect(an,&fx::destroyed,this,&gongn::show);
    an->show();

}


void gongn::onYCpB()
{this->hide();

}

