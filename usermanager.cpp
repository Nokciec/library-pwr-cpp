#include "usermanager.h"

bool userManager::userSearching(std::string login, std::string password)
{
    QString path = QCoreApplication::applicationDirPath();
            path.append("\\userdatabase.txt");
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"Error", file.errorString());
    QTextStream in(&file);
    QString text;
    text = in.readAll();
    file.close();
    QRegExp rx("(\\;)");
    QStringList query = text.split(rx);

    int index = query.indexOf(QString::fromStdString(login));
    if(index!=-1)
    {
        QString realPassword = query[index+1];
        QString md5password = QString(QCryptographicHash::hash((QString::fromStdString(password).toUtf8()),QCryptographicHash::Md5).toHex());
        if (realPassword==md5password)
        {
            access=true;
            type = query[index+2].toInt();
        }
        else access = false;

        return true;
    }

    else return false;
}

userManager::userManager()
    :access(false),
      type(0)
{

}
