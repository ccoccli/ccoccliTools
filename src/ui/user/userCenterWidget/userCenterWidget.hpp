#pragma once

#include <QWidget>

#include "config.h"

class userCenterWidget : public QWidget
{
    Q_OBJECT
public:
    userCenterWidget(QWidget *parent = nullptr);
    ~userCenterWidget();
};