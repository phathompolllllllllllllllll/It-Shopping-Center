#ifndef SHOW_INFO_VR_H
#define SHOW_INFO_VR_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class Show_info_VR;
}

class Show_info_VR : public QDialog
{
    Q_OBJECT

public:
    explicit Show_info_VR(QWidget *parent = nullptr, std::string cat = "");
    ~Show_info_VR();

private:
    Ui::Show_info_VR *ui;
    std::string cata;
};

#endif // SHOW_INFO_VR_H
