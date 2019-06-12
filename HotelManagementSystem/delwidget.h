#ifndef DELWIDGET_H
#define DELWIDGET_H

#include <QWidget>

namespace Ui {
class DelWidget;
}

class DelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DelWidget(QWidget *parent = nullptr);
    ~DelWidget();

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked();

private:
    Ui::DelWidget *ui;
};

#endif // DELWIDGET_H
