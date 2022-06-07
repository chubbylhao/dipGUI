#include "filterdialog.h"
#include "ui_filterdialog.h"
#include <QDebug>

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);
    ui->gaussSigma->setEnabled(false);
}

FilterDialog::~FilterDialog()
{
    delete ui;
    qDebug() << "销毁了filterDialog窗口...";
}

// 重写窗口关闭事件
void FilterDialog::closeEvent(QCloseEvent *)
{
    on_buttonBox_rejected();
    qDebug() << "正在执行filterDialog的窗口关闭事件...";
}

// 按下确定
void FilterDialog::on_buttonBox_accepted()
{
    size_sigma.win_size = ui->winSize->value();
    size_sigma.sigma = ui->gaussSigma->value();
    size_sigma.ok_cancel = true;
    emit pass_filter_parameters_signal(size_sigma);

    // 恢复默认值
    ui->winSize->setValue(7);
    ui->gaussSigma->setValue(1.0);
    if (ui->gaussSigma->isEnabled())
    {
        ui->gaussSigma->setEnabled(false);
    }
}

// 按下取消
void FilterDialog::on_buttonBox_rejected()
{
    size_sigma.ok_cancel = false;
    emit pass_filter_parameters_signal(size_sigma);

    // 恢复
    if (ui->gaussSigma->isEnabled())
    {
        ui->gaussSigma->setEnabled(false);
    }
}

// 使能
void FilterDialog::open_gauss_sigma_slot()
{
    ui->gaussSigma->setEnabled(true);
}
