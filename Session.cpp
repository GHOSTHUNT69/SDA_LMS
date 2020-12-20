#include "Session.h"

Session::Session()
{
}

Session::Session(string sessionD_, vector<Section*> sesection_, bool regOpen_)
    :sessionD(sessionD_),sesection(sesection_),regOpen(regOpen_)
{
}

Session::~Session()
{
}
