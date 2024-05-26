#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
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
    _statusbar = new statusbarWidget();

    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
    this->setFixedSize(QSize(QGuiApplication::primaryScreen()->size().width() / 2, QGuiApplication::primaryScreen()->size().height() / 2));
    this->setMenuBar(_menubar);
    this->setStatusBar(_statusbar);

    this->setWindowTitle(config::WINDOW_TITLE);
    this->setWindowIcon(QIcon(config::image::WINDOW_ICON));
    this->setCursor(QCursor(QPixmap(config::image::WINDOW_CURSOR).scaled(QSize(16, 16))));
}

void MainWindow::initSystemDatabase()
{
    // init sqlite database
    try
    {
        _systemDB = new OriginDB(config::database::SYSTEMINFO_DATABASE);
        _systemDB->connect();
    }
    catch (const std::runtime_error &e)
    {
        qDebug() << "Error : " << e.what();
    }
}
