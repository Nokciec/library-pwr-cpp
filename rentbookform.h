#ifndef RENTBOOKFORM_H
#define RENTBOOKFORM_H

#include <QDialog>
#include "registermanager.h"

namespace Ui {
class rentbookform;
}

class rentbookform : public QDialog
{
    Q_OBJECT

public:
    explicit rentbookform(QWidget *parent = 0);
    ~rentbookform();
        QString getLogin() { return login; }

private slots:
    void on_buttonBox_accepted();

private:
    Ui::rentbookform *ui;
        QString login;
};

#endif // RENTBOOKFORM_H
