#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QTimer>

class MainPage : public QWidget {
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);

    QPushButton *btnIntro;
    QPushButton *btnAdmission;
    QPushButton *btnVR;
    QPushButton *btnCulture;
    // 添加声明
    QPushButton *btnGame;

private:
    QLabel *labelBanner;
    QTimer *bannerTimer;
    QVector<QString> bannerPaths;
    int currentBannerIndex = 0;

    void setupUI();
    void setupBanner();
private slots:
    void switchBanner();
};

#endif // MAINPAGE_H
