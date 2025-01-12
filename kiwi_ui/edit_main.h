#ifndef EDIT_MAIN_H
#define EDIT_MAIN_H

#include <QDialog>
#include "all_list.h"
#include <QMessageBox>
#include <QDebug>

#include "edit_device_phones.h"
#include "edit_device_tablet.h"
#include "edit_device_vr.h"
#include "edit_device_desktop.h"
#include "edit_device_laptop.h"
#include "edit_device_watch.h"
#include "edit_device_console.h"


namespace Ui {
class Edit_main;
}

class Edit_main : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_main(QWidget *parent = nullptr, std::string = "");
    ~Edit_main();

private slots:
    void on_ok_btn_clicked();

private:
    Ui::Edit_main *ui;
    std::string cata;
};

#endif // EDIT_MAIN_H
