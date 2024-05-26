#include "colorPackerWidget.hpp"

colorPackerWidget::colorPackerWidget(QWidget *parent) : m_hex(config::menu::tool::colorPacker::DEFAULT_COLOR_HEX),
                                                        m_a(config::menu::tool::colorPacker::DEFAULT_COLOR_A),
                                                        m_r(config::menu::tool::colorPacker::DEFAULT_COLOR_R),
                                                        m_g(config::menu::tool::colorPacker::DEFAULT_COLOR_G),
                                                        m_b(config::menu::tool::colorPacker::DEFAULT_COLOR_B),
                                                        _color_packer_table_current_index(0)
{
    // this->setFixedSize(QSize(QGuiApplication::primaryScreen()->size().width() / 2, QGuiApplication::primaryScreen()->size().height() / 2));
    initLayout();
    initAction();
}

colorPackerWidget::~colorPackerWidget()
{
    delete _table;
    delete _colorBlock;
}

void colorPackerWidget::initLayout()
{
    auto colorLabelTitle = new QLabel(QString::fromLocal8Bit(config::menu::tool::colorPacker::COLOR_PACKER_TITLE));
    _colorBlock = new QLabel(this);
    auto leftLayout = new QVBoxLayout;
    auto rightLayout = new QVBoxLayout;
    auto colorPackListTitle = new QLabel(QString::fromLocal8Bit(config::menu::tool::colorPacker::COLOR_PACKER_PACKLIST_TITLE));
    _table = new QTableWidget;
    QStringList tableHead;
    auto centerLayout = new QHBoxLayout;

    setColor(_colorBlock, QColor(config::menu::tool::colorPacker::DEFAULT_COLOR_BLOCK_CLOR));
    colorLabelTitle->setFixedHeight(config::menu::tool::colorPacker::COLOR_PACKER_PACKLIST_HEIGHT);
    colorPackListTitle->setFixedHeight(config::menu::tool::colorPacker::COLOR_PACKER_PACKLIST_HEIGHT);

    tableHead << config::menu::tool::colorPacker::COLOR_PACKER_PACKLIST_HEAD_RGB << config::menu::tool::colorPacker::COLOR_PACKER_PACKLIST_HEAD_ARGB << config::menu::tool::colorPacker::COLOR_PACKER_PACKLIST_HEAD_HEX;
    _table->setColumnCount(config::menu::tool::colorPacker::COLOR_PACKER_PACKLIST_COLUMN_NUM);
    _table->setHorizontalHeaderLabels(tableHead);
    _table->verticalHeader()->setVisible(false);

    for (auto i = 0; i < config::menu::tool::colorPacker::COLOR_PACKER_PACKLIST_COLUMN_NUM; i++)
    {
        _table->setColumnWidth(i, QGuiApplication::primaryScreen()->size().width() / 2 / 2 / config::menu::tool::colorPacker::COLOR_PACKER_PACKLIST_COLUMN_NUM);
    }

    leftLayout->addWidget(colorLabelTitle, 1);
    leftLayout->addWidget(_colorBlock, 3);

    rightLayout->addWidget(colorPackListTitle, 1);
    rightLayout->addWidget(_table, 3);

    centerLayout->addLayout(leftLayout, 1);
    centerLayout->addLayout(rightLayout, 1);

    this->setLayout(centerLayout);
}

void colorPackerWidget::initAction()
{
    auto timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &colorPackerWidget::getCurrentValue);
    timer->start();

    auto action = new QAction(this);
    connect(action, &QAction::triggered, this, &colorPackerWidget::saveCurrentValue);
    connect(new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_S), this), &QShortcut::activated, action, &QAction::trigger);
}

void colorPackerWidget::getCurrentValue()
{
    auto screenShot = QGuiApplication::primaryScreen()->grabWindow(0, QCursor::pos().x(), QCursor::pos().y(), 1, 1);

    if (!screenShot.isNull())
    {
        auto image = screenShot.toImage();
        if (!image.isNull())
        {
            auto color = image.pixelColor(0, 0);
            m_a = color.alpha();
            m_r = color.red();
            m_g = color.green();
            m_b = color.blue();
            m_hex = color.name();

            setColor(_colorBlock, m_hex);
        }
    }
}

void colorPackerWidget::saveCurrentValue()
{
    _table->insertRow(_color_packer_table_current_index);

    _table->setItem(_color_packer_table_current_index, 0, new QTableWidgetItem(QString("(%1, %2, %3)").arg(QString::number(m_r)).arg(QString::number(m_g)).arg(QString::number(m_b))));
    _table->setItem(_color_packer_table_current_index, 1, new QTableWidgetItem(QString("(%1, %2, %3, %4)").arg(QString::number(m_a)).arg(QString::number(m_r)).arg(QString::number(m_g)).arg(QString::number(m_b))));
    _table->setItem(_color_packer_table_current_index, 2, new QTableWidgetItem(QString("%1").arg(m_hex)));

    _table->scrollToItem(_table->item(_color_packer_table_current_index++, 0));
}

void colorPackerWidget::setColor(QWidget *widget, const QColor &color)
{
    widget->setStyleSheet(QString("background-color:%1;").arg(color.name()));
}

void colorPackerWidget::setColor(QWidget *widget, const QString &hexColor)
{
    widget->setStyleSheet(QString("background-color:%1;").arg(hexColor));
}
