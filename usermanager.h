#ifndef USERMANAGER_H
#define USERMANAGER_H
#include "user.h"
#include <string>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QCoreApplication>

class userManager
{
public:
    bool access;

    int type;

    bool userSearching(std::string login, std::string password);

    userManager();

    bool accessAccepted() const {return access;}

    int getPermissions() const{return type;}
};

#endif // USERMANAGER_H
