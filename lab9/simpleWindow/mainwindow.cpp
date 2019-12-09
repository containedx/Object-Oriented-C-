#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //displacement = new Displacement(this);

    //connect(displacement, SIGNAL(changed(double)))

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="XD")
    {
        ui->lineEdit->setText(":>");
        ui->textBrowser->setText("");
    }
    else
    {
        ui->lineEdit->setText("XD");
        ui->textBrowser->setText("pomelo");
    }
}
