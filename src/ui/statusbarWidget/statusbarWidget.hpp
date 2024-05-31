#pragma once

#include <QStatusBar>
#include <QDateTime>
#include <QTimer>
#include <QLabel>

#include "config.h"

class statusbarWidget : public QStatusBar
{
    Q_OBJECT
public:
    statusbarWidget( QWidget *parent = nullptr );
    ~statusbarWidget();

private:
    void setColor( QWidget *widget, const QColor &color );
    void setColor( QWidget *widget, const QString &hexColor );

    QString getCurrentDateTimeString()
    {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        return currentDateTime.toString( "yyyy-MM-dd hh:mm:ss" );
    }

private:
    QLabel *label;
};