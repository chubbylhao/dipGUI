#include "dipgui.h"
#include "ui_dipgui.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

dipGUI::dipGUI(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::dipGUI)
{
    ui->setupUi(this);

    // 在堆上创建
    IV_w = new imgView;
    IP_w = new imgView;

    // 禁用某些功能
    disabled_dip_function();

    /* **************信号与槽的连接**************** */

    // 显示原图像
    connect(this, SIGNAL(pass_qimage_data_signal(const QImage&, const QString)), IV_w, \
            SLOT(pass_qimage_data_slot(const QImage&, const QString)));

    // 显示处理后的图像
    connect(this, SIGNAL(pass_qimage_data_signal(const QImage&)), IP_w, \
            SLOT(pass_qimage_data_slot(const QImage&)));

    /* **************信号与槽的连接**************** */
}

dipGUI::~dipGUI()
{
    delete ui;
    qDebug() << "销毁了dipGUI窗口...";

    // 手动释放
    delete IV_w;
    delete IP_w;
    vector_clear();
}

// 禁用图像处理功能
void dipGUI::disabled_dip_function()
{
    ui->actProcColorSpaceGray->setEnabled(false);
    ui->actSpatialBoxFilt->setEnabled(false);
}

// 启用图像处理功能
void dipGUI::enabled_dip_function()
{
    ui->actProcColorSpaceGray->setEnabled(true);
    ui->actSpatialBoxFilt->setEnabled(true);
}

// 将Mat类型转化为QImage类型
void dipGUI::mat_to_qimage()
{
    if (cv_img.channels() == 4)
    {
        cv::cvtColor(cv_img, cv_img, cv::COLOR_BGRA2RGB);
        qDebug() << "OpenCV读入了BGRA类型的图像...";
        qt_img = QImage((const unsigned char*)cv_img.data, \
                        cv_img.cols, cv_img.rows, cv_img.step, QImage::Format_RGB888);
        qDebug() << "已经转换成了QImage的RGB类型...";
    }
    else if (cv_img.channels() == 3)
    {
        cv::cvtColor(cv_img, cv_img, cv::COLOR_BGR2RGB);
        qDebug() << "OpenCV读入了BGR类型的图像...";
        qt_img = QImage((const unsigned char*)cv_img.data, \
                        cv_img.cols, cv_img.rows, cv_img.step, QImage::Format_RGB888);
        qDebug() << "已经转换成了QImage的RGB类型...";
    }
    else if (cv_img.channels() == 1)
    {
        qDebug() << "OpenCV读入了灰度图像...";
        qt_img = QImage((const unsigned char*)cv_img.data, \
                        cv_img.cols, cv_img.rows, cv_img.step, QImage::Format_Grayscale8);
        qDebug() << "已经转换成了QImage的灰度类型...";
    }
    else
    {
        qt_img = QImage();
        qDebug() << "OpenCV读入了不知类型的图像...";
    }
}

/* ***************************************************************** */
/* **************************文件处理部分***************************** */

/* 使用OpenCV从本地的资源管理器中读入一张图像
 * Mat格式的图像在完成处理操作后转化为QImage
 * 格式的图像并传递给子窗体用于界面显示 */
void dipGUI::on_actFileLoad_triggered() // 加载图像action的槽函数
{
    // 窗口清理
    img_clear();
    vector_clear();

    // 启用某些功能
    enabled_dip_function();

    // 从资源管理器中读图
    QString imagePath = QFileDialog::getOpenFileName\
            (IV_w, "", "/", "Image Files (*.jpg *.png *.tif);;(All(*.*))");
    if (imagePath.isEmpty())
    {
        qDebug() << "资源管理器未能成功加载图像...";
        return;
    }
    cv_original_img = cv::imread(imagePath.toLatin1().data(), cv::IMREAD_UNCHANGED);
    if (!cv_original_img.data)
    {
        qDebug() << "OpenCV加载图像时发生错误...";
        return;
    }
    cv_img = cv_original_img;
    mat_to_qimage();
    emit pass_qimage_data_signal(qt_img, imagePath);   // 传递QImage格式的图像数据
}

