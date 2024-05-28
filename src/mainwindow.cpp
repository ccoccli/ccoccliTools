#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), _login(new loginWidget)
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

#if 0
    QList<QVariantMap> results;
    if(_systemDB->query(OriginDB::DB_QUERY_TYPE::QUERY_SELECT, "select * from users where username = 'ccoccli';", &results))
    {
         if (!results.isEmpty()) 
         {
            QVariantMap userRecord = results.first();

            int id = userRecord["id"].toInt();
            QString username = userRecord["username"].toString();
            QString password = userRecord["password"].toString();
            QString email = userRecord["email"].toString();

            if(password == "0929")
            {
                _userLoginStatus = true;
            }
         }
    }
#endif
}

void MainWindow::initMenubarCallback()
{
    connect(_menubar, &menubarWidget::openFileNew, this, [=]() {

    });
    connect(_menubar, &menubarWidget::openFileOpen, this, [=]() {

    });
    connect(_menubar, &menubarWidget::openViewStatusbar, this, [=]() {

    });
    connect(_menubar, &menubarWidget::openColorPacker, this, [=]()
            { 
        if(!_login->getLoginStatus())
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_NOT_LOGIN_1));
        else
            this->setCentralWidget(new colorPackerWidget()); });

    connect(_menubar, &menubarWidget::openUserLogin, this, [=]()
            {
        if(_login->getLoginStatus())
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_HAS_LOGINED));
        else
        {
            this->setCentralWidget(_login);
        } });
    connect(_menubar, &menubarWidget::openUserCenter, this, [=]()
            {
        if(!_login->getLoginStatus())
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_NOT_LOGIN_1));
        else
        {
            this->setCentralWidget(new userCenterWidget());
        } });
    connect(_menubar, &menubarWidget::openUserSignup, this, [=]() {
        #if 0
        if(!_login->getLoginStatus())
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_HAS_NONEED_SIGNUP));
        else
            this->setCentralWidget(new signupWidget());
            #endif
    });
    connect(_menubar, &menubarWidget::openUserLogout, this, [=]()
            {
        if(!_login->getLoginStatus())
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_NOT_LOGIN_2));
        else
        {
            
        } });
    connect(_menubar, &menubarWidget::openCodeStatisticsCAndCPP, this, [=]()
            {
        if(!_login->getLoginStatus())
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_NOT_LOGIN_1));
        else
        {
            this->setCentralWidget(new codeStatisticsWidget(this, CODE_TYPE::CANDCPP));
        } });
    connect(_menubar, &menubarWidget::openCodeStatisticsJava, this, [=]()
            {
        if(!_login->getLoginStatus())
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_NOT_LOGIN_1));
        else
        {
            this->setCentralWidget(new codeStatisticsWidget(this, CODE_TYPE::JAVA));
        } });
    connect(_menubar, &menubarWidget::openCodeStatisticsPython, this, [=]()
            {
        if(!_login->getLoginStatus())
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_NOT_LOGIN_1));
        else
        {
            this->setCentralWidget(new codeStatisticsWidget(this, CODE_TYPE::PYTHON));
        } });
    connect(_menubar, &menubarWidget::openCodeStatisticsAssembly, this, [=]()
            {
        if(!_login->getLoginStatus())
            staticFunc::info(this, QString::fromStdString(config::menu::user::USER_NOT_LOGIN_1));
        else
        {
            this->setCentralWidget(new codeStatisticsWidget(this, CODE_TYPE::ASSEMBLY));
        } });
}
