#pragma once

#include <QStatusBar>

class statusbarWidget : public QStatusBar
{
    Q_OBJECT
public:
    statusbarWidget(QWidget *parent = nullptr);
    ~statusbarWidget();
};