#ifndef EDIT_DEVICE_WATCH_H
#define EDIT_DEVICE_WATCH_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class edit_device_watch;
}

class edit_device_watch : public QDialog
{
    Q_OBJECT

public:
    explicit edit_device_watch(QWidget *parent = nullptr, std::string cat = "");
    ~edit_device_watch();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::edit_device_watch *ui;
    std::string cata;
};

#endif // EDIT_DEVICE_WATCH_H
