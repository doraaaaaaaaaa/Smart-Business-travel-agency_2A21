
#include "localisation.h"
#include "ui_localisation.h"
#include<QSqlQuery>
localisation::localisation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::localisation)
{
    ui->setupUi(this);
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

}
localisation::~localisation()
{
    delete ui;

}

void localisation::on_pushButton_clicked()
{
int numero=ui->loc->text().toInt() ;
QString id_string= QString::number(numero);
                            QSqlQuery query;
                            query.prepare("select * from partenaire where numero_p='"+id_string+"'");

                            if(query.exec()){

                                while(query.next())
                                { ui->textEdit->setText(query.value(4).toString());


                                    if(ui->textEdit->toPlainText()== "fondative")
                                      {
                                        ui->map->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/Fondative/@36.847012,10.193823,17z/data=!3m1!4b1!4m5!3m4!1s0x12fd357cdd1d2ff1:0x6d829d4b505b0479!8m2!3d36.8469975!4d10.195993");
}
                                    else if(ui->textEdit->toPlainText()== "vermeg")
                                    {
                                     ui->map->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/VERMEG+Tunis/@36.8309885,10.2304609,19.42z/data=!4m5!3m4!1s0x12fd351432affb6b:0xa2369429e6a98662!8m2!3d36.8312882!4d10.2327641");
                                    }
                                    else if(ui->textEdit->toPlainText()== "wwschool")
                                    {
                                     ui->map->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESB+:+Esprit+School+of+Business/@36.8972373,10.1913024,17z/data=!3m1!4b1!4m5!3m4!1s0x12e2cb745e5c6f1b:0xf69a51ee3c65c12e!8m2!3d36.897233!4d10.1934964");
                                    }




                                }
                                                 }
}
