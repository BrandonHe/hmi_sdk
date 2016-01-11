﻿#ifndef UIINTERFACE_H
#define UIINTERFACE_H
#include "AppData/AppDataInterface.h"
#include "AppData/AppCommon.h"


class UIInterface
{
public:
    virtual void onAppShow(int type) = 0;

    virtual void onVideoStreamStart() = 0;
    virtual void onVideoStreamStop() = 0;

    virtual void tsSpeak(int VRID, std::string strText) = 0;
};

#endif // UIINTERFACE_H
