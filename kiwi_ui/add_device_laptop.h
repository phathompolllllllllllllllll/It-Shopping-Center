#ifndef ADD_DEVICE_LAPTOP_H
#define ADD_DEVICE_LAPTOP_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class add_device_laptop;
}

class add_device_laptop : public QDialog
{
    Q_OBJECT

public:
    explicit add_device_laptop(QWidget *parent = nullptr, std::string cat = "");
    ~add_device_laptop();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::add_device_laptop *ui;
    std::string cata;
};

#endif // ADD_DEVICE_LAPTOP_H
