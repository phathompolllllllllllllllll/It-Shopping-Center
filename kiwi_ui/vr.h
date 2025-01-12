#ifndef VR_H
#define VR_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class Vr;
}

class Vr : public QDialog
{
    Q_OBJECT

protected:
        void closeEvent(QCloseEvent *event) override;

public:
    explicit Vr(QWidget *parent = nullptr);
    ~Vr();

private:
    Ui::Vr *ui;
};

#endif // VR_H
