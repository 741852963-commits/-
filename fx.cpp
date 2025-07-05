#include "fx.h"
#include "Train.h"
#include "ui_fx.h"
#include<QValueAxis>
#include<QCategoryAxis>
#include<QBarSet>
#include<QBarSeries>
#include<QLineSeries>
#include<QBarCategoryAxis>
#include"Yuce.h"
#include<fstream>
#include <set>
#include<sstream>
#include<QMessageBox>
vector<Yuce> v_y;
extern vector<Train> v_t;
int shu=0;
fx::fx(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::fx)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("川渝地区轨道交通客流数据分析展示系统");
    connect(ui->rb1,&QRadioButton::clicked,this,&fx::lc_kl);
    connect(ui->rb2,&QRadioButton::clicked,this,&fx::sx_kl);
    connect(ui->rb3,&QRadioButton::clicked,this,&fx::zd_kl);
     connect(ui->pbh,&QRadioButton::clicked,this,&fx::xia);
     connect(ui->pbq,&QRadioButton::clicked,this,&fx::shang);
      connect(ui->pbs,&QRadioButton::clicked,this,&fx::sx);
    ifstream inf("yc.txt");
    if(!inf.is_open()){
        qDebug()<<"文件打开失败";
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
        int a1,a2,a3,a4,a5,a6,a7,a10;
        string a8,a9;

        ss>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10;
       // qDebug()<<a1<<a2<<a3<<a4<<a5<<a6<<a7<<a8<<a9<<a10;
        v_y.emplace_back(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);
    }

}

fx::~fx()
{
    delete ui;
}
void fx::sx(){
    shu=0;
}
void fx::xia(){
    shu++;
    lc_kl();
}
void fx::shang(){

    shu--;
    if(shu<0){
        QMessageBox::information(this,"警告","无法前移");
        return;
    }
    lc_kl();
}

void fx::lc_kl(){
    QString s1=ui->dateEdit->text();
    QString s2=ui->dateEdit_2->text();
    for(unsigned int i=0;i<s1.size();i++){
        if(s1[i]=='/'){
            s1[i]=' ';
        }
        if(s2[i]=='/'){
            s2[i]=' ';
        }
    }
    string s11=s1.toStdString();
    string s22=s2.toStdString();
    stringstream ss(s11);
    stringstream ss2(s22);


    int a1,a2,a3;
    ss>>a1>>a2>>a3;
    int star_ti=a1*10000+a2*100+a3;
    ss2>>a1>>a2>>a3;
     int end_ti=a1*10000+a2*100+a3;
    if(end_ti<star_ti){
         QMessageBox::information(this,"警告","终止时间早于起始时间");
         return;
    }

    set<int> st;
    vector<pair<int,int>> bh_sk;
    for(auto &it:v_y){
        if((it.get_yxd()>=star_ti&&it.get_yxd()<=end_ti)&&it.get_liu().get_inf()!=0){
            st.insert(it.get_lcbm());
            bh_sk.push_back({it.get_lcbm(),it.get_liu().get_inf()});
        }
    }
    vector<QString> vt_lcbm;
    vector<int> vt_lcbm2;
    for(auto &it:st){
        vt_lcbm.push_back(QString::number(it));
        vt_lcbm2.push_back(it);
    }
    vector<double> zkl(vt_lcbm.size());
    for(unsigned int i=0;i<vt_lcbm.size();i++){
        int cnt=0;
        double inf=0;
        double yn;
        for(auto &it:bh_sk){
            if(it.first==vt_lcbm2[i]){
                cnt++;
                inf+=it.second;
            }
        }
        for(auto &it:v_t){
            if(stoi(it.get_b())==vt_lcbm2[i]){
                yn=it.get_yn();
                break;
            }
        }
        zkl[i]=(inf/cnt)/yn*1.0*100;
    }

    // 创建数据集合
    QBarSet *set0 = new QBarSet("列车编号");
    unsigned int num=shu;

    // 添加数据
    if( num+4 >zkl.size()-1){
        QMessageBox::information(this,"警告","数据已加载完");
        return;
    }

    *set0 << zkl[num] << zkl[num+1] << zkl[num+2] << zkl[num+3] << zkl[num+4];


    // 创建柱状图系列
    QBarSeries *series = new QBarSeries();
    series->append(set0);

    // 创建图表并添加系列
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("列车载客率");
    chart->setAnimationOptions(QChart::SeriesAnimations); // 添加动画效果

    // 创建类别轴（X轴）
    QStringList categories;
    categories << vt_lcbm[num] << vt_lcbm[num+1] <<vt_lcbm[num+2] <<vt_lcbm[num+3] << vt_lcbm[num+4] ;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 创建数值轴（Y轴）
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 50);
    axisY->setTitleText("载客率");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 设置图例
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // 创建图表视图
    ui->graphicsView->setChart(chart);
   ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}
