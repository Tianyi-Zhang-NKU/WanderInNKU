#ifndef ADMISSIONPAGE_H
#define ADMISSIONPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPainter>

class AdmissionPage : public QWidget {
    Q_OBJECT

public:
    explicit AdmissionPage(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*event);

private:
    QLabel *titleLabel;
    QPushButton *openButton;

    void setupUI();

signals:
    void backToHome();  // 返回主页的信号

};

#endif // ADMISSIONPAGE_H
