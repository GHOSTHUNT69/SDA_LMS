#pragma once
#include "Session.h"

namespace LMS
{
    Session::Session()
        : regOpen(true)
    {
    }

    Session::Session(string sessionD_, vector<Section *> sesection_, bool regOpen_)
        : sessionD(sessionD_), sesection(sesection_), regOpen(regOpen_)
    {
    }

    Session::~Session()
    {
    }

    bool Session::addSection(Section *_sec)
    {
        sesection.push_back(_sec);
        return true;
    }

    void Session::closeReg()
    {
        regOpen = false;
    }

    bool Session::isRegOpen()
    {
        return regOpen;
    }
} // namespace LMS
