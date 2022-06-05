#ifndef IMGVIEW_H
#define IMGVIEW_H

#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class imgView;
}

class imgView : public QMainWindow
{
    Q_OBJECT

public:
    explicit imgView(QWidget* parent = nullptr);
    ~imgView();

protected:
    void resizeEvent(QResizeEvent* ) override;

private slots:
    void pass_qimage_data_slot(const QImage& qt_image, const QString image_path);   // 单图像处理
    void pass_multi_qimage_data_slot(const QImage& qt_image, const QString image_path); // 多图像处理
    void pass_qimage_data_slot(const QImage& qt_image);     // 重载接收数据的两个槽
    void on_actAdapt_triggered();
    void on_actRestore_triggered();
    void on_actOriginalSize_triggered();
    void on_actStretch_triggered();
    void on_actZoomIn_triggered();
    void on_actZoomOut_triggered();

private:
    void adaptively_resize_image();
    void roll_image();
    void initUI();

private:
    Ui::imgView* ui;

    // 接收来自主窗口的图像数据
    QImage qt_view_img;
    QPixmap qt_show_img;

    // 常量（用于初始化窗口大小）
    const int BASE_WIDTH = 600;
    const int BASE_HEIGHT = 450;

    // 用代码添加的组件
    QComboBox* view_mode;
};

#endif // IMGVIEW_H
