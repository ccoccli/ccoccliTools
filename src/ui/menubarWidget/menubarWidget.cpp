#include "menubarWidget.hpp"

menubarWidget::menubarWidget( QWidget *parent ) : QMenuBar( parent )
{
    initMenuBar();
    initFileMenuAction();
    initViewMenuAction();
    initToolMenuAction();
    initUserMenuAction();
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
    delete _userMenu;
    delete _fileNew;
    delete _fileOpen;
    delete _viewStatusbar;
    delete _colorPacker;
    delete _userLogin;
    delete _userCenter;
    delete _userSignup;
    delete _userLogout;
}

void menubarWidget::initMenuBar()
{
    _fileMenu = addMenu( QString::fromStdString( config::menu::MENU_FILE ) );
    _EditMenu = addMenu( QString::fromStdString( config::menu::MENU_EDIT ) );
    _viewMenu = addMenu( QString::fromStdString( config::menu::MENU_VIEW ) );
    _settingMenu = addMenu( QString::fromStdString( config::menu::MENU_SETTING ) );
    _toolMenu = addMenu( QString::fromStdString( config::menu::MENU_TOOL ) );
    _aboutMenu = addMenu( QString::fromStdString( config::menu::MENU_ABOUT ) );
    _helpMenu = addMenu( QString::fromStdString( config::menu::MENU_HELP ) );
    _userMenu = addMenu( QString::fromStdString( config::menu::MENU_USER ) );
    _codeStatistics = _toolMenu->addMenu( QString::fromStdString( config::menu::tool::TOOL_CODE_STATISTICS ) );
}

void menubarWidget::initFileMenuAction()
{
    _fileNew = _fileMenu->addAction( QString::fromStdString( config::menu::file::FILE_NEW ) );
    _fileNew->setShortcut( QKeySequence( Qt::CTRL | Qt::Key_N ) );
    connect( _fileNew, &QAction::triggered, this, [this]()
    {
        emit openFileNew();
    } );
    _fileOpen = _fileMenu->addAction( QString::fromStdString( config::menu::file::FILE_OPEN ) );
    _fileOpen->setShortcut( QKeySequence( Qt::CTRL | Qt::Key_O ) );
    connect( _fileOpen, &QAction::triggered, this, [this]()
    {
        emit openFileOpen();
    } );
}

void menubarWidget::initViewMenuAction()
{
    _viewStatusbar = _viewMenu->addAction( QString::fromStdString( config::menu::view::VIEW_STATUSBAR ) );
    _viewStatusbar->setShortcut( QKeySequence( Qt::CTRL | Qt::Key_M ) );
    connect( _viewStatusbar, &QAction::triggered, this, [this]()
    {
        emit openViewStatusbar();
    } );
}

void menubarWidget::initToolMenuAction()
{
    _colorPacker = _toolMenu->addAction( QString::fromStdString( config::menu::tool::TOOL_COLOR_PACKER ) );
    _colorPacker->setShortcut( QKeySequence( Qt::CTRL | Qt::Key_P ) );
    connect( _colorPacker, &QAction::triggered, this, [this]()
    {
        emit openColorPacker();
    } );
    _codeStatisticsCAndCPlusPlus = _codeStatistics->addAction( QString::fromStdString( config::menu::tool::codeStatistics::CODESTATISTICS_C_CPP ) );
    connect( _codeStatisticsCAndCPlusPlus, &QAction::triggered, this, [this]()
    {
        emit openCodeStatisticsCAndCPP();
    } );
    _codeStatisticsAssembly = _codeStatistics->addAction( QString::fromStdString( config::menu::tool::codeStatistics::CODESTATISTICS_ASSEMBLY ) );
    connect( _codeStatisticsAssembly, &QAction::triggered, this, [this]()
    {
        emit openCodeStatisticsAssembly();
    } );
    _codeStatisticsJava = _codeStatistics->addAction( QString::fromStdString( config::menu::tool::codeStatistics::CODESTATISTICS_JAVA ) );
    connect( _codeStatisticsJava, &QAction::triggered, this, [this]()
    {
        emit openCodeStatisticsJava();
    } );
    _codeStatisticsPython = _codeStatistics->addAction( QString::fromStdString( config::menu::tool::codeStatistics::CODESTATISTICS_PYTHON ) );
    connect( _codeStatisticsPython, &QAction::triggered, this, [this]()
    {
        emit openCodeStatisticsPython();
    } );
}

void menubarWidget::initUserMenuAction()
{
    _userLogin = _userMenu->addAction( QString::fromStdString( config::menu::user::USER_LOGIN ) );
    _userLogin->setShortcut( QKeySequence( Qt::CTRL | Qt::Key_L ) );
    connect( _userLogin, &QAction::triggered, this, [this]()
    {
        emit openUserLogin();
    } );
    _userSignup = _userMenu->addAction( QString::fromStdString( config::menu::user::USER_SIGNUP ) );
    _userSignup->setShortcut( QKeySequence( Qt::CTRL | Qt::Key_K ) );
    connect( _userSignup, &QAction::triggered, this, [this]()
    {
        emit openUserSignup();
    } );
    _userCenter = _userMenu->addAction( QString::fromStdString( config::menu::user::USER_CENTER ) );
    _userCenter->setShortcut( QKeySequence( Qt::CTRL | Qt::Key_J ) );
    connect( _userCenter, &QAction::triggered, this, [this]()
    {
        emit openUserCenter();
    } );
    _userLogout = _userMenu->addAction( QString::fromStdString( config::menu::user::USER_LOGOUT ) );
    _userLogout->setShortcut( QKeySequence( Qt::CTRL | Qt::Key_H ) );
    connect( _userLogout, &QAction::triggered, this, [this]()
    {
        emit openUserLogout();
    } );
}
