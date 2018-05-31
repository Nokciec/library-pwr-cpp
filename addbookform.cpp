#include "addbookform.h"
#include "ui_addbookform.h"
#include <QDebug>

addbookform::addbookform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addbookform)
{
    ui->setupUi(this);
    this->setWindowTitle("Adding a book");
}

addbookform::~addbookform()
{
    delete ui;
}

void addbookform::on_pushButton_clicked()
{
    QString book_title;
    QString book_author;
    QString book_ISBN;
    QString book_publicationDate;
    QString book_publicationPlace;
    QString book_publisher;
    QString book_pagesNumber;

    if (!ui->lineEdit->text().trimmed().isEmpty())
        book_title = ui->lineEdit->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Title of book cannot be empty!"));
        return;
    }

    if (!ui->lineEdit_2->text().trimmed().isEmpty())
        book_author = ui->lineEdit_2->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Author cannot be empty!"));
        return;
    }

    if (!ui->lineEdit_3->text().trimmed().isEmpty())
        book_ISBN = ui->lineEdit_3->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("ISBN cannot be empty!"));
        return;
    }

    if (!ui->lineEdit_4->text().trimmed().isEmpty())
        book_publicationDate = ui->lineEdit_4->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Publication date cannot be empty!"));
        return;
    }
    if (!ui->lineEdit_5->text().trimmed().isEmpty())
        book_publicationPlace = ui->lineEdit_5->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Publication place cannot be empty!"));
        return;
    }

    if (!ui->lineEdit_6->text().trimmed().isEmpty())
        book_publisher = ui->lineEdit_6->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Publisher cannot be empty!"));
        return;
    }

    if (!ui->lineEdit_7->text().trimmed().isEmpty())
        book_pagesNumber = ui->lineEdit_7->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Number of pages cannot be empty!"));
        return;
    }

    addNewBook(book_title,book_author,book_ISBN,book_publicationDate,book_publicationPlace,book_publisher,book_pagesNumber);
    QMessageBox::information(this, tr("Information"), tr("Book added!"));
    return;

}

void addbookform::addNewBook(QString title, QString author, QString ISBN, QString publicationDate, QString publicationPlace, QString publisher, QString pagesNumber)
{
    QString path = QCoreApplication::applicationDirPath();
            path.append("\\bookdatabase.txt");
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"Error", file.errorString());
    QTextStream in(&file);
    QString text;
    text = in.readAll();
    file.close();
    QRegExp rx("(\\;)");
    QStringList query = text.split(rx);

    query.pop_back();
    query.pop_back();

    int numberofbooks = query.size()/14 + 1;
    QString lastID = query[(numberofbooks-2)*14];
    int newID = lastID.toInt() + 2;

    QString bookID = QString::number(newID);
    QString availability = "1";
    QString borrowerID = "0";
    QString startDate = "0";
    QString endDate = "0";
    QString reservation = "0";
    QString reserveLogin  = "0";

    QString insertQuery = text +
            bookID + ";" +
            title + ";" +
            author + ";" +
            ISBN + ";" +
            publicationDate + ";" +
            publicationPlace + ";" +
            publisher + ";" +
            pagesNumber + ";" +
            availability + ";" +
            borrowerID + ";" +
            startDate + ";" +
            endDate + ";" +
            reservation + ";" +
            reserveLogin + ";";

    QString path2 = QCoreApplication::applicationDirPath();
            path2.append("\\bookdatabase.txt");
    QFile file2(path);
    if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file2);
    out << insertQuery;

}


void addbookform::on_pushButton_2_clicked()
{
    close();
}
