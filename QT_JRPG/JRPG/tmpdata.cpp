#include "tmpdata.h"

TmpData::TmpData(const QString &newId, const QString &newEvents)//присваиваем новые значения полученные при создании экземпляра
{
    id = newId;
    events = newEvents;
}

TmpData::TmpData(){}

QString TmpData::getId() const
{
    return id;//возвращаем значение
}

void TmpData::setId(const QString &newId)
{
    id = newId;//присваиваем новые значения
}

QString TmpData::getEvents() const
{
    return events;//возвращаем значение
}

void TmpData::setEvents(const QString &newEvents)
{
    events = newEvents;//присваиваем новые значения
}

void TmpData::setStr(const QString &newId, const QString &newEvents)
{
    id = newId;//присваиваем новые значения
    events = newEvents;//присваиваем новые значения
}
