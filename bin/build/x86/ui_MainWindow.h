/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *credBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *recEdit;
    QLineEdit *sendEdit;
    QLineEdit *pwEdit;
    QGroupBox *mailBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *subEdit;
    QTextEdit *msgEdit;
    QGroupBox *sendBox;
    QPushButton *sendBtn;
    QLabel *statusLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 487);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        credBox = new QGroupBox(centralWidget);
        credBox->setObjectName(QString::fromUtf8("credBox"));
        credBox->setGeometry(QRect(10, 10, 380, 111));
        layoutWidget = new QWidget(credBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 361, 80));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        recEdit = new QLineEdit(layoutWidget);
        recEdit->setObjectName(QString::fromUtf8("recEdit"));

        verticalLayout->addWidget(recEdit);

        sendEdit = new QLineEdit(layoutWidget);
        sendEdit->setObjectName(QString::fromUtf8("sendEdit"));

        verticalLayout->addWidget(sendEdit);

        pwEdit = new QLineEdit(layoutWidget);
        pwEdit->setObjectName(QString::fromUtf8("pwEdit"));
        pwEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(pwEdit);

        mailBox = new QGroupBox(centralWidget);
        mailBox->setObjectName(QString::fromUtf8("mailBox"));
        mailBox->setEnabled(true);
        mailBox->setGeometry(QRect(10, 130, 380, 251));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mailBox->sizePolicy().hasHeightForWidth());
        mailBox->setSizePolicy(sizePolicy1);
        mailBox->setMaximumSize(QSize(400, 16777215));
        layoutWidget1 = new QWidget(mailBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 361, 220));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        subEdit = new QLineEdit(layoutWidget1);
        subEdit->setObjectName(QString::fromUtf8("subEdit"));

        verticalLayout_2->addWidget(subEdit);

        msgEdit = new QTextEdit(layoutWidget1);
        msgEdit->setObjectName(QString::fromUtf8("msgEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(msgEdit->sizePolicy().hasHeightForWidth());
        msgEdit->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(msgEdit);

        sendBox = new QGroupBox(centralWidget);
        sendBox->setObjectName(QString::fromUtf8("sendBox"));
        sendBox->setGeometry(QRect(125, 390, 150, 81));
        sendBtn = new QPushButton(sendBox);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setGeometry(QRect(20, 20, 110, 23));
        statusLabel = new QLabel(sendBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(20, 50, 110, 20));
        sizePolicy2.setHeightForWidth(statusLabel->sizePolicy().hasHeightForWidth());
        statusLabel->setSizePolicy(sizePolicy2);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Email Sender", nullptr));
        credBox->setTitle(QApplication::translate("MainWindow", "Credentials", nullptr));
        recEdit->setPlaceholderText(QApplication::translate("MainWindow", "Receiver: ", nullptr));
        sendEdit->setPlaceholderText(QApplication::translate("MainWindow", "Username: ", nullptr));
        pwEdit->setPlaceholderText(QApplication::translate("MainWindow", "Password: ", nullptr));
        mailBox->setTitle(QApplication::translate("MainWindow", "Mail", nullptr));
        subEdit->setPlaceholderText(QApplication::translate("MainWindow", "Subject:", nullptr));
        msgEdit->setPlaceholderText(QApplication::translate("MainWindow", "Message:", nullptr));
        sendBox->setTitle(QString());
        sendBtn->setText(QApplication::translate("MainWindow", "Send", nullptr));
        statusLabel->setText(QApplication::translate("MainWindow", "Status: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
