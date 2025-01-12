#ifndef SHOW_INFO_LAPTOP_H
#define SHOW_INFO_LAPTOP_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class Show_info_laptop;
}

class Show_info_laptop : public QDialog
{
    Q_OBJECT

public:
    explicit Show_info_laptop(QWidget *parent = nullptr, std::string cat = "");
    ~Show_info_laptop();

private:
    Ui::Show_info_laptop *ui;
    std::string cata;
};

#endif // SHOW_INFO_LAPTOP_H
