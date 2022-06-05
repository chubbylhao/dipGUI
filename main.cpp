#include "dipgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    dipGUI* w = new dipGUI;  // 还是在堆上开辟新窗口（管理更加灵活）
    w->setAttribute(Qt::WA_DeleteOnClose);  // 在叉掉窗口后立即销毁内存
    w->show();
    return app.exec();
}
