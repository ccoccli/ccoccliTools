#include "statusbarWidget.hpp"

statusbarWidget::statusbarWidget(QWidget *parent) : QStatusBar(parent)
{
    setColor(this, QColor(config::statusbar::DEFAULT_BACKGROUND_COLOR));

    label = new QLabel(getCurrentDateTimeString());

    // 创建定时器
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]()
            { label->setText(getCurrentDateTimeString()); });

    timer->start(1000); // 1000ms = 1s

    this->addWidget(label);
}

statusbarWidget::~statusbarWidget()
{
}

void statusbarWidget::setColor(QWidget *widget, const QColor &color)
{
    widget->setStyleSheet(QString("background-color:%1;").arg(color.name()));
}

void statusbarWidget::setColor(QWidget *widget, const QString &hexColor)
{
    widget->setStyleSheet(QString("background-color:%1;").arg(hexColor));
}
