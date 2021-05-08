#include "sha2_wind.h"
#include "ui_sha2_wind.h"
#include "sha_c.hpp"

sha2_wind::sha2_wind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sha2_wind)
{
    ui->setupUi(this);
}

sha2_wind::~sha2_wind()
{
    delete ui;
}

using namespace std;

static int HASH_BIT = 224;

void sha2_wind::on_radioButton_224_toggled(bool checked)
{
    if(checked){
        HASH_BIT = 224;
        QString text = ui->lineEdit->text();
        if(text.length() > 0){
            this->on_lineEdit_textChanged(text);
        }
        cout << "HASH_BIT: " << HASH_BIT << endl;
    }
}

void sha2_wind::on_radioButton_256_toggled(bool checked)
{
    if(checked){
        HASH_BIT = 256;
        QString text = ui->lineEdit->text();
        if(text.length() > 0){
            this->on_lineEdit_textChanged(text);
        }
        cout << "HASH_BIT: " << HASH_BIT << endl;
    }
}

void sha2_wind::on_radioButton_384_toggled(bool checked)
{
    if(checked){
        HASH_BIT = 384;
        QString text = ui->lineEdit->text();
        if(text.length() > 0){
            this->on_lineEdit_textChanged(text);
        }
        cout << "HASH_BIT: " << HASH_BIT << endl;
    }
}

void sha2_wind::on_radioButton_512_toggled(bool checked)
{
    if(checked){
        HASH_BIT = 512;
        QString text = ui->lineEdit->text();
        if(text.length() > 0){
            this->on_lineEdit_textChanged(text);
        }
        cout << "HASH_BIT: " << HASH_BIT << endl;
    }
}

void sha2_wind::on_lineEdit_textChanged(const QString &arg1)
{
    string input_text = arg1.toStdString();
    QString output;
    ostringstream oss;
    int iv_size = input_text.size();
    iv_size = iv_size * 4;
    oss<< iv_size;
    output.push_back(oss.str().c_str());

    output.push_back("bit");
    ui->label_input_bit->setText(output);

    SHA_c sha;
    string hash;
    switch (HASH_BIT) {
    case 224:
        hash = sha.sha2_cal(input_text, sha.SHA2_bit::SHA_224);
        break;
    case 256:
        hash = sha.sha2_cal(input_text, sha.SHA2_bit::SHA_256);
        break;
    case 384:
        hash = sha.sha2_cal(input_text, sha.SHA2_bit::SHA_384);
        break;
    case 512:
        hash = sha.sha2_cal(input_text, sha.SHA2_bit::SHA_512);
        break;
    default:
        break;
    }
    hash = sha.str2hex(hash);

    ui->textBrowser_hash->setText(QString::fromStdString(hash));

    ui->label_hash_mode->setText("SHA-2");
    ui->label_hash_bit->setText(QString::fromStdString(to_string(HASH_BIT)));
}
