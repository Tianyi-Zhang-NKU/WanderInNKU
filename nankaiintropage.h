#ifndef NANKAI_INTRO_PAGE_H
#define NANKAI_INTRO_PAGE_H

#include <QWidget>
#include <QLabel>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QScrollArea>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class NankaiIntroPage : public QWidget {
    Q_OBJECT

public:
    explicit NankaiIntroPage(QWidget *parent = nullptr);

private:
    QTextBrowser *historyTextBrowser; // 显示校史
    QVBoxLayout *timelineLayout;      // 时间轴布局
    QVBoxLayout *famousLayout;        // 名人卡片布局

    void loadSchoolHistory();         // 加载校史内容
    void loadTimeline();              // 添加时间轴事件
    void loadFamousPeople();          // 加载名人信息

signals:
    void backToHome();  // 返回主页的信号
};

#endif // NANKAI_INTRO_PAGE_H
