#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), _userLoginStatus(false)
{
    ui->setupUi(this);

    initSystemSetting();
    initSystemDatabase();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _menubar;
    delete _statusbar;
    delete _systemDB;
}

void MainWindow::initSystemSetting()
{
    _menubar = new menubarWidget();
    initMenubarCallback();

    _statusbar = new statusbarWidget();

    this->setFixedSize(QSize(QGuiApplication::primaryScreen()->size().width() / 2, QGuiApplication::primaryScreen()->size().height() / 2));
    this->setMenuBar(_menubar);
    this->setStatusBar(_statusbar);

    this->setWindowTitle(QString::fromStdString(config::WINDOW_TITLE));
    this->setWindowIcon(QIcon(config::image::WINDOW_ICON));
    this->setCursor(QCursor(QPixmap(config::image::WINDOW_CURSOR).scaled(QSize(16, 16))));
}

void MainWindow::initSystemDatabase()
{
    // init user info sqlite database
    try
    {
        _systemDB = new OriginDB(config::database::SYSTEMINFO_USER_DATABASE);
        _systemDB->connect();
    }
    catch (const std::runtime_error &e)
    {
        qDebug() << "Error : " << e.what();
    }
}

void MainWindow::initMenubarCallback()
{
    connect(_menubar, &menubarWidget::openFileNew, this, [=]() {

    });
    connect(_menubar, &menubarWidget::openFileOpen, this, [=]() {

    });
    connect(_menubar, &menubarWidget::openViewStatusbar, this, [=]() {

    });
    connect(_menubar, &menubarWidget::openColorPacker, this, [=]() { 
        if(!_userLoginStatus)
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_NOT_LOGIN_1));
        else
            this->setCentralWidget(new colorPackerWidget());
    });

    connect(_menubar, &menubarWidget::openUserLogin, this, [=]() {
        if(_userLoginStatus)
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_HAS_LOGINED));
        else
        {

        }
    });
    connect(_menubar, &menubarWidget::openUserCenter, this, [=]() {
        if(!_userLoginStatus)
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_NOT_LOGIN_1));
        else
        {

        }
    });
    connect(_menubar, &menubarWidget::openUserSignup, this, [=]() {

    });
    connect(_menubar, &menubarWidget::openUserLogout, this, [=]() {
        if(!_userLoginStatus)
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_NOT_LOGIN_2));
        else
        {
            
        }
    });
    connect(_menubar, &menubarWidget::openCodeStatisticsCAndCPP, this, [=]() {
        this->setCentralWidget(new codeStatisticsWidget(this, CODE_TYPE::CANDCPP));
    });
    connect(_menubar, &menubarWidget::openCodeStatisticsJava, this, [=]() {
        this->setCentralWidget(new codeStatisticsWidget(this, CODE_TYPE::JAVA));

    });
    connect(_menubar, &menubarWidget::openCodeStatisticsPython, this, [=]() {
        this->setCentralWidget(new codeStatisticsWidget(this, CODE_TYPE::PYTHON));

    });
    connect(_menubar, &menubarWidget::openCodeStatisticsAssembly, this, [=]() {
        this->setCentralWidget(new codeStatisticsWidget(this, CODE_TYPE::ASSEMBLY));

    });
}
