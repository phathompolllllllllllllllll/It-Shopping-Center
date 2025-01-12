#ifndef SHOW_INFO_PHONE_H
#define SHOW_INFO_PHONE_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class Show_info_phone;
}

class Show_info_phone : public QDialog
{
    Q_OBJECT

public:
    explicit Show_info_phone(QWidget *parent = nullptr, std::string cat = "");
    ~Show_info_phone();

private:
    Ui::Show_info_phone *ui;
    std::string cata;
};

#endif // SHOW_INFO_PHONE_H
