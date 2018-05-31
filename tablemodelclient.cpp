#include "tablemodelclient.h"

tablemodelclient::tablemodelclient(QObject *parent)
    : QAbstractTableModel(parent)
{
    bookmanager manager;
    m_query = manager.getContent();

    table_content.resize(m_query.size()/14);

    for(auto &row : table_content)
        row.resize(14);

    int j=0;
    for(int i=0; i < m_query.size()/14; i++)
    {
        for(int x=0; x<14;x++)
        {
            table_content[i][x]=m_query[j];
            j++;
        }
    }

    for(auto &row : table_content)
    {
        row.erase(row.begin()+13);
        row.erase(row.begin()+11);
        row.erase(row.begin()+10);
        row.erase(row.begin()+9);
        row.erase(row.begin());
    }
}

QVariant tablemodelclient::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Title");
            case 1:
                return QString("Author");
            case 2:
                return QString("ISBN");
            case 3:
                return QString("Date of publishing");
            case 4:
                return QString("Place of publishing");
            case 5:
                return QString("Publisher");
            case 6:
                return QString("Number of pages");
            case 7:
                return QString("Avalibility");
            case 8:
                return QString("Reservation");
            default:
                return QString("where did this column come from");
            }
        }
    }
    return QVariant();
}

int tablemodelclient::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    else return m_query.size()/14;
}

int tablemodelclient::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    else return 9;
}

QVariant tablemodelclient::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        return QString(table_content[index.row()][index.column()]);
    }
    return QVariant();
}
