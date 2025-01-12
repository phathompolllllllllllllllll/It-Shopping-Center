#ifndef EDIT_DEVICE_HANDHELD_H
#define EDIT_DEVICE_HANDHELD_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class Edit_device_handheld;
}

class Edit_device_handheld : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_device_handheld(QWidget *parent = nullptr, std::string cat = "");
    ~Edit_device_handheld();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::Edit_device_handheld *ui;
    std::string cata;
};

#endif // EDIT_DEVICE_HANDHELD_H
