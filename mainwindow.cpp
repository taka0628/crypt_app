#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aes_wind.h"
#include "sha1_wind.h"
#include "sha2_wind.h"
#include "sub_test.h"
#include "rsa_wind.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_aes_pressed()
{
    aes_wind_ = new aes_wind(this);
    aes_wind_->show();
}

void MainWindow::on_pushButton_sha1_pressed()
{
    sha_wind_ = new sha_wind(this);
    sha_wind_->show();
}

void MainWindow::on_pushButton_sha2_pressed()
{
    sha2_wind_ = new sha2_wind(this);
    sha2_wind_->show();
}

void MainWindow::on_pushButton_rsa_pressed()
{
    rsa_wind_ = new rsa_wind(this);
    rsa_wind_->show();
}
