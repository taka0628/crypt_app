#ifndef RSA_WIND_H
#define RSA_WIND_H

#include <QMainWindow>

namespace Ui {
class rsa_wind;
}

class rsa_wind : public QMainWindow
{
    Q_OBJECT

public:
    explicit rsa_wind(QWidget *parent = 0);
    ~rsa_wind();

private slots:
    void on_radioButton_2048_toggled(bool checked);

    void on_radioButton_4096_toggled(bool checked);

    void on_radioButton_8192_toggled(bool checked);

    void on_radioButton_other_toggled(bool checked);

    void on_pushButton_enc_pressed();

    void on_lineEdit_input_textChanged(const QString &arg1);

    void on_pushButton_cpy_pressed();

    void on_pushButton_dec_pressed();

    void on_lineEdit_bit_textChanged(const QString &arg1);

private:
    Ui::rsa_wind *ui;
};

#endif // RSA_WIND_H
