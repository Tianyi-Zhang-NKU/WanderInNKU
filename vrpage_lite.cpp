#include "VRPage_Lite.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>

VRPageLite::VRPageLite(QWidget *parent)
    : QWidget(parent) {
    setupUI();
}

void VRPageLite::setupUI() {

    this->setStyleSheet("background-color: #7e0c6e;");

    // 标题标签
    QLabel *titleLabel = new QLabel("南开大学 VR 全景浏览");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font: bold 20pt '仿宋'; color: #66FFFF; margin: 20px;");

    // 按钮：旧版VR（720云）
    QPushButton *btnOldVR = new QPushButton("打开旧版VR（720云）");
    btnOldVR->setStyleSheet("font: 12pt '微软雅黑'; padding: 10px 24px;");
    connect(btnOldVR, &QPushButton::clicked, this, &VRPageLite::openOldVR);

    // 按钮：新版VR（官方平台）
    QPushButton *btnNewVR = new QPushButton("打开新版VR（官方平台）");
    btnNewVR->setStyleSheet("font: 12pt '微软雅黑'; padding: 10px 24px;");
    connect(btnNewVR, &QPushButton::clicked, this, &VRPageLite::openNewVR);

    // 返回按钮
    QPushButton *btnBack = new QPushButton("返回主页");
    btnBack->setStyleSheet("font: 12pt '微软雅黑'; padding: 8px 20px;");
    connect(btnBack, &QPushButton::clicked, this, &VRPageLite::backToHome);

    // 主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleLabel);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(btnOldVR, 0, Qt::AlignCenter);
    mainLayout->addWidget(btnNewVR, 0, Qt::AlignCenter);
    mainLayout->addStretch(1);
    mainLayout->addWidget(btnBack, 0, Qt::AlignCenter);

    setLayout(mainLayout);
}

// 打开旧版 VR（720yun）
void VRPageLite::openOldVR() {
    QDesktopServices::openUrl(QUrl("https://www.720yun.com/t/f65jv04frf3?scene_id=19502661"));
}

// 打开新版 VR（南开官方）
void VRPageLite::openNewVR() {
    QDesktopServices::openUrl(QUrl("https://nkvr.nankai.edu.cn/"));
}

void VRPageLite::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/main_picture/picture/pic_3.jpg"));
}
