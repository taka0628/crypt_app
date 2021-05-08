#include "sub_test.h"
#include "ui_sub_test.h"

sub_test::sub_test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sub_test)
{
    ui->setupUi(this);
}

sub_test::~sub_test()
{
    delete ui;
}
