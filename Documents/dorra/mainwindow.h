#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "partenaire.h"
#include "localisation.h"
#include "localisation.h"
#include "ui_localisation.h"
#include "stat_combo.h"
#include "ui_stat_combo.h"

#include <QMainWindow>
#include <QAxWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_supp_button_clicked();

    void on_bouton_modif_clicked();

    void on_afficher_activated(const QModelIndex &index);

    void on_recherche_button_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Partenaire p;
    //WebAxWidget  WebAxWidget;
    stat_combo *s;
      localisation *l;
};
#endif // MAINWINDOW_H
