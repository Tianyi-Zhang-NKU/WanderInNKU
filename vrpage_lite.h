#ifndef VRPAGE_LITE_H
#define VRPAGE_LITE_H

#include <QWidget>
#include <QPainter>

class QPushButton;
class QLabel;

class VRPageLite : public QWidget {
    Q_OBJECT

public:
    explicit VRPageLite(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*event);

private:
    void setupUI();  // 初始化界面
    void openOldVR(); // 打开旧版 VR
    void openNewVR(); // 打开新版 VR

signals:
    void backToHome();  // 返回主页的信号
};

#endif // VRPAGE_LITE_H
