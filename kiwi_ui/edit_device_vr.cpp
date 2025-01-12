#include "edit_device_vr.h"
#include "ui_edit_device_vr.h"

Edit_device::Edit_device(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Edit_device)
{
    ui->setupUi(this);
    cata = cat;
}

Edit_device::~Edit_device()
{
    delete ui;
}

std::string brand, model, name, display, type_usb;
int quantity, resolution1, resolution2, max_refreshrate;
double price, field_view, size_display;
bool have_controller = false, have = false;

void Edit_device::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g;

    model = ui->model_lineEdit_2->text().toStdString();
    brand = ui->brand_lineEdit_2->text().toStdString();
    name = ui->des_lineEdit_2->text().toStdString();
    display = ui->display_lineEdit_2->text().toStdString();
    type_usb = ui->usb_lineEdit_2->text().toStdString();
    quantity = ui->quantity_lineEdit_2->text().toInt(&a);
    resolution1 = ui->resolution_lineEdit_3->text().toInt(&b);
    resolution2 = ui->resolution_lineEdit_4->text().toInt(&c);
    max_refreshrate = ui->max_refreah_lineEdit_2->text().toInt(&d);
    price = ui->price_lineEdit_2->text().toDouble(&e);
    field_view = ui->field_v_lineEdit_2->text().toDouble(&f);
    size_display = ui->size_lineEdit_2->text().toDouble(&g);

    if(ui->with_controller_2->isChecked()){
        have_controller = true;
    }

    if(a && b && c && d && e && f && g && price >= 0 && quantity > 0) {
        VR vr1;
        vr1.setID(cata);
        vr1.setModel(model);
        vr1.setBrand(brand);
        vr1.setDescription(name);
        vr1.setDisplay(display);
        vr1.setUsbCable(type_usb);
        vr1.setQuantity(quantity);
        vr1.setResolution(resolution1, resolution2);
        vr1.setRefreshRate(max_refreshrate);
        vr1.setPrice(price);
        vr1.setFieldOfView(field_view);
        vr1.setSizeDisplayInch(size_display);
        vr1.setWithControllers(have_controller);
        vr1.setOnDisplay(true);

        //         have = true;
        //     }
        // }
        // if(have == false){
        //     QMessageBox::information(this, "ID", "Invalid id");
        // }

        VR::updateVec(vr1);
        this->close();

    } else {
        QMessageBox::warning(this, "Error", "Invalid type please try again.");
        ui->brand_lineEdit_2->clear();
        ui->model_lineEdit_2->clear();
        ui->quantity_lineEdit_2->clear();
        ui->resolution_lineEdit_3->clear();
        ui->resolution_lineEdit_4->clear();
        ui->price_lineEdit_2->clear();
        ui->des_lineEdit_2->clear();
        ui->display_lineEdit_2->clear();
        ui->usb_lineEdit_2->clear();
        ui->resolution_lineEdit_3->clear();
        ui->resolution_lineEdit_4->clear();
        ui->max_refreah_lineEdit_2->clear();
        ui->field_v_lineEdit_2->clear();
        ui->size_lineEdit_2->clear();
    }



}

