#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->myPushButton1, SIGNAL(clicked()), this, SLOT(myEventHandler()));
    QObject::connect(this, SIGNAL(mySignal(QString)), ui->myLineEdit2, SLOT(setText(QString)));
    QObject::connect(this, SIGNAL(mySignal(QString)), ui->myLabel, SLOT(setText(QString)));
    QObject::connect(ui->incButton, SIGNAL(clicked()), this, SLOT(IncrementHandler()));
    QObject::connect(ui->decButton, SIGNAL(clicked()), this, SLOT(DecrementHandler()));
    ui->myLabel->setText("Test text.");
    QList<QTreeWidgetItem *> items;
    for(int i=0; i<10; ++i)
        items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
    ui->treeWidget->insertTopLevelItems(0, items);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myEventHandler() {
    emit mySignal(ui->myLineEdit1->text());
}

void MainWindow::IncrementHandler() {
    ui->lcdNumber->display(ui->lcdNumber->intValue() + 1);
}

void MainWindow::DecrementHandler() {
    ui->lcdNumber->display(ui->lcdNumber->intValue() - 1);
}
