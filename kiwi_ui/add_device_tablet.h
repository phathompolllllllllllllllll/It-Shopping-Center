#ifndef ADD_DEVICE_TABLET_H
#define ADD_DEVICE_TABLET_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class add_device_tablet;
}

class add_device_tablet : public QDialog
{
    Q_OBJECT

public:
    explicit add_device_tablet(QWidget *parent = nullptr, std::string cat = "");
    ~add_device_tablet();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::add_device_tablet *ui;
    std::string cata;
};

#endif // ADD_DEVICE_TABLET_H
