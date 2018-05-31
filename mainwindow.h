#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "loginmanager.h"
#include <QMainWindow>
#include <QDebug>
#include "user.h"
#include "registermanager.h"
#include <QModelIndexList>
#include "bookmanager.h"
#include "addbookform.h"
#include "rentbookform.h"
#include <QSqlTableModel>
#include <loginmanager.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void cellActivated(const QModelIndex &index);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();


private:
    Ui::MainWindow *ui;
    LoginManager *loginmanager;
    User::Type type;
    RegisterManager *registermanager;
    addbookform *addbookdialog;
    rentbookform *rentbookdialog;
    void setTypeOfUser(int permissions);
    int rowActivate;
    QAbstractTableModel *model1;
    QAbstractTableModel *model2;

};

#endif // MAINWINDOW_H