// 单图像窗口清理
void dipGUI::img_clear()
{
    cv_original_img = cv::Mat();
    cv_img = cv::Mat();
    qt_img = QImage();
    IV_w->close();
    emit pass_qimage_data_signal(qt_img, QString());
    IP_w->close();
    emit pass_qimage_data_signal(qt_img);
}

// 关闭打开的文件
void dipGUI::on_actFileClose_triggered()
{
    // 单图像清理
    img_clear();

    // 多图像清理
    vector_clear();

    // 禁用图像处理功能
    disabled_dip_function();
}

// 保存空图像时的错误提示框
void dipGUI::save_img_error(const QString imagePath)
{
    if (imagePath.isEmpty())
    {
        qDebug() << "没有保存图像...";
        return;
    }
    if (!cv_img.data)
    {
        qDebug() << "OpenCV无法保存空图像...";
        QMessageBox* null_img_box = new QMessageBox(this);
        null_img_box->setWindowTitle("错误警告");
        null_img_box->setIcon(QMessageBox::Critical);
        null_img_box->setText("不能保存空图像！你目前还没有处理完成的图像！");
        null_img_box->addButton("确定(Y)", QMessageBox::AcceptRole);
        null_img_box->exec();
        return;
    }
    cv::imwrite(imagePath.toLatin1().data(), cv_img);
}

// 保存文件
void dipGUI::on_actFileSave_triggered()
{
    QDir dir;
    QString folder = QDir::currentPath() + "/savedProc";
    if (!dir.exists(folder))
    {
        dir.mkpath(folder);
    }
    QString imagePath = QFileDialog::getSaveFileName\
            (IP_w, "", folder, "Image Files (*.jpg) ;; (*.png) ;; (*.tif)");
    save_img_error(imagePath);
}

// 将文件另存为
void dipGUI::on_actFileSaveAs_triggered()
{
    QString imagePath = QFileDialog::getSaveFileName\
            (IP_w, "", "/", "Image Files (*.jpg) ;; (*.png) ;; (*.tif)");
    save_img_error(imagePath);
}

// 退出程序
void dipGUI::on_actExit_triggered()
{
    QMessageBox* exit_box = new QMessageBox(this);
    exit_box->setWindowTitle("系统提示");
    exit_box->setIcon(QMessageBox::Warning);
    exit_box->setText("确定要退出吗？这样做将会结束整个进" + \
                      QString("\n") + "程，所有的已有结果都会被销毁");
    QPushButton* btn_yes = exit_box->addButton("确定(Y)", QMessageBox::AcceptRole);
    QPushButton* btn_no = exit_box->addButton("取消(N)", QMessageBox::RejectRole);
    exit_box->exec();
    if (exit_box->clickedButton() == btn_yes)
    {
        delete this;
    }
    else if (exit_box->clickedButton() == btn_no)
    {
       return;
    }
}

/* **************************文件处理部分***************************** */
/* ***************************************************************** */



/* ***************************************************************** */
/* **************************图像处理部分***************************** */

// 将输入图像转化为灰度图像
void dipGUI::qt_im2gray()
{
    if (cv_original_img.channels() == 4)
    {
        cv::cvtColor(cv_original_img, cv_img, cv::COLOR_BGRA2GRAY);
    }
    else if (cv_original_img.channels() == 3)
    {
        cv::cvtColor(cv_original_img, cv_img, cv::COLOR_BGR2GRAY);
    }
    else if (cv_original_img.channels() == 1)
    {
        cv_img = cv_original_img;   // 这一步不多余
    }
    else
    {
        cv_img = cv::Mat();
        qDebug() << "OpenCV读入了不知类型的图像...";
    }
}

