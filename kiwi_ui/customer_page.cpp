#include "customer_page.h"
#include "ui_customer_page.h"

#include <variant>

// using DevicesType = std::variant<
//                                  Handheld,
//                                  Stationed,
//                                  Laptop,
//                                  Desktop,
//                                  Smartphones,
//                                  Smartwatch,
//                                  Tablet,
//                                  VR*>;

// std::vector<DevicesType> cart;


customer_page::customer_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::customer_page)
{
    ui->setupUi(this);
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(120, 120, 1050, 550);
    QWidget *scrollWidget = new QWidget(scrollArea);
    QVBoxLayout *layout = new QVBoxLayout(scrollWidget);
    // QGridLayout *layout = new QGridLayout(scrollWidget);
    for (int i = 0; i < 1; i++) {
        for(int j = 0; j < VR::vr_vec.size(); j++){
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(VR::vr_vec[j].getBrand()) + QString("    Model:  ") + QString::fromStdString(VR::vr_vec[j].getModel()) + QString("    Description:  ") + QString::fromStdString(VR::vr_vec[j].getDescription()) + QString("    Price:  ") + QString::number(VR::vr_vec[j].getPrice()) + QString("    Quantity:  ") + QString::number(VR::vr_vec[j].getQuantity()) + QString("    ID:  ") + QString::fromStdString(VR::vr_vec[j].getID()));
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);
            qDebug() << VR::vr_vec[i].getID();

        }

        for(int k = 0; k < Smartphones::smartphones_vec.size(); k++){
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Smartphones::smartphones_vec[k].getBrand()) + QString("    Model:  ") + QString::fromStdString(Smartphones::smartphones_vec[k].getModel()) + QString("    Description:  ") + QString::fromStdString(Smartphones::smartphones_vec[k].getDescription()) + QString("    Price:  ") + QString::number(Smartphones::smartphones_vec[k].getPrice()) + QString("    Quantity:  ") + QString::number(Smartphones::smartphones_vec[k].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Smartphones::smartphones_vec[k].getID()));
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);
        }

        for(int l = 0; l < Tablet::tablet_vec.size(); l++){
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Tablet::tablet_vec[l].getBrand()) + QString("    Model:  ") + QString::fromStdString(Tablet::tablet_vec[l].getModel()) + QString("    Description:  ") + QString::fromStdString(Tablet::tablet_vec[l].getDescription()) + QString("    Price:  ") + QString::number(Tablet::tablet_vec[l].getPrice()) + QString("    Quantity:  ") + QString::number(Tablet::tablet_vec[l].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Tablet::tablet_vec[l].getID()));
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);
        }

        for(int m = 0; m < Desktop::desktop_vec.size(); m++){
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Desktop::desktop_vec[m].getBrand()) + QString("    Model:  ") + QString::fromStdString(Desktop::desktop_vec[m].getModel()) + QString("    Description:  ") + QString::fromStdString(Desktop::desktop_vec[m].getDescription()) + QString("    Price:  ") + QString::number(Desktop::desktop_vec[m].getPrice()) + QString("    Quantity:  ") + QString::number(Desktop::desktop_vec[m].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Desktop::desktop_vec[m].getID()));
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);
        }

        for(int n = 0; n < Laptop::laptop_vec.size(); n++){
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Laptop::laptop_vec[n].getBrand()) + QString("    Model:  ") + QString::fromStdString(Laptop::laptop_vec[n].getModel()) + QString("    Description:  ") + QString::fromStdString(Laptop::laptop_vec[n].getDescription()) + QString("    Price:  ") + QString::number(Laptop::laptop_vec[n].getPrice()) + QString("    Quantity:  ") + QString::number(Laptop::laptop_vec[n].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Laptop::laptop_vec[n].getID()));
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);
        }

        for(int q = 0; q < Smartwatch::smartwatch_vec.size(); q++){
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[q].getBrand()) + QString("    Model:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[q].getModel()) + QString("    Description:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[q].getDescription()) + QString("    Price:  ") + QString::number(Smartwatch::smartwatch_vec[q].getPrice()) + QString("    Quantity:  ") + QString::number(Smartwatch::smartwatch_vec[q].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Smartwatch::smartwatch_vec[q].getID()));
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);
        }

        for(int r = 0; r < Handheld::handheld_vec.size(); r++){
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Handheld::handheld_vec[r].getBrand()) + QString("    Model:  ") + QString::fromStdString(Handheld::handheld_vec[r].getModel()) + QString("    Description:  ") + QString::fromStdString(Handheld::handheld_vec[r].getDescription()) + QString("    Price:  ") + QString::number(Handheld::handheld_vec[r].getPrice()) + QString("    Quantity:  ") + QString::number(Handheld::handheld_vec[r].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Handheld::handheld_vec[r].getID()));
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);
        }

        for(int g = 0; g < Stationed::stationed_vec.size(); g++){
            QLabel* panelLabel = new QLabel(QString("Brand:  ") + QString::fromStdString(Stationed::stationed_vec[g].getBrand()) + QString("    Model:  ") + QString::fromStdString(Stationed::stationed_vec[g].getModel()) + QString("    Description:  ") + QString::fromStdString(Stationed::stationed_vec[g].getDescription()) + QString("    Price:  ") + QString::number(Stationed::stationed_vec[g].getPrice()) + QString("    Quantity:  ") + QString::number(Stationed::stationed_vec[g].getQuantity()) + QString("    ID:  ") + QString::fromStdString(Stationed::stationed_vec[g].getID()));
            panelLabel->setStyleSheet("border: 1px solid black; padding: 5px; background-color: lightgray;");
            panelLabel->setFixedSize(1000, 100);
            layout->addWidget(panelLabel);
        }
    }

    scrollArea->setWidget(scrollWidget);

}

customer_page::~customer_page()
{
    delete ui;
}

void customer_page::on_back_btn_clicked()
{
    this->close();
    parentWidget()->show();
}


void customer_page::on_show_btn_clicked()
{
    Show_info info(this);
    info.setModal(true);
    info.exec();
}


void customer_page::on_add_btn_clicked()
{
    Add_to_Cart cart(this);
    cart.setModal(true);
    cart.exec();
}


void customer_page::on_cart_btn_clicked()
{

    Cart c(this);
    c.setModal(true);
    c.exec();

}

