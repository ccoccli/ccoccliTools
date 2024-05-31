#pragma once

#include <stdexcept>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

class OriginDB
{
public:
    typedef enum class _database_query_type_e
    {
        QUERY_INSERT,
        QUERY_DELETE,
        QUERY_UPDATE,
        QUERY_SELECT
    } DB_QUERY_TYPE;

public:
    OriginDB() = delete;
    OriginDB( const QString &pDBName );
    ~OriginDB();

    void connect();
    bool query( const DB_QUERY_TYPE &pType, const std::string &pCommand, void *data );
private:
    QSqlDatabase _db;
    bool _connect_status;
};