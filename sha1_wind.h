#ifndef SHA_WIND_H
#define SHA_WIND_H

#include <QDialog>

namespace Ui {
class sha_wind;
}

class sha_wind : public QDialog
{
    Q_OBJECT

public:
    explicit sha_wind(QWidget *parent = 0);
    ~sha_wind();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::sha_wind *ui;
};

#endif // SHA_WIND_H
