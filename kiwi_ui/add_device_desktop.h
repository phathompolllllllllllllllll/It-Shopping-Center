#ifndef ADD_DEVICE_DESKTOP_H
#define ADD_DEVICE_DESKTOP_H

#include <QDialog>
#include "all_list.h"
#include <QMessageBox>

namespace Ui {
class Add_device_desktop;
}

class Add_device_desktop : public QDialog
{
    Q_OBJECT

public:
    explicit Add_device_desktop(QWidget *parent = nullptr, std::string cat = "");
    ~Add_device_desktop();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::Add_device_desktop *ui;
    std::string cata;
};

#endif // ADD_DEVICE_DESKTOP_H
