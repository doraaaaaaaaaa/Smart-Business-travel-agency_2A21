#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vol.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lajout_clicked();

    void on_suplvol_clicked();

    void on_tablvol_activated(const QModelIndex &index);

    void on_lmodifier_clicked();

private:
    Ui::MainWindow *ui;
    vol v;

};

#endif // MAINWINDOW_H
