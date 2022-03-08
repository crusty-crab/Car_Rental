#ifndef SQL_H
#define SQL_H

#include <QtSql>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

#include "car.h"

class sql
{
public:
    QSqlDatabase db;           //database
    void createdbFile();
    bool connectionOpen();
    void connectionClose();
    int importTotalAccounts();
    bool usernameExists(QString username);
    void importAccountDetails(QString username, QString &password, int &key);
    int importKey();
    void exportCarDetails(Car x);
};

#endif // SQL_H
