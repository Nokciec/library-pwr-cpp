#ifndef ADDBOOKFORM_H
#define ADDBOOKFORM_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QString>

namespace Ui {
class addbookform;
}

class addbookform : public QDialog
{
    Q_OBJECT

public:
    explicit addbookform(QWidget *parent = 0);
    ~addbookform();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addbookform *ui;

    void addNewBook(QString title, QString author, QString ISBN, QString publicationDate, QString publicationPlace, QString publisher, QString pagesNumber);
};

#endif // ADDBOOKFORM_H
