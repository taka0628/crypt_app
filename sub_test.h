#ifndef SUB_TEST_H
#define SUB_TEST_H

#include <QMainWindow>

namespace Ui {
class sub_test;
}

class sub_test : public QMainWindow
{
    Q_OBJECT

public:
    explicit sub_test(QWidget *parent = 0);
    ~sub_test();

private:
    Ui::sub_test *ui;
};

#endif // SUB_TEST_H
