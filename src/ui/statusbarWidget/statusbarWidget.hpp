#pragma once

#include <QStatusBar>

#include "config.h"

class statusbarWidget : public QStatusBar
{
    Q_OBJECT
public:
    statusbarWidget(QWidget *parent = nullptr);
    ~statusbarWidget();

private:
    void setColor(QWidget *widget, const QColor &color);
    void setColor(QWidget *widget, const QString &hexColor);
};