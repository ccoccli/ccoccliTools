#pragma once

#include <QScreen>
#include <QLayout>
#include <QMessageBox>
#include <QMainWindow>
#include <QLayoutItem>
#include <QGuiApplication>

#include "config.h"

#include "db/originDB.hpp"
#include "ui/menubarWidget/menubarWidget.hpp"
#include "ui/statusbarWidget/statusbarWidget.hpp"

#include "tool/colorPacker/colorPackerWidget.hpp"
#include "tool/codeStatistics/codeStatisticsWidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

namespace staticFunc
{
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
    static inline void info(QWidget *parent, QString msg)
    {
        QMessageBox::information(parent, QString::fromStdString(config::WINDOW_MSGBOX_INFO_TITLE), msg);
    }
    static inline void warn(QWidget *parent, QString msg)
    {
        QMessageBox::warning(parent, QString::fromStdString(config::WINDOW_MSGBOX_WARN_TITLE), msg);
    }
    static inline void error(QWidget *parent, QString msg)
    {
        QMessageBox::warning(parent, QString::fromStdString(config::WINDOW_MSGBOX_ERROR_TITLE), msg);
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

    bool _userLoginStatus;
};
