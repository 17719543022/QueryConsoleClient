#include "ScrollText.h"

#include <QLabel>
#include <QPropertyAnimation>
#include <QTimer>
#include <QResizeEvent>
#include <QPainter>
#include <qdebug.h>

ScrollText_Vertical::ScrollText_Vertical(QWidget *parent)
    :QWidget(parent)
{
    Init();
}

ScrollText_Vertical::ScrollText_Vertical(QStringList &textList, QWidget *parent)
    : QWidget(parent)
{
    Init();
    this->setTextList(textList);
}

ScrollText_Vertical::~ScrollText_Vertical()
{
    if (m_scrollTimer->isActive()){
        m_scrollTimer->stop();
    }
    disconnect(m_scrollTimer, &QTimer::timeout, this, &ScrollText_Vertical::autoScroll);
}

void ScrollText_Vertical::Init()
{
    m_TopLabel = new QLabel(this);
    m_CurrentLabel = new QLabel(this);
    m_TopLabel->hide();
    m_CurrentLabel->hide();

    m_scrollTimerInterval = 1000;
    m_AnimationInterval = 500;
    m_currentIndex = 0;
    m_TopPropertyAnimation = new QPropertyAnimation(this);
    m_TopPropertyAnimation->setTargetObject(m_TopLabel);
    m_TopPropertyAnimation->setPropertyName("geometry");
    m_TopPropertyAnimation->setEasingCurve(QEasingCurve::OutCubic);
    m_TopPropertyAnimation->setDuration(m_AnimationInterval);

    m_CurrentPropertyAnimation = new QPropertyAnimation(this);
    m_CurrentPropertyAnimation->setTargetObject(m_CurrentLabel);
    m_CurrentPropertyAnimation->setPropertyName("geometry");
    m_CurrentPropertyAnimation->setEasingCurve(QEasingCurve::OutCubic);
    m_CurrentPropertyAnimation->setDuration(m_AnimationInterval);

    m_scrollTimer = new QTimer(this);
    connect(m_scrollTimer, &QTimer::timeout, this, &ScrollText_Vertical::autoScroll);
    m_scrollTimer->start(m_scrollTimerInterval);
}

void ScrollText_Vertical::setInterval_scrollTimer(const int scrollTimerInterval)
{
    m_scrollTimerInterval = scrollTimerInterval;
    m_scrollTimer->start(m_scrollTimerInterval);
}

void ScrollText_Vertical::setInterval_animation(const int AnimationInterval)
{
    m_AnimationInterval = AnimationInterval;
    m_TopPropertyAnimation->setDuration(m_AnimationInterval);
    m_CurrentPropertyAnimation->setDuration(m_AnimationInterval);
}

void ScrollText_Vertical::setScrollStat(bool stat)
{
    if (stat){
        m_scrollTimer->start(m_scrollTimerInterval);
    }
    else {
        m_scrollTimer->stop();
    }
}

void ScrollText_Vertical::setTextList(const QStringList &textList)
{
    m_textList = textList;
    if (!m_textList.isEmpty()){
        m_currentIndex = 0;
        setCurrentText(m_textList.at(m_currentIndex));
    }
    else {
        setCurrentText("");
    }
}

bool ScrollText_Vertical::addText(const QString &text)
{
     if (!m_textList.contains(text)){
        m_textList<<text;
        return true;
     }
     else{
         return false;
     }
}

void ScrollText_Vertical::setCurrentText(const QString &text)
{
    if (m_CurrentLabel->text().isEmpty())
    {
        m_CurrentLabel->setGeometry(0, 0, this->width(), this->height());
        m_TopLabel->setText(text);
        m_CurrentLabel->setText(text);
        if (m_CurrentLabel->isHidden())
            m_CurrentLabel->show();
    }
    else
    {
        QString string = m_CurrentLabel->text();
        m_TopLabel->setText(string);
        m_CurrentLabel->setText(text);

        if (m_CurrentLabel->isHidden())
            m_CurrentLabel->show();
        if (m_TopLabel->isHidden())
            m_TopLabel->show();

//        m_TopPropertyAnimation->stop();
//        m_CurrentPropertyAnimation->stop();
        m_TopPropertyAnimation->start();
        m_CurrentPropertyAnimation->start();
    }
}


