#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>
#include "develop_page.h"
#include "customer_page.h"
#include "all_list.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Signin;
}
QT_END_NAMESPACE

class Signin : public QMainWindow
{
    Q_OBJECT

public:
    Signin(QWidget *parent = nullptr);
    ~Signin();

private slots:
    // void on_testBt_clicked();

    // void on_OK_btn_clicked();


    void on_btn_login_dev_clicked();

    void on_btn_customer_clicked();


private:
    Ui::Signin *ui;

};
#endif // SIGNIN_H
