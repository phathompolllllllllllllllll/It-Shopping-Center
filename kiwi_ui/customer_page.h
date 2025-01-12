#ifndef CUSTOMER_PAGE_H
#define CUSTOMER_PAGE_H

#include <QDialog>
#include "all_list.h"
#include <vector>
#include <any>
#include "show_info.h"
#include "add_to_cart.h"
#include "../logic_classes.h"
#include "cart.h"
#include <QDebug>

namespace Ui {
class customer_page;
}

class customer_page : public QDialog
{
    Q_OBJECT

public:
    explicit customer_page(QWidget *parent = nullptr);
    ~customer_page();

private slots:
    void on_back_btn_clicked();

    void on_show_btn_clicked();

    void on_add_btn_clicked();

    void on_cart_btn_clicked();

private:
    Ui::customer_page *ui;
};

#endif // CUSTOMER_PAGE_H
