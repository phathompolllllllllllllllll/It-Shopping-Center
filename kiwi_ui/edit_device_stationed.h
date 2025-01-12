#ifndef EDIT_DEVICE_STATIONED_H
#define EDIT_DEVICE_STATIONED_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class Edit_device_stationed;
}

class Edit_device_stationed : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_device_stationed(QWidget *parent = nullptr, std::string cat = "");
    ~Edit_device_stationed();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::Edit_device_stationed *ui;
    std::string cata;
};

#endif // EDIT_DEVICE_STATIONED_H
