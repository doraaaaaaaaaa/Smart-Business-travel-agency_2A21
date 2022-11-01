#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMessageBox>
#include <QMainWindow>
#include"mission.h"

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_supprime_clicked();

    void on_ajoute_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Mission M;
};
#endif // MAINWINDOW_H

