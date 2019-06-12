#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    menuwidget = new MenuWidget;
    addwidget = new AddWidget;
    showwidget = new Showwidget;
    modifywidget = new ModifyWidget;
    stackLayout = new QStackedLayout;

    stackLayout->addWidget(menuwidget);
    stackLayout->addWidget(addwidget);
    stackLayout->addWidget(showwidget);
    stackLayout->addWidget(modifywidget);


    setLayout(stackLayout);

    connect(menuwidget, &MenuWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(addwidget, &AddWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(showwidget, &Showwidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(modifywidget, &ModifyWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);

}

MainWidget::~MainWidget()
{
    delete ui;
}
