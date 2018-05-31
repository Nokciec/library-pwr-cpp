#include "loginmanager.h"
#include "ui_loginmanager.h"
#include "usermanager.h"

LoginManager::LoginManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginManager),
    isAccepted(false)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
}

LoginManager::~LoginManager()
{
    delete ui;
}

QString LoginManager::getLogin()
{
    return ui->lineEdit_2->text();
}

QString LoginManager::getPassword()
{
    return ui->lineEdit->text();
}

void LoginManager::on_buttonBox_accepted()
{
    QString user_login;
    QString user_password;

    if (!ui->lineEdit_2->text().trimmed().isEmpty())
        user_login = ui->lineEdit_2->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Login cannot be empty!"));
        return ;
    }

    if (!ui->lineEdit->text().trimmed().isEmpty())
        user_password = ui->lineEdit->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Password cannot be empty!"));
        return ;
    }


    userManager manager;
    if (manager.userSearching(user_login.toStdString() , user_password.toStdString() ))
    {
        if (manager.access==true)
        {
            this->access= true;
            this->permissions=manager.getPermissions();
        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), tr("Wrong password!"));
            return ;
        }

    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Wrong login or password!"));
        return ;
    }
}

void LoginManager::on_buttonBox_rejected()
{

}
