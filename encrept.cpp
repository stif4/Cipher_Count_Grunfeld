#include "encrept.h"
#include <QDebug>


encrept::encrept()
{
}

QString encrept::encrept_en(QString key, QString data)
{
    this->key = key;
    this->data = data;

    QString assistant;

    for(int j=0; j < data.size(); j++)// пробегаем все элементы того что шифруем
    {
        if(data.at(j).isUpper())
        {
           data[j] = data[j].toLower();
           caps_lock=true;
        }
             for (int i = 0; i < alphabet.size(); i++)// пробегаем все элементы алфавита
             {
                if (alphabet[i] == data[j])// поиск символа в латинском алфавите
                {
                    if (count_key == key.size()) // обнуляем ключ
                    {
                        count_key = 0;
                    }
                    assistant = key[count_key];// скидываем значение в спомогательную переменную
                    if (i + (assistant.toInt()) >= alphabet.size())// проверяем хватает ли символов с права
                    {
                        current_sign = i + assistant.toInt() - alphabet.size();
                        count_key++;
                    }
                    else // хватает
                    {
                        current_sign = i + assistant.toInt();
                        count_key++;
                    }
                    sign_bool = 1;
                    break;
                }
             }

          if (sign_bool)// Если символ найден и зашифрован
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
          else // Не найден
          {
              result = result + data[j];
          }
      }

    return result;
}



