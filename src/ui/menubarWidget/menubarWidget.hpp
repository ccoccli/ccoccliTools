#pragma once

#include <QMenuBar>

class menubarWidget : public QMenuBar
{
    Q_OBJECT
public:
    menubarWidget(QWidget *parent = nullptr);
    ~menubarWidget();
};