#ifndef SHA2_WIND_H
#define SHA2_WIND_H

#include <QDialog>

namespace Ui {
class sha2_wind;
}

class sha2_wind : public QDialog
{
    Q_OBJECT

public:
    explicit sha2_wind(QWidget *parent = 0);
    ~sha2_wind();

private slots:
    void on_radioButton_224_toggled(bool checked);


    void on_radioButton_256_toggled(bool checked);

    void on_radioButton_384_toggled(bool checked);

    void on_radioButton_512_toggled(bool checked);

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::sha2_wind *ui;
};

#endif // SHA2_WIND_H
