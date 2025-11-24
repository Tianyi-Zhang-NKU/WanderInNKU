#include "mainpage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

MainPage::MainPage(QWidget *parent)
    : QWidget(parent) {
    setupUI();
    setupBanner();
}

void MainPage::setupUI() {

    this->setStyleSheet("background-color: #7e0c6e;");

    QLabel *labelLogo = new QLabel(this);
    QPixmap logoPixmap(":/main_picture/picture/NKU-logo-white.png");
    labelLogo->setPixmap(logoPixmap.scaled(180, 180, Qt::KeepAspectRatio));
    labelLogo->setAlignment(Qt::AlignCenter);

    QLabel *labelSlogan = new QLabel("允公允能  日新月异", this);
    labelSlogan->setAlignment(Qt::AlignCenter);
    labelSlogan->setStyleSheet("font: 24pt '微软雅黑'; font-weight: 800; color: #66FFFF;");

    labelBanner = new QLabel(this);
    labelBanner->setFixedSize(600, 300);
    labelBanner->setScaledContents(true);

    btnIntro = new QPushButton("南开简介", this);
    btnAdmission = new QPushButton("招生信息", this);
    btnVR = new QPushButton("校园VR", this);
    btnCulture = new QPushButton("文化专题", this);

    QString btnStyle = "QPushButton { font: 12pt '微软雅黑'; padding: 8px; }";
    btnIntro->setStyleSheet(btnStyle);
    btnAdmission->setStyleSheet(btnStyle);
    btnVR->setStyleSheet(btnStyle);
    btnCulture->setStyleSheet(btnStyle);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(btnIntro);
    btnLayout->addWidget(btnAdmission);
    btnLayout->addWidget(btnVR);
    btnLayout->addWidget(btnCulture);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(labelLogo);
    mainLayout->addWidget(labelSlogan);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(labelBanner);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(btnLayout);

    btnGame = new QPushButton("南开塔防小游戏");
    btnGame->setFixedHeight(50); // 设置高度
    btnGame->setStyleSheet("font-size: 20px;"); // 设置字体大小
    mainLayout->addWidget(btnGame); // 添加到底部


    this->setLayout(mainLayout);
}

void MainPage::setupBanner() {
    bannerPaths = {
        ":/main_picture/picture/pic_1.jpg",
        ":/main_picture/picture/pic_2.jpg",
        ":/main_picture/picture/pic_3.jpg",
        ":/main_picture/picture/pic_4.jpg",
        ":/main_picture/picture/pic_5.jpg",
    };

    if (!bannerPaths.isEmpty()) {
        QPixmap pix(bannerPaths[0]);
        labelBanner->setPixmap(pix.scaled(labelBanner->size(), Qt::KeepAspectRatioByExpanding));
    }

    bannerTimer = new QTimer(this);
    connect(bannerTimer, &QTimer::timeout, this, &MainPage::switchBanner);
    bannerTimer->start(2000);
}

void MainPage::switchBanner() {
    if (bannerPaths.isEmpty()) return;
    currentBannerIndex = (currentBannerIndex + 1) % bannerPaths.size();
    QPixmap pix(bannerPaths[currentBannerIndex]);
    labelBanner->setPixmap(pix.scaled(labelBanner->size(), Qt::KeepAspectRatioByExpanding));
}
