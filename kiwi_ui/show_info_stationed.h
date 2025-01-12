#ifndef SHOW_INFO_STATIONED_H
#define SHOW_INFO_STATIONED_H

#include <QDialog>
#include "all_list.h"

namespace Ui {
class Show_info_Stationed;
}

class Show_info_Stationed : public QDialog
{
    Q_OBJECT

public:
    explicit Show_info_Stationed(QWidget *parent = nullptr, std::string cat = "");
    ~Show_info_Stationed();

private:
    Ui::Show_info_Stationed *ui;
    std::string cata;
};

#endif // SHOW_INFO_STATIONED_H
