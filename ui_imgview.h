/********************************************************************************
** Form generated from reading UI file 'imgview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGVIEW_H
#define UI_IMGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imgView
{
public:
    QAction *actAdapt;
    QAction *actZoomIn;
    QAction *actZoomOut;
    QAction *actRestore;
    QAction *actOriginalSize;
    QAction *actStretch;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *imgViewLab;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *imgView)
    {
        if (imgView->objectName().isEmpty())
            imgView->setObjectName(QString::fromUtf8("imgView"));
        imgView->resize(600, 450);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imgView->sizePolicy().hasHeightForWidth());
        imgView->setSizePolicy(sizePolicy);
        imgView->setMinimumSize(QSize(400, 300));
        actAdapt = new QAction(imgView);
        actAdapt->setObjectName(QString::fromUtf8("actAdapt"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgview/images/adapt.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAdapt->setIcon(icon);
        actZoomIn = new QAction(imgView);
        actZoomIn->setObjectName(QString::fromUtf8("actZoomIn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgview/images/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomIn->setIcon(icon1);
        actZoomOut = new QAction(imgView);
        actZoomOut->setObjectName(QString::fromUtf8("actZoomOut"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgview/images/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomOut->setIcon(icon2);
        actRestore = new QAction(imgView);
        actRestore->setObjectName(QString::fromUtf8("actRestore"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgview/images/restore.png"), QSize(), QIcon::Normal, QIcon::Off);
        actRestore->setIcon(icon3);
        actOriginalSize = new QAction(imgView);
        actOriginalSize->setObjectName(QString::fromUtf8("actOriginalSize"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imgview/images/originalsize.png"), QSize(), QIcon::Normal, QIcon::Off);
        actOriginalSize->setIcon(icon4);
        actStretch = new QAction(imgView);
        actStretch->setObjectName(QString::fromUtf8("actStretch"));
        actStretch->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imgview/images/stretch.png"), QSize(), QIcon::Normal, QIcon::Off);
        actStretch->setIcon(icon5);
        centralwidget = new QWidget(imgView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 578, 343));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        imgViewLab = new QLabel(scrollAreaWidgetContents);
        imgViewLab->setObjectName(QString::fromUtf8("imgViewLab"));
        sizePolicy.setHeightForWidth(imgViewLab->sizePolicy().hasHeightForWidth());
        imgViewLab->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(13);
        imgViewLab->setFont(font);
        imgViewLab->setFrameShape(QFrame::NoFrame);
        imgViewLab->setFrameShadow(QFrame::Plain);
        imgViewLab->setScaledContents(false);
        imgViewLab->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(imgViewLab, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        imgView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(imgView);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 26));
        imgView->setMenuBar(menubar);
        statusbar = new QStatusBar(imgView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        imgView->setStatusBar(statusbar);
        toolBar = new QToolBar(imgView);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        imgView->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actRestore);
        toolBar->addSeparator();
        toolBar->addAction(actAdapt);
        toolBar->addSeparator();
        toolBar->addAction(actOriginalSize);
        toolBar->addSeparator();
        toolBar->addAction(actStretch);
        toolBar->addSeparator();
        toolBar->addAction(actZoomIn);
        toolBar->addSeparator();
        toolBar->addAction(actZoomOut);
        toolBar->addSeparator();

        retranslateUi(imgView);

        QMetaObject::connectSlotsByName(imgView);
    } // setupUi

    void retranslateUi(QMainWindow *imgView)
    {
        imgView->setWindowTitle(QCoreApplication::translate("imgView", "imgView", nullptr));
        actAdapt->setText(QCoreApplication::translate("imgView", "\350\207\252\351\200\202\345\272\224", nullptr));
#if QT_CONFIG(tooltip)
        actAdapt->setToolTip(QCoreApplication::translate("imgView", "\344\275\277\345\233\276\345\203\217\350\207\252\351\200\202\345\272\224\347\252\227\345\217\243\345\244\247\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomIn->setText(QCoreApplication::translate("imgView", "\346\224\276\345\244\247", nullptr));
#if QT_CONFIG(tooltip)
        actZoomIn->setToolTip(QCoreApplication::translate("imgView", "\346\224\276\345\244\247\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actZoomOut->setText(QCoreApplication::translate("imgView", "\347\274\251\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        actZoomOut->setToolTip(QCoreApplication::translate("imgView", "\347\274\251\345\260\217\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actRestore->setText(QCoreApplication::translate("imgView", "\350\277\230\345\216\237\351\273\230\350\256\244", nullptr));
#if QT_CONFIG(tooltip)
        actRestore->setToolTip(QCoreApplication::translate("imgView", "\345\260\206\347\252\227\345\217\243\345\222\214\345\233\276\345\203\217\350\277\230\345\216\237\350\207\263\351\273\230\350\256\244\345\244\247\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actOriginalSize->setText(QCoreApplication::translate("imgView", "\346\230\276\347\244\272\345\216\237\345\233\276", nullptr));
#if QT_CONFIG(tooltip)
        actOriginalSize->setToolTip(QCoreApplication::translate("imgView", "\344\273\245\345\233\276\345\203\217\347\232\204\345\216\237\345\244\247\345\260\217\346\230\276\347\244\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actStretch->setText(QCoreApplication::translate("imgView", "\351\223\272\346\273\241\347\252\227\345\217\243", nullptr));
#if QT_CONFIG(tooltip)
        actStretch->setToolTip(QCoreApplication::translate("imgView", "\345\260\206\345\233\276\345\203\217\351\223\272\346\273\241\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        imgViewLab->setText(QCoreApplication::translate("imgView", "\345\233\276\345\203\217\346\230\276\347\244\272\345\214\272\345\237\237...", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("imgView", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class imgView: public Ui_imgView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGVIEW_H
