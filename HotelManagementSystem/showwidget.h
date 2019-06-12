#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QtDebug>
#include <QMessageBox>
#include <QVector>
#include <QFile>
#include "customerinfo.h"

namespace Ui {
    class Showwidget;
}

class Showwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Showwidget(QWidget *parent = nullptr);
    ~Showwidget();

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked();
    void on_showButton_clicked();
private:
    Ui::Showwidget *ui;
};

#endif // SHOWWIDGET_H
