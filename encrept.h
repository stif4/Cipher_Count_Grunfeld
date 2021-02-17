#ifndef ENCREPT_H
#define ENCREPT_H

#include <QString>

class encrept
{
public:
    encrept();
    QString encrept_en(QString key, QString data);

private:
    QString key;
    QString data;
    QString alphabet = "abcdefghijklmnopqrstuvwxyz";
    int count_key=0;
    int current_sign;
    bool sign_bool=0;
    QString result="";
    bool caps_lock=0;
};

#endif // ENCREPT_H
