#ifndef SHOW_INFO_DESTOP_H
#define SHOW_INFO_DESTOP_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class Show_info_Destop;
}

class Show_info_Destop : public QDialog
{
    Q_OBJECT

public:
    explicit Show_info_Destop(QWidget *parent = nullptr, std::string cat = "");
    ~Show_info_Destop();

private:
    Ui::Show_info_Destop *ui;
    std::string cata;
};

#endif // SHOW_INFO_DESTOP_H
