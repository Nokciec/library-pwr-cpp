#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "book.h"
#include <QCoreApplication>


class bookmanager
{
public:
    enum class Type
    {
        Guest,
        Client,
        Librarian
    };
    std::vector<Book> showBooks(Type type=Type::Guest);
    std::vector<QString> getContent();
    void deleteBook(int row);
    bookmanager();
    void rentABook(int row, QString login);
    void reserveABook(int row, QString login);
    void renewABook (int row);

};

#endif // BOOKMANAGER_H
