#ifndef ADD_DEVICE_VR_H
#define ADD_DEVICE_VR_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class Add_device_vr;
}

class Add_device_vr : public QDialog
{
    Q_OBJECT

public:
    explicit Add_device_vr(QWidget *parent = nullptr, std::string cat = "");
    ~Add_device_vr();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::Add_device_vr *ui;
    std::string cata;
};

#endif // ADD_DEVICE_VR_H
