#include "originDB.hpp"

OriginDB::OriginDB(const QString &pDBName)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(pDBName);
}

OriginDB::~OriginDB()
{
    if (_connect_status)
    {
        _db.close();
    }
}

void OriginDB::connect()
{
    if (_db.open())
    {
        _connect_status = true;
    }
    else
    {
        _connect_status = false;
        throw std::runtime_error(_db.lastError().text().toStdString());
    }
}
