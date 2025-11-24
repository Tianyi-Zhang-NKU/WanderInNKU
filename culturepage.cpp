#include "CulturePage.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDir>

#include "culturepopup.h"

CulturePage::CulturePage(QWidget *parent)
    : QWidget(parent) {
    setupUI();
}

void CulturePage::setupUI() {
    // 标题

    this->setStyleSheet("background-color: #7e0c6e;");

    QLabel *title = new QLabel("南开文化专题");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font: bold 20pt '微软雅黑'; font-weight: 800; color: #66FFFF ; margin: 15px;");

    // 介绍文字
    QLabel *desc = new QLabel("了解“公能精神”等南开文化关键词,有机会获得精美壁纸！");
    desc->setWordWrap(true);
    desc->setAlignment(Qt::AlignCenter);
    desc->setStyleSheet("font: 12pt '微软雅黑'; padding: 0 20px;");

    // 词云图展示
    QLabel *wordcloud = new QLabel(this);
    QPixmap wcPixmap(":/main_picture/picture/pic_1.jpg");
    wordcloud->setPixmap(wcPixmap.scaled(600, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    wordcloud->setAlignment(Qt::AlignCenter);
    wordcloud->setStyleSheet("margin: 15px;");

    // 三个文化按钮
    QPushButton *btnSpirit = new QPushButton("公能精神");
    QPushButton *btnPatriotism = new QPushButton("爱国三问");
    QPushButton *btnMotto = new QPushButton("南开校训");

    // 设置样式
    QString cultureBtnStyle = "font: 12pt '微软雅黑'; padding: 8px 20px;";
    btnSpirit->setStyleSheet(cultureBtnStyle);
    btnPatriotism->setStyleSheet(cultureBtnStyle);
    btnMotto->setStyleSheet(cultureBtnStyle);

    // 绑定槽函数
    connect(btnSpirit, &QPushButton::clicked, this, &CulturePage::on_btnYunGongYunNeng_clicked);
    connect(btnPatriotism, &QPushButton::clicked, this, &CulturePage::showPatriotismDialog);
    connect(btnMotto, &QPushButton::clicked, this, &CulturePage::showMottoDialog);


    // 返回按钮
    QPushButton *btnBack = new QPushButton("返回主页");
    btnBack->setStyleSheet("font: 12pt '微软雅黑'; padding: 8px 20px;");
    connect(btnBack, &QPushButton::clicked, this, &CulturePage::backToHome);


    // 总体布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(desc);
    layout->addWidget(wordcloud);
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(btnSpirit);
    btnLayout->addWidget(btnPatriotism);
    btnLayout->addWidget(btnMotto);
    layout->addLayout(btnLayout);
    //layout->addWidget(btnSave, 0, Qt::AlignCenter);
    layout->addStretch(1);
    layout->addWidget(btnBack, 0, Qt::AlignCenter);

    setLayout(layout);
}

void CulturePage::on_btnYunGongYunNeng_clicked()
{
    QString title = "公能精神";
    QString text = "“公能”即“公德”与“才能”的统一，是南开教育理念的核心。它由南开创办人张伯苓提出，强调培养既有社会责任感（公）又有实际能力（能）的人才。与传统儒家“修齐治平”理念相通，体现南开致力于“服务国家、造福社会”的育人方向,如今已成为南开大学育人评价与人才培养的重要标准。";
    QString imagePath = ":/main_picture/picture/Culture_pic_1.jpg"; // 资源路径

    CulturePopup popup(title, text, imagePath, this);
    popup.exec(); // 以模态方式显示弹窗
}

void CulturePage::showPatriotismDialog() {
    QString title = "爱国三问";
    QString text = "“你是中国人吗？你爱中国吗？你愿意中国好吗？”1935年，南开校长张伯苓在抗战前夕提出这三问，引发强烈社会反响。三问直击灵魂、唤醒民族意识，成为当时青年学生的思想动员口号。爱国三问体现出南开大学深厚的爱国主义传统和使命感，至今仍是南开精神的重要象征，被广泛引用于新生入学教育、重大纪念活动中。";
    QString imagePath = ":/main_picture/picture/Culture_pic_2.jpg"; // 资源路径

    CulturePopup popup(title, text, imagePath, this);
    popup.exec(); // 以模态方式显示弹窗
}

void CulturePage::showMottoDialog() {
    QString title = "南开校训";
    QString text = "“允公允能”：出自《尚书》，意思是“要有公德，也要有才能”。“日新月异”：意为不断进步、日益更新，鼓励学生勇于探索、不断创新。该校训深刻体现南开办学宗旨，即培养具有高尚品格和实际能力，并能顺应时代发展的人才。";
    QString imagePath = ":/main_picture/picture/Culture_pic_3.jpg"; // 资源路径

    CulturePopup popup(title, text, imagePath, this);
    popup.exec(); // 以模态方式显示弹窗
}