// 转换为灰度图像的响应槽函数
void dipGUI::on_actProcColorSpaceGray_triggered()
{
    // 单图像处理时无需专门清理窗口
    qt_im2gray();
    mat_to_qimage();
    emit pass_qimage_data_signal(qt_img);
}

/* **************************图像处理部分***************************** */
/* ***************************************************************** */



/* **************************帮助关于部分***************************** */
/* ***************************************************************** */

// 帮助
void dipGUI::on_actHelpInfo_triggered()
{
    QMessageBox* help_box = new QMessageBox(this);
    help_box->setWindowTitle("帮助");
    help_box->setIcon(QMessageBox::Information);
    help_box->setText("首先，为什么我会想到使用Qt和OpenCV联合编程？"
                      "因为这是一个视觉工程师的必备技能，Qt编写上位机，OpenCV处理实际任务。"
                      "工业界项目要落地，还得是C或C++，MATLAB只能用于辅助开发。"
                      "Python拿来玩儿或者拿来搞搞深度学习还是不错的。"
                      "总之，使用C++，熟悉Qt库和OpenCV库，其它的可以交给MATLAB和Python。"
                      "坚持学习，不要畏难，总会成功！");
    help_box->addButton("我已知晓(Y)", QMessageBox::AcceptRole);
    help_box->exec();
}

// 关于软件
void dipGUI::on_actAboutApp_triggered()
{
    QMessageBox* app_box = new QMessageBox(this);
    app_box->setWindowTitle("关于软件");
    app_box->setIcon(QMessageBox::Information);
    app_box->setText("本软件基于Qt5.14.2和OpenCV4.4.0联合" + \
                     QString("\n") + "开发，一切工作皆源于本人对技术的热爱" + \
                     QString("\n") + "——始于2022毕业季（5月下旬）");
    app_box->addButton("我已知晓(Y)", QMessageBox::AcceptRole);
    app_box->exec();    // 需要阻塞显示
}

// 关于我
void dipGUI::on_actAboutMe_triggered()
{
    QMessageBox* me_box = new QMessageBox(this);
    me_box->setWindowTitle("关于我");
    me_box->setIcon(QMessageBox::Information);
    me_box->setText("关于我的信息，请右键复制以下链接到浏览器打开：<br><br>"
                    "GitHub: <a href='https://github.com/chubbylhao'>"
                    "https://github.com/chubbylhao</a><br><br>"
                    "Blogs: <a href='https://chubbylhao.github.io/'>"
                    "https://chubbylhao.github.io</a>");
    me_box->addButton("我已知晓(Y)", QMessageBox::AcceptRole);
    me_box->exec();
}

/* **************************帮助关于部分***************************** */
/* ***************************************************************** */



/* **************************其它处理部分***************************** */
/* ***************************************************************** */

// 读入动态数组
void dipGUI::vector_add()
{
    QStringList img_paths = QFileDialog::getOpenFileNames\
            (this, "", "/", "Image Files (*.jpg *.png *.tif);;(All(*.*))");
    QString img_path;

    // 判空
    if (img_paths.isEmpty())
    {
        qDebug() << "未能载入多图像...";
        return;
    }

    // 读图
    for (int i = 0; i < img_paths.size(); ++i)
    {
        // 建立窗口
        imgView* temp_ptr = new imgView;
        multi_ws.push_back(temp_ptr);

        // 建立图像
        qDebug() << "检查读了几张图...";
        img_path = img_paths[i];
        cv_original_img = cv::imread(img_path.toLatin1().data(), cv::IMREAD_UNCHANGED);
        multi_imgs.push_back(cv_original_img);
    }

    // 检查大小是否一致
    if (!size_consistency_of_multi_imgs())
    {
        return;
    }

    // 将Mat格式转化为QImage格式
    QVector<cv::Mat>::iterator iter_imgs;
    for (iter_imgs = multi_imgs.begin(); iter_imgs != multi_imgs.end(); ++iter_imgs)
    {
        qDebug() << "多图像将Mat格式转化为QImage格式...";
        cv_img = *iter_imgs;
        mat_to_qimage();
        multi_qimgs.push_back(qt_img);
    }

    // 建立动态的信号与槽的连接（实现多图处理的关键）
    int flag = 0;
    QVector<imgView* >::iterator iter_ws;
    for (iter_ws = multi_ws.begin(); iter_ws != multi_ws.end(); ++iter_ws)
    {
        qDebug() << "建立动态连接...";
        connect(this, SIGNAL(pass_multi_qimage_data_signal(const QImage&, const QString)), \
                *iter_ws, SLOT(pass_multi_qimage_data_slot(const QImage&, const QString)));
        // emit容易出错
        emit pass_multi_qimage_data_signal(multi_qimgs.at(flag), img_paths[flag]);
        qDebug() << "断开动态连接...";
        disconnect(this, SIGNAL(pass_multi_qimage_data_signal(const QImage&, const QString)), \
                   *iter_ws, SLOT(pass_multi_qimage_data_slot(const QImage&, const QString)));
        flag ++;
    }
}

