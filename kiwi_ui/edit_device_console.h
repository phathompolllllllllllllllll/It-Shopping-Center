#ifndef EDIT_DEVICE_CONSOLE_H
#define EDIT_DEVICE_CONSOLE_H

#include <QDialog>
#include "all_list.h"
#include "edit_device_handheld.h"
#include "edit_device_stationed.h"
#include <QMessageBox>
namespace Ui {
class edit_device_console;
}

class edit_device_console : public QDialog
{
    Q_OBJECT

public:
    explicit edit_device_console(QWidget *parent = nullptr, std::string cat = "");
    ~edit_device_console();

private slots:
    void on_handheld_btn_clicked();

    void on_Stationed_btn_clicked();

private:
    Ui::edit_device_console *ui;
    std::string cata;
};

#endif // EDIT_DEVICE_CONSOLE_H