bool ScrollText_Vertical::removeText(const QString &text)
{
    if (m_textList.contains(text)){
       m_textList.removeOne(text);
       return true;
    }
    else{
        return false;
    }
}


void ScrollText_Vertical::autoScroll()
{
    if (m_textList.isEmpty())
        return;

    if ((++m_currentIndex) == m_textList.size()){
        m_currentIndex = 0;
    }
    setCurrentText(m_textList.at(m_currentIndex));
}


void ScrollText_Vertical::resizeEvent(QResizeEvent *event)
{
    int width = event->size().width();
    int height = event->size().height();

    m_TopPropertyAnimation->setStartValue(QRect(0, 0, width, height));
    m_TopPropertyAnimation->setEndValue(QRect(0, -height, width, height));

    m_CurrentPropertyAnimation->setStartValue(QRect(0, height, width, height));
    m_CurrentPropertyAnimation->setEndValue(QRect(0, 0, width, height));

    return QWidget::resizeEvent(event);
}


////////////////////////////////////////////////////////////////////////////////////////////
/// \brief ScrollText_Horizontal::ScrollText_Horizontal

ScrollText_Horizontal::ScrollText_Horizontal(QWidget* parent)
    :QLabel(parent),
      m_spaceWidth(50),
      m_timerId(-1),
      m_interval(10)
{

}

ScrollText_Horizontal::~ScrollText_Horizontal()
{

}

void ScrollText_Horizontal::setText(const QString &text)
{
    if (this->styleSheet().isEmpty())
        this->setStyleSheet("color: rgb(188, 58, 58);font: 28pt \"Ubuntu\";");

    this->curr_text = text;

    updateSCrollingStat();

    update();
}

void ScrollText_Horizontal::setAlignment(Qt::Alignment alignment)
{
    QLabel::setAlignment(alignment);
    updateSCrollingStat();
}

void ScrollText_Horizontal::clear()
{
    QLabel::clear();

    this->setText("");
}

void ScrollText_Horizontal::updateSCrollingStat()
{
    QFontMetrics fm(this->font());
    text_pixwidth = fm.width(curr_text);
    text_pixheight = fm.height();
    Qt::Alignment alignProxy= alignment();
    //AlignmentFlag: qt中该参数的枚举值，包括横向和众向两个值的按位或运算
    switch (alignProxy & 0x001F) {  //采用与运算符只截取最右边的横向策略，众向策略不管
    case Qt::AlignLeft:
        show_index = 0;
        break;
    case Qt::AlignHCenter:
        show_index = (this->width()-text_pixwidth)/2;
        break;
    case Qt::AlignRight:
        show_index = this->width()-text_pixwidth;
        break;
    case Qt::AlignJustify:  //两端对齐采用居中策略
        show_index = (this->width()-text_pixwidth)/2;
        break;
    default:
        show_index = 0;
        break;
    }

    if(text_pixwidth > this->width()) // 开启文本框滚动
    {
        m_timerId = startTimer(m_interval);
        show_index = this->width();
    }
    else if(m_timerId >= 0) // 关闭文本框滚动
    {
        killTimer(m_timerId);
        m_timerId = -1;
    }
}

void ScrollText_Horizontal::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    //画出当前index所跟着的画面
    painter.drawText(show_index, (this->height()/2 + text_pixheight/3), curr_text);
    if(text_pixwidth > this->width()) // 开启文本框滚动
    {
        //画出上一圈的画面，防止index归位的时候上一圈的画面消失不见
        painter.drawText(show_index - (text_pixwidth+m_spaceWidth), (this->height()/2 + text_pixheight/3), curr_text);
    }

    return QLabel::paintEvent(e);
}

void ScrollText_Horizontal::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == m_timerId && isVisible())
    {
        show_index--;  //  每次左移1个像素
        //index走完一圈，回到最右边
        if(show_index < (this->width() - (text_pixwidth + m_spaceWidth)))
        {
            show_index = this->width();
        }
        update();
    }

    return QLabel::timerEvent(e);
}

void ScrollText_Horizontal::resizeEvent(QResizeEvent *e)
{
    updateSCrollingStat();

    return QLabel::resizeEvent(e);
}
