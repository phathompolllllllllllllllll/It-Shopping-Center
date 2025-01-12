#include "edit_device_phones.h"
#include "ui_edit_device_phones.h"

edit_device_phones::edit_device_phones(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::edit_device_phones)
{
    ui->setupUi(this);
    cata = cat;
}

edit_device_phones::~edit_device_phones()
{
    delete ui;
}

std::string brand_ph_edit, model_ph_edit, name_ph_edit, processor_ph_edit, os_ph_edit, charger_ph_edit, camera_ph_edit;
int quantity_ph_edit, resolution_1_ph_edit, resolution_2_ph_edit, num_sim_ph_edit, storage_ph_edit, refreash_rate_ph_edit;
double price_ph_edit, dimension_ph1_edit, dimension_ph2_edit, dimension_ph3_edit, wifi_ph_edit, brightness_ph_edit, bluetooth_ph_edit, weight_ph_edit, batterry_ph_edit;
bool biometric_ph1_edit = false, biometric_ph2_edit = false, biometric_ph3_edit = false, have_dualsim_ph_edit = false, have_microSD_ph_edit = false, have_jack_ph_edit = false, has_pen_ph_edit = false;

void edit_device_phones::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;

    brand_ph_edit = ui->brand_lineEdit->text().toStdString();
    model_ph_edit = ui->model_lineEdit->text().toStdString();
    price_ph_edit = ui->price_lineEdit->text().toDouble(&a);
    quantity_ph_edit = ui->quantity_lineEdit->text().toInt(&b);
    name_ph_edit = ui->des_lineEdit->text().toStdString();
    resolution_1_ph_edit = ui->resolution_lineEdit_1->text().toInt(&c);
    resolution_2_ph_edit = ui->resolution_lineEdit_2->text().toInt(&d);
    processor_ph_edit = ui->processor_lineEdit->text().toStdString();
    os_ph_edit = ui->os_lineEdit->text().toStdString();
    charger_ph_edit = ui->charger_lineEdit->text().toStdString();
    camera_ph_edit = ui->camera_spec_lineEdit->text().toStdString();
    num_sim_ph_edit = ui->number_sim_lineEdit->text().toInt(&e);
    dimension_ph1_edit = ui->dimension1_lineEdit->text().toDouble(&f);
    dimension_ph2_edit = ui->dimension2_lineEdit->text().toDouble(&g);
    dimension_ph3_edit = ui->dimension3_lineEdit->text().toDouble(&h);
    storage_ph_edit = ui->storage_lineEdit->text().toInt(&i);
    refreash_rate_ph_edit = ui->refresh_rate_lineEdit->text().toInt(&j);
    wifi_ph_edit = ui->wifi_lineEdit->text().toDouble(&k);
    brightness_ph_edit = ui->brightness_lineEdit->text().toDouble(&l);
    bluetooth_ph_edit = ui->bluetooth_lineEdit->text().toDouble(&m);
    weight_ph_edit = ui->weight_lineEdit->text().toDouble(&n);
    batterry_ph_edit = ui->battery_lineEdit->text().toDouble(&o);

    if(ui->finger_with_controller->isChecked()){
        biometric_ph1_edit = true;
    }
    if(ui->face_with_controller->isChecked()){
        biometric_ph2_edit = true;
    }
    if(ui->iris_with_controller->isChecked()){
        biometric_ph3_edit = true;
    }

    if(ui->have_dual_sim_with_controller->isChecked()){
        have_dualsim_ph_edit = true;
    }
    if(ui->have_micro_sim_with_controller->isChecked()){
        have_microSD_ph_edit = true;
    }
    if(ui->have_jack_with_controller->isChecked()){
        have_jack_ph_edit = true;
    }
    if(ui->has_pen_with_controller->isChecked()){
        has_pen_ph_edit = true;
    }

    if(a && b && c && d && e && f && g && i && h && j && k && l && m && n && o && price_ph_edit >= 0 && quantity_ph_edit > 0) {
        Smartphones phone;
        phone.setID(cata);
        phone.setBrand(brand_ph_edit);
        phone.setModel(model_ph_edit);
        phone.setDescription(name_ph_edit);
        phone.setQuantity(quantity_ph_edit);
        phone.setPrice(price_ph_edit);
        phone.setResolution(resolution_1_ph_edit, resolution_2_ph_edit);
        phone.setProcessor(processor_ph_edit);
        phone.setOS(os_ph_edit);
        phone.setCharger(charger_ph_edit);
        phone.setCameraSpec(camera_ph_edit);
        phone.setNumSim(num_sim_ph_edit);
        phone.setDimensions(dimension_ph1_edit, dimension_ph2_edit, dimension_ph3_edit);
        phone.setStorage(storage_ph_edit);
        phone.setRefreshRate(refreash_rate_ph_edit);
        phone.setWifi(wifi_ph_edit);
        phone.setBrightness(brightness_ph_edit);
        phone.setBluetooth(bluetooth_ph_edit);
        phone.setWeight(weight_ph_edit);
        phone.setBattery(batterry_ph_edit);
        phone.setBiometrics(biometric_ph1_edit, biometric_ph2_edit, biometric_ph3_edit);
        phone.setDualSim(have_dualsim_ph_edit);
        phone.setMicroSD(have_microSD_ph_edit);
        phone.setJack(have_jack_ph_edit);
        phone.setHasPen(has_pen_ph_edit);
        phone.setOnDisplay(true);

        Smartphones::updateVec(phone);

        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Invalid type please try again.");
        ui->brand_lineEdit->clear();
        ui->model_lineEdit->clear();
        ui->des_lineEdit->clear();
        ui->price_lineEdit->clear();
        ui->quantity_lineEdit->clear();
        ui->resolution_lineEdit_1->clear();
        ui->resolution_lineEdit_2->clear();
        ui->processor_lineEdit->clear();
        ui->os_lineEdit->clear();
        ui->charger_lineEdit->clear();
        ui->camera_spec_lineEdit->clear();
        ui->number_sim_lineEdit->clear();
        ui->dimension1_lineEdit->clear();
        ui->dimension2_lineEdit->clear();
        ui->dimension3_lineEdit->clear();
        ui->storage_lineEdit->clear();
        ui->refresh_rate_lineEdit->clear();
        ui->wifi_lineEdit->clear();
        ui->brightness_lineEdit->clear();
        ui->bluetooth_lineEdit->clear();
        ui->weight_lineEdit->clear();
        ui->battery_lineEdit->clear();
        ui->finger_with_controller->setChecked(false);
        ui->face_with_controller->setChecked(false);
        ui->iris_with_controller->setChecked(false);
        ui->have_dual_sim_with_controller->setChecked(false);
        ui->have_micro_sim_with_controller->setChecked(false);
        ui->have_jack_with_controller->setChecked(false);
        ui->has_pen_with_controller->setChecked(false);

    }
}

