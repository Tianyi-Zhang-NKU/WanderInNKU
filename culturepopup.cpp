#include "culturepopup.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

CulturePopup::CulturePopup(const QString &title, const QString &text, const QString &imagePath, QWidget *parent)
    : QDialog(parent), imagePath(imagePath)
{
    setWindowTitle(title);
    setModal(true);      // 模态窗口
    setFixedSize(420, 220);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel(text);
    label->setWordWrap(true);
    layout->addWidget(label);

    QPushButton *btn = new QPushButton("🎁 了解完毕，下载壁纸作为奖励");
    btn->setStyleSheet("background-color: #FFFF66; color: #7e0c6e; padding: 8px 16px; border-radius: 10px;");
    layout->addWidget(btn, 0, Qt::AlignRight);

    connect(btn, &QPushButton::clicked, this, &CulturePopup::onDownloadClicked);
}

void CulturePopup::onDownloadClicked()
{
    QString savePath = QFileDialog::getSaveFileName(this, "保存壁纸", ":/main_picture/picture/Culture_pic_1.jpg", "Images (*.jpg *.png)");
    if (!savePath.isEmpty()) {
        if (QFile::copy(imagePath, savePath)) {
            QMessageBox::information(this, "下载成功", "壁纸已保存到指定位置！");
        } else {
            QMessageBox::warning(this, "下载失败", "文件保存失败，请重试。");
        }
    }
    accept(); // 关闭弹窗
}