// 清理动态数组
void dipGUI::vector_clear()
{
    // 窗口动态数组的释放与清空
    if (!multi_ws.isEmpty())
    {
        qDebug() << "窗口动态数组不为空...";
        QVector<imgView* >::iterator iter;
        for (iter = multi_ws.begin(); iter != multi_ws.end(); ++iter)
        {
            delete *iter;
            qDebug() << "销毁了多图窗口...";
        }
        multi_ws.clear();
    }

    // 图像动态数组的释放与清空
    if (!multi_imgs.isEmpty())
    {
        qDebug() << "图像动态数组不为空...";
        multi_imgs.clear();
    }

    // 传递用的图像动态数组的释放与清空
    if (!multi_qimgs.isEmpty())
    {
        qDebug() << "传递用的图像动态数组不为空...";
        multi_qimgs.clear();
    }
}

// 检查待处理图像大小是否一致
bool dipGUI::size_consistency_of_multi_imgs()
{
    for (int i = 1; i < multi_imgs.size(); ++i)
    {
        if (multi_imgs.first().size != multi_imgs.at(i).size)
        {
            qDebug() << "待处理的多幅图像大小不一致...";
            QMessageBox* size_box = new QMessageBox(this);
            size_box->setWindowTitle("错误警告");
            size_box->setIcon(QMessageBox::Critical);
            size_box->setText("错误！待处理的图像大小不一致！请检查！");
            size_box->addButton("我已知晓(Y)", QMessageBox::AcceptRole);
            size_box->exec();
            return false;
        }
    }
    return true;
}

// 均值融合的响应槽函数
void dipGUI::on_actAvgFusion_triggered()
{
    // 禁用单图像处理功能
    disabled_dip_function();

    // 窗口清理
    img_clear();
    vector_clear();

    // 读图与处理
    vector_add();
    qt_imfusion_avg();

    // 转化与传输
    mat_to_qimage();
    emit pass_qimage_data_signal(qt_img);
}

// 均值融合
void dipGUI::qt_imfusion_avg()
{
    cv::Mat temp_img = cv::Mat::zeros(multi_imgs.first().rows, \
                                      multi_imgs.first().cols, CV_32FC1);
    for (int k = 0; k < multi_imgs.size(); ++k)
    {
        cv_original_img = multi_imgs.at(k);
        qt_im2gray();
        cv_img.convertTo(cv_img, CV_32FC1);
        temp_img += cv_img;
    }
    temp_img /= multi_imgs.size();

    // 注意类型转换
    cv::normalize(temp_img, temp_img, 0, 1, cv::NORM_MINMAX, CV_32FC1);
    temp_img.convertTo(cv_img, CV_8UC1, 255, 0);
}

/* **************************其它处理部分***************************** */
/* ***************************************************************** */
