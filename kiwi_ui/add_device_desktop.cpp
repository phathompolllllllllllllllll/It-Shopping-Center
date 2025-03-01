#include "add_device_desktop.h"
#include "ui_add_device_desktop.h"

Add_device_desktop::Add_device_desktop(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::Add_device_desktop)
{
    ui->setupUi(this);
    cata = cat;
}

Add_device_desktop::~Add_device_desktop()
{
    delete ui;
}

std::string brand_d, name_d;
std::string model_d;
int quantity_d;
double price_d;
std::string cpu_d;
std::string gpu_d;
std::string memory_d;
std::vector<std::string> storage_d;
std::string os_d;
std::string motherboard_d;
std::string psu_d;
std::string pc_case_d;
std::string cooling_d;

void Add_device_desktop::on_OK_btn_clicked()
{

    bool d, e;

    brand_d = ui->brand_lineEdit->text().toStdString();
    model_d = ui->model_lineEdit->text().toStdString();
    name_d = ui->des_lineEdit->text().toStdString();
    price_d = ui->price_lineEdit->text().toDouble(&d);
    quantity_d = ui->quantity_lineEdit->text().toInt(&e);
    cpu_d = ui->cpu->text().toStdString();
    gpu_d = ui->gpu->text().toStdString();
    memory_d = ui->memory->text().toStdString();

    os_d = ui->os_lineEdit->text().toStdString();
    motherboard_d = ui->motherboard->text().toStdString();
    psu_d = ui->psu->text().toStdString();
    pc_case_d = ui->pc_case->text().toStdString();
    cooling_d = ui->cooling->text().toStdString();

    if(d && e && price_d >= 0 && quantity_d > 0){
        Desktop desktop(quantity_d, price_d);

        desktop.setDescription(name_d);
        desktop.setBrand(brand_d);
        desktop.setModel(model_d);
        desktop.setOnDisplay(true);
        desktop.setCPU(cpu_d);
        desktop.setGPU(gpu_d);
        desktop.setMemory(memory_d);
        desktop.setOS(os_d);
        desktop.setMotherboard(motherboard_d);
        desktop.setPSU(psu_d);
        desktop.setPCCase(pc_case_d);
        desktop.setCooling(cooling_d);

        Desktop::updateVec(desktop);
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Invalid type please try again.");
        ui->brand_lineEdit->clear();
        ui->model_lineEdit->clear();
        ui->des_lineEdit->clear();
        ui->price_lineEdit->clear();
        ui->quantity_lineEdit->clear();
        ui->cpu->clear();
        ui->gpu->clear();
        ui->memory->clear();
        ui->os_lineEdit->clear();
        ui->motherboard->clear();
        ui->psu->clear();
        ui->pc_case->clear();
        ui->cooling->clear();
    }





}

