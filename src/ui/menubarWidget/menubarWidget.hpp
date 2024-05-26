#pragma once

#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QKeySequence>

#include "config.h"

class menubarWidget : public QMenuBar
{
    Q_OBJECT
public:
    menubarWidget(QWidget *parent = nullptr);
    ~menubarWidget();

private:
    void initMenuBar();
    void initFileMenuAction();
    void initViewMenuAction();
    void initToolMenuAction();
    void initUserMenuAction();
signals:
    void openFileNew();
    void openFileOpen();
    void openViewStatusbar();
    void openColorPacker();
    void openUserLogin();
    void openUserCenter();
    void openUserSignup();
    void openUserLogout();

private:
    QMenu *_fileMenu, *_EditMenu, *_viewMenu, *_settingMenu, *_toolMenu, *_helpMenu, *_aboutMenu, *_userMenu;

    QAction *_fileNew, *_fileOpen;

    QAction *_viewStatusbar;

    QAction *_colorPacker;

    QAction *_userLogin, *_userCenter, *_userSignup, *_userLogout;
};