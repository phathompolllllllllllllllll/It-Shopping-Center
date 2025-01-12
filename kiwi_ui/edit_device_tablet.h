#ifndef EDIT_DEVICE_TABLET_H
#define EDIT_DEVICE_TABLET_H

#include <QDialog>
#include "all_list.h"
#include "QMessageBox"

namespace Ui {
class Edit_device_tablet;
}

class Edit_device_tablet : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_device_tablet(QWidget *parent = nullptr, std::string cat = "");
    ~Edit_device_tablet();

private slots:
    void on_OK_btn_clicked();

private:
    Ui::Edit_device_tablet *ui;
    std::string cata;
};

#endif // EDIT_DEVICE_TABLET_H
