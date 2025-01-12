#include "edit_device_stationed.h"
#include "ui_edit_device_stationed.h"

Edit_device_stationed::Edit_device_stationed(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Edit_device_stationed)
{
    ui->setupUi(this);
    cata = cat;
}

Edit_device_stationed::~Edit_device_stationed()
{
    delete ui;
}

std::string brand_st_edit;
std::string model_st_edit;
int quantity_st_edit, resolution_1_st_edit, resolution_2_st_edit;
double price_st_edit;
std::string name_st_edit;
std::string ssd_st_edit;
std::string size_st_edit;
std::string main_processor_st_edit;
std::string graphics_processor_st_edit;
int storage_capacity_st_edit;
std::string USB_st_edit;
std::string display_st_edit;
std::string input_output_port_st_edit;
std::string wifi_st_edit;
double weight_st_edit;
std::string bluetooth_st_edit;
double power_consumption_st_edit;
bool controller_vibration_st_edit = false;
bool TV_mode_st_edit = false;

void Edit_device_stationed::on_OK_btn_clicked()
{
    bool a, b, c, d, e, f, g;
    brand_st_edit = ui->brand_lineEdit->text().toStdString();
    model_st_edit = ui->model_lineEdit->text().toStdString();
    quantity_st_edit = ui->quantity_lineEdit->text().toInt(&a);
    resolution_1_st_edit = ui->resolution_lineEdit_1->text().toInt(&b);
    resolution_2_st_edit = ui->resolution_lineEdit_2->text().toInt(&c);
    price_st_edit = ui->price_lineEdit->text().toDouble(&d);
    name_st_edit = ui->des_lineEdit->text().toStdString();
    ssd_st_edit = ui->SSD->text().toStdString();
    size_st_edit = ui->size->text().toStdString();
    main_processor_st_edit = ui->main_processor_lineEdit->text().toStdString();
    graphics_processor_st_edit = ui->graphiv_processor_lineEdit->text().toStdString();
    storage_capacity_st_edit = ui->storage_lineEdit->text().toInt(&e);
    USB_st_edit = ui->USB_lineEdit->text().toStdString();
    display_st_edit = ui->display_lineEdit->text().toStdString();
    input_output_port_st_edit = ui->input_output_port->text().toStdString();
    wifi_st_edit = ui->wifi_lineEdit->text().toStdString();
    weight_st_edit = ui->weight_lineEdit->text().toDouble(&f);
    bluetooth_st_edit = ui->bluetooth_lineEdit->text().toStdString();
    power_consumption_st_edit = ui->power_consum->text().toDouble(&g);
    if(ui->controller_vibra->isChecked()){
        controller_vibration_st_edit = true;
    }
    if(ui->have_tv_mode->isChecked()){
        TV_mode_st_edit = true;
    }

    if(a && b && c && d && e && f && g && price_st_edit >= 0 && quantity_st_edit > 0) {
        Stationed stationed1;

        stationed1.setID(cata);
        stationed1.setPrice(price_st_edit);
        stationed1.setQuantity(quantity_st_edit);
        stationed1.setDescription(name_st_edit);
        stationed1.setBrand(brand_st_edit);
        stationed1.setModel(model_st_edit);
        stationed1.setOnDisplay(true);
        stationed1.setResolution(resolution_1_st_edit, resolution_2_st_edit);
        stationed1.setMainProcessor(main_processor_st_edit);
        stationed1.setGraphicsProcessor(graphics_processor_st_edit);
        stationed1.setStorageCapacity(storage_capacity_st_edit);
        stationed1.setUSB(USB_st_edit);
        stationed1.setDisplay(display_st_edit);
        stationed1.setInputOutputPort(input_output_port_st_edit);
        stationed1.setWifi(wifi_st_edit);
        stationed1.setWeight(weight_st_edit);
        stationed1.setBluetooth(bluetooth_st_edit);
        stationed1.setPowerConsumption(power_consumption_st_edit);
        stationed1.setControllerVibration(controller_vibration_st_edit);
        stationed1.setTVMode(TV_mode_st_edit);
        stationed1.setSSD(ssd_st_edit);
        stationed1.setSize(size_st_edit);

        Stationed::updateVec(stationed1);

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
        ui->SSD->clear();
        ui->size->clear();
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

