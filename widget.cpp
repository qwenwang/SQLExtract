#include "widget.h"
#include "ui_widget.h"
#include <QClipboard>
#include <QRegExp>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    clipboard = QGuiApplication::clipboard();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnOk_clicked()
{
    text = clipboard->text();
    index = 0;
    QString result = analyse();
    ui->textEdit->setText(result);
    clipboard->setText(result);
}


void Widget::on_btnNext_clicked()
{

}

QString Widget::analyse()
{
    QString result;
    int endIndex = text.mid(index).indexOf("Query");
    QRegExp reg("\"([^\"]*)\"");
    while(index < endIndex) {
        index = reg.indexIn(text.mid(index))+index;
        index += reg.matchedLength();
        result += reg.cap(1);
    }
    return result;
}
