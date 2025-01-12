#ifndef ADD_DEVICE_PHONE_H
#define ADD_DEVICE_PHONE_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class add_device_phone;
}

class add_device_phone : public QDialog
{
    Q_OBJECT

public:
    explicit add_device_phone(QWidget *parent = nullptr, std::string cat = "");
    ~add_device_phone();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::add_device_phone *ui;
    std::string cata;
};

#endif // ADD_DEVICE_PHONE_H
