#include "rsa_wind.h"
#include "ui_rsa_wind.h"
#include "RSA_c.hpp"

rsa_wind::rsa_wind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rsa_wind)
{
    ui->setupUi(this);
}

rsa_wind::~rsa_wind()
{
    delete ui;
}

static int RSA_BIT = 2048;
static bool canCalc = false;

using namespace std;


void rsa_wind::on_radioButton_2048_toggled(bool checked)
{
    if(checked){
        RSA_BIT = 2048;
        std::cout << "RSA_BIT: " << RSA_BIT << std::endl;
        ui->label_status_bit->setText(QString::fromStdString(to_string(RSA_BIT)));
        this->on_lineEdit_input_textChanged(ui->lineEdit_input->text());
    }
}

void rsa_wind::on_radioButton_4096_toggled(bool checked)
{
    if(checked){
        RSA_BIT = 4096;
        std::cout << "RSA_BIT: " << RSA_BIT << std::endl;
        ui->label_status_bit->setText(QString::fromStdString(to_string(RSA_BIT)));
        this->on_lineEdit_input_textChanged(ui->lineEdit_input->text());
    }
}

void rsa_wind::on_radioButton_8192_toggled(bool checked)
{
    if(checked){
        RSA_BIT = 8192;
        std::cout << "RSA_BIT: " << RSA_BIT << std::endl;
        ui->label_status_bit->setText(QString::fromStdString(to_string(RSA_BIT)));
        this->on_lineEdit_input_textChanged(ui->lineEdit_input->text());
    }
}

void rsa_wind::on_radioButton_other_toggled(bool checked)
{
    if(checked){
        RSA_BIT = ui->lineEdit_bit->text().toInt(nullptr, 10);
        std::cout << "RSA_BIT: " << RSA_BIT << std::endl;
        ui->label_status_bit->setText(QString::fromStdString(to_string(RSA_BIT)));
        this->on_lineEdit_input_textChanged(ui->lineEdit_input->text());
    }
}

void rsa_wind::on_pushButton_enc_pressed()
{
    if(canCalc){
        RSA_c rsa;
        string input_text = ui->lineEdit_input->text().toStdString();
        rsa.create_key(RSA_BIT);
        string enc_text(rsa.encrypt(input_text));
        enc_text = rsa.str2hex(enc_text);
        ui->textBrowser_output->setText(QString::fromStdString(enc_text));
        ui->textBrowser_out_privkey->setText(QString::fromStdString(rsa.get_string_key(RSA_c::KEY_STATUS::PRIV_KEY)));
        ui->textBrowser_out_pubkey->setText(QString::fromStdString(rsa.get_string_key(RSA_c::KEY_STATUS::PUB_KEY)));
    }
}

void rsa_wind::on_lineEdit_input_textChanged(const QString &arg1)
{
    string input_text(arg1.toStdString());
    int text_size = input_text.length() * 8;
    stringstream oss;
    QString out;
    oss << text_size;
    out.push_back(QString::fromStdString(oss.str()));
    if(text_size <= RSA_BIT){
        out.push_back("bit | ok");
        canCalc = true;
    }else{
        out.push_back("bit | ng");
        canCalc = false;
    }
    ui->label_input_check_bit->setText(out);
}

void rsa_wind::on_pushButton_cpy_pressed()
{
    ui->textBrowser_output->selectAll();
    ui->textBrowser_output->copy();
}

void rsa_wind::on_pushButton_dec_pressed()
{
    string input(ui->lineEdit_input->text().toStdString());
    int size = input.size()/2;
    if(size <= RSA_BIT){
        RSA_c rsa;
        rsa.set_key();
        string input_text = ui->lineEdit_input->text().toStdString();
        cout << "input_text: " << input_text << endl;
        input_text = rsa.hex2bin(input_text);
        string enc_text(rsa.decrypt(input_text));
        ui->textBrowser_output->setText(QString::fromStdString(enc_text));
        ui->textBrowser_out_privkey->setText(QString::fromStdString(rsa.get_string_key(RSA_c::KEY_STATUS::PRIV_KEY)));
        ui->textBrowser_out_pubkey->setText(QString::fromStdString(rsa.get_string_key(RSA_c::KEY_STATUS::PUB_KEY)));
    }
}

void rsa_wind::on_lineEdit_bit_textChanged(const QString &arg1)
{
    string input_bit(arg1.toStdString());
    bool isSelect = ui->radioButton_other->isChecked();
    if(isSelect){
        ui->radioButton_other->toggled(isSelect);
    }
}
