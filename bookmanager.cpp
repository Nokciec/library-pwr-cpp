#include "bookmanager.h"

std::vector<Book> bookmanager::showBooks(bookmanager::Type type)
{

    QList<QString> query = QList<QString>::fromVector(QVector<QString>::fromStdVector(getContent()));

    std::vector<Book> temp_books;

    for(int i=0;i<(query.size()-1);i++)
    {
        long i_bookID = query[0].toLong();
        std::string i_title = query[1].toStdString();
        std::string i_author = query[2].toStdString();
        long i_ISBN = query[3].toLong();
        int i_publicationDate = query[4].toInt();
        std::string i_publicationPlace = query[5].toStdString();
        std::string i_publisher = query[6].toStdString();
        int i_pagesNumber = query[7].toInt();
        bool i_availability = query[8].toInt();
        std::string i_borrowerLogin = query[9].toStdString();
        QDateTime i_startdate = QDateTime::fromString(query[10], "MM dd yyyy");
        QDateTime i_enddate = QDateTime::fromString(query[11], "MM dd yyyy");
        bool i_reservation = query[12].toInt();
        std::string i_reserveLogin = query[13].toStdString();


        Book temp_book(i_bookID,
                       i_title,
                       i_author,
                       i_ISBN,
                       i_publicationDate,
                       i_publicationPlace,
                       i_publisher,
                       i_pagesNumber,
                       i_availability,
                       i_borrowerLogin,
                       i_startdate,
                       i_enddate,
                       i_reservation,
                       i_reserveLogin);

        temp_books.push_back(temp_book);

        for(int i=0;i<14;i++)
            query.pop_front();
    }

    return temp_books;

}

std::vector<QString> bookmanager::getContent()
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
    QRegExp rx("(\\;)"); //RegEx for ';'
    QStringList query = text.split(rx);

    std::vector<QString> vec = query.toVector().toStdVector();
    return vec;
}

void bookmanager::deleteBook(int row)
{
    std::vector<QString> content = getContent();
    int start = 14*row;
    int end= start+14;
    content.erase(content.begin()+start, content.begin()+end);

    QString query;
     for (auto x : content)
     {
         query+=x+";";

     }
     query.truncate(query.size()-1);

     QString path = QCoreApplication::applicationDirPath();
             path.append("\\bookdatabase.txt");
     QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << query;
}

bookmanager::bookmanager()
{
}

void bookmanager::rentABook(int row, QString login)
{
    std::vector<QString> content = getContent();

    int start = 14*row;
    content[start+8]="0";
    content[start+9]=login;

    QDateTime today = QDateTime::currentDateTime();
    QDateTime later = today.addDays(30);

   content[start+10]= today.toString("MM dd yyyy");
   content[start+11]=later.toString("MM dd yyyy");


    QString query;
     for (auto x : content)
     {
         query += x + ";";
     }

     QString path = QCoreApplication::applicationDirPath();
             path.append("\\bookdatabase.txt");
     QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << query;
}

void bookmanager::reserveABook(int row, QString login)
{
    std::vector<QString> content = getContent();
    int start = 14*row;
    content[start+12]="1";
    content[start+13]=login;

    QString query;
     for (auto x : content)
     {
         query+=x+";";
     }

     QString path = QCoreApplication::applicationDirPath();
             path.append("\\bookdatabase.txt");
     QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << query;
}

void bookmanager::renewABook(int row)
{
    std::vector<QString> content = getContent();
    int start = 14*row;

    QDateTime current = QDateTime::currentDateTime();
    QDateTime renew = current.addDays(30);

    content[start+11]=renew.toString("MM dd yyyy");


    QString query;
     for (auto x : content)
     {
         query+=x+";";

     }

     QString path = QCoreApplication::applicationDirPath();
             path.append("\\bookdatabase.txt");
     QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << query;
}
