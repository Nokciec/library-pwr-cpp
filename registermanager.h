#ifndef REGISTERMANAGER_H
#define REGISTERMANAGER_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QCryptographicHash>

namespace Ui {
class RegisterManager;
}

class RegisterManager : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterManager(QWidget *parent = 0);
    ~RegisterManager();
    QString getLogin();
    QString getPassword();

    bool isUserInDatabase(QString login);

private slots:
    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_buttonBox_accepted(QAbstractButton *button);

    void on_buttonBox_rejected();

private:
    Ui::RegisterManager *ui;

    void LoadDatabaseUser();


    void createNewUser(QString login, QString password, QString name, QString surname, QString type);
};

#endif // REGISTERMANAGER_H
