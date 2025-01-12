#ifndef EDIT_DEVICE_LAPTOP_H
#define EDIT_DEVICE_LAPTOP_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class edit_device_laptop;
}

class edit_device_laptop : public QDialog
{
    Q_OBJECT

public:
    explicit edit_device_laptop(QWidget *parent = nullptr, std::string cat = "");
    ~edit_device_laptop();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::edit_device_laptop *ui;
    std::string cata;
};

#endif // EDIT_DEVICE_LAPTOP_H
