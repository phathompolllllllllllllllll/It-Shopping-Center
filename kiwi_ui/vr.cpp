#include "vr.h"
#include "qpushbutton.h"
#include "ui_vr.h"

Vr::Vr(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Vr)
{
    ui->setupUi(this);
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         QPushButton* panelButton = new QPushButton();
    //         panelButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //         ui->PanelButtonGridLayout->addWidget(panelButton,i,j);
    //     }
    // }
}

Vr::~Vr()
{
    delete ui;
}

void Vr::closeEvent(QCloseEvent *event) {
    event->ignore();
    close();
}
