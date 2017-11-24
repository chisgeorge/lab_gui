/********************************************************************************
** Form generated from reading UI file 'lab_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB_GUI_H
#define UI_LAB_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab_guiClass
{
public:
    QAction *actionAdauga_produs;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuEdit;
    QMenu *menuExit;

    void setupUi(QMainWindow *lab_guiClass)
    {
        if (lab_guiClass->objectName().isEmpty())
            lab_guiClass->setObjectName(QStringLiteral("lab_guiClass"));
        lab_guiClass->resize(960, 584);
        actionAdauga_produs = new QAction(lab_guiClass);
        actionAdauga_produs->setObjectName(QStringLiteral("actionAdauga_produs"));
        actionUndo = new QAction(lab_guiClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(lab_guiClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        centralWidget = new QWidget(lab_guiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_5->addWidget(label_3);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_5->addWidget(label);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_5->addWidget(label_2);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_3->addWidget(lineEdit_2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_3->addWidget(lineEdit);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_3->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_3->addWidget(lineEdit_4);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_4);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_6->addWidget(widget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_5->addWidget(pushButton);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout_5->addWidget(stackedWidget);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(pushButton_3);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButton_4 = new QRadioButton(centralWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        horizontalLayout_3->addWidget(radioButton_4);

        radioButton_3 = new QRadioButton(centralWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        horizontalLayout_3->addWidget(radioButton_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_2->addWidget(radioButton_2);

        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_2->addWidget(radioButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);


        horizontalLayout->addLayout(verticalLayout_2);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout->addWidget(tableWidget);


        verticalLayout_6->addLayout(horizontalLayout);

        lab_guiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lab_guiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        lab_guiClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(lab_guiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 960, 26));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName(QStringLiteral("menuExit"));
        lab_guiClass->setMenuBar(menuBar);

        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuExit->menuAction());
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(lab_guiClass);

        QMetaObject::connectSlotsByName(lab_guiClass);
    } // setupUi

    void retranslateUi(QMainWindow *lab_guiClass)
    {
        lab_guiClass->setWindowTitle(QApplication::translate("lab_guiClass", "lab_gui", Q_NULLPTR));
        actionAdauga_produs->setText(QApplication::translate("lab_guiClass", "Adauga produs", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("lab_guiClass", "Undo", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("lab_guiClass", "Redo", Q_NULLPTR));
        label_3->setText(QApplication::translate("lab_guiClass", "Nume", Q_NULLPTR));
        label->setText(QApplication::translate("lab_guiClass", "Tip", Q_NULLPTR));
        label_4->setText(QApplication::translate("lab_guiClass", "Pret", Q_NULLPTR));
        label_2->setText(QApplication::translate("lab_guiClass", "Producator", Q_NULLPTR));
        pushButton->setText(QApplication::translate("lab_guiClass", "Adauga", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("lab_guiClass", "Actualizeaza", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("lab_guiClass", "Sterge", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("lab_guiClass", "Sortare", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("lab_guiClass", "Filtrare", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("lab_guiClass", "Crescator", Q_NULLPTR));
        radioButton->setText(QApplication::translate("lab_guiClass", "Descrescator", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("lab_guiClass", "1.Dupa nume", Q_NULLPTR)
         << QApplication::translate("lab_guiClass", "2.Dupa pret", Q_NULLPTR)
         << QApplication::translate("lab_guiClass", "3.Dupa nume si pret", Q_NULLPTR)
        );
        menuEdit->setTitle(QApplication::translate("lab_guiClass", "Edit", Q_NULLPTR));
        menuExit->setTitle(QApplication::translate("lab_guiClass", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lab_guiClass: public Ui_lab_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB_GUI_H
