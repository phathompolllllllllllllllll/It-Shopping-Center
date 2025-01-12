#ifndef SHOW_INFO_H
#define SHOW_INFO_H

#include <QDialog>
#include "all_list.h"
#include "show_info_destop.h"
#include "show_info_handheld.h"
#include "show_info_laptop.h"
#include "show_info_phone.h"
#include "show_info_stationed.h"
#include "show_info_tablet.h"
#include "show_info_watch.h"
#include "show_info_vr.h"

namespace Ui {
class Show_info;
}

class Show_info : public QDialog
{
    Q_OBJECT

public:
    explicit Show_info(QWidget *parent = nullptr);
    ~Show_info();

private slots:
    void on_ok_btn_clicked();

private:
    Ui::Show_info *ui;
};

#endif // SHOW_INFO_H
