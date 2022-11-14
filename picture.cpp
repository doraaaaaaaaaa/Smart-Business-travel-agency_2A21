#include "picture.h"
#include "ui_picture.h"
#include"ui_mainwindow.h"
#include <QMainWindow>
#include <QWidget>
#include<QPicture>

Picture::Picture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Picture)
{
    ui->setupUi(this);
    //To View the picture in the Label
    QPixmap pix("C:/Users/user/Desktop/Picture.jpg");
    ui->label_pic->setPixmap(pix);
}

Picture::~Picture()
{
    delete ui;
}

void Picture::changeEvent(QEvent*e)
{
    Picture::changeEvent(e);
    switch(e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
        defalut:
        break;
    }
}


void Picture::on_pushButton_Browse_clicked()
{
    //To Open the file
    QFileDialog dialog(this);
   dialog.setNameFilter(tr("Images(*.png *.xmp *.jpg)"));
   dialog.setViewMode(QFileDialog::Detail);
   QString fileName=QFileDialog::getOpenFileName(this,tr ("Open Images"), "C:/Users/user/Desktop/Picture", tr("Image Files (*.png *.jpg *.bmp"));
//To Select and show the picture
   if(!fileName.isEmpty())
 {
     QImage image (fileName);
     ui->label_pic->setPixmap(QPixmap::fromImage(image));
 }
}

