#include "edit_device_desktop.h"
#include "ui_edit_device_desktop.h"

edit_device_desktop::edit_device_desktop(QWidget *parent, std::string cat)
    : QDialog(parent)
    , ui(new Ui::edit_device_desktop)
{
    ui->setupUi(this);
    cata = cat;
}

edit_device_desktop::~edit_device_desktop()
{
    delete ui;
}

std::string brand_d_edit, name_d_edit;
std::string model_d_edit;
int quantity_d_edit;
double price_d_edit;
std::string cpu_d_edit;
std::string gpu_d_edit;
std::string memory_d_edit;
std::string os_d_edit;
std::string motherboard_d_edit;
std::string psu_d_edit;
std::string pc_case_d_edit;
std::string cooling_d_edit;

void edit_device_desktop::on_OK_btn_clicked()
{
    bool a, e;

    brand_d_edit = ui->brand_lineEdit->text().toStdString();
    model_d_edit = ui->model_lineEdit->text().toStdString();
    name_d_edit = ui->des_lineEdit->text().toStdString();
    price_d_edit = ui->price_lineEdit->text().toDouble(&a);
    quantity_d_edit = ui->quantity_lineEdit->text().toInt(&e);
    cpu_d_edit = ui->cpu->text().toStdString();
    gpu_d_edit = ui->gpu->text().toStdString();
    memory_d_edit = ui->memory->text().toStdString();
    os_d_edit = ui->os_lineEdit->text().toStdString();
    motherboard_d_edit = ui->motherboard->text().toStdString();
    psu_d_edit = ui->psu->text().toStdString();
    pc_case_d_edit = ui->pc_case->text().toStdString();
    cooling_d_edit = ui->cooling->text().toStdString();

    if(a && e && price_d_edit >= 0 && quantity_d_edit > 0){
        Desktop d;

        d.setPrice(price_d_edit);
        d.setQuantity(quantity_d_edit);
        d.setID(cata);
        d.setDescription(name_d_edit);
        d.setBrand(brand_d_edit);
        d.setModel(model_d_edit);
        d.setOnDisplay(true);
        d.setCPU(cpu_d_edit);
        d.setGPU(gpu_d_edit);
        d.setMemory(memory_d_edit);
        d.setOS(os_d_edit);
        d.setMotherboard(motherboard_d_edit);
        d.setPSU(psu_d_edit);
        d.setPCCase(pc_case_d_edit);
        d.setCooling(cooling_d_edit);

        Desktop::updateVec(d);

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

