#pragma once

#include <stdexcept>
#include <QSqlError>
#include <QSqlDatabase>

class OriginDB
{
public:
    OriginDB() = delete;
    OriginDB(const QString &pDBName);
    ~OriginDB();

    void connect();
    
private:
    QSqlDatabase _db;
    bool _connect_status;
};