#include "edit_device_handheld.h"
#include "ui_edit_device_handheld.h"

Edit_device_handheld::Edit_device_handheld(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Edit_device_handheld)
{
    ui->setupUi(this);
    cata = cat;
}

Edit_device_handheld::~Edit_device_handheld()
{
    delete ui;
}

std::string brand_ha_edit;
std::string model_ha_edit;
int quantity_ha_edit, resolution_1_ha_edit, resolution_2_ha_edit;
double price_ha_edit;
std::string name_ha_edit;
std::string main_processor_ha_edit;
std::string graphics_processor_ha_edit;
int storage_capacity_ha_edit;
std::string USB_ha_edit;
std::string display_ha_edit;
std::string input_output_port_ha_edit;
std::string wifi_ha_edit;
double weight_ha_edit;
std::string bluetooth_ha_edit;
double power_consumption_ha_edit;
bool controller_vibration_ha_edit = false;
bool TV_mode_ha_edit = false;
std::string battery_ha_edit;
std::string power_supply_ha_edit;
std::string headphone_jack_ha_edit;
int microSD_slot_ha_edit;
std::string size_ha_edit;

void Edit_device_handheld::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g, i;
    brand_ha_edit = ui->brand_lineEdit->text().toStdString();
    model_ha_edit = ui->model_lineEdit->text().toStdString();
    quantity_ha_edit = ui->quantity_lineEdit->text().toInt(&a);
    resolution_1_ha_edit = ui->resolution_lineEdit_1->text().toInt(&b);
    resolution_2_ha_edit = ui->resolution_lineEdit_2->text().toInt(&c);
    price_ha_edit = ui->price_lineEdit->text().toDouble(&d);
    name_ha_edit = ui->des_lineEdit->text().toStdString();
    main_processor_ha_edit = ui->main_processor_lineEdit->text().toStdString();
    graphics_processor_ha_edit = ui->graphiv_processor_lineEdit->text().toStdString();
    storage_capacity_ha_edit = ui->storage_lineEdit->text().toInt(&e);
    USB_ha_edit = ui->USB_lineEdit->text().toStdString();
    display_ha_edit = ui->display_lineEdit->text().toStdString();
    input_output_port_ha_edit = ui->input_output_port->text().toStdString();
    wifi_ha_edit = ui->wifi_lineEdit->text().toStdString();
    weight_ha_edit = ui->weight_lineEdit->text().toDouble(&f);
    bluetooth_ha_edit = ui->bluetooth_lineEdit->text().toStdString();
    power_consumption_ha_edit = ui->power_consum->text().toDouble(&g);
    if(ui->controller_vibra->isChecked()){
        controller_vibration_ha_edit = true;
    }
    if(ui->have_tv_mode->isChecked()){
        TV_mode_ha_edit = true;
    }

    battery_ha_edit = ui->battery_lineEdit->text().toStdString();
    power_supply_ha_edit = ui->power_supply->text().toStdString();
    headphone_jack_ha_edit = ui->headphone_jack->text().toStdString();
    microSD_slot_ha_edit = ui->microSD_slot->text().toInt(&i);
    size_ha_edit = ui->size->text().toStdString();

    if(a && b && c && d && e && f && g && i && price_ha_edit >= 0 && quantity_ha_edit > 0){
        Handheld h;

        h.setPrice(price_ha_edit);
        h.setQuantity(quantity_ha_edit);
        h.setID(cata);
        h.setDescription(name_ha_edit);
        h.setBrand(brand_ha_edit);
        h.setModel(model_ha_edit);
        h.setOnDisplay(true);
        h.setResolution(resolution_1_ha_edit, resolution_2_ha_edit);
        h.setMainProcessor(main_processor_ha_edit);
        h.setGraphicsProcessor(graphics_processor_ha_edit);
        h.setStorageCapacity(storage_capacity_ha_edit);
        h.setUSB(USB_ha_edit);
        h.setDisplay(display_ha_edit);
        h.setInputOutputPort(input_output_port_ha_edit);
        h.setWifi(wifi_ha_edit);
        h.setWeight(weight_ha_edit);
        h.setBluetooth(bluetooth_ha_edit);
        h.setPowerConsumption(power_consumption_ha_edit);
        h.setControllerVibration(controller_vibration_ha_edit);
        h.setTVMode(TV_mode_ha_edit);
        h.setBattery(battery_ha_edit);
        h.setPowerSupply(power_supply_ha_edit);
        h.setHeadphoneJack(headphone_jack_ha_edit);
        h.setMicroSDSlot(microSD_slot_ha_edit);
        h.setSize(size_ha_edit);

        Handheld::updateVec(h);

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
        ui->main_processor_lineEdit->clear();
        ui->graphiv_processor_lineEdit->clear();
        ui->storage_lineEdit->clear();
        ui->USB_lineEdit->clear();
        ui->display_lineEdit->clear();
        ui->input_output_port->clear();
        ui->wifi_lineEdit->clear();
        ui->weight_lineEdit->clear();
        ui->bluetooth_lineEdit->clear();
        ui->power_consum->clear();
        ui->controller_vibra->setChecked(false);
        ui->have_tv_mode->setChecked(false);
    }



}

