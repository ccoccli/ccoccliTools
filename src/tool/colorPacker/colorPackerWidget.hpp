#pragma once

#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QScreen>
#include <QShortcut>
#include <QHeaderView>
#include <QStringList>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QApplication>
#include <QKeySequence>
#include <QGuiApplication>

#include "config.h"

class colorPackerWidget : public QWidget
{
    Q_OBJECT
public:
    colorPackerWidget( QWidget *parent = nullptr );
    ~colorPackerWidget();

private:
    void initLayout();
    void initAction();

    void getCurrentValue();
    void saveCurrentValue();

    void setColor( QWidget *widget, const QColor &color );
    void setColor( QWidget *widget, const QString &hexColor );

private:
    QTableWidget *_table;
    QLabel *_colorBlock;
    QString m_hex;
    unsigned int m_a, m_r, m_g, m_b;
    unsigned int _color_packer_table_current_index;
};