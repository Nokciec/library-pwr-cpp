#include <QCryptographicHash>
#include <QStringListModel>
#include <QTextStream>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QFile>
#include "book.h"
#include "mainwindow.h"
#include "bookmanager.h"
#include "ui_mainwindow.h"
#include "tablemodelclient.h"
#include "tablemodellibrarian.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    type(User::Type::Guest),
    rowActivate(-1)
{
    ui->setupUi(this);
    this->setWindowTitle("Library management system");
    setTypeOfUser(0);

    QHeaderView * qH = 	ui->tableView->horizontalHeader();
    qH->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->setVisible(false);

    connect(ui->tableView, SIGNAL(activated(const QModelIndex &)), this, SLOT(cellActivated(const QModelIndex &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    registermanager = new RegisterManager(this);
    if(registermanager->exec())
    {}
}

void MainWindow::on_pushButton_2_pressed()
{
    loginmanager = new LoginManager(this);
    if(loginmanager->exec())
    {
        if(loginmanager->getAccess())
            setTypeOfUser(loginmanager->getPermissions());
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    bookmanager manager;
    std::string stext;

    for(auto book : manager.showBooks())
        stext+=book.getTitle()+'\n';

    QString text = QString::fromStdString(stext);
    ui->textBrowser->setText(text);
}

void MainWindow::setTypeOfUser(int permissions)
{
    if (permissions==0)
    {
        this->type= User::Type::Guest;
        ui->tableView->setVisible(false);
        ui->textBrowser->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(false);
        ui->pushButton_5->setVisible(false);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_7->setVisible(false);
        ui->pushButton_8->setVisible(false);
        ui->pushButton_9->setVisible(false);
        ui->label->setVisible(false);
    }

    if (permissions==1)
    {
        QAbstractTableModel* model = new tablemodelclient(0);

        this->type= User::Type::Client;
        ui->tableView->setModel(model);
        ui->tableView->setVisible(true);
        ui->textBrowser->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->pushButton_5->setVisible(false);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_7->setVisible(true);
        ui->pushButton_8->setVisible(true);
        ui->pushButton_9->setVisible(true);
        ui->label->setVisible(true);
    }

    if (permissions==2)
    {
        QAbstractTableModel* model = new tablemodellibrarian(0);


        this->type= User::Type::Librarian;
        ui->tableView->setModel(model);
        ui->tableView->setVisible(true);
        ui->textBrowser->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(true);
        ui->pushButton_5->setVisible(true);
        ui->pushButton_6->setVisible(true);
        ui->pushButton_7->setVisible(false);
        ui->pushButton_8->setVisible(true);
        ui->pushButton_9->setVisible(true);
        ui->label->setVisible(true);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    addbookdialog= new addbookform(this);
    if(addbookdialog->exec())
    {}
    setTypeOfUser(loginmanager->getPermissions());
}

void MainWindow::on_pushButton_5_clicked()
{
    bookmanager manager;
    manager.deleteBook(rowActivate);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);

    setTypeOfUser(loginmanager->getPermissions());
}

void MainWindow::cellActivated(const QModelIndex &index)
{
    rowActivate=index.row();
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    rentbookdialog = new rentbookform(this);

    if(rentbookdialog->exec())
    {
        QString login = rentbookdialog->getLogin();
        if (!login.isEmpty())
        {
            bookmanager manager;
            manager.rentABook(rowActivate, login);
        }
    }
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);

    setTypeOfUser(loginmanager->getPermissions());
}

void MainWindow::on_pushButton_7_clicked()
{
    bookmanager manager;
    QString login = loginmanager->getLogin();
    manager.reserveABook(rowActivate, login);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);

    setTypeOfUser(loginmanager->getPermissions());
}

void MainWindow::on_pushButton_8_clicked()
{
    bookmanager manager;
    manager.renewABook(rowActivate);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);

    setTypeOfUser(loginmanager->getPermissions());
}

void MainWindow::on_pushButton_9_clicked()
{
        setTypeOfUser(0);
}
