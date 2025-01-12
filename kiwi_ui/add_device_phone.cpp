#include "add_device_phone.h"
#include "ui_add_device_phone.h"

add_device_phone::add_device_phone(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::add_device_phone)
{
    ui->setupUi(this);
    cata = cat;
}

add_device_phone::~add_device_phone()
{
    delete ui;
}

std::string brand_ph, model_ph, name_ph, display_ph, processor_ph, os_ph, charger_ph, camera_ph;
int quantity_ph, resolution_1_ph, resolution_2_ph, num_sim_ph, storage_ph, refreash_rate_ph;
double price_ph, dimension_ph1, dimension_ph2, dimension_ph3, wifi_ph, brightness_ph, bluetooth_ph, weight_ph, batterry_ph;
bool biometric_ph1 = false, biometric_ph2 = false, biometric_ph3 = false, have_dualsim_ph = false, have_microSD_ph = false, have_jack_ph = false, has_pen_ph = false;

void add_device_phone::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;
    price_ph = ui->price_lineEdit->text().toDouble(&a);
    quantity_ph = ui->quantity_lineEdit->text().toInt(&b);
    brand_ph = ui->brand_lineEdit->text().toStdString();
    model_ph = ui->model_lineEdit->text().toStdString();
    name_ph = ui->des_lineEdit->text().toStdString();
    resolution_1_ph = ui->resolution_lineEdit_1->text().toInt(&c);
    resolution_2_ph = ui->resolution_lineEdit_2->text().toInt(&d);
    processor_ph = ui->processor_lineEdit->text().toStdString();
    os_ph = ui->os_lineEdit->text().toStdString();
    charger_ph = ui->charger_lineEdit->text().toStdString();
    camera_ph = ui->camera_spec_lineEdit->text().toStdString();
    num_sim_ph = ui->number_sim_lineEdit->text().toInt(&e);
    dimension_ph1 = ui->dimension1_lineEdit->text().toDouble(&f);
    dimension_ph2 = ui->dimension2_lineEdit->text().toDouble(&g);
    dimension_ph3 = ui->dimension3_lineEdit->text().toDouble(&h);
    storage_ph = ui->storage_lineEdit->text().toInt(&i);
    refreash_rate_ph = ui->refresh_rate_lineEdit->text().toInt(&j);
    wifi_ph = ui->wifi_lineEdit->text().toDouble(&k);
    brightness_ph = ui->brightness_lineEdit->text().toDouble(&l);
    bluetooth_ph = ui->bluetooth_lineEdit->text().toDouble(&m);
    weight_ph = ui->weight_lineEdit->text().toDouble(&n);
    batterry_ph = ui->battery_lineEdit->text().toDouble(&o);

    if(ui->finger_with_controller->isChecked()){
        biometric_ph1 = true;
    }
    if(ui->face_with_controller->isChecked()){
        biometric_ph2 = true;
    }
    if(ui->iris_with_controller->isChecked()){
        biometric_ph3 = true;
    }

    if(ui->have_dual_sim_with_controller->isChecked()){
        have_dualsim_ph = true;
    }
    if(ui->have_micro_sim_with_controller->isChecked()){
        have_microSD_ph = true;
    }
    if(ui->have_jack_with_controller->isChecked()){
        have_jack_ph = true;
    }
    if(ui->has_pen_with_controller->isChecked()){
        has_pen_ph = true;
    }

    if(a && b && c && d && e && f && g && i && h && j && k && l && m && n && o && price_ph >= 0 && quantity_ph > 0) {
        Smartphones phone(quantity_ph, price_ph);

        phone.setBrand(brand_ph);
        phone.setModel(model_ph);
        phone.setDescription(name_ph);
        phone.setResolution(resolution_1_ph, resolution_2_ph);
        phone.setProcessor(processor_ph);
        phone.setOS(os_ph);
        phone.setCharger(charger_ph);
        phone.setCameraSpec(camera_ph);
        phone.setNumSim(num_sim_ph);
        phone.setDimensions(dimension_ph1, dimension_ph2, dimension_ph3);
        phone.setStorage(storage_ph);
        phone.setRefreshRate(refreash_rate_ph);
        phone.setWifi(wifi_ph);
        phone.setBrightness(brightness_ph);
        phone.setBluetooth(bluetooth_ph);
        phone.setWeight(weight_ph);
        phone.setBattery(batterry_ph);
        phone.setBiometrics(biometric_ph1, biometric_ph2, biometric_ph3);
        phone.setDualSim(have_dualsim_ph);
        phone.setMicroSD(have_microSD_ph);
        phone.setJack(have_jack_ph);
        phone.setHasPen(has_pen_ph);
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

