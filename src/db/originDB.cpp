#include "originDB.hpp"

OriginDB::OriginDB( const QString &pDBName )
{
    _db = QSqlDatabase::addDatabase( "QSQLITE" );
    _db.setDatabaseName( pDBName );
}

OriginDB::~OriginDB()
{
    if ( _connect_status )
        _db.close();
}

void OriginDB::connect()
{
    if ( _db.open() )
        _connect_status = true;
    else
    {
        _connect_status = false;
        throw std::runtime_error( _db.lastError().text().toStdString() );
    }
}
bool OriginDB::query( const DB_QUERY_TYPE &pType, const std::string &pCommand, void *data )
{
    if ( !_connect_status )
        throw std::runtime_error( "Database not connected" );
    QSqlQuery query;
    QString command = QString::fromStdString( pCommand );
    switch ( pType )
    {
    case DB_QUERY_TYPE::QUERY_INSERT:
    case DB_QUERY_TYPE::QUERY_DELETE:
    case DB_QUERY_TYPE::QUERY_UPDATE:
        if ( !query.exec( command ) )
        {
            qDebug() << "SQL error: " << query.lastError();
            return false;
        }
        return true;
    case DB_QUERY_TYPE::QUERY_SELECT:
        if ( !query.exec( command ) )
        {
            qDebug() << "SQL error: " << query.lastError();
            return false;
        }
        if ( data != nullptr )
        {
            auto *resultList = static_cast<QList<QVariantMap>*>( data );
            QSqlRecord record = query.record();
            while ( query.next() )
            {
                QVariantMap row;
                for ( int i = 0; i < record.count(); ++i )
                    row.insert( record.fieldName( i ), query.value( i ) );
                resultList->append( row );
            }
        }
        return true;
    default:
        throw std::invalid_argument( "Invalid query type" );
    }
}
