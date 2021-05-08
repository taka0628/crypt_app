#ifndef AES_WIND_H
#define AES_WIND_H

#include <QDialog>

namespace Ui {
class aes_wind;
}

class aes_wind : public QDialog
{
    Q_OBJECT

public:
    explicit aes_wind(QWidget *parent = 0);
    ~aes_wind();

private slots:
    void on_radioButton_aes128_toggled(bool checked);

    void on_radioButton_aes256_toggled(bool checked);

    void on_lineEdit_key_textChanged(const QString &arg1);

    void on_lineEdit_iv_textChanged(const QString &arg1);

    void on_pushButton_enc_pressed();

    void on_pushButton_dec_pressed();

    void on_pushButton_cpy_pressed();

private:
    Ui::aes_wind *ui;
};

#endif // AES_WIND_H
