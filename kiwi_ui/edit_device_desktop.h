#ifndef EDIT_DEVICE_DESKTOP_H
#define EDIT_DEVICE_DESKTOP_H

#include <QDialog>
#include "all_list.h"


namespace Ui {
class edit_device_desktop;
}

class edit_device_desktop : public QDialog
{
    Q_OBJECT

public:
    explicit edit_device_desktop(QWidget *parent = nullptr, std::string cat = "");
    ~edit_device_desktop();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::edit_device_desktop *ui;
    std::string cata;
};

#endif // EDIT_DEVICE_DESKTOP_H
