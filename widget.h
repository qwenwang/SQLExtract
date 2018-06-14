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

private slots:
    void on_btnOk_clicked();
    void on_btnNext_clicked();

private:
    Ui::Widget *ui;
    QClipboard *clipboard;
    QString text;
    int index;

    QString analyse();

};

#endif // WIDGET_H
