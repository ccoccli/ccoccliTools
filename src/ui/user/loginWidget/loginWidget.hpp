#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

#include "config.h"

#include "db/originDB.hpp"

class loginWidget : public QWidget
{
    Q_OBJECT
public:
    loginWidget( QWidget *parent = nullptr );
    ~loginWidget();

public:
    bool getLoginStatus()
    {
        return _userLoginStatus;
    }

private:
    void initLayout();

private:
    OriginDB *_userInfoDB;

    bool _userLoginStatus;
};
