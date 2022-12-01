#include "dialog.h"
#include "ui_dialog.h"
#include <QPdfWriter>
#include <QDesktopServices>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());

    ui->le_mdp->setValidator(new QIntValidator(0,999999,this));
    ui->le_IDemploye->setValidator(new QIntValidator(0,999999,this));

    QRegularExpression rw("^[A-Z a-z]+$");
    QValidator *validator = new  QRegularExpressionValidator(rw,this);

    ui->le_nom->setValidator(validator);
    ui->le_nom->setMaxLength(12);
    ui->le_prenom->setValidator(validator);
    ui->le_prenom->setMaxLength(12);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_clicked()
{
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString d=ui->dateEdit->text();
    QString Genre=ui->Genre_select->currentText();
    int ID_emp=ui->le_IDemploye->text().toInt();
    int MDPS=ui->le_mdp->text().toInt();
    Employe e(ID_emp,MDPS,NOM,PRENOM,d,Genre);
    bool test=e.ajouter();
    if(test)
    {    ui->tableView->setModel(e.afficher());

        QMessageBox::information(nullptr,QObject::tr("add completed"),
                                       QObject::tr("add completed \n"
                                                   "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("add not completed"),
                                       QObject::tr("add not completed \n"
                                                   "Click Cancel to exit."),QMessageBox::Cancel);
}

void Dialog::on_pb_supp_clicked()
{
    Employe e;
         bool test1;
         int ID=ui->le_IDemploye->text().toInt();

         test1 =e.supprimer(ID);
         if(test1)
         {    ui->tableView->setModel(e.afficher());

             ui->tableView->setModel(e.afficher());

             QMessageBox::information(nullptr, QObject::tr("SUPP effuctué"),
                                      QObject::tr("connection successful.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("supp n'est pas effuctué"),
                                   QObject::tr("connection failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pb_supp_2_clicked()
{

}

void Dialog::on_pb_modifier_clicked()
{
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString d=ui->dateEdit->text();
     QString Genre=ui->Genre_select->currentText();
    int ID_emp=ui->le_IDemploye->text().toInt();
    int MDPS=ui->le_mdp->text().toInt();
    Employe e(ID_emp,MDPS,NOM,PRENOM,d,Genre);
    bool test=e.modifier();
    if(test)
    {
        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("add completed"),
                                       QObject::tr("add completed \n"
                                                   "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("add not completed"),
                                       QObject::tr("add not completed \n"
                                                   "Click Cancel to exit."),QMessageBox::Cancel);
}

void Dialog::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
       QSqlQuery qry;
       qry.prepare("select * from EMPLOYEE where ID_EMP='"+val+"'");
       if(qry.exec())
       {
           while(qry.next())
           {
               ui->le_IDemploye->setText(qry.value(0).toString());
               ui->Genre_select->setCurrentText(qry.value(5).toString());
               ui->le_nom->setText(qry.value(2).toString());
               ui->le_prenom->setText(qry.value(3).toString());
               ui->dateEdit->setDate(qry.value(4).toDate());
               ui->le_mdp->setText(qry.value(1).toString());

           }
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("selection n'est pas effuctué"),
                                 QObject::tr("connection failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void Dialog::on_pb_recher_clicked()
{
    int id=ui->lineEdit->text().toInt();
      QString cin= QString::number(id);
      if(id!=0)
          ui->tableView->setModel(e.recherche(cin));
      else
          ui->tableView->setModel(e.afficher());

}

void Dialog::on_comboBox_2_activated(const QString &arg1)
{
    if(arg1=="date d'ajout")
        ui->tableView->setModel(e.afficher());
    else  if(arg1=="id")
        ui->tableView->setModel(e.trier(3));
    else  if(arg1=="nom")
        ui->tableView->setModel(e.trier(2));
    else  if(arg1=="date de naissance")
        ui->tableView->setModel(e.trier(1));
}

void Dialog::on_Afficher_stat_clicked()
{
    s = new statistique();

        s->setWindowTitle("statistique des employés");
        s->choix_bar();
        s->show();
}

void Dialog::on_pb_pdf_clicked()
{
    QString ach=".pdf";
            QPdfWriter pdf("C:/Users/Aziz Chlif/Desktop/validation"+ach);


                              QPainter painter(&pdf);
                             int i = 4000;
                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Impact", 30));
                                  painter.drawText(2200,1400,"Liste des employés ");
                                  painter.setPen(Qt::black);
                                  painter.setFont(QFont("impact", 50));
                                  painter.drawRect(0,3000,9600,500);
                                  painter.setFont(QFont("impact", 11));
                                  painter.drawText(200,3300,"ID_Emp");
                                  painter.drawText(1200,3300,"Nom");
                                  painter.drawText(2400,3300,"Prenom");
                                  painter.drawText(4400,3300,"date");
                                  painter.drawText(5900,3300,"Genre");
                                  painter.drawText(6900,3300,"MDP");




                                  QSqlQuery query;
                                  query.prepare("select * from EMPLOYEE");
                                  query.exec();
                                  painter.setFont(QFont("Arial",9));
                                  while (query.next())
                                  {
                                      painter.drawText(200,i,query.value(0).toString());
                                      painter.drawText(1200,i,query.value(2).toString());
                                      painter.drawText(2400,i,query.value(3).toString());
                                      painter.drawText(4000,i,query.value(4).toString());
                                      painter.drawText(6000,i,query.value(5).toString());
                                      painter.drawText(7000,i,query.value(1).toString());



                                     i = i + 500;
                                  }
                                  painter.drawRect(0,3000,9600,i-3000);
                                  int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                      if (reponse == QMessageBox::Yes)
                                      {
                                          QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Aziz Chlif/Desktop/validation"+ach));

                                          painter.end();
                                      }
                                      if (reponse == QMessageBox::No)
                                      {
                                           painter.end();
                                      }

}
