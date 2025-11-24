#ifndef CULTUREPAGE_H
#define CULTUREPAGE_H

#include <QWidget>

class QLabel;
class QPushButton;

class CulturePage : public QWidget {
    Q_OBJECT

public:
    explicit CulturePage(QWidget *parent = nullptr);


private:
    void setupUI(); // 初始化界面

signals:
    void backToHome();  // 返回主页的信号

private slots:
    void on_btnYunGongYunNeng_clicked(); // “公能精神”
    void showPatriotismDialog(); // “爱国三问”
    void showMottoDialog();    // “南开校训”


};

#endif // CULTUREPAGE_H
