#include "registermanager.h"
#include "ui_registermanager.h"


RegisterManager::RegisterManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterManager)
{
    ui->setupUi(this);
    this->setWindowTitle("Registration");
}

RegisterManager::~RegisterManager()
{
    delete ui;
}

QString RegisterManager::getLogin()
{
    return ui->lineEdit->text();
}

QString RegisterManager::getPassword()
{
    return ui->lineEdit_2->text();
}

void RegisterManager::on_lineEdit_2_textChanged(const QString &arg1)
{
    QPushButton* bt = ui->buttonBox->button(QDialogButtonBox::Ok);
    if (ui->lineEdit_2->text() != ui->lineEdit_3->text())
        ui->label_4->setText("Passwords don't match!");
    else {
        ui->label_4->setText("Passwords match!");
    }
}

void RegisterManager::on_lineEdit_3_textChanged(const QString &arg1)
{
    if (ui->lineEdit_2->text() != ui->lineEdit_3->text())
        ui->label_4->setText("Passwords don't match!");
    else {
        ui->label_4->setText("Passwords match!");
    }
}

void RegisterManager::on_buttonBox_accepted(QAbstractButton *button)
{
    QString user_name;
    QString user_surname;
    QString user_login;
    QString user_password;
    QString user_type;


    if (!ui->lineEdit->text().trimmed().isEmpty())
        user_login = ui->lineEdit->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Login cannot be empty!"));
        return;
    }
    if (!ui->lineEdit_2->text().trimmed().isEmpty()&& (ui->lineEdit_2->text() == ui->lineEdit_3->text()))
        user_password = ui->lineEdit_2->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Passwords cannot be empty or they don't match!"));
        return;
    }
    if (!ui->lineEdit_3->text().trimmed().isEmpty()&& (ui->lineEdit_2->text() == ui->lineEdit_3->text()))
        user_password = ui->lineEdit_3->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Passwords cannot be empty or they don't match!"));
        return;
    }

    if (!ui->lineEdit_4->text().trimmed().isEmpty())
        user_name = ui->lineEdit_4->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Name cannot be empty!"));
        return;
    }
    if (!ui->lineEdit_5->text().trimmed().isEmpty())
        user_surname = ui->lineEdit_5->text().trimmed();
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Surname cannot be empty!"));
        return;
    }
    if (!ui->comboBox->currentText().trimmed().isEmpty())
    {
        user_type = ui->comboBox->currentText().trimmed();
        if (user_type=="Librarian")
        user_type="2";
        if (user_type=="Client")
        user_type="1";
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Type cannot be empty!"));
        return;
    }

    bool isUser = isUserInDatabase(user_login);
    if (isUser)
    {
        QMessageBox::warning(this, tr("Warning"), tr("User already exists!"));
        return;
    }
    else
    {
        user_password = QString(QCryptographicHash::hash((user_password).toUtf8(),QCryptographicHash::Md5).toHex());
        createNewUser(user_login,user_password,user_name,user_surname,user_type);

        QMessageBox::information(this, tr("Information"), tr("Please, log in now."));
        return;
    }
}

bool RegisterManager::isUserInDatabase(QString login)
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

    QStringList logins;

    query.pop_back();

    while (!query.isEmpty())
    {
        logins.push_back(query[2]);
        for(int i=0;i<5;i++)
            query.pop_front();
    }

    int index = logins.indexOf(login);
    if(index!=-1)
    {
        return true;
    }

    else return false;

}

void RegisterManager::createNewUser(QString login, QString password, QString name, QString surname, QString type)
{
    QString path2 = QCoreApplication::applicationDirPath();
            path2.append("\\userdatabase.txt");
    QFile file2(path2);
    if (!file2.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"Error", file2.errorString());
    QTextStream in(&file2);
    QString text;
    text = in.readAll();
    file2.close();

    QString newQuery = text + name + ";" + surname + ";" + login + ";" + password + ";" + type + ";";

    QString path = QCoreApplication::applicationDirPath();
            path.append("\\userdatabase.txt");
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << newQuery;
}

void RegisterManager::on_buttonBox_rejected()
{

}

