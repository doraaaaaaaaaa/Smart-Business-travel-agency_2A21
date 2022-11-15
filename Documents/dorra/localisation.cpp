#include "localisation.h"
#include "ui_localisation.h"
localisation::localisation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::localisation)
{
    ui->setupUi(this);
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    ui->map->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/Fondative/@36.847012,10.193823,17z/data=!3m1!4b1!4m5!3m4!1s0x12fd357cdd1d2ff1:0x6d829d4b505b0479!8m2!3d36.8469975!4d10.195993");
}
localisation::~localisation()
{
    delete ui;

}
