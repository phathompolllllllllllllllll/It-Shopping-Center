#include "add_device_handheld.h"
#include "ui_add_device_handheld.h"

add_device_handheld::add_device_handheld(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::add_device_handheld)
{
    ui->setupUi(this);
    cata = cat;
}

add_device_handheld::~add_device_handheld()
{
    delete ui;
}

std::string brand_ha;
std::string model_ha;
int quantity_ha, resolution_1_ha, resolution_2_ha;
double price_ha;
std::string name_ha;
std::string main_processor_ha;
std::string graphics_processor_ha;
int storage_capacity_ha;
std::string USB_ha;
std::string display_ha;
std::string input_output_port_ha;
std::string wifi_ha;
double weight_ha;
std::string bluetooth_ha;
double power_consumption_ha;
bool controller_vibration_ha = false;
bool TV_mode_ha = false;
std::string battery_ha;
std::string power_supply_ha;
std::string headphone_jack_ha;
int microSD_slot_ha;
std::string size_ha;

void add_device_handheld::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g, i;
    brand_ha = ui->brand_lineEdit->text().toStdString();
    model_ha = ui->model_lineEdit->text().toStdString();
    quantity_ha = ui->quantity_lineEdit->text().toInt(&a);
    resolution_1_ha = ui->resolution_lineEdit_1->text().toInt(&b);
    resolution_2_ha = ui->resolution_lineEdit_2->text().toInt(&c);
    price_ha = ui->price_lineEdit->text().toDouble(&d);
    name_ha = ui->des_lineEdit->text().toStdString();
    main_processor_ha = ui->main_processor_lineEdit->text().toStdString();
    graphics_processor_ha = ui->graphiv_processor_lineEdit->text().toStdString();
    storage_capacity_ha = ui->storage_lineEdit->text().toInt(&e);
    USB_ha = ui->USB_lineEdit->text().toStdString();
    display_ha = ui->display_lineEdit->text().toStdString();
    input_output_port_ha = ui->input_output_port->text().toStdString();
    wifi_ha = ui->wifi_lineEdit->text().toStdString();
    weight_ha = ui->weight_lineEdit->text().toDouble(&f);
    bluetooth_ha = ui->bluetooth_lineEdit->text().toStdString();
    power_consumption_ha = ui->power_consum->text().toDouble(&g);
    if(ui->controller_vibra->isChecked()){
        controller_vibration_ha = true;
    }
    if(ui->have_tv_mode->isChecked()){
        TV_mode_ha = true;
    }

    battery_ha = ui->battery_lineEdit->text().toStdString();
    power_supply_ha = ui->power_supply->text().toStdString();
    headphone_jack_ha = ui->headphone_jack->text().toStdString();
    microSD_slot_ha = ui->microSD_slot->text().toInt(&i);
    size_ha = ui->size->text().toStdString();

    if(a && b && c && d && e && f && g && i && price_ha >= 0 && quantity_ha > 0){
        Handheld h(quantity_ha, price_ha);

        h.setDescription(name_ha);
        h.setBrand(brand_ha);
        h.setModel(model_ha);
        h.setOnDisplay(true);
        h.setResolution(resolution_1_ha, resolution_2_ha);
        h.setMainProcessor(main_processor_ha);
        h.setGraphicsProcessor(graphics_processor_ha);
        h.setStorageCapacity(storage_capacity_ha);
        h.setUSB(USB_ha);
        h.setDisplay(display_ha);
        h.setInputOutputPort(input_output_port_ha);
        h.setWifi(wifi_ha);
        h.setWeight(weight_ha);
        h.setBluetooth(bluetooth_ha);
        h.setPowerConsumption(power_consumption_ha);
        h.setControllerVibration(controller_vibration_ha);
        h.setTVMode(TV_mode_ha);
        h.setBattery(battery_ha);
        h.setPowerSupply(power_supply_ha);
        h.setHeadphoneJack(headphone_jack_ha);
        h.setMicroSDSlot(microSD_slot_ha);
        h.setSize(size_ha);

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

