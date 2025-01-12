#ifndef SHOW_INFO_HANDHELD_H
#define SHOW_INFO_HANDHELD_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class Show_info_Handheld;
}

class Show_info_Handheld : public QDialog
{
    Q_OBJECT

public:
    explicit Show_info_Handheld(QWidget *parent = nullptr, std::string cat = "");
    ~Show_info_Handheld();

private:
    Ui::Show_info_Handheld *ui;
    std::string cata;
};

#endif // SHOW_INFO_HANDHELD_H
