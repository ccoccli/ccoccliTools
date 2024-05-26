#include "statusbarWidget.hpp"

statusbarWidget::statusbarWidget(QWidget *parent) : QStatusBar(parent)
{
    setColor(this, QColor(config::statusbar::DEFAULT_BACKGROUND_COLOR));
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
