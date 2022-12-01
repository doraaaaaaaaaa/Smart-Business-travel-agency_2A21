#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H
#include "employe.h"
#include "stat1.h"
#include <QMessageBox>

#include <QMainWindow>
#include"arduino1.h"
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
  //  QByteArray don;

    void on_Log_In_clicked();

    void update();


private:
    Ui::MainWindow *ui;
    Employe e;
    QChartView *chartView ;
    statistique *s;
     Arduino A;
QByteArray don;
QByteArray ch;

};
#endif // MAINWINDOW_H

