#include "loginWidget.hpp"

loginWidget::loginWidget( QWidget *parent ) : QWidget( parent ), _userLoginStatus( false )
{
    // init user info sqlite database
    try
    {
        _userInfoDB = new OriginDB( config::database::SYSTEMINFO_USER_DATABASE );
        _userInfoDB->connect();
    }
    catch ( const std::runtime_error &e )
    {
        qDebug() << "Error : " << e.what();
    }
    initLayout();
}

loginWidget::~loginWidget()
{
    delete _userInfoDB;
}

void loginWidget::initLayout()
{
    // 设置标签样式
    QFont labelFont;
    labelFont.setPointSize( config::menu::user::login::LOGIN_FONT_SIZE ); // 设置字体大小
    labelFont.setBold( true );                                          // 设置字体加粗
    // 创建用户名标签和输入框
    QLabel *usernameLabel = new QLabel( QString::fromStdString( config::menu::user::login::LOGIN_USERNAME ) );
    usernameLabel->setFont( labelFont );
    usernameLabel->setFixedWidth( config::menu::user::login::LOGIN_LABEL_WIDTH );
    usernameLabel->setFixedHeight( config::menu::user::login::LOGIN_COMPONENT_HEIGHT );
    usernameLabel->setAlignment( Qt::AlignCenter | Qt::AlignVCenter );
    QLineEdit *usernameLineEdit = new QLineEdit;
    usernameLineEdit->setFont( labelFont );
    usernameLineEdit->setPlaceholderText( QString::fromStdString( config::menu::user::login::LOGIN_INPUT_USERNAME ) );
    usernameLineEdit->setFixedHeight( config::menu::user::login::LOGIN_COMPONENT_HEIGHT );
    // 创建密码标签和输入框
    QLabel *passwordLabel = new QLabel( QString::fromStdString( config::menu::user::login::LOGIN_PASSWORD ) );
    passwordLabel->setFont( labelFont );
    passwordLabel->setFixedWidth( config::menu::user::login::LOGIN_LABEL_WIDTH );
    passwordLabel->setFixedHeight( config::menu::user::login::LOGIN_COMPONENT_HEIGHT );
    passwordLabel->setAlignment( Qt::AlignCenter | Qt::AlignVCenter );
    QLineEdit *passwordLineEdit = new QLineEdit;
    passwordLineEdit->setFont( labelFont );
    passwordLineEdit->setPlaceholderText( QString::fromStdString( config::menu::user::login::LOGIN_INPUT_PASSWORD ) );
    passwordLineEdit->setEchoMode( QLineEdit::Password ); // 隐藏输入字符
    passwordLineEdit->setFixedHeight( config::menu::user::login::LOGIN_COMPONENT_HEIGHT );
    // 创建按钮
    QPushButton *loginButton = new QPushButton( QString::fromStdString( config::menu::user::login::LOGIN_LOGIN ) );
    QPushButton *forgetPasswordButton = new QPushButton( QString::fromStdString( config::menu::user::login::LOGIN_FORGET_PASSWORD ) );
    QPushButton *signupButton = new QPushButton( QString::fromStdString( config::menu::user::login::LOGIN_SINGNUP ) );
    // 设置按钮样式
    QPalette buttonPalette;
    buttonPalette.setColor( QPalette::Button, QColor( QString::fromStdString( config::menu::user::login::LOGIN_BUTTON_BG ) ) ); // 设置按钮背景色
    buttonPalette.setColor( QPalette::ButtonText, QColor( QString::fromStdString( config::menu::user::login::LOGIN_BUTTON_FG ) ) ); // 设置按钮文字颜色
    loginButton->setPalette( buttonPalette );
    forgetPasswordButton->setPalette( buttonPalette );
    signupButton->setPalette( buttonPalette );
    loginButton->setFixedHeight( config::menu::user::login::LOGIN_COMPONENT_HEIGHT );
    forgetPasswordButton->setFixedHeight( config::menu::user::login::LOGIN_COMPONENT_HEIGHT );
    signupButton->setFixedHeight( config::menu::user::login::LOGIN_COMPONENT_HEIGHT );
    loginButton->setFont( labelFont );
    forgetPasswordButton->setFont( labelFont );
    signupButton->setFont( labelFont );
    // 设置按钮悬停样式
    loginButton->setStyleSheet( QString::fromStdString( config::menu::user::login::LOGIN_BUTTON_HOVER_STYLE ) );
    forgetPasswordButton->setStyleSheet( QString::fromStdString( config::menu::user::login::LOGIN_BUTTON_HOVER_STYLE ) );
    signupButton->setStyleSheet( QString::fromStdString( config::menu::user::login::LOGIN_BUTTON_HOVER_STYLE ) );
    // 创建布局
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *usernameLayout = new QHBoxLayout;
    QHBoxLayout *passwordLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *loginLayout = new QVBoxLayout;
    // 添加控件到布局
    usernameLayout->addWidget( usernameLabel );
    usernameLayout->addWidget( usernameLineEdit );
    passwordLayout->addWidget( passwordLabel );
    passwordLayout->addWidget( passwordLineEdit );
    buttonLayout->addWidget( loginButton );
    buttonLayout->addWidget( forgetPasswordButton );
    loginLayout->addLayout( buttonLayout );
    loginLayout->addWidget( signupButton );
    mainLayout->addLayout( usernameLayout );
    mainLayout->addLayout( passwordLayout );
    mainLayout->addLayout( loginLayout );
    // 设置间距
    mainLayout->setSpacing( config::menu::user::login::LOGIN_LAYOUT_PADDING ); // 设置布局之间的间距
    // 设置窗口布局
    this->setLayout( mainLayout );
    // 连接按钮的信号和槽函数
    connect( loginButton, &QPushButton::clicked, this, [ = ]()
    {
        QList<QVariantMap> results;
        auto cmd = QString( "select password from users where username = '%1';" ).arg( usernameLineEdit->text() );
        if ( _userInfoDB->query( OriginDB::DB_QUERY_TYPE::QUERY_SELECT, cmd.toStdString(), &results ) )
        {
            if ( !results.isEmpty() )
            {
                if ( results.first()["password"].toString() == passwordLineEdit->text() )
                    _userLoginStatus = true;
                else
                    _userLoginStatus = false;
            }
        }
    } );
    connect( forgetPasswordButton, &QPushButton::clicked, this, [ = ]()
    {
        // 实现忘记密码逻辑
        QMessageBox::information( this, "Forget Password", "Forget Password clicked" );
    } );
    connect( signupButton, &QPushButton::clicked, this, [ = ]()
    {
        // 实现注册逻辑
        QMessageBox::information( this, "Sign Up", "Sign Up clicked" );
    } );
}
