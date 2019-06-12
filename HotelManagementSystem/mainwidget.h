#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include "menuwidget.h"
#include "addwidget.h"
#include "showwidget.h"
#include "modifywidget.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;

    MenuWidget *menuwidget;
    AddWidget *addwidget;
    ModifyWidget *modifywidget;
    Showwidget *showwidget;
    QStackedLayout *stackLayout;


};
#endif // MAINWIDGET_H
