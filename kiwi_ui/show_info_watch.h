#ifndef SHOW_INFO_WATCH_H
#define SHOW_INFO_WATCH_H

#include <QDialog>

#include "all_list.h"

namespace Ui {
class Show_info_Watch;
}

class Show_info_Watch : public QDialog
{
    Q_OBJECT

public:
    explicit Show_info_Watch(QWidget *parent = nullptr, std::string cat = "");
    ~Show_info_Watch();

private:
    Ui::Show_info_Watch *ui;
    std::string cata;
};

#endif // SHOW_INFO_WATCH_H
