#include "AdmissionPage.h"
#include <QDesktopServices>
#include <QUrl>

AdmissionPage::AdmissionPage(QWidget *parent)
    : QWidget(parent) {
    setupUI();
}

void AdmissionPage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/main_picture/picture/pic_3.jpg"));
}

void AdmissionPage::setupUI() {

    this->setStyleSheet("background-color: #7e0c6e;");

    // 顶部标题
    titleLabel = new QLabel("南开大学招生信息平台");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font: bold 18pt '微软雅黑'; font-weight: 800; color: #66FFFF ; padding: 20px;");

    // 跳转按钮
    openButton = new QPushButton("点击打开招生官网");
    openButton->setStyleSheet("font: 12pt '微软雅黑'; padding: 10px 20px;");
    openButton->setFixedWidth(260);
    openButton->setCursor(Qt::PointingHandCursor);
    openButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    connect(openButton, &QPushButton::clicked, []() {
        QDesktopServices::openUrl(QUrl("https://zsb.nankai.edu.cn/"));
    });

    // 返回按钮
    QPushButton *btnBack = new QPushButton("返回主页");
    btnBack->setStyleSheet("font: 12pt '微软雅黑'; padding: 8px 20px;");
    connect(btnBack, &QPushButton::clicked, this, &AdmissionPage::backToHome);


    // 布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addSpacing(50); // 加一些间距
    layout->addWidget(openButton, 0, Qt::AlignCenter);
    layout->addSpacing(50); // 加一些间距
    layout->addStretch(1);
    layout->addWidget(btnBack, 0, Qt::AlignCenter);  // 添加返回按钮


    setLayout(layout);

}

