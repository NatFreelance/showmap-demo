/********************************************************************************
** Form generated from reading UI file 'addobjectform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOBJECTFORM_H
#define UI_ADDOBJECTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddObjectForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *type_comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *latitude_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *longitude_lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *radius_lineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *altitude_lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *id_checkBox_3;
    QComboBox *station_comboBox;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *id_checkBox;
    QComboBox *copter_comboBox;
    QCheckBox *status_checkBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *closeButton;

    void setupUi(QWidget *AddObjectForm)
    {
        if (AddObjectForm->objectName().isEmpty())
            AddObjectForm->setObjectName(QString::fromUtf8("AddObjectForm"));
        AddObjectForm->resize(469, 462);
        verticalLayout_2 = new QVBoxLayout(AddObjectForm);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        frame = new QFrame(AddObjectForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        type_comboBox = new QComboBox(frame);
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->setObjectName(QString::fromUtf8("type_comboBox"));
        type_comboBox->setMinimumSize(QSize(200, 0));
        type_comboBox->setMaximumSize(QSize(220, 16777215));

        horizontalLayout->addWidget(type_comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        latitude_lineEdit = new QLineEdit(frame);
        latitude_lineEdit->setObjectName(QString::fromUtf8("latitude_lineEdit"));
        latitude_lineEdit->setMinimumSize(QSize(200, 0));
        latitude_lineEdit->setMaximumSize(QSize(220, 16777215));
        latitude_lineEdit->setAutoFillBackground(false);
        latitude_lineEdit->setStyleSheet(QString::fromUtf8(""));
        latitude_lineEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);
        latitude_lineEdit->setMaxLength(8);

        horizontalLayout_3->addWidget(latitude_lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        longitude_lineEdit = new QLineEdit(frame);
        longitude_lineEdit->setObjectName(QString::fromUtf8("longitude_lineEdit"));
        longitude_lineEdit->setMinimumSize(QSize(200, 0));
        longitude_lineEdit->setMaximumSize(QSize(220, 16777215));
        longitude_lineEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);
        longitude_lineEdit->setMaxLength(8);

        horizontalLayout_2->addWidget(longitude_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        radius_lineEdit = new QLineEdit(frame);
        radius_lineEdit->setObjectName(QString::fromUtf8("radius_lineEdit"));
        radius_lineEdit->setMinimumSize(QSize(200, 0));
        radius_lineEdit->setMaximumSize(QSize(220, 16777215));
        radius_lineEdit->setInputMethodHints(Qt::ImhDigitsOnly);
        radius_lineEdit->setMaxLength(6);

        horizontalLayout_4->addWidget(radius_lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        altitude_lineEdit = new QLineEdit(frame);
        altitude_lineEdit->setObjectName(QString::fromUtf8("altitude_lineEdit"));
        altitude_lineEdit->setMinimumSize(QSize(200, 0));
        altitude_lineEdit->setMaximumSize(QSize(220, 16777215));
        altitude_lineEdit->setInputMethodHints(Qt::ImhDigitsOnly);
        altitude_lineEdit->setMaxLength(7);

        horizontalLayout_6->addWidget(altitude_lineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        id_checkBox_3 = new QCheckBox(frame);
        id_checkBox_3->setObjectName(QString::fromUtf8("id_checkBox_3"));

        horizontalLayout_9->addWidget(id_checkBox_3);

        station_comboBox = new QComboBox(frame);
        station_comboBox->setObjectName(QString::fromUtf8("station_comboBox"));
        station_comboBox->setMinimumSize(QSize(200, 0));
        station_comboBox->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_9->addWidget(station_comboBox);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        id_checkBox = new QCheckBox(frame);
        id_checkBox->setObjectName(QString::fromUtf8("id_checkBox"));

        horizontalLayout_7->addWidget(id_checkBox);

        copter_comboBox = new QComboBox(frame);
        copter_comboBox->setObjectName(QString::fromUtf8("copter_comboBox"));
        copter_comboBox->setMinimumSize(QSize(200, 0));
        copter_comboBox->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_7->addWidget(copter_comboBox);


        verticalLayout->addLayout(horizontalLayout_7);

        status_checkBox = new QCheckBox(frame);
        status_checkBox->setObjectName(QString::fromUtf8("status_checkBox"));
        status_checkBox->setChecked(true);

        verticalLayout->addWidget(status_checkBox);


        verticalLayout_2->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        saveButton = new QPushButton(AddObjectForm);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_5->addWidget(saveButton);

        closeButton = new QPushButton(AddObjectForm);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_5->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(AddObjectForm);

        QMetaObject::connectSlotsByName(AddObjectForm);
    } // setupUi

    void retranslateUi(QWidget *AddObjectForm)
    {
        AddObjectForm->setWindowTitle(QCoreApplication::translate("AddObjectForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202 \320\275\320\260 \320\272\320\260\321\200\321\202\321\203", nullptr));
        label->setText(QCoreApplication::translate("AddObjectForm", "\320\242\320\270\320\277 \320\276\320\261\321\212\320\265\320\272\321\202\320\260", nullptr));
        type_comboBox->setItemText(0, QCoreApplication::translate("AddObjectForm", "\320\241\321\202\320\260\320\275\321\206\320\270\321\217", nullptr));
        type_comboBox->setItemText(1, QCoreApplication::translate("AddObjectForm", "\320\221\320\265\321\201\320\277\320\270\320\273\320\276\321\202\320\275\320\270\320\272", nullptr));
        type_comboBox->setItemText(2, QCoreApplication::translate("AddObjectForm", "\320\237\321\203\320\273\321\214\321\202 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));

        label_3->setText(QCoreApplication::translate("AddObjectForm", "\320\250\320\270\321\200\320\276\321\202\320\260,\302\260", nullptr));
        latitude_lineEdit->setText(QCoreApplication::translate("AddObjectForm", "0", nullptr));
        label_2->setText(QCoreApplication::translate("AddObjectForm", "\320\224\320\276\320\273\320\263\320\276\321\202\320\260,\302\260", nullptr));
        longitude_lineEdit->setText(QCoreApplication::translate("AddObjectForm", "0", nullptr));
        label_4->setText(QCoreApplication::translate("AddObjectForm", "\320\240\320\260\320\264\320\270\321\203\321\201 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217, \320\272\320\274", nullptr));
        radius_lineEdit->setText(QCoreApplication::translate("AddObjectForm", "0", nullptr));
        label_5->setText(QCoreApplication::translate("AddObjectForm", "\320\222\321\213\321\201\320\276\321\202\320\260, \320\274", nullptr));
        altitude_lineEdit->setText(QCoreApplication::translate("AddObjectForm", "0", nullptr));
        id_checkBox_3->setText(QCoreApplication::translate("AddObjectForm", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214  \321\201\321\202\320\260\320\275\321\206\320\270\321\216 \320\270\320\267 \321\201\320\277\320\270\321\201\320\272\320\260", nullptr));
        id_checkBox->setText(QCoreApplication::translate("AddObjectForm", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\260\320\277\320\277\320\260\321\200\320\260\321\202 \320\270\320\267 \321\201\320\277\320\270\321\201\320\272\320\260", nullptr));
        status_checkBox->setText(QCoreApplication::translate("AddObjectForm", "\320\236\320\261\321\212\320\265\320\272\321\202 \320\260\320\272\321\202\320\270\320\262\320\265\320\275", nullptr));
        saveButton->setText(QCoreApplication::translate("AddObjectForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        closeButton->setText(QCoreApplication::translate("AddObjectForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddObjectForm: public Ui_AddObjectForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOBJECTFORM_H
