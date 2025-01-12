#ifndef ADD_DEVICE_HANDHELD_H
#define ADD_DEVICE_HANDHELD_H

#include <QDialog>
#include "all_list.h"
#include <QMessageBox>

namespace Ui {
class add_device_handheld;
}

class add_device_handheld : public QDialog
{
    Q_OBJECT

public:
    explicit add_device_handheld(QWidget *parent = nullptr, std::string cat = "");
    ~add_device_handheld();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::add_device_handheld *ui;
    std::string cata;
};

#endif // ADD_DEVICE_HANDHELD_H
