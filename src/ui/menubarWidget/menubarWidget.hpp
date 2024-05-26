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
signals:
    void openFileNew();
    void openFileOpen();
    void openViewStatusbar();
    void openColorPacker();
private:
    QMenu *_fileMenu, *_EditMenu, *_viewMenu, *_settingMenu, *_toolMenu, *_helpMenu, *_aboutMenu;

    QAction *_fileNew, *_fileOpen;

    QAction *_viewStatusbar;

    QAction *_colorPacker;
};