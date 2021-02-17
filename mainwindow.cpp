#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "encrept.h"
#include "decrept.h"

#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0, 100000000, this));
    ui->lineEdit_3->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    encrept d;
    ui->lineEdit_3->setText(d.encrept_en(ui->lineEdit->text(),ui->lineEdit_2->text()));
}

void MainWindow::on_pushButton_2_clicked()
{
    decrept s;
    ui->lineEdit_3->setText(s.decrept_de(ui->lineEdit->text(),ui->lineEdit_2->text()));
}
