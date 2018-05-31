#include "rentbookform.h"
#include "ui_rentbookform.h"

rentbookform::rentbookform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rentbookform)
{
    ui->setupUi(this);
    this->setWindowTitle("Renting a book");
}

rentbookform::~rentbookform()
{
    delete ui;
}

void rentbookform::on_buttonBox_accepted()
{
    RegisterManager manager;

    if (!ui->lineEdit->text().trimmed().isEmpty())
    {
        QString templogin = ui->lineEdit->text().trimmed();
        bool isInDatabase =  manager.isUserInDatabase(templogin);
        if(isInDatabase==false)
        {
            QMessageBox::warning(this, tr("Warning"), tr("User doesn't exist!"));
            return;
        }
        else
        {
            login = templogin;
            return;
        }
    }

    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Login cannot be empty!"));
        return;
    }
}
