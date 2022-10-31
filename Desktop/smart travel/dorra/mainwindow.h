#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "partenaire.h"

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
    void on_pushButton_clicked();

    void on_supp_button_clicked();

    void on_bouton_modif_clicked();

private:
    Ui::MainWindow *ui;
    Partenaire p;
};
#endif // MAINWINDOW_H
