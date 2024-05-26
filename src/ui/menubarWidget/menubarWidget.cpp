#include "menubarWidget.hpp"

menubarWidget::menubarWidget(QWidget *parent) : QMenuBar(parent)
{
    initMenuBar();
    initFileMenuAction();
    initViewMenuAction();
    initToolMenuAction();
}

menubarWidget::~menubarWidget()
{
    delete _fileMenu;
    delete _EditMenu;
    delete _viewMenu;
    delete _settingMenu;
    delete _toolMenu;
    delete _aboutMenu;
    delete _helpMenu;

    delete _fileNew;
    delete _fileOpen;
    delete _viewStatusbar;
    delete _colorPacker;
}

void menubarWidget::initMenuBar()
{
    _fileMenu = addMenu(QString::fromLocal8Bit(config::menu::MENU_FILE));
    _EditMenu = addMenu(QString::fromLocal8Bit(config::menu::MENU_EDIT));
    _viewMenu = addMenu(QString::fromLocal8Bit(config::menu::MENU_VIEW));
    _settingMenu = addMenu(QString::fromLocal8Bit(config::menu::MENU_SETTING));
    _toolMenu = addMenu(QString::fromLocal8Bit(config::menu::MENU_TOOL));
    _aboutMenu = addMenu(QString::fromLocal8Bit(config::menu::MENU_ABOUT));
    _helpMenu = addMenu(QString::fromLocal8Bit(config::menu::MENU_HELP));
}

void menubarWidget::initFileMenuAction()
{
    _fileNew = _fileMenu->addAction(QString::fromLocal8Bit(config::menu::file::FILE_NEW));
    _fileNew->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    connect(_fileNew, &QAction::triggered, this, [this]()
            { emit openFileNew(); });

    _fileOpen = _fileMenu->addAction(QString::fromLocal8Bit(config::menu::file::FILE_OPEN));
    _fileOpen->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    connect(_fileOpen, &QAction::triggered, this, [this]()
            { emit openFileOpen(); });
}

void menubarWidget::initViewMenuAction()
{
    _viewStatusbar = _viewMenu->addAction(QString::fromLocal8Bit(config::menu::view::VIEW_STATUSBAR));
    _viewStatusbar->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_M));
    connect(_viewStatusbar, &QAction::triggered, this, [this]()
            { emit openViewStatusbar(); });
}

void menubarWidget::initToolMenuAction()
{
    _colorPacker = _toolMenu->addAction(QString::fromLocal8Bit(config::menu::tool::TOOL_COLOR_PACKER));
    _colorPacker->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_P));
    connect(_colorPacker, &QAction::triggered, this, [this]()
            { emit openColorPacker(); });
}
