#ifndef DEVELOP_PAGE_H
#define DEVELOP_PAGE_H

#include <QDialog>

#include "all_list.h"
#include <fstream>


namespace Ui {
class develop_page;
}

class develop_page : public QDialog
{
    Q_OBJECT

public:
    explicit develop_page(QWidget *parent = nullptr);
    ~develop_page();



private slots:


    void on_vr_btn_clicked();

    void on_console_btn_clicked();

    void on_desktop_btn_clicked();

    void on_laptop_btn_clicked();

    void on_phone_btn_clicked();

    void on_watch_btn_clicked();

    void on_tablet_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::develop_page *ui;

};

#endif // DEVELOP_PAGE_H
