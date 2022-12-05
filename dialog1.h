#ifndef DIALOG_H
#define DIALOG_H
#include"ui_Mail.h"
#include "ui_localisation.h"
#include "ui_stat1.h"
//#include "ui_stat_combo.h"
#include"hebergement.h"
//#include"arduino1.h"
#include"Mail.h"
#include"statistique2.h"
#include"employe.h"
#include "partenaire.h"
#include "localisation.h"
#include"mapping.h"
#include "stat1.h"
#include"arduino.h"
#include "smtp.h"
#include"picture.h"
#include <QMainWindow>
#include <QWidget>
#include <QAxWidget>
#include <QDialog>
#include <QChart>
#include <QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QValueAxis>
#include <QWidget>
#include<vol.h>
#include"mission.h"
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
    //void update();
    void on_tri_button_clicked();
    void on_afficher_p_clicked(const QModelIndex &index);

    //Partie Ranim
    void on_Ajouter_h_clicked(); //Ajout
    void on_Modif_h_clicked(); //Modif
    void on_tableViewH_clicked(const QModelIndex &index); //Modif
    void on_radioButton_clicked(); //Tri
    void on_triNom_clicked();
    void on_triPrix_clicked();
    void on_lineEdit_Rech_textChanged(const QString &arg1); //Rech
    void on_PDF_clicked();
    void on_stat_clicked();
    void on_Send_mail_clicked();
    void on_pushButton_Picture_clicked();
    void update_label();
    void on_Supprimer_H_clicked();
    //Partie yassine
    void on_lajout_clicked();
    void on_suplvol_clicked();
    void on_tablvol_activated(const QModelIndex &index);
    void on_lmodifier_clicked();
    void on_lreset_clicked();
    void myfunction();
    void on_chercher_clicked();
    void on_trie_clicked();
    void on_lexport_clicked();
    void on_lqr_clicked();


    //aziz
    void on_statistique_clicked();
    void on_pb_ajouter_2_clicked();
    void on_radio_duree_clicked();
    void on_radio_mois_clicked();
    void on_radio_jour_clicked();
    void on_supprimer_mission_clicked();
    void on_chercher_modifier_clicked();
    void on_pb_modifier_5_clicked();
    void on_pb_modifier_6_clicked();
    void on_reset_ajouter_3_clicked();
    void on_reset_ajouter_4_clicked();

private:
    hebergement H;
    //statistique2 *st;
    QWidget  WebAxWidget;
    //Mail *sm;
    Picture *pt;
    //arduino A;
    QByteArray data;
    Ui::Dialog *ui;
    Employe e;
    QChartView *chartView ;
    statistique *s;
    Partenaire p;
    //stat_combo *s;
    localisation *l;
    Arduino A;
    //partie yassine
    vol v;
    QTimer *timer;
    //aziz
      Mission M;
};

#endif // DIALOG_H
