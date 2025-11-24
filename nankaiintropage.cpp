#include "NankaiIntroPage.h"
#include <QFile>
#include <QJsonParseError>
#include <QDebug>
#include <QPushButton>

NankaiIntroPage::NankaiIntroPage(QWidget *parent)
    : QWidget(parent) {

    this->setStyleSheet("background-color: #7e0c6e;");


    // === 校史文本 ===
    QLabel *title = new QLabel("南开大学简介", this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font: bold 20pt '微软雅黑'; font-weight: 800; color: #66FFFF;");

    historyTextBrowser = new QTextBrowser(this);
    historyTextBrowser->setStyleSheet("font: 12pt '微软雅黑'; padding: 10px;");
    loadSchoolHistory();

    // === 时间轴区域 ===
    QLabel *timelineLabel = new QLabel("发展历程", this);
    timelineLabel->setStyleSheet("font: 16pt '微软雅黑'; color: #FFFFFF;");
    timelineLayout = new QVBoxLayout();
    loadTimeline();

    QGroupBox *timelineBox = new QGroupBox();
    timelineBox->setLayout(timelineLayout);

    // === 名人堂区域 ===
    QLabel *famousLabel = new QLabel("南开名人堂", this);
    famousLabel->setStyleSheet("font: 16pt '微软雅黑'; color: #FFFFFF;");
    famousLayout = new QVBoxLayout();
    loadFamousPeople();

    QGroupBox *famousBox = new QGroupBox();
    famousBox->setLayout(famousLayout);

    // 返回按钮
    QPushButton *btnBack = new QPushButton("返回主页");
    btnBack->setStyleSheet("font: 12pt '微软雅黑'; padding: 8px 20px;");
    connect(btnBack, &QPushButton::clicked, this, &NankaiIntroPage::backToHome);

    // === 总布局 ===
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(title);
    mainLayout->addWidget(historyTextBrowser);
    mainLayout->addWidget(timelineLabel);
    mainLayout->addWidget(timelineBox);
    mainLayout->addWidget(famousLabel);
    mainLayout->addWidget(famousBox);

    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *contentWidget = new QWidget(this);
    contentWidget->setLayout(mainLayout);
    scrollArea->setWidget(contentWidget);
    scrollArea->setWidgetResizable(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(scrollArea);
    layout->addWidget(btnBack, 0, Qt::AlignCenter);
    setLayout(layout);
}

// === 加载校史文本内容 ===
void NankaiIntroPage::loadSchoolHistory() {
    QFile file(":/txt/txt/1.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        historyTextBrowser->setText("校史加载失败！");
        return;
    }
    QString content = file.readAll();
    historyTextBrowser->setText(content);
}

// === 简易时间轴内容 ===
void NankaiIntroPage::loadTimeline() {
    QStringList years = {"1919", "1921" , "1927" , "1937", "1938","1946", "1952","1978","1980","1994","2000", "2006","2017","2019","至今"};
    QStringList events = {
        "南开学校校长张伯苓与严修共同创办南开大学，以文理科为主，采用西式大学课程体系。",
        "设立商科，成立南开大学商学院，为中国最早的商学院之一",
        "南开大学被北洋政府正式批准为私立大学，确立完整的大学体系",
        "七七事变爆发，日军轰炸天津南开校园，南开大学校舍被毁",
        "与清华大学、北京大学南迁至昆明，合组西南联合大学，继续教育与科研",
        "抗战胜利后南开大学返回天津，重建校舍，恢复教学科研工作",
        "全国高校院系调整，南开大学的工科并入天津大学，南开转为以文理基础学科为主的综合性大学",
        "改革开放初期，南开被列为首批国家重点高校之一，开启快速发展新阶段",
        "设立周恩来政府管理学院，纪念杰出校友周恩来总理",
        "入选国家“211工程”重点支持高校",
        "与原天津对外贸易学院合并，拓展经济与国际交流方向",
        "被列入“985工程”重点支持建设高校",
        "入选“双一流”世界一流大学建设高校（A类）名单",
        "迎来建校100周年，举行百年校庆，发布《南开大学章程（修订）》，重申“知中国 服务中国”的理念",
        "南开大学迈入多学科融合发展阶段不断加强科研创新与国际合作，致力于建设“世界一流大学”目标"
    };

    for (int i = 0; i < years.size(); ++i) {
        QLabel *label = new QLabel(years[i] + "年： " + events[i]);
        label->setStyleSheet("font: 11pt '微软雅黑'; color: #FFFFFF;");
        timelineLayout->addWidget(label);
    }
}

// === 加载名人卡片内容 ===
void NankaiIntroPage::loadFamousPeople() {
    QFile file(":/txt/txt/school_figures.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QLabel *err = new QLabel("名人信息加载失败！");
        famousLayout->addWidget(err);
        return;
    }

    QByteArray data = file.readAll();
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if (err.error != QJsonParseError::NoError) {
        qDebug() << "Json parse error:" << err.errorString();
        return;
    }

    QJsonArray arr = doc.array();
    for (const QJsonValue &v : arr) {
        QJsonObject obj = v.toObject();
        QString name = obj["name"].toString();
        QString desc = obj["desc"].toString();

        QLabel *label = new QLabel(name + "： " + desc);
        label->setStyleSheet("font: 11pt '微软雅黑'; margin-bottom: 10px;");
        label->setWordWrap(true);
        famousLayout->addWidget(label);
    }
}