void fx::sx_kl(){
    QString s1=ui->dateEdit->text();
    QString s2=ui->dateEdit_2->text();
    for(unsigned int i=0;i<s1.size();i++){
        if(s1[i]=='/'){
            s1[i]=' ';
        }
        if(s2[i]=='/'){
            s2[i]=' ';
        }
    }
    string s11=s1.toStdString();
    string s22=s2.toStdString();
    stringstream ss(s11);
    stringstream ss2(s22);


    int a1,a2,a3;
    ss>>a1>>a2>>a3;
    int star_ti=a1*10000+a2*100+a3;
    ss2>>a1>>a2>>a3;
    int end_ti=a1*10000+a2*100+a3;
    if(end_ti<star_ti){
        QMessageBox::information(this,"警告","终止时间早于起始时间");
        return;
    }

    QBarSet *set0 = new QBarSet("");
    int sx_kl=0;
    for(auto &it:v_y){
        if((it.get_yxd()>=star_ti&&it.get_yxd()<=end_ti)){
            sx_kl+=it.get_zkll();
        }
    }

    // 添加数据
    *set0 <<sx_kl ;


    // 创建柱状图系列
    QBarSeries *series = new QBarSeries();
    series->append(set0);

    // 创建图表并添加系列
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("川渝双向旅客流量");
    chart->setAnimationOptions(QChart::SeriesAnimations); // 添加动画效果

    // 创建类别轴（X轴）
    QStringList categories;
    categories << "川渝地区" ;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 创建数值轴（Y轴）
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 15000000);
    axisY->setTitleText("双向旅客流量");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 设置图例
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // 创建图表视图
    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);




}

struct zkl_z{
    QString a;
    int kl;
};
bool cmp(zkl_z a,zkl_z b){
    return a.kl>b.kl;
}
void fx::zd_kl(){
    QString s1=ui->dateEdit->text();
    QString s2=ui->dateEdit_2->text();
    for(unsigned int i=0;i<s1.size();i++){
        if(s1[i]=='/'){
            s1[i]=' ';
        }
        if(s2[i]=='/'){
            s2[i]=' ';
        }
    }
    string s11=s1.toStdString();
    string s22=s2.toStdString();
    stringstream ss(s11);
    stringstream ss2(s22);


    int a1,a2,a3;
    ss>>a1>>a2>>a3;
    int star_ti=a1*10000+a2*100+a3;
    ss2>>a1>>a2>>a3;
    int end_ti=a1*10000+a2*100+a3;
    if(end_ti<star_ti){
        QMessageBox::information(this,"警告","终止时间早于起始时间");
        return;
    }
    set<int> st;
    vector<int> vt_id;
    vector<QString> vq_id;
    vector<pair<int,int>> zd_kl;
    for(auto &it:v_y){
        if(it.get_yxd()>=star_ti&&it.get_yxd()<=end_ti){
            st.insert(it.get_zdid());
            zd_kl.push_back({it.get_zdid(),it.get_zkll()});
        }
    }
    for(auto &it:st){
        vt_id.push_back(it);
        vq_id.push_back(QString::number(it));
    }
    vector<int> zkl(7,0);
    for(int i=0;i<7;i++){
        for(auto &it:zd_kl){
            if(vt_id[i]==it.first){
                zkl[i]+=it.second;
            }
        }
    }
    QBarSet *set0 = new QBarSet("站点ID");

    vector<zkl_z> zs(7);
    for(int i=0;i<7;i++){
        zs[i].a=vq_id[i];
        zs[i].kl=zkl[i];
    }
    sort(zs.begin(),zs.end(),cmp);

    *set0 << zs[0].kl << zs[1].kl << zs[2].kl << zs[3].kl << zs[4].kl<<zs[5].kl<<zs[6].kl;


    // 创建柱状图系列
    QBarSeries *series = new QBarSeries();
    series->append(set0);

    // 创建图表并添加系列
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("旅客流量");
    chart->setAnimationOptions(QChart::SeriesAnimations); // 添加动画效果

    // 创建类别轴（X轴）
    QStringList categories;
    categories << zs[0].a << zs[1].a <<zs[2].a <<zs[3].a << zs[4].a<<zs[5].a<<zs[6].a ;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 创建数值轴（Y轴）
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 5015632);
    axisY->setTitleText("载客率");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 设置图例
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // 创建图表视图
    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);


}
