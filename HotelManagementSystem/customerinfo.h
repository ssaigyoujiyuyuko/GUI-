#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H
#include <QString>

class Customerinfo
{
private:
    QString name, sex, phone;
    int id;
public:
    Customerinfo();
    Customerinfo(QString tname, QString tsex, QString tphone, int tid){
        name = tname;
        sex = tsex;
        phone = tphone;
        id = tid;
    }
    int getId(){
        return id;
    }
    QString getName(){
        return name;
    }
    QString getSex(){
        return sex;
    }
    QString getPhone(){
        return phone;
    }
    void setId(int tid){
        id = tid;
    }
    void setName(QString tname){
        name = tname;
    }
    void setSex(QString tsex){
        sex = tsex;
    }
    void setPhone(QString tphone){
        phone = tphone;
    }
};

#endif // CUSTOMERINFO_H
