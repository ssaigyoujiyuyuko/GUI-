#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QVector>
#include <QtDebug>
#include "customerinfo.h"

namespace Ui {
    class ModifyWidget;
}

class ModifyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyWidget(QWidget *parent = nullptr);
    ~ModifyWidget();

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked();
    void on_modifyButton_clicked();
    void on_deleteButton_clicked();
private:
    Ui::ModifyWidget *ui;
};

#endif // MODIFYWIDGET_H
