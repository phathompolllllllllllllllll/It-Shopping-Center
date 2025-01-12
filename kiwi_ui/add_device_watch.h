#ifndef ADD_DEVICE_WATCH_H
#define ADD_DEVICE_WATCH_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class add_device_watch;
}

class add_device_watch : public QDialog
{
    Q_OBJECT

public:
    explicit add_device_watch(QWidget *parent = nullptr, std::string cat = "");
    ~add_device_watch();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::add_device_watch *ui;
    std::string cata;
};

#endif // ADD_DEVICE_WATCH_H
