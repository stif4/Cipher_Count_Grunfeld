#include "decrept.h"

decrept::decrept()
{
}

QString decrept::decrept_de(QString key, QString data)
{
    this->key = key;
    this->data = data;

    QString assistant;

    for (int j = 0; j < data.size(); j++)
    {
        if(data.at(j).isUpper())
        {
           data[j] = data[j].toLower();
           caps_lock=true;
        }
            for (int i = 0; i < alphabet.size(); i++)
            {
                if (alphabet[i] == data[j])
                {
                    if (count_key ==  key.size())
                    {
                        count_key = 0;
                    }
                    assistant = key[count_key];
                    if (i - assistant.toInt() < 0)
                    {
                        current_sign = i - assistant.toInt() + alphabet.size();
                        count_key++;
                    }
                    else
                    {
                        current_sign = i - assistant.toInt();
                        count_key++;
                    }
                    sign_bool = 1;
                    break;
                }
            }
            if (sign_bool)
            {
                if(caps_lock)
                {
                   result = result + alphabet[current_sign].toUpper();
                   caps_lock=false;
                }
                else
                {
                   result = result + alphabet[current_sign];
                }

                sign_bool = 0;
            }
            else
            {
                result = result + data[j];
            }
    }
    return result;
}

