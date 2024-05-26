#pragma once

#include <QScreen>
#include <QMainWindow>
#include <QGuiApplication>

#include "config.h"

#include "db/originDB.hpp"
#include "ui/menubarWidget/menubarWidget.hpp"
#include "ui/statusbarWidget/statusbarWidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initSystemSetting();
    void initSystemDatabase();
private:
    Ui::MainWindow *ui;

    menubarWidget *_menubar;
    statusbarWidget *_statusbar;
    OriginDB *_systemDB;
};
