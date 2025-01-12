#ifndef EDIT_DEVICE_VR_H
#define EDIT_DEVICE_VR_H

#include <QDialog>
#include "all_list.h"
#include "QMessageBox"

namespace Ui {
class Edit_device;
}

class Edit_device : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_device(QWidget *parent = nullptr, std::string cat = "");
    ~Edit_device();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::Edit_device *ui;
    std::string cata;
};

#endif // EDIT_DEVICE_VR_H
