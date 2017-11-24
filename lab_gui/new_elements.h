#pragma once

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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class gui_elements
{
public:
	QMenuBar *menu_bar;
	QMenu *menuEdit, *menuExit;
	QAction *actionUndo,*actionRedo;
	QWidget *central_widget;
	QVBoxLayout *vLayout_sort_filter, *vLayout_lineEdits, *vLayout_labels, *vLayout_central;
	QHBoxLayout *hLayout_display, *hLayout_asc_desc, *hLayout_sort_filter, *hLayout_lineEdits, *hLayout_buttons;
	QLabel *label_name, *label_type, *label_price, *label_prod;
	QSpacerItem *horizontalSpacer;
	QLineEdit *lineEdit_name, *lineEdit_type, *lineEdit_price, *lineEdit_prod;
	QPushButton *button_add, *button_update, *button_delete;
	QRadioButton *radio_desc, *radio_asc, *radio_filter, *radio_sort;
	QComboBox *comboBox;
	QTableWidget *display_table;
	QStatusBar *status_bar;
	

	void setup(QMainWindow *window)
	{
		window->resize(960, 584);
		actionUndo = new QAction(window);
		//actionUndo->setObjectName(QStringLiteral("actionUndo"));
		actionRedo = new QAction(window);
		//actionRedo->setObjectName(QStringLiteral("actionRedo"));
		central_widget = new QWidget(window);
		//central_widget->setObjectName(QStringLiteral("centralWidget"));
		vLayout_central = new QVBoxLayout(central_widget);
		vLayout_central->setSpacing(6);
		//vLayout_central->setContentsMargins(11, 11, 11, 11);
		//vLayout_central->setObjectName(QStringLiteral("verticalLayout_6"));
		hLayout_lineEdits = new QHBoxLayout();
		hLayout_lineEdits->setSpacing(6);
		//hLayout_lineEdits->setObjectName(QStringLiteral("horizontalLayout_4"));
		vLayout_labels = new QVBoxLayout();
		vLayout_labels->setSpacing(6);
		//vLayout_labels->setObjectName(QStringLiteral("verticalLayout_5"));
		label_name = new QLabel(central_widget);
		//label_name->setObjectName(QStringLiteral("label_3"));

		vLayout_labels->addWidget(label_name);

		label_type = new QLabel(central_widget);
		//label_type->setObjectName(QStringLiteral("label"));

		vLayout_labels->addWidget(label_type);

		label_price = new QLabel(central_widget);
		//label_price->setObjectName(QStringLiteral("label_4"));

		vLayout_labels->addWidget(label_price);

		label_prod = new QLabel(central_widget);
		//label_prod->setObjectName(QStringLiteral("label_2"));

		vLayout_labels->addWidget(label_prod);


		hLayout_lineEdits->addLayout(vLayout_labels);

		horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

		hLayout_lineEdits->addItem(horizontalSpacer);

		vLayout_lineEdits = new QVBoxLayout();
		vLayout_lineEdits->setSpacing(6);
		//vLayout_lineEdits->setObjectName(QStringLiteral("verticalLayout_3"));
		lineEdit_name = new QLineEdit(central_widget);
		//lineEdit_name->setObjectName(QStringLiteral("lineEdit"));

		vLayout_lineEdits->addWidget(lineEdit_name);

		lineEdit_type = new QLineEdit(central_widget);
		//lineEdit_type->setObjectName(QStringLiteral("lineEdit_2"));

		vLayout_lineEdits->addWidget(lineEdit_type);

		lineEdit_price = new QLineEdit(central_widget);
		//lineEdit_price->setObjectName(QStringLiteral("lineEdit_3"));

		vLayout_lineEdits->addWidget(lineEdit_price);

		lineEdit_prod = new QLineEdit(central_widget);
		//lineEdit_prod->setObjectName(QStringLiteral("lineEdit_4"));

		vLayout_lineEdits->addWidget(lineEdit_prod);


		hLayout_lineEdits->addLayout(vLayout_lineEdits);


		vLayout_central->addLayout(hLayout_lineEdits);

		hLayout_buttons = new QHBoxLayout();
		hLayout_buttons->setSpacing(6);
		//hLayout_buttons->setObjectName(QStringLiteral("horizontalLayout_5"));
		button_add = new QPushButton(central_widget);
		//button_add->setObjectName(QStringLiteral("pushButton"));

		hLayout_buttons->addWidget(button_add);

		button_update = new QPushButton(central_widget);
		//button_update->setObjectName(QStringLiteral("pushButton_2"));

		hLayout_buttons->addWidget(button_update);

		button_delete = new QPushButton(central_widget);
		//button_delete->setObjectName(QStringLiteral("pushButton_3"));

		hLayout_buttons->addWidget(button_delete);


		vLayout_central->addLayout(hLayout_buttons);

		hLayout_display = new QHBoxLayout();
		hLayout_display->setSpacing(6);
		//hLayout_display->setObjectName(QStringLiteral("horizontalLayout"));
		hLayout_display->setSizeConstraint(QLayout::SetDefaultConstraint);
		vLayout_sort_filter = new QVBoxLayout();
		vLayout_sort_filter->setSpacing(6);
		//vLayout_sort_filter->setObjectName(QStringLiteral("verticalLayout_2"));
		hLayout_sort_filter = new QHBoxLayout();
		hLayout_sort_filter->setSpacing(6);
		//hLayout_sort_filter->setObjectName(QStringLiteral("horizontalLayout_3"));
		radio_sort = new QRadioButton(central_widget);
		//radio_sort->setObjectName(QStringLiteral("radioButton_4"));

		hLayout_sort_filter->addWidget(radio_sort);

		radio_filter = new QRadioButton(central_widget);
		//radio_filter->setObjectName(QStringLiteral("radioButton_3"));

		hLayout_sort_filter->addWidget(radio_filter);


		vLayout_sort_filter->addLayout(hLayout_sort_filter);

		hLayout_asc_desc = new QHBoxLayout();
		hLayout_asc_desc->setSpacing(6);
		//hLayout_asc_desc->setObjectName(QStringLiteral("horizontalLayout_2"));
		radio_asc = new QRadioButton(central_widget);
		//radio_asc->setObjectName(QStringLiteral("radioButton_2"));

		hLayout_asc_desc->addWidget(radio_asc);

		radio_desc = new QRadioButton(central_widget);
		//radio_desc->setObjectName(QStringLiteral("radioButton"));

		hLayout_asc_desc->addWidget(radio_desc);


		vLayout_sort_filter->addLayout(hLayout_asc_desc);

		comboBox = new QComboBox(central_widget);
		comboBox->clear();
		comboBox->insertItems(0, QStringList()
			<< "1.Dupa nume"
			<< "2.Dupa pret"
			<< "3.Dupa nume si pret"
		);
		//comboBox->setObjectName(QStringLiteral("comboBox"));

		vLayout_sort_filter->addWidget(comboBox);


		hLayout_display->addLayout(vLayout_sort_filter);

		display_table = new QTableWidget(central_widget);
		//display_table->setObjectName(QStringLiteral("tableWidget"));

		hLayout_display->addWidget(display_table);


		vLayout_central->addLayout(hLayout_display);

		window->setCentralWidget(central_widget);
		status_bar = new QStatusBar(window);
		//status_bar->setObjectName(QStringLiteral("statusBar"));
		window->setStatusBar(status_bar);
		menu_bar = new QMenuBar(window);
		//menu_bar->setObjectName(QStringLiteral("menuBar"));
		menu_bar->setGeometry(QRect(0, 0, 960, 26));
		menuEdit = new QMenu(menu_bar);
		//menuEdit->setObjectName(QStringLiteral("menuEdit"));
		menuExit = new QMenu(menu_bar);
		//menuExit->setObjectName(QStringLiteral("menuExit"));
		window->setMenuBar(menu_bar);

		menu_bar->addAction(menuEdit->menuAction());
		menu_bar->addAction(menuExit->menuAction());
		actionUndo->setIcon(QIcon("undo-arrow.png"));
		actionRedo->setIcon(QIcon("redo-arrow.png"));
		menuEdit->addAction(actionUndo);
		menuEdit->addAction(actionRedo);

		//retranslateUi(window);

		QMetaObject::connectSlotsByName(window);
	} // setupUi

	void retranslateUi(QMainWindow *lab_guiClass)
	{
		lab_guiClass->setWindowTitle(QApplication::translate("lab_guiClass", "lab_gui", Q_NULLPTR));
		actionUndo->setText(QApplication::translate("lab_guiClass", "Undo", Q_NULLPTR));
		actionRedo->setText(QApplication::translate("lab_guiClass", "Redo", Q_NULLPTR));
		label_name->setText(QApplication::translate("lab_guiClass", "Nume", Q_NULLPTR));
		label_type->setText(QApplication::translate("lab_guiClass", "Tip", Q_NULLPTR));
		label_price->setText(QApplication::translate("lab_guiClass", "Pret", Q_NULLPTR));
		label_prod->setText(QApplication::translate("lab_guiClass", "Producator", Q_NULLPTR));
		button_add->setText(QApplication::translate("lab_guiClass", "Adauga", Q_NULLPTR));
		button_update->setText(QApplication::translate("lab_guiClass", "Actualizeaza", Q_NULLPTR));
		button_delete->setText(QApplication::translate("lab_guiClass", "Sterge", Q_NULLPTR));
		radio_sort->setText(QApplication::translate("lab_guiClass", "Sortare", Q_NULLPTR));
		radio_filter->setText(QApplication::translate("lab_guiClass", "Filtrare", Q_NULLPTR));
		radio_asc->setText(QApplication::translate("lab_guiClass", "Crescator", Q_NULLPTR));
		radio_desc->setText(QApplication::translate("lab_guiClass", "Descrescator", Q_NULLPTR));
		
		menuEdit->setTitle(QApplication::translate("lab_guiClass", "Edit", Q_NULLPTR));
		menuExit->setTitle(QApplication::translate("lab_guiClass", "Exit", Q_NULLPTR));
	} // retranslateUi

};

QT_END_NAMESPACE

#endif // UI_LAB_GUI_H

