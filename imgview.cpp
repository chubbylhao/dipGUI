#include "imgview.h"
#include "ui_imgview.h"
#include <QDebug>

imgView::imgView(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::imgView)
{
    ui->setupUi(this);
    initUI();
}

imgView::~imgView()
{
    delete ui;
    qDebug() << "销毁了imgView窗口...";
}

// 初始化布局
void imgView::initUI()
{
    view_mode = new QComboBox(this);
    view_mode->addItem("手动模式");
    view_mode->addItem("自动模式");
    ui->toolBar->addWidget(view_mode);
}

// 让图像大小随窗口大小而变化
void imgView::resizeEvent(QResizeEvent* )
{
    if (view_mode->currentIndex() == 0)
    {
        qDebug() << "目前处于手动模式...";
    }
    else if (view_mode->currentIndex() == 1)
    {
        qDebug() << "目前处于自动模式...";
        roll_image();
    }
    else
    {
        return;
    }
}

// 图像自适应窗口大小的复用代码
void imgView::adaptively_resize_image()
{
    ui->imgViewLab->setPixmap(qt_show_img.scaled(ui->imgViewLab->size(), Qt::KeepAspectRatio));
}

// 让窗口产生滚动效果的复用代码
void imgView::roll_image()
{
    ui->imgViewLab->resize(this->size());
    adaptively_resize_image();
}

// 接收图像数据（初始化显示）
void imgView::pass_qimage_data_slot(const QImage& qt_image, const QString image_path)
{
    qt_view_img = qt_image;
    qt_show_img = QPixmap::fromImage(qt_view_img);
    if (qt_image.isNull() && image_path.isNull())
    {
        qDebug() << "图像为空，IV_w窗口不显示...";
    }
    else
    {
        this->show();
    }
    ui->statusbar->showMessage("图像路径：" + image_path);
    on_actRestore_triggered();
}

// 接收图像数据（处理后显示）
void imgView::pass_qimage_data_slot(const QImage &qt_image)
{
    qt_view_img = qt_image;
    qt_show_img = QPixmap::fromImage(qt_view_img);
    if (qt_image.isNull())
    {
        qDebug() << "图像为空，IP_w窗口不显示...";
    }
    else
    {
        this->show();
    }
    ui->statusbar->showMessage("原图像的处理结果如上所示......");
    on_actRestore_triggered();
}

// 接收图像数据（多子窗口显示）
void imgView::pass_multi_qimage_data_slot(const QImage &qt_image, const QString image_path)
{
    pass_qimage_data_slot(qt_image, image_path);
}

// 显示方式：默认
void imgView::on_actRestore_triggered()
{
    this->resize(BASE_WIDTH, BASE_HEIGHT);
    roll_image();
}

// 显示方式：图像自适应窗口的大小
void imgView::on_actAdapt_triggered()
{
    // 要使用viewport
    ui->imgViewLab->resize(ui->scrollArea->viewport()->width() - 2*ui->imgViewLab->x(), \
                           ui->scrollArea->viewport()->height() - 2*ui->imgViewLab->y());
    adaptively_resize_image();
    qDebug() << "图像已自适应窗口的大小...";
}

// 显示方式：以图像原大小显示
void imgView::on_actOriginalSize_triggered()
{
    ui->imgViewLab->setPixmap(qt_show_img);
}

// 显示方式：铺满窗口
void imgView::on_actStretch_triggered()
{
    on_actAdapt_triggered();
    if (ui->actStretch->isChecked())
    {
        ui->imgViewLab->setScaledContents(true);
    }
    else
    {
        ui->imgViewLab->setScaledContents(false);
    }
}

// 显示方式：放大图像
void imgView::on_actZoomIn_triggered()
{
    ui->imgViewLab->resize(1.1*ui->imgViewLab->size());
    adaptively_resize_image();
}

// 显示方式：缩小图像
void imgView::on_actZoomOut_triggered()
{
    // ! 这里应该是有点小bug的
    ui->imgViewLab->resize(0.9*ui->imgViewLab->size());
    adaptively_resize_image();
}
