#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    QSqlDatabase mydb;
    void connClose()
    {
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
