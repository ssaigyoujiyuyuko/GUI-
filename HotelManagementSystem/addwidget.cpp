#include "addwidget.h"
#include "ui_addwidget.h"

AddWidget::AddWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddWidget)
{
    ui->setupUi(this);
}

AddWidget::~AddWidget()
{
    delete ui;
}

void AddWidget::on_returnButton_clicked()
{
    emit display(0);
}
void AddWidget::on_addButton_clicked(){
    QString name = ui->nameLineEdit->text();
    QString sex = ui->sexLineEdit->text();
    QString phone = ui->phoneLineEdit->text();
    int id = ui->idLineEdit->text().toInt();

    if(ui->nameLineEdit->text() == ""|| ui->idLineEdit->text() == ""|| ui->sexLineEdit->text() == ""||ui->phoneLineEdit->text() == ""){
        QMessageBox::about(nullptr,"反馈","存在空项");
    }

    QFile file("customer.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(!file.isOpen()){
        QMessageBox::about(nullptr,"反馈","数据文件打开失败");
        return;
    }
    QTextStream out(&file);
    out << name << " " << sex << " "<< phone << " " << id;
    file.close();
    QMessageBox::about(nullptr,"反馈","插入成功");
    ui->nameLineEdit->clear();
    ui->sexLineEdit->clear();
    ui->phoneLineEdit->clear();
    ui->idLineEdit->clear();
}
