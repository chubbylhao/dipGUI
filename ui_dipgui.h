/********************************************************************************
** Form generated from reading UI file 'dipgui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIPGUI_H
#define UI_DIPGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dipGUI
{
public:
    QAction *actFileLoad;
    QAction *actSpatialBoxFilt;
    QAction *actAboutApp;
    QAction *actAboutMe;
    QAction *actHelpInfo;
    QAction *actProcColorSpaceGray;
    QAction *actFileClose;
    QAction *actExit;
    QAction *actFileSave;
    QAction *actFileSaveAs;
    QAction *actAvgFusion;
    QAction *actSpatialGaussFilt;
    QAction *actSpatialMedianFilt;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *messageLab;
    QMenuBar *menubar;
    QMenu *File;
    QMenu *Process;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *Help;
    QMenu *About;
    QMenu *Analyze;
    QMenu *Feature;
    QMenu *Vedio;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *dipGUI)
    {
        if (dipGUI->objectName().isEmpty())
            dipGUI->setObjectName(QString::fromUtf8("dipGUI"));
        dipGUI->resize(800, 600);
        actFileLoad = new QAction(dipGUI);
        actFileLoad->setObjectName(QString::fromUtf8("actFileLoad"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/dipGUI/File/images/loadfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFileLoad->setIcon(icon);
        actSpatialBoxFilt = new QAction(dipGUI);
        actSpatialBoxFilt->setObjectName(QString::fromUtf8("actSpatialBoxFilt"));
        actAboutApp = new QAction(dipGUI);
        actAboutApp->setObjectName(QString::fromUtf8("actAboutApp"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/dipGUI/About/images/aboutapp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAboutApp->setIcon(icon1);
        actAboutMe = new QAction(dipGUI);
        actAboutMe->setObjectName(QString::fromUtf8("actAboutMe"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/dipGUI/About/images/aboutme.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAboutMe->setIcon(icon2);
        actHelpInfo = new QAction(dipGUI);
        actHelpInfo->setObjectName(QString::fromUtf8("actHelpInfo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/dipGUI/Help/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actHelpInfo->setIcon(icon3);
        actProcColorSpaceGray = new QAction(dipGUI);
        actProcColorSpaceGray->setObjectName(QString::fromUtf8("actProcColorSpaceGray"));
        actFileClose = new QAction(dipGUI);
        actFileClose->setObjectName(QString::fromUtf8("actFileClose"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/dipGUI/File/images/closefile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFileClose->setIcon(icon4);
        actExit = new QAction(dipGUI);
        actExit->setObjectName(QString::fromUtf8("actExit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/dipGUI/File/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon5);
        actFileSave = new QAction(dipGUI);
        actFileSave->setObjectName(QString::fromUtf8("actFileSave"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/dipGUI/File/images/savefile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFileSave->setIcon(icon6);
        actFileSaveAs = new QAction(dipGUI);
        actFileSaveAs->setObjectName(QString::fromUtf8("actFileSaveAs"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/dipGUI/File/images/saveasfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFileSaveAs->setIcon(icon7);
        actAvgFusion = new QAction(dipGUI);
        actAvgFusion->setObjectName(QString::fromUtf8("actAvgFusion"));
        actSpatialGaussFilt = new QAction(dipGUI);
        actSpatialGaussFilt->setObjectName(QString::fromUtf8("actSpatialGaussFilt"));
        actSpatialMedianFilt = new QAction(dipGUI);
        actSpatialMedianFilt->setObjectName(QString::fromUtf8("actSpatialMedianFilt"));
        centralwidget = new QWidget(dipGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        messageLab = new QLabel(centralwidget);
        messageLab->setObjectName(QString::fromUtf8("messageLab"));
        QFont font;
        font.setPointSize(13);
        messageLab->setFont(font);
        messageLab->setFrameShape(QFrame::Box);
        messageLab->setFrameShadow(QFrame::Sunken);
        messageLab->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(messageLab, 0, 0, 1, 1);

        dipGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(dipGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        File = new QMenu(menubar);
        File->setObjectName(QString::fromUtf8("File"));
        Process = new QMenu(menubar);
        Process->setObjectName(QString::fromUtf8("Process"));
        menu = new QMenu(Process);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(Process);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        Help = new QMenu(menubar);
        Help->setObjectName(QString::fromUtf8("Help"));
        About = new QMenu(menubar);
        About->setObjectName(QString::fromUtf8("About"));
        Analyze = new QMenu(menubar);
        Analyze->setObjectName(QString::fromUtf8("Analyze"));
        Feature = new QMenu(menubar);
        Feature->setObjectName(QString::fromUtf8("Feature"));
        Vedio = new QMenu(menubar);
        Vedio->setObjectName(QString::fromUtf8("Vedio"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menu_3);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        dipGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(dipGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        dipGUI->setStatusBar(statusbar);
        toolBar = new QToolBar(dipGUI);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        dipGUI->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(File->menuAction());
        menubar->addAction(Process->menuAction());
        menubar->addAction(Analyze->menuAction());
        menubar->addAction(Feature->menuAction());
        menubar->addAction(Vedio->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(Help->menuAction());
        menubar->addAction(About->menuAction());
        File->addAction(actFileLoad);
        File->addSeparator();
        File->addAction(actFileClose);
        File->addSeparator();
        File->addAction(actFileSave);
        File->addSeparator();
        File->addAction(actFileSaveAs);
        File->addSeparator();
        File->addAction(actExit);
        Process->addAction(menu->menuAction());
        Process->addSeparator();
        Process->addAction(menu_2->menuAction());
        Process->addSeparator();
        menu->addAction(actProcColorSpaceGray);
        menu->addSeparator();
        menu_2->addAction(actSpatialBoxFilt);
        menu_2->addSeparator();
        menu_2->addAction(actSpatialGaussFilt);
        menu_2->addSeparator();
        menu_2->addAction(actSpatialMedianFilt);
        Help->addAction(actHelpInfo);
        About->addAction(actAboutApp);
        About->addSeparator();
        About->addAction(actAboutMe);
        menu_3->addAction(menu_4->menuAction());
        menu_4->addAction(actAvgFusion);
        toolBar->addAction(actFileLoad);
        toolBar->addSeparator();
        toolBar->addAction(actFileClose);
        toolBar->addSeparator();
        toolBar->addAction(actFileSave);
        toolBar->addSeparator();
        toolBar->addAction(actFileSaveAs);
        toolBar->addSeparator();
        toolBar->addAction(actExit);
        toolBar->addSeparator();

        retranslateUi(dipGUI);

        QMetaObject::connectSlotsByName(dipGUI);
    } // setupUi

    void retranslateUi(QMainWindow *dipGUI)
    {
        dipGUI->setWindowTitle(QCoreApplication::translate("dipGUI", "dipGUI_alpha", nullptr));
        actFileLoad->setText(QCoreApplication::translate("dipGUI", "\345\212\240\350\275\275\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        actFileLoad->setToolTip(QCoreApplication::translate("dipGUI", "\344\273\216\346\234\254\345\234\260\345\212\240\350\275\275\344\270\200\345\274\240\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actFileLoad->setShortcut(QCoreApplication::translate("dipGUI", "Ctrl+Shift+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actSpatialBoxFilt->setText(QCoreApplication::translate("dipGUI", "\347\233\222\345\274\217\346\273\244\346\263\242", nullptr));
#if QT_CONFIG(tooltip)
        actSpatialBoxFilt->setToolTip(QCoreApplication::translate("dipGUI", "\347\233\222\345\274\217\346\273\244\346\263\242\345\217\210\347\247\260\345\235\207\345\200\274\346\273\244\346\263\242", nullptr));
#endif // QT_CONFIG(tooltip)
        actAboutApp->setText(QCoreApplication::translate("dipGUI", "\345\205\263\344\272\216\350\275\257\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        actAboutApp->setToolTip(QCoreApplication::translate("dipGUI", "\345\205\263\344\272\216\350\275\257\344\273\266\347\232\204\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        actAboutMe->setText(QCoreApplication::translate("dipGUI", "\345\205\263\344\272\216\346\210\221", nullptr));
#if QT_CONFIG(tooltip)
        actAboutMe->setToolTip(QCoreApplication::translate("dipGUI", "\345\205\263\344\272\216\346\210\221\357\274\210\345\274\200\345\217\221\350\200\205\357\274\211\347\232\204\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        actHelpInfo->setText(QCoreApplication::translate("dipGUI", "\345\270\256\345\212\251\344\277\241\346\201\257", nullptr));
#if QT_CONFIG(tooltip)
        actHelpInfo->setToolTip(QCoreApplication::translate("dipGUI", "\347\273\231\345\207\272\344\270\200\347\202\271\345\270\256\345\212\251\345\273\272\350\256\256", nullptr));
#endif // QT_CONFIG(tooltip)
        actProcColorSpaceGray->setText(QCoreApplication::translate("dipGUI", "Grayscale", nullptr));
#if QT_CONFIG(tooltip)
        actProcColorSpaceGray->setToolTip(QCoreApplication::translate("dipGUI", "\350\275\254\346\215\242\344\270\272\347\201\260\345\272\246\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        actFileClose->setText(QCoreApplication::translate("dipGUI", "\345\205\263\351\227\255\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        actFileClose->setToolTip(QCoreApplication::translate("dipGUI", "\345\205\263\351\227\255\345\267\262\346\211\223\345\274\200\347\232\204\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actFileClose->setShortcut(QCoreApplication::translate("dipGUI", "Ctrl+Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actExit->setText(QCoreApplication::translate("dipGUI", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actExit->setToolTip(QCoreApplication::translate("dipGUI", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actExit->setShortcut(QCoreApplication::translate("dipGUI", "Ctrl+Shift+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actFileSave->setText(QCoreApplication::translate("dipGUI", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        actFileSave->setToolTip(QCoreApplication::translate("dipGUI", "\345\234\250\351\273\230\350\256\244\350\267\257\345\276\204\344\277\235\345\255\230\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actFileSave->setShortcut(QCoreApplication::translate("dipGUI", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actFileSaveAs->setText(QCoreApplication::translate("dipGUI", "\346\226\207\344\273\266\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(tooltip)
        actFileSaveAs->setToolTip(QCoreApplication::translate("dipGUI", "\345\260\206\345\233\276\345\203\217\345\217\246\345\255\230\344\270\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actFileSaveAs->setShortcut(QCoreApplication::translate("dipGUI", "Ctrl+Shift+S, Ctrl+Shift+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actAvgFusion->setText(QCoreApplication::translate("dipGUI", "\345\235\207\345\200\274\350\236\215\345\220\210", nullptr));
        actSpatialGaussFilt->setText(QCoreApplication::translate("dipGUI", "\351\253\230\346\226\257\346\273\244\346\263\242", nullptr));
#if QT_CONFIG(tooltip)
        actSpatialGaussFilt->setToolTip(QCoreApplication::translate("dipGUI", "\351\253\230\346\226\257\346\273\244\346\263\242", nullptr));
#endif // QT_CONFIG(tooltip)
        actSpatialMedianFilt->setText(QCoreApplication::translate("dipGUI", "\344\270\255\345\200\274\346\273\244\346\263\242", nullptr));
#if QT_CONFIG(tooltip)
        actSpatialMedianFilt->setToolTip(QCoreApplication::translate("dipGUI", "\344\270\255\345\200\274\346\273\244\346\263\242", nullptr));
#endif // QT_CONFIG(tooltip)
        messageLab->setText(QCoreApplication::translate("dipGUI", "\345\220\216\347\273\255\345\274\200\345\217\221\345\214\272\345\237\237...", nullptr));
        File->setTitle(QCoreApplication::translate("dipGUI", "\346\226\207\344\273\266", nullptr));
        Process->setTitle(QCoreApplication::translate("dipGUI", "\345\244\204\347\220\206", nullptr));
        menu->setTitle(QCoreApplication::translate("dipGUI", "\351\242\234\350\211\262\347\251\272\351\227\264", nullptr));
        menu_2->setTitle(QCoreApplication::translate("dipGUI", "\347\251\272\351\227\264\346\273\244\346\263\242", nullptr));
        Help->setTitle(QCoreApplication::translate("dipGUI", "\345\270\256\345\212\251", nullptr));
        About->setTitle(QCoreApplication::translate("dipGUI", "\345\205\263\344\272\216", nullptr));
        Analyze->setTitle(QCoreApplication::translate("dipGUI", "\345\210\206\346\236\220", nullptr));
        Feature->setTitle(QCoreApplication::translate("dipGUI", "\347\211\271\345\276\201", nullptr));
        Vedio->setTitle(QCoreApplication::translate("dipGUI", "\350\247\206\351\242\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("dipGUI", "\345\205\266\345\256\203", nullptr));
        menu_4->setTitle(QCoreApplication::translate("dipGUI", "\345\233\276\345\203\217\350\236\215\345\220\210", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("dipGUI", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dipGUI: public Ui_dipGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIPGUI_H
