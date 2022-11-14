#include "mail.h"
#include "ui_mail.h"
#include"smtp.h"

Mail::Mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mail)
{
    ui->setupUi(this);
}

Mail::~Mail()
{
    delete ui;
}

void Mail::on_send_clicked()
{
    QString from = ui->lineEdit_from->text();
              QString to = ui->lineEdit_to->text();
              QString subject = ui->lineEdit_subj->text();
              QString password =ui->lineEdit_pass->text();
              QString email_text = ui->textEdit_mail->toPlainText();

             Smtp* smtp = new Smtp(from, password, "smtp.gmail.com",465);
              QObject::connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


                 smtp->sendMail(from, to, subject, email_text);
}

