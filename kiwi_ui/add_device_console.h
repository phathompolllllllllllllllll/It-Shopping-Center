#ifndef ADD_DEVICE_CONSOLE_H
#define ADD_DEVICE_CONSOLE_H

#include <QDialog>
#include "add_device_handheld.h"
#include "add_device_stationed.h"
#include "all_list.h"

namespace Ui {
class add_device_console;
}

class add_device_console : public QDialog
{
    Q_OBJECT

public:
    explicit add_device_console(QWidget *parent = nullptr, std::string cat = "");
    ~add_device_console();

private slots:
    void on_handheld_btn_clicked();

    void on_Stationed_btn_clicked();

private:
    Ui::add_device_console *ui;
    std::string cata;
};

#endif // ADD_DEVICE_CONSOLE_H
