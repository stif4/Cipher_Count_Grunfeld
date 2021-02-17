#ifndef DECREPT_H
#define DECREPT_H

#include <QString>

class decrept
{
public:
    decrept();
    QString decrept_de(QString key, QString data);

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

#endif // DECREPT_H
