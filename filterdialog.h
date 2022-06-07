#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>

struct FilterParms
{
    int win_size = 7;   // 窗口大小
    float sigma = 1.0;    // 高斯方差
    bool ok_cancel;
};

namespace Ui {
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();

protected:
    void closeEvent(QCloseEvent* ) override;

signals:
    void pass_filter_parameters_signal(const FilterParms& size_sigma);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void open_gauss_sigma_slot();

private:
    Ui::FilterDialog *ui;

    // 类内全局值
    FilterParms size_sigma;
};

#endif // FILTERDIALOG_H
