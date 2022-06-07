#ifndef DIPGUI_H
#define DIPGUI_H

#include <QMainWindow>
#include "imgview.h"
#include "filterdialog.h"

#include <QVector>  // 多图像处理时需要用到动态数组

#include <opencv2/opencv.hpp>   // 所有的图像处理工作均在dipgui内完成

QT_BEGIN_NAMESPACE
namespace Ui { class dipGUI; }
QT_END_NAMESPACE

class dipGUI : public QMainWindow
{
    Q_OBJECT

public:
    dipGUI(QWidget* parent = nullptr);
    ~dipGUI();

signals:
    void pass_qimage_data_signal(const QImage& qt_image, const QString image_path);   // 主窗口给子窗口传递原图
    void pass_multi_qimage_data_signal(const QImage& qt_image, const QString image_path);   // 主窗口给多子窗口传递原图
    void pass_qimage_data_signal(const QImage& qt_image);   // 主窗口给子窗口传递处理后的图像
    void open_about_app_signal();
    void open_about_me_signal();
    void open_gauss_sigma_signal();

private slots:
    void mat_to_qimage();   // Mat格式到QImage格式的转换
    void on_actFileLoad_triggered();    // 从本地加载一张图像
    void on_actExit_triggered();    // 退出程序

/* *****************和图像处理相关***************** */

// 图像处理函数
private:
    void qt_im2gray();  // 转化为灰度图像
    void qt_imfusion_avg(); // 图像融合

// 图像处理响应槽函数
private slots:
    void on_actProcColorSpaceGray_triggered();  // 转化为灰度图像
    void on_actSpatialBoxFilt_triggered();  // 盒式滤波
    void on_actSpatialGaussFilt_triggered();    // 高斯滤波
    void on_actSpatialMedianFilt_triggered();   // 中值滤波
    void on_actAvgFusion_triggered();   // 均值融合

/* *****************和图像处理相关***************** */

private slots:
    void on_actHelpInfo_triggered();
    void on_actAboutApp_triggered();
    void on_actAboutMe_triggered();
    void on_actFileClose_triggered();
    void on_actFileSave_triggered();
    void on_actFileSaveAs_triggered();
    void pass_filter_parameters_slot(const FilterParms& size_sigma);

private:
    void disabled_dip_function();
    void enabled_dip_function();
    void save_img_error(const QString imagePath);
    void vector_add();
    void img_clear();
    void vector_clear();
    bool size_consistency_of_multi_imgs();

private:
    Ui::dipGUI* ui;

    // 创建imgView类的对象指针
    imgView* IV_w;  // 原图显示窗口
    imgView* IP_w;  // 处理完的图像显示窗口
    QVector<imgView* > multi_ws; // 多显示窗口
//    QVector<imgView* > multi_proc_ws;   // 处理完的多显示窗口（以后可能用得上）

    // 创建Mat对象（一个用于存放原图，另一个用于存放处理后的图）
    // OpenCV算法处理的原图始终是cv_original_img
    // OpenCV算法处理后的图始终是cv_img
    cv::Mat cv_original_img;
    cv::Mat cv_img;
    QVector<cv::Mat> multi_imgs;    // 多图像原图

    // 创建QImage对象（用于传递给子窗口显示图像）
    QImage qt_img;
    QVector<QImage> multi_qimgs;    // 用于传递的多图像

    // 其它小窗口
    FilterDialog* filt_dlg;
    FilterParms size_sigma;
};

#endif // DIPGUI_H
