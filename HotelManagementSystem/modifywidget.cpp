#include "modifywidget.h"
#include "ui_modifywidget.h"

ModifyWidget::ModifyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyWidget)
{
    ui->setupUi(this);
}

ModifyWidget::~ModifyWidget()
{
    delete ui;
}

void ModifyWidget::on_returnButton_clicked()
{
    emit display(0);
}

void ModifyWidget::on_deleteButton_clicked(){
    QVector<Customerinfo>allCustomerinfo;
    if(ui->idLineEdit->text() == ""){
        QMessageBox::about(nullptr,"反馈","id不得为空");
        return;
    }
    QFile file("customer.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.isOpen()){
        QMessageBox::about(nullptr,"反馈","数据文件打开失败");
        return;
    }
    QTextStream inp(&file);
    while(!inp.atEnd()){
        QString name;
        QString sex;
        QString phone;
        int id;
        inp >> name >> sex >> phone >> id;
        allCustomerinfo.push_back(Customerinfo(name, sex, phone, id));
    }
    //allCustomerinfo.pop_back();
    file.close();
    int id = ui->idLineEdit->text().toInt();
    bool flag = false;
    for(QVector<Customerinfo>::iterator it = allCustomerinfo.begin(); it !=allCustomerinfo.end();it++)
    {
        if(it->getId() == id){
            allCustomerinfo.erase(it);
            flag = true;
        }
    }
    if(flag){
        QMessageBox::about(nullptr,"反馈","删除成功");
        file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        if(!file.isOpen()){
            QMessageBox::about(nullptr,"反馈","数据文件打开失败");
            return;
        }
        QTextStream out(&file);
        for(auto i : allCustomerinfo){
            out << i.getName() << " "<< i.getSex() << " " << i.getPhone() <<" " << i.getId();
        }
        file.close();
    }
    else {
        QMessageBox::about(nullptr,"反馈","id不存在");
    }
    ui->idLineEdit->clear();
}
void ModifyWidget::on_modifyButton_clicked(){
    if(ui->nameLineEdit->text() == "" || ui->idLineEdit->text() == "" || ui->sexLineEdit->text() == "" || ui->phoneLineEdit->text() == ""){
        QMessageBox::about(nullptr, "反馈", "存在空项");
        return;
    }
    QVector<Customerinfo> allCustomer;
    QFile file("customer.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    if(!file.isOpen()){
        QMessageBox::about(nullptr, "反馈", "数据文件打开失败");
        return;
    }

    QTextStream inp(&file);
    while(!inp.atEnd()){
        QString name;
        QString sex;
        QString phone;
        int id;
        inp >> name >> sex >> phone >> id;
        allCustomer.push_back(Customerinfo(name, sex, phone, id));
    }
    //allCustomer.pop_back();
    file.close();
    int id = ui->idLineEdit->text().toInt();
    QString name = ui->nameLineEdit->text();
    QString sex = ui->sexLineEdit->text();
    QString phone = ui->phoneLineEdit->text();
    bool flag = false;
    for(QVector<Customerinfo>::iterator it = allCustomer.begin(); it != allCustomer.end(); it++){
        if(it->getId() == id){
            it->setName(name);
            it->setSex(sex);
            it->setPhone(phone);
            flag = true;
        }
    }
    if(flag){
        QMessageBox::about(nullptr, "反馈", "修改成功");
        file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        if(!file.isOpen()){
            QMessageBox::about(nullptr, "反馈", "数据文件打开失败");
            return;
        }
        QTextStream out(&file);
        for(auto i : allCustomer){
            out << i.getName() << " " << i.getSex() << " " << i.getPhone() << " " << i.getId()<< endl;
        }
        file.close();
    }else{
         QMessageBox::about(nullptr, "反馈", "id不存在！");
    }
    ui->nameLineEdit->clear();
    ui->sexLineEdit->clear();
    ui->phoneLineEdit->clear();
    ui->sexLineEdit->clear();
}
