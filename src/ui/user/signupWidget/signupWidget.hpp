#pragma once

#include <QWidget>

#include "config.h"

class signupWidget : public QWidget
{
    Q_OBJECT
public:
    signupWidget( QWidget *parent = nullptr );
    ~signupWidget();
};
