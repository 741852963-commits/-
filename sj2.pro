QT       += core gui
QT        +=charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Date1.cpp \
    Line.cpp \
    Line2.cpp \
    PersonFlow.cpp \
    Station.cpp \
    Time1.cpp \
    Train.cpp \
    User.cpp \
    Yuce.cpp \
    fx.cpp \
    gn_lc_seek.cpp \
    gn_seek.cpp \
    gn_xtgl.cpp \
    gongn.cpp \
    lc_zj.cpp \
    lcgl.cpp \
    main.cpp \
    widget.cpp \
    xl_seek.cpp \
    xl_zengjia.cpp \
    xtgl_xl.cpp \
    zdgl.cpp \
    zj.cpp

HEADERS += \
    Date1.h \
    Line.h \
    Line2.h \
    PersonFlow.h \
    Station.h \
    Time1.h \
    Train.h \
    User.h \
    Yuce.h \
    fx.h \
    gn_lc_seek.h \
    gn_seek.h \
    gn_xtgl.h \
    gongn.h \
    lc_zj.h \
    lcgl.h \
    widget.h \
    xl_seek.h \
    xl_zengjia.h \
    xtgl_xl.h \
    zdgl.h \
    zj.h

FORMS += \
    fx.ui \
    gn_lc_seek.ui \
    gn_seek.ui \
    gn_xtgl.ui \
    gongn.ui \
    lc_zj.ui \
    lcgl.ui \
    widget.ui \
    xl_seek.ui \
    xl_zengjia.ui \
    xtgl_xl.ui \
    zdgl.ui \
    zj.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    lc.txt \
    mima.txt \
    xl.txt \
    yc.txt \
    zd.CSV \
    zd.txt

