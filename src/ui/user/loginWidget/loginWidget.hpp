#pragma once

#include <QWidget>

#include "config.h"

class loginWidget : public QWidget
{
    Q_OBJECT
public:
    loginWidget(QWidget *parent = nullptr);
    ~loginWidget();
};
