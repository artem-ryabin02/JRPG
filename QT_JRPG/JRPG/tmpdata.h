#ifndef TMPDATA_H
#define TMPDATA_H

#include <QString>

class TmpData
{
public:
    TmpData(const QString &newId, const QString &newEvents);// конструктор с вхаодными данными: айди и собитием
    TmpData();//конструктор по умолчанию
    QString getId() const;// геттер для поля айди
    void setId(const QString &newId);// сеттер для поля айди

    QString getEvents() const;// геттер для поля событий
    void setEvents(const QString &newEvents);// сеттер для поля айди

    void setStr(const QString &newId, const QString &newEvents);// сеттер для всех полей разом


private:
    QString id ;// айди поля
    QString events ;// событие

};

#endif // TMPDATA_H
