#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sub_test.h>
#include <aes_wind.h>
#include <sha1_wind.h>
#include <sha2_wind.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_aes_pressed();

    void on_pushButton_sha1_pressed();

    void on_pushButton_sha2_pressed();

private:
    Ui::MainWindow *ui;
    sub_test *sub_wind;
    aes_wind *aes_wind_;
    sha_wind *sha_wind_;
    sha2_wind *sha2_wind_;

};

#endif // MAINWINDOW_H
