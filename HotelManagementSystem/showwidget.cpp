#include "showwidget.h"
#include "ui_showwidget.h"

Showwidget::Showwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Showwidget)
{
    ui->setupUi(this);
}

Showwidget::~Showwidget()
{
    delete ui;
}

void Showwidget::on_returnButton_clicked()
{
    emit display(0);
}

void Showwidget::on_showButton_clicked(){
    if(ui->idLineEdit->text() == ""){
        QMessageBox::about(nullptr,"反馈","id不能为空");
        return;
    }
    QFile file("customer.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.isOpen()){
        QMessageBox::about(nullptr,"反馈","文件打开失败");
        return;
    }
    QTextStream inp(&file);
    QVector<Customerinfo> allCustomerinfo;
    while(!inp.atEnd()){
        QString name;
        QString sex;
        QString phone;
        int id;
        inp >> name >> sex >> phone >> id;
        allCustomerinfo.push_back(Customerinfo(name,sex,phone,id));
    }
    //allCustomerinfo.pop_back();
    file.close();
    int id = ui->idLineEdit->text().toInt();
    bool flag = false;
    for(auto i : allCustomerinfo){
        if(i.getId() == id){
            ui->shownameLabel->setText(i.getName());
            ui->showsexLabel->setText(i.getSex());
            ui->showphoneLabel->setText(i.getPhone());
            flag = true;
            break;
        }
    }
    if(!flag){
        QMessageBox::about(nullptr,"反馈","id不存在");
    }
    ui->idLineEdit->clear();
}
