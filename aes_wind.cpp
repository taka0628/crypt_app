#include "aes_wind.h"
#include "ui_aes_wind.h"
#include "aes_c.hpp"

aes_wind::aes_wind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aes_wind)
{
    ui->setupUi(this);
}

aes_wind::~aes_wind()
{
    delete ui;
}

static int AES_BIT = 128;


void aes_wind::on_radioButton_aes128_toggled(bool checked)
{
    if(checked){
        AES_BIT = 128;
        std::cout << "AES_BIT: " << AES_BIT << std::endl;
        this->on_lineEdit_iv_textChanged(ui->lineEdit_iv->text());
        this->on_lineEdit_key_textChanged(ui->lineEdit_key->text());
    }
}

void aes_wind::on_radioButton_aes256_toggled(bool checked)
{
    if(checked){
        AES_BIT = 256;
        std::cout << "AES_BIT: " << AES_BIT << std::endl;
        this->on_lineEdit_iv_textChanged(ui->lineEdit_iv->text());
        this->on_lineEdit_key_textChanged(ui->lineEdit_key->text());
    }
}

void aes_wind::on_lineEdit_key_textChanged(const QString &arg1)
{
    QString input_key = arg1;
    QString output;
    std::ostringstream oss;
    int key_size = input_key.size();
    key_size = key_size * 4;
    oss<< key_size;
    output.push_back(oss.str().c_str());

    if(key_size == AES_BIT){
        output.push_back("bit | ok");
    }else{
        output.push_back("bit | ng");
    }
    ui->label_check_key->setText(output);
}

void aes_wind::on_lineEdit_iv_textChanged(const QString &arg1)
{
    QString input_iv = arg1;
    QString output;
    std::ostringstream oss;
    int iv_size = input_iv.size();
    iv_size = iv_size * 4;
    oss<< iv_size;
    output.push_back(oss.str().c_str());

    if(iv_size == AES_BIT){
        output.push_back("bit | ok");
    }else{
        output.push_back("bit | ng");
    }
    ui->label_check_iv->setText(output);
}

void aes_wind::on_pushButton_enc_pressed()
{
    aes_c aes;

    QString input_text = ui->textEdit_in->toPlainText();
    QString input_key = ui->lineEdit_key->text();
    int key_len = input_key.size() * 4;
    QString input_iv = ui->lineEdit_iv->text();
    int iv_len = input_iv.size() * 4;

    if(key_len != AES_BIT){
        aes.create_key(AES_BIT);
    }else {
        aes.set_key(input_key.toUtf8().data());
        std::cout << "get_key: " << aes.get_key() << std::endl;
    }
    if(iv_len != AES_BIT){
        aes.create_iv(AES_BIT);
    }else{
        aes.set_iv(input_iv.toUtf8().data());
        std::cout << "get_iv: " << aes.get_iv() << std::endl;
    }

    std::string enc_text;
    if(AES_BIT == 128){
        aes.encrypt(enc_text, input_text.toUtf8().data(), aes_c::AES_bit_e::aes_128);
        ui->label_status_bit->setText(QString::fromUtf8("128bit"));
    }else if(AES_BIT == 256){
        aes.encrypt(enc_text, input_text.toUtf8().data(), aes_c::AES_bit_e::aes_256);
        ui->label_status_bit->setText(QString::fromUtf8("256bit"));
    }
    std::string enc_0x = aes.str2hex(enc_text);

    QString output_enc = QString::fromUtf8(enc_0x.c_str());

    ui->textBrowser_result->setText( output_enc );

    ui->lineEdit_key->setText(aes.get_key().c_str());
    ui->lineEdit_iv->setText(aes.get_iv().c_str());
    ui->label_status_mode->setText(QString::fromUtf8("AES CTR"));
}

void aes_wind::on_pushButton_dec_pressed()
{
    aes_c aes;

    QString input_text = ui->textEdit_in->toPlainText();
    QString input_key = ui->lineEdit_key->text();
    int key_len = input_key.size() * 4;
    QString input_iv = ui->lineEdit_iv->text();
    int iv_len = input_iv.size() * 4;

    if(key_len != AES_BIT){
        ui->lineEdit_key->setText("keyを入力してください");
    }else {
        aes.set_key(input_key.toUtf8().data());
        std::cout << "get_key: " << aes.get_key() << std::endl;
    }

    if(iv_len != AES_BIT){
        ui->lineEdit_key->setText("ivを入力してください");
    }else{
        aes.set_iv(input_iv.toUtf8().data());
        std::cout << "get_iv: " << aes.get_iv() << std::endl;
    }

    std::string dec_text;
    std::string input_text_bin = aes.hex2str(input_text.toUtf8().data());
    if(AES_BIT == 128){
        aes.decrypt(dec_text, input_text_bin, aes_c::AES_bit_e::aes_128);
        ui->label_status_bit->setText(QString::fromUtf8("128bit"));
    }else if(AES_BIT == 256){
        aes.decrypt(dec_text, input_text_bin, aes_c::AES_bit_e::aes_256);
        ui->label_status_bit->setText(QString::fromUtf8("256bit"));
    }

    QString output_dec = QString::fromUtf8(dec_text.c_str());

    ui->textBrowser_result->setText( output_dec );

    ui->lineEdit_key->setText(aes.get_key().c_str());
    ui->lineEdit_iv->setText(aes.get_iv().c_str());
    ui->label_status_mode->setText(QString::fromUtf8("AES CTR"));
}

void aes_wind::on_pushButton_cpy_pressed()
{
    ui->textBrowser_result->selectAll();
    ui->textBrowser_result->copy();
}
