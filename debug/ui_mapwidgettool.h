/********************************************************************************
** Form generated from reading UI file 'mapwidgettool.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWIDGETTOOL_H
#define UI_MAPWIDGETTOOL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWidgetTool
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *tool_layout;
    QToolButton *optionButton;
    QToolButton *addButton;
    QToolButton *playButton;
    QToolButton *stopButton;
    QVBoxLayout *del_layout;
    QSpacerItem *verticalSpacer;
    QToolButton *savemapButton;
    QToolButton *clearAllButton;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *qml_canvas_layout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *status_layout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QWidget *MapWidgetTool)
    {
        if (MapWidgetTool->objectName().isEmpty())
            MapWidgetTool->setObjectName(QString::fromUtf8("MapWidgetTool"));
        MapWidgetTool->resize(840, 597);
        verticalLayout_2 = new QVBoxLayout(MapWidgetTool);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame_3 = new QFrame(MapWidgetTool);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(55, 520));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tool_layout = new QVBoxLayout();
        tool_layout->setSpacing(3);
        tool_layout->setObjectName(QString::fromUtf8("tool_layout"));
        optionButton = new QToolButton(frame_3);
        optionButton->setObjectName(QString::fromUtf8("optionButton"));
        optionButton->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        optionButton->setIcon(icon);

        tool_layout->addWidget(optionButton);

        addButton = new QToolButton(frame_3);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setMaximumSize(QSize(40, 40));
        QFont font;
        font.setPointSize(24);
        addButton->setFont(font);
        addButton->setCursor(QCursor(Qt::PointingHandCursor));

        tool_layout->addWidget(addButton);

        playButton = new QToolButton(frame_3);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/debug/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon1);

        tool_layout->addWidget(playButton);

        stopButton = new QToolButton(frame_3);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/debug/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon2);

        tool_layout->addWidget(stopButton);


        verticalLayout_4->addLayout(tool_layout);

        del_layout = new QVBoxLayout();
        del_layout->setSpacing(3);
        del_layout->setObjectName(QString::fromUtf8("del_layout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        del_layout->addItem(verticalSpacer);

        savemapButton = new QToolButton(frame_3);
        savemapButton->setObjectName(QString::fromUtf8("savemapButton"));
        savemapButton->setMaximumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/debug/savemap.png"), QSize(), QIcon::Normal, QIcon::Off);
        savemapButton->setIcon(icon3);

        del_layout->addWidget(savemapButton);

        clearAllButton = new QToolButton(frame_3);
        clearAllButton->setObjectName(QString::fromUtf8("clearAllButton"));
        clearAllButton->setMaximumSize(QSize(40, 40));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/debug/clear_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearAllButton->setIcon(icon4);

        del_layout->addWidget(clearAllButton);


        verticalLayout_4->addLayout(del_layout);


        horizontalLayout_3->addWidget(frame_3);

        frame = new QFrame(MapWidgetTool);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(550, 0));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        qml_canvas_layout = new QHBoxLayout();
        qml_canvas_layout->setObjectName(QString::fromUtf8("qml_canvas_layout"));

        gridLayout_2->addLayout(qml_canvas_layout, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(frame);


        verticalLayout_2->addLayout(horizontalLayout_3);

        frame_2 = new QFrame(MapWidgetTool);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
        status_layout = new QHBoxLayout();
        status_layout->setSpacing(3);
        status_layout->setObjectName(QString::fromUtf8("status_layout"));
        status_layout->setSizeConstraint(QLayout::SetMinimumSize);

        horizontalLayout_2->addLayout(status_layout);


        verticalLayout_2->addWidget(frame_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(MapWidgetTool);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(MapWidgetTool);

        QMetaObject::connectSlotsByName(MapWidgetTool);
    } // setupUi

    void retranslateUi(QWidget *MapWidgetTool)
    {
        MapWidgetTool->setWindowTitle(QCoreApplication::translate("MapWidgetTool", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\272\320\260\321\200\321\202\321\213 \320\274\320\265\321\201\321\202\320\275\320\276\321\201\321\202\320\270", nullptr));
#if QT_CONFIG(tooltip)
        optionButton->setToolTip(QCoreApplication::translate("MapWidgetTool", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        optionButton->setText(QString());
#if QT_CONFIG(tooltip)
        addButton->setToolTip(QCoreApplication::translate("MapWidgetTool", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
#endif // QT_CONFIG(tooltip)
        addButton->setText(QCoreApplication::translate("MapWidgetTool", "+", nullptr));
#if QT_CONFIG(tooltip)
        playButton->setToolTip(QCoreApplication::translate("MapWidgetTool", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262", nullptr));
#endif // QT_CONFIG(tooltip)
        playButton->setText(QString());
#if QT_CONFIG(tooltip)
        stopButton->setToolTip(QCoreApplication::translate("MapWidgetTool", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
        stopButton->setText(QString());
#if QT_CONFIG(tooltip)
        savemapButton->setToolTip(QCoreApplication::translate("MapWidgetTool", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\272\320\260\321\200\321\202\321\203 \320\275\320\260 \320\264\320\270\321\201\320\272", nullptr));
#endif // QT_CONFIG(tooltip)
        savemapButton->setText(QString());
#if QT_CONFIG(tooltip)
        clearAllButton->setToolTip(QCoreApplication::translate("MapWidgetTool", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
#endif // QT_CONFIG(tooltip)
        clearAllButton->setText(QString());
        closeButton->setText(QCoreApplication::translate("MapWidgetTool", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapWidgetTool: public Ui_MapWidgetTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWIDGETTOOL_H
