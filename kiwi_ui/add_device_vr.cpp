#include "add_device_vr.h"
#include "ui_add_device_vr.h"

Add_device_vr::Add_device_vr(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Add_device_vr)
{
    ui->setupUi(this);
    cata = cat;
}

Add_device_vr::~Add_device_vr()
{
    delete ui;
}


std::string brandd, model1, namee, displayy, type_usbb;
int quantityy, resolution11, resolution22, max_refreshratee;
double pricee, field_vieww, size_displayy;
bool have_controllerr = false, havee = false;

void Add_device_vr::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g;
    pricee = ui->price_lineEdit->text().toDouble(&a);
    quantityy = ui->quantity_lineEdit->text().toInt(&b);
    model1 = ui->model_lineEdit->text().toStdString();
    brandd = ui->brand_lineEdit->text().toStdString();
    namee = ui->des_lineEdit->text().toStdString();
    displayy = ui->display_lineEdit->text().toStdString();
    type_usbb = ui->usb_lineEdit->text().toStdString();
    // quantity = ui->quantity_lineEdit->text().toInt();
    resolution11 = ui->resolution_lineEdit_1->text().toInt(&c);
    resolution22 = ui->resolution_lineEdit_2->text().toInt(&d);
    max_refreshratee = ui->max_refreah_lineEdit->text().toInt(&e);
    // price = ui->price_lineEdit->text().toDouble();
    field_vieww = ui->field_v_lineEdit->text().toDouble(&f);
    size_displayy = ui->size_lineEdit->text().toDouble(&g);


    if(ui->with_controller->isChecked()){
        have_controllerr = true;
    }

    if(a && b && c && d && e && f && g && pricee >= 0 && quantityy > 0) {
        VR vr1(quantityy, pricee);

        vr1.setModel(model1);
        vr1.setBrand(brandd);
        vr1.setDescription(namee);
        vr1.setDisplay(displayy);
        vr1.setUsbCable(type_usbb);
        vr1.setResolution(resolution11, resolution22);
        vr1.setRefreshRate(max_refreshratee);
        vr1.setFieldOfView(field_vieww);
        vr1.setSizeDisplayInch(size_displayy);
        vr1.setWithControllers(have_controllerr);
        vr1.setOnDisplay(true);

        VR::updateVec(vr1);

        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Invalid type please try again.");
        ui->brand_lineEdit->clear();
        ui->model_lineEdit->clear();
        ui->quantity_lineEdit->clear();
        ui->resolution_lineEdit_1->clear();
        ui->resolution_lineEdit_2->clear();
        ui->price_lineEdit->clear();
        ui->des_lineEdit->clear();
        ui->display_lineEdit->clear();
        ui->usb_lineEdit->clear();
        ui->resolution_lineEdit_1->clear();
        ui->resolution_lineEdit_2->clear();
        ui->max_refreah_lineEdit->clear();
        ui->field_v_lineEdit->clear();
        ui->size_lineEdit->clear();
    }

}

