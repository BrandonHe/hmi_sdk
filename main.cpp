﻿#include <QApplication>
#include <QTextCodec>

#include "UI/Config/Config.h"
#include <QDialog>
#include "HMI_Initial.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
#endif


    HMI_Initial appManager;
    QDialog diaStart;
    diaStart.setGeometry(0,0,ui_res_width,ui_res_height);
    diaStart.setStyleSheet("border-image:url(:/images/Screen.png);");
    QObject::connect(&appManager,SIGNAL(finishMainHMI()),&diaStart, SLOT(accept()));
    diaStart.exec();
    appManager.ShowUI();

    return a.exec();
}