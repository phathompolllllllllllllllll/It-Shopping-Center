#ifndef COMPART_H
#define COMPART_H

#include <QDialog>

namespace Ui {
class Compart;
}

class Compart : public QDialog
{
    Q_OBJECT

public:
    explicit Compart(QWidget *parent = nullptr);
    ~Compart();

private:
    Ui::Compart *ui;
};

#endif // COMPART_H
