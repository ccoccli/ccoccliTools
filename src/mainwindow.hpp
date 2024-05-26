#pragma once

#include <QScreen>
#include <QLayout>
#include <QMainWindow>
#include <QLayoutItem>
#include <QGuiApplication>

#include "config.h"

#include "db/originDB.hpp"
#include "ui/menubarWidget/menubarWidget.hpp"
#include "ui/statusbarWidget/statusbarWidget.hpp"

#include "tool/colorPacker/colorPackerWidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

static inline void clearLayoutRecursive(QLayout *layout) noexcept
{
    if (!layout)
    {
        return;
    }
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr)
    {
        if (child->widget())
        {
            delete child->widget();
        }
        else if (QLayout *childLayout = child->layout())
        {
            clearLayoutRecursive(childLayout);
            delete childLayout;
        }
    }
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initSystemSetting();
    void initSystemDatabase();

    void initMenubarCallback();

private:
    Ui::MainWindow *ui;

    QWidget *_centerWidget;
    menubarWidget *_menubar;
    statusbarWidget *_statusbar;
    OriginDB *_systemDB;
};
