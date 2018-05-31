#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include <QDialog>
#include <QAbstractButton>
#include <QMessageBox>

namespace Ui {
class LoginManager;
}

class LoginManager : public QDialog
{
    Q_OBJECT

public:
    explicit LoginManager(QWidget *parent = 0);
    ~LoginManager();

    QString getLogin();
    QString getPassword();

    bool isAccepted;
    bool getAccess() const {return access;}
    int getPermissions() const {return permissions;}

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::LoginManager *ui;

    QString login;
    QString password;

    int permissions=0;
    bool access=false;
};

#endif // LOGINMANAGER_H
