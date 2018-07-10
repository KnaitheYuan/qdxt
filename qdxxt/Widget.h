#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int buzzer_fd,led_fd;
    char da[100];
private:
    Ui::Widget *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void onTime();
};

#endif // WIDGET_H
