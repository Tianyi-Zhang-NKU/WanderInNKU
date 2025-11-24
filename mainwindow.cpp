#include "MainWindow.h"
#include "mainpage.h"            // ✅ 新加
#include "nankaiintropage.h"
#include "admissionpage.h"
#include "vrpage_lite.h"
#include "culturepage.h"
#include "new/game_page.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    MainPage *mainPage = new MainPage(); //  正确使用 MainPage
    stackedWidget->addWidget(mainPage);  // index 0

    AdmissionPage *admissionPage = new AdmissionPage(stackedWidget);
    stackedWidget->addWidget(admissionPage);  // 1
    connect(admissionPage, &AdmissionPage::backToHome, [=]() {
        stackedWidget->setCurrentIndex(0);  // 切换回主页
    });

    NankaiIntroPage *introPage = new NankaiIntroPage(stackedWidget);
    stackedWidget->addWidget(introPage);      // 2
    connect(introPage, &NankaiIntroPage::backToHome, [=]() {
        stackedWidget->setCurrentIndex(0);  // 切换回主页
    });

    VRPageLite *vrPage = new VRPageLite(stackedWidget);
    stackedWidget->addWidget(vrPage);         // 3
    connect(vrPage, &VRPageLite::backToHome, [=]() {
        stackedWidget->setCurrentIndex(0);  // 切换回主页
    });

    CulturePage *culturePage = new CulturePage(stackedWidget);
    stackedWidget->addWidget(culturePage);    // 4
    connect(culturePage, &CulturePage::backToHome, [=]() {
        stackedWidget->setCurrentIndex(0);  // 切换回主页
    });

    Game_Page *gamePage = new Game_Page();
    //stackedWidget->addWidget(gamePage);  // index 5（可根据已有顺序）
    /*connect(gamePage, &Game_Page::backToHome, [=]() {
        stackedWidget->setCurrentIndex(0);  // 切换回主页
    });*/



    stackedWidget->setCurrentIndex(0);        // 初始显示主页

    connect(mainPage->btnIntro, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentWidget(introPage);
    });
    connect(mainPage->btnAdmission, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentWidget(admissionPage);
    });
    connect(mainPage->btnVR, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentWidget(vrPage);
    });
    connect(mainPage->btnCulture, &QPushButton::clicked, [=]() {
        stackedWidget->setCurrentWidget(culturePage);
    });

    connect(mainPage->btnGame, &QPushButton::clicked, [=]() {
        gamePage->show();
    });

}

MainWindow::~MainWindow()
{

}
