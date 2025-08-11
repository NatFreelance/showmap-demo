/********************************************************************************
** Form generated from reading UI file 'showmapwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWMAPWIDGET_H
#define UI_SHOWMAPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowMapWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *latSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *lonSpinBox;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QWidget *ShowMapWidget)
    {
        if (ShowMapWidget->objectName().isEmpty())
            ShowMapWidget->setObjectName(QString::fromUtf8("ShowMapWidget"));
        ShowMapWidget->resize(962, 460);
        verticalLayout = new QVBoxLayout(ShowMapWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_2 = new QFrame(ShowMapWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Plain);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        latSpinBox = new QDoubleSpinBox(frame_2);
        latSpinBox->setObjectName(QString::fromUtf8("latSpinBox"));
        latSpinBox->setDecimals(4);
        latSpinBox->setSingleStep(0.100000000000000);
        latSpinBox->setValue(56.666699999999999);

        horizontalLayout_2->addWidget(latSpinBox);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lonSpinBox = new QDoubleSpinBox(frame_2);
        lonSpinBox->setObjectName(QString::fromUtf8("lonSpinBox"));
        lonSpinBox->setDecimals(4);
        lonSpinBox->setSingleStep(0.100000000000000);
        lonSpinBox->setValue(37.404600000000002);

        horizontalLayout_2->addWidget(lonSpinBox);

        addButton = new QPushButton(frame_2);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout_2->addWidget(addButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(ShowMapWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(ShowMapWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ShowMapWidget);

        QMetaObject::connectSlotsByName(ShowMapWidget);
    } // setupUi

    void retranslateUi(QWidget *ShowMapWidget)
    {
        ShowMapWidget->setWindowTitle(QCoreApplication::translate("ShowMapWidget", "\320\232\320\260\321\200\321\202\320\260 \320\274\320\265\321\201\321\202\320\275\320\276\321\201\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("ShowMapWidget", "\320\250\320\270\321\200\320\276\321\202\320\260, \320\263\321\200\320\260\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("ShowMapWidget", "\320\224\320\276\320\273\320\263\320\276\321\202\320\260, \320\263\321\200\320\260\320\264", nullptr));
        addButton->setText(QCoreApplication::translate("ShowMapWidget", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        closeButton->setText(QCoreApplication::translate("ShowMapWidget", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowMapWidget: public Ui_ShowMapWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWMAPWIDGET_H
