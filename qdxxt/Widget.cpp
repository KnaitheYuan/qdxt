#include "Widget.h"
#include "ui_Widget.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <QDateTime>
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    led_fd = open("/dev/leds",0);
    buzzer_fd = open("/dev/pwm",0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

    int num=ui->spinBox->value();
    QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    FILE *fp = fopen("./qd_data","a");

    fprintf(fp,"%d %s\n",num,time.toUtf8().data());
    fclose(fp);

    sprintf(da,"学号 %d 已于 %s 签到成功！",num,time.toUtf8().data());
    QString str;
    ui->textEdit->append(str.append(da));


    QTimer::singleShot(2000,this,SLOT(onTime()));
}

void Widget::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
    QTimer::singleShot(2000,this,SLOT(onTime()));
}

void Widget::onTime()
{
    //ioctl(buzzer_fd,1,100);
    //sleep(1);
    ioctl(buzzer_fd,0,0);
    ioctl(led_fd,1,0);
    ioctl(led_fd,2,0);
    ioctl(led_fd,3,0);
    ioctl(led_fd,4,0);
}
