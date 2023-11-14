#ifndef TMPDATA_H
#define TMPDATA_H

#include <QString>

class TmpData
{
public:
    TmpData(const QString &newId, const QString &newEvents);
    TmpData();
    QString getId() const;
    void setId(const QString &newId);

    QString getEvents() const;
    void setEvents(const QString &newEvents);

    void setStr(const QString &newId, const QString &newEvents);


private:
    QString id ;
    QString events ;

};

#endif // TMPDATA_H
