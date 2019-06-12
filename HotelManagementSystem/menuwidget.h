#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    ~MenuWidget();

signals:
    void display(int number);

private slots:
    void on_addButton_clicked();

    void on_showButton_clicked();

    void on_modifyButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MenuWidget *ui;
};



#endif // MENUWIDGET_H
