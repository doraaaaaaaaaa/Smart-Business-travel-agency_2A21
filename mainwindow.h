#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "stat.h"
#include <QMessageBox>

#include <QMainWindow>

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
    void on_pb_ajouter_clicked();

  // void on_pb_supp_2_clicked();



    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pb_recher_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_Afficher_stat_clicked();

    void on_pb_pdf_clicked();

    void on_pushButton_clicked();

    void on_Log_In_clicked();

private:
    Ui::MainWindow *ui;
    Employe e;
    QChartView *chartView ;
    statistique *s;


};
#endif // MAINWINDOW_H

