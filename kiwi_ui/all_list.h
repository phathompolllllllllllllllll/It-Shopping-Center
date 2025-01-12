#ifndef ALL_LIST_H
#define ALL_LIST_H

#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QCloseEvent>
#include "../logic_classes.h"
#include <QPixmap>
#include <QLabel>
#include <QtWidgets>
#include <QString>
#include <QScrollBar>
#include <QScrollArea>
#include <QVBoxLayout>
#include "edit_main.h"
#include <QCloseEvent>
#include <QVector>
#include <QDebug>
#include "add_device_vr.h"
#include "remove_vr.h"
#include <vector>
#include <set>
#include "add_device_phone.h"
#include "add_device_tablet.h"
#include "add_device_desktop.h"
#include "add_device_laptop.h"
#include "add_device_watch.h"
#include "add_device_console.h"
#include <any>





namespace Ui {
class All_list;
}

class All_list : public QDialog
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event) override;


public:
    explicit All_list(QWidget *parent = nullptr, std::string = "");
    ~All_list();


private slots:
    void on_add_btn_clicked();

    void on_edit_btn_clicked();


    void on_remove_btn_clicked();

private:
    Ui::All_list *ui;
    QGridLayout *PanelButtonGridLayout;
    std::string cata;
    QVector<QLabel *> dynamicLabels;
    QVector<QScrollArea *> dynamicScroll;
    QVector<QWidget *> dynamicQWidget;
    QVector<QVBoxLayout *> dynamicQVBoxLayout;

};

#endif // ALL_LIST_H
