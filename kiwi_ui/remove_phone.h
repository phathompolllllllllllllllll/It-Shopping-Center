#ifndef REMOVE_PHONE_H
#define REMOVE_PHONE_H

#include <QDialog>

namespace Ui {
class Remove_phone;
}

class Remove_phone : public QDialog
{
    Q_OBJECT

public:
    explicit Remove_phone(QWidget *parent = nullptr, std::string cat = "");
    ~Remove_phone();

private slots:
    void on_ok_btn_clicked();

private:
    Ui::Remove_phone *ui;
    std::string cata;
};

#endif // REMOVE_PHONE_H
