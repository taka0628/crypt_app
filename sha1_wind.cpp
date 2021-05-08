#include "sha1_wind.h"
#include "ui_sha_wind.h"
#include "sha_c.hpp"

sha_wind::sha_wind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sha_wind)
{
    ui->setupUi(this);
}

sha_wind::~sha_wind()
{
    delete ui;
}

using namespace std;

void sha_wind::on_lineEdit_textChanged(const QString &arg1)
{
    QString input_iv = arg1;
    QString output;
    std::ostringstream oss;
    int iv_size = input_iv.size();
    iv_size = iv_size * 4;
    oss<< iv_size;
    output.push_back(oss.str().c_str());

    output.push_back("bit");
    ui->label_input_bit->setText(output);

    SHA_c sha;
    string hash;
    hash = sha.sha1_cal(input_iv.toUtf8().data());
    hash = sha.str2hex(hash);
    ui->textBrowser_hash->setText(QString::fromUtf8(hash.c_str()));

    ui->label_hash_mode->setText("SHA-1");
    ui->label_hash_bit->setText("160bit");
}
