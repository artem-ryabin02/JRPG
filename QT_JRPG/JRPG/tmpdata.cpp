#include "tmpdata.h"

TmpData::TmpData(const QString &newId, const QString &newEvents)
{
    id = newId;
    events = newEvents;
}

TmpData::TmpData(){}

QString TmpData::getId() const
{
    return id;
}

void TmpData::setId(const QString &newId)
{
    id = newId;
}

QString TmpData::getEvents() const
{
    return events;
}

void TmpData::setEvents(const QString &newEvents)
{
    events = newEvents;
}

void TmpData::setStr(const QString &newId, const QString &newEvents)
{
    id = newId;
    events = newEvents;
}
