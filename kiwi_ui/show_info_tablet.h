#ifndef SHOW_INFO_TABLET_H
#define SHOW_INFO_TABLET_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class Show_info_tablet;
}

class Show_info_tablet : public QDialog
{
    Q_OBJECT

public:
    explicit Show_info_tablet(QWidget *parent = nullptr, std::string cat = "");
    ~Show_info_tablet();

private:
    Ui::Show_info_tablet *ui;
    std::string cata;
};

#endif // SHOW_INFO_TABLET_H
