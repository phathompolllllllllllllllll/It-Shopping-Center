#ifndef REMOVE_VR_H
#define REMOVE_VR_H

#include <QDialog>
#include "all_list.h"
#include <fstream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <filesystem>
#include <sstream>
#include <string>
#include <array>
#include <tuple>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <QDebug>

namespace Ui {
class Remove_vr;
}

class Remove_vr : public QDialog
{
    Q_OBJECT

public:
    explicit Remove_vr(QWidget *parent = nullptr, std::string cat = "");
    ~Remove_vr();

private slots:
    void on_ok_btn_clicked();

private:
    Ui::Remove_vr *ui;
    std::string cata;
};

#endif // REMOVE_VR_H
