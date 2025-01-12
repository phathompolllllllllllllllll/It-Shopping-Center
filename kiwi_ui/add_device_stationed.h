#ifndef ADD_DEVICE_STATIONED_H
#define ADD_DEVICE_STATIONED_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class add_device_stationed;
}

class add_device_stationed : public QDialog
{
    Q_OBJECT

public:
    explicit add_device_stationed(QWidget *parent = nullptr, std::string cat = "");
    ~add_device_stationed();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::add_device_stationed *ui;
    std::string cata;
};

#endif // ADD_DEVICE_STATIONED_H
