/********************************************************************************
** Form generated from reading UI file 'filterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDIALOG_H
#define UI_FILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FilterDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *winSizeLab;
    QSpacerItem *horizontalSpacer;
    QSpinBox *winSize;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *gaussSigmaLab;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *gaussSigma;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FilterDialog)
    {
        if (FilterDialog->objectName().isEmpty())
            FilterDialog->setObjectName(QString::fromUtf8("FilterDialog"));
        FilterDialog->resize(260, 140);
        FilterDialog->setMinimumSize(QSize(260, 140));
        FilterDialog->setMaximumSize(QSize(260, 140));
        verticalLayout_2 = new QVBoxLayout(FilterDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(25, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        winSizeLab = new QLabel(FilterDialog);
        winSizeLab->setObjectName(QString::fromUtf8("winSizeLab"));
        QFont font;
        font.setPointSize(9);
        winSizeLab->setFont(font);

        horizontalLayout->addWidget(winSizeLab);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        winSize = new QSpinBox(FilterDialog);
        winSize->setObjectName(QString::fromUtf8("winSize"));
        winSize->setMinimumSize(QSize(60, 25));
        winSize->setMaximumSize(QSize(60, 25));
        QFont font1;
        font1.setPointSize(10);
        winSize->setFont(font1);
        winSize->setMinimum(3);
        winSize->setMaximum(43);
        winSize->setValue(7);

        horizontalLayout->addWidget(winSize);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gaussSigmaLab = new QLabel(FilterDialog);
        gaussSigmaLab->setObjectName(QString::fromUtf8("gaussSigmaLab"));

        horizontalLayout_2->addWidget(gaussSigmaLab);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        gaussSigma = new QDoubleSpinBox(FilterDialog);
        gaussSigma->setObjectName(QString::fromUtf8("gaussSigma"));
        gaussSigma->setMinimumSize(QSize(60, 25));
        gaussSigma->setMaximumSize(QSize(60, 25));
        gaussSigma->setFont(font1);
        gaussSigma->setMinimum(1.000000000000000);
        gaussSigma->setMaximum(7.000000000000000);
        gaussSigma->setStepType(QAbstractSpinBox::DefaultStepType);

        horizontalLayout_2->addWidget(gaussSigma);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(25, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(17, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        buttonBox = new QDialogButtonBox(FilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setMinimumSize(QSize(140, 25));
        buttonBox->setMaximumSize(QSize(140, 25));
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

#if QT_CONFIG(shortcut)
        winSizeLab->setBuddy(winSize);
        gaussSigmaLab->setBuddy(gaussSigma);
#endif // QT_CONFIG(shortcut)

        retranslateUi(FilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FilterDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterDialog)
    {
        FilterDialog->setWindowTitle(QCoreApplication::translate("FilterDialog", "\350\256\276\347\275\256\346\273\244\346\263\242\345\217\202\346\225\260", nullptr));
        winSizeLab->setText(QCoreApplication::translate("FilterDialog", "\347\252\227\345\217\243\345\244\247\345\260\217(&W):", nullptr));
        gaussSigmaLab->setText(QCoreApplication::translate("FilterDialog", "\351\253\230\346\226\257\346\226\271\345\267\256(&S):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterDialog: public Ui_FilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDIALOG_H
