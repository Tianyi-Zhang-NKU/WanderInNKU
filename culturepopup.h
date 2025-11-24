#ifndef CULTUREPOPUP_H
#define CULTUREPOPUP_H

#include <QDialog>
#include <QString>

class QLabel;
class QPushButton;

class CulturePopup : public QDialog
{
    Q_OBJECT

public:
    explicit CulturePopup(const QString &title,
                          const QString &text,
                          const QString &imagePath,
                          QWidget *parent = nullptr);

private slots:
    void onDownloadClicked(); // 下载并关闭

private:
    QString imagePath; // 保存图像路径
};

#endif // CULTUREPOPUP_H
