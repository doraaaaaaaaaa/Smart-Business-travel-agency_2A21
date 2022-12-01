#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"employe.h"
#include"stat.h"

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
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_supp_2_clicked();

    void on_pb_modifier_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pb_recher_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_Afficher_stat_clicked();

    void on_pb_pdf_clicked();

private:
    Ui::Dialog *ui;
    Employe e;
    QChartView *chartView ;
    statistique *s;
};

#endif // DIALOG_H
