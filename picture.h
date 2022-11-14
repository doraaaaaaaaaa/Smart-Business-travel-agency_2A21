#ifndef PICTURE_H
#define PICTURE_H
#include<QFileDialog>
#include<QLabel>
#include <QDialog>
#include<QMainWindow>

namespace Ui {
class Picture;
}

class Picture : public QDialog
{
    Q_OBJECT

public:
    explicit Picture(QWidget *parent = nullptr);
    ~Picture();
protected  :
    void changeEvent(QEvent *e);
private slots:


    void on_pushButton_Browse_clicked();

private:
    Ui::Picture *ui;
};

#endif // PICTURE_H
