#ifndef TABLEMODELLIBRARIAN_H
#define TABLEMODELLIBRARIAN_H

#include <QAbstractTableModel>
#include "bookmanager.h"


class tablemodellibrarian : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit tablemodellibrarian(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    std::vector<QString> m_query;
    std::vector<std::vector<QString>> table_content;

};

#endif // TABLEMODELLIBRARIAN_H
