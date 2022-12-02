#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"employe.h"

#include "partenaire.h"
#include "localisation.h"
#include "ui_localisation.h"
#include"mapping.h"
#include "stat1.h"
#include "ui_stat1.h"
#include "ui_stat_combo.h"

#include <QMainWindow>
#include <QWidget>
#include <QAxWidget>
#include"arduino.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    //PARTIE AZIZ
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_supp_2_clicked();

    void on_pb_modifier_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pb_recher_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_Afficher_stat_clicked();

    void on_pb_pdf_clicked();



    //PARTIE DORRA
    void on_pushButton_clicked();

    void on_supp_button_clicked();

    void on_bouton_modif_clicked();


    void on_recherche_button_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();
    void update();
    void on_tri_button_clicked();

    void on_afficher_p_clicked(const QModelIndex &index);

private:
    Ui::Dialog *ui;
    Employe e;
    QChartView *chartView ;
    statistique *s;

    Partenaire p;
    WebAxWidget  WebAxWidget;
    //stat_combo *s;
      localisation *l;

      Arduino A;
};

#endif // DIALOG_H
