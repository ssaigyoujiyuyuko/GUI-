#ifndef ADDWIDGET_H
#define ADDWIDGET_H
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
    class AddWidget;
}

class AddWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddWidget(QWidget *parent = nullptr);
    ~AddWidget();

private:
    Ui::AddWidget *ui;

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked();
    void on_addButton_clicked();

};

#endif // ADDWIDGET_H
