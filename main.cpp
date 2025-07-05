#include "Train.h"
#include "widget.h"
#include <QApplication>
#include"Station.h"
#include"Line.h"
#include<fstream>
#include<sstream>
vector<Line> v_l(200);
vector<Station> v_s;
vector<Train> v_t;
int seek_id;
string seek_bm;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    ifstream inf("lc.txt");
    if (!inf.is_open()) {

        qDebug() << "文件打开失败，请检查路径和权限";
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
        string a1,a2,a3;

        ss>>a1>>a2>>a3;
        if(a3=="#N/A")
            v_t.emplace_back(a1,a2,-1);
        else {
            v_t.emplace_back(a1,a2,stoi(a3));
        }
    }
    inf.close();




    Widget w;
    w.show();
    return a.exec();
}
