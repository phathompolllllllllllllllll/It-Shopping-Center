#ifndef EDIT_DEVICE_PHONES_H
#define EDIT_DEVICE_PHONES_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class edit_device_phones;
}

class edit_device_phones : public QDialog
{
    Q_OBJECT

public:
    explicit edit_device_phones(QWidget *parent = nullptr, std::string cat = "");
    ~edit_device_phones();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::edit_device_phones *ui;
    std::string cata;
};

#endif // EDIT_DEVICE_PHONES_H
