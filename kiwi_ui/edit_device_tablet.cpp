#include "edit_device_tablet.h"
#include "ui_edit_device_tablet.h"

Edit_device_tablet::Edit_device_tablet(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Edit_device_tablet)
{
    ui->setupUi(this);
    cata = cat;
}

Edit_device_tablet::~Edit_device_tablet()
{
    delete ui;
}

std::string brand_ta_edit, model_ta_edit, name_ta_edit, display_ta_edit, processor_ta_edit;
std::string os_ta_edit;
std::string storage_ta_edit;
std::string camera_ta_edit;
int quantity_ta_edit;
double price_ta_edit;
double battery_mAh_ta_edit;
std::string bluetooth_ta_edit;
int resolution_1_ta_edit, resolution_2_ta_edit;
double dimension_ta1_edit, dimension_ta2_edit, dimension_ta3_edit;
double weight_ta_edit;
double brightness_nits_ta_edit;
std::string wifi_ta_edit;
bool have_pen_ta_edit = false;
std::string Internal_Memory_ta_edit;
std::string External_Memory_ta_edit;
std::string speaker_ta_edit;
bool biometric_ta1_edit = false, biometric_ta2_edit = false, biometric_ta3_edit = false;
bool is_waterproof_ta_edit = false;

void Edit_device_tablet::on_OK_btn_clicked()
{

    bool a, b, c, d, e, f, g, h, i, j;

    price_ta_edit = ui->price_lineEdit->text().toDouble(&a);
    quantity_ta_edit = ui->quantity_lineEdit->text().toInt(&b);
    brand_ta_edit = ui->brand_lineEdit->text().toStdString();
    model_ta_edit = ui->model_lineEdit->text().toStdString();
    name_ta_edit = ui->des_lineEdit->text().toStdString();
    display_ta_edit = ui->display_lineEdit->text().toStdString();
    resolution_1_ta_edit = ui->resolution_lineEdit_1->text().toInt(&c);
    resolution_2_ta_edit = ui->resolution_lineEdit_2->text().toInt(&d);
    processor_ta_edit = ui->processor_lineEdit->text().toStdString();
    os_ta_edit = ui->os_lineEdit->text().toStdString();
    camera_ta_edit = ui->camera_spec_lineEdit->text().toStdString();
    storage_ta_edit = ui->storage_lineEdit->text().toStdString();
    battery_mAh_ta_edit = ui->battery_lineEdit->text().toDouble(&e);
    bluetooth_ta_edit = ui->bluetooth_lineEdit->text().toStdString();
    dimension_ta1_edit = ui->dimension1_lineEdit->text().toDouble(&f);
    dimension_ta2_edit = ui->dimension2_lineEdit->text().toDouble(&g);
    dimension_ta3_edit = ui->dimension3_lineEdit->text().toDouble(&h);
    weight_ta_edit = ui->weight_lineEdit->text().toDouble(&i);
    brightness_nits_ta_edit = ui->brightness_lineEdit->text().toDouble(&j);
    wifi_ta_edit = ui->wifi_lineEdit->text().toStdString();
    Internal_Memory_ta_edit = ui->internal_Memory->text().toStdString();
    External_Memory_ta_edit = ui->external_memory_lineEdit->text().toStdString();
    speaker_ta_edit = ui->speaker_lineEdit->text().toStdString();

    if(ui->have_pen_with_controller->isChecked()){
        have_pen_ta_edit = true;
    }
    if(ui->finger_with_controller->isChecked()){
        biometric_ta1_edit = true;
    }
    if(ui->face_with_controller->isChecked()){
        biometric_ta2_edit = true;
    }
    if(ui->iris_with_controller->isChecked()){
        biometric_ta3_edit = true;
    }
    if(ui->water_proof_with_controller->isChecked()){
        is_waterproof_ta_edit = true;
    }

    if(a && b && c && d && e && f && g && h && i && j && price_ta_edit >= 0 && quantity_ta_edit > 0) {
        Tablet tablet;
        tablet.setID(cata);
        tablet.setDescription(name_ta_edit);
        tablet.setBrand(brand_ta_edit);
        tablet.setModel(model_ta_edit);
        tablet.setPrice(price_ta_edit);
        tablet.setQuantity(quantity_ta_edit);
        tablet.setOnDisplay(true);
        tablet.setDisplay(display_ta_edit);
        tablet.setProcessor(processor_ta_edit);
        tablet.setOs(os_ta_edit);
        tablet.setStorage(storage_ta_edit);
        tablet.setCamera(camera_ta_edit);
        tablet.setBattery(battery_mAh_ta_edit);
        tablet.setBluetooth(bluetooth_ta_edit);
        tablet.setResolution(resolution_1_ta_edit, resolution_2_ta_edit);
        tablet.setDimensions(dimension_ta1_edit, dimension_ta2_edit, dimension_ta3_edit);
        tablet.setWeight(weight_ta_edit);
        tablet.setBrightness(brightness_nits_ta_edit);
        tablet.setWifi(wifi_ta_edit);
        tablet.setHavePen(have_pen_ta_edit);
        tablet.setInternal_Memory(Internal_Memory_ta_edit);
        tablet.setExternal_Memory(External_Memory_ta_edit);
        tablet.setSpeaker(speaker_ta_edit);
        tablet.setBiometrics(biometric_ta1_edit, biometric_ta2_edit, biometric_ta3_edit);
        tablet.setIsWaterproof(is_waterproof_ta_edit);

        Tablet::updateVec(tablet);

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
        ui->processor_lineEdit->clear();
        ui->storage_lineEdit->clear();
        ui->os_lineEdit->clear();
        ui->camera_spec_lineEdit->clear();
        ui->display_lineEdit->clear();
        ui->battery_lineEdit->clear();
        ui->wifi_lineEdit->clear();
        ui->weight_lineEdit->clear();
        ui->bluetooth_lineEdit->clear();
        ui->dimension1_lineEdit->clear();
        ui->dimension2_lineEdit->clear();
        ui->dimension3_lineEdit->clear();
        ui->brightness_lineEdit->clear();
        ui->internal_Memory->clear();
        ui->external_memory_lineEdit->clear();
        ui->speaker_lineEdit->clear();
        ui->have_pen_with_controller->setChecked(false);
        ui->finger_with_controller->setChecked(false);
        ui->face_with_controller->setChecked(false);
        ui->iris_with_controller->setChecked(false);
        ui->water_proof_with_controller->setChecked(false);
    }



}

