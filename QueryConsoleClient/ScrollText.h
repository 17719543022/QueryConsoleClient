#ifndef SCROLL_TEXT_H
#define SCROLL_TEXT_H

#include <QWidget>
#include <QLabel>

#include <QStringList>

class QLabel;
class QPropertyAnimation;
class QTimer;
class ScrollText_Vertical : public QWidget
{
    Q_OBJECT

public:
    explicit ScrollText_Vertical(QWidget *parent = nullptr);
    ScrollText_Vertical(QStringList &textList, QWidget *parent = nullptr);
    ~ScrollText_Vertical() override;

    //设置切换时间间隔
    void setInterval_scrollTimer(const int scrollTimerInterval);
    //设置切换动画持续时间
    void setInterval_animation(const int AnimationInterval);
    void setScrollStat(bool stat);
    // 设置文字内容
    void setTextList(const QStringList &textList);
    void setCurrentText(const QString &text);
    bool addText(const QString &text);
    bool removeText(const QString &text);

    inline QStringList getTextList(){
        return m_textList;
    }
    inline QString getCurrentText(){
        return m_textList.at(m_currentIndex);
    }
    inline int getCurrentIndex(){
        return m_currentIndex;
    }

private:
    void Init();

private slots:
    void autoScroll();

private:

    QLabel *m_TopLabel = nullptr;
    QLabel *m_CurrentLabel = nullptr;
    QPropertyAnimation *m_TopPropertyAnimation = nullptr;
    QPropertyAnimation *m_CurrentPropertyAnimation = nullptr;

    QTimer *m_scrollTimer = nullptr;
    int m_scrollTimerInterval;
    int m_AnimationInterval;

    QStringList m_textList;
    int m_currentIndex;
protected:
    void resizeEvent(QResizeEvent *event) override;
};


class ScrollText_Horizontal : public QLabel
{
    Q_OBJECT
public:
    explicit ScrollText_Horizontal(QWidget* parent = nullptr);
    ~ScrollText_Horizontal()override;

    void setText(const QString &text); //redefin

    void setAlignment(Qt::Alignment alignment);   //redefin

    void clear();   //redefin

    inline QString getText(){   //redefin
        return curr_text;
    }
    void setMovingInterval(int m_sec);
    void setSpaceWidth(int pix);
private:
    void paintEvent(QPaintEvent *e) override;

    void timerEvent(QTimerEvent *e) override;
    void resizeEvent(QResizeEvent *e) override;

    void updateSCrollingStat();

private:
    QString curr_text;
    int text_pixwidth;
    int text_pixheight;
    int m_spaceWidth;

    int m_timerId;
    int m_interval;
    int show_index;
};

#endif

