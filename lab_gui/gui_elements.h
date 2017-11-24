#pragma once

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
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QPainter>

QT_BEGIN_NAMESPACE

class Table_Model : public QAbstractTableModel
{
	const std::vector<Product>& all;
public:
	Table_Model(const std::vector<Product>& all) : all{ all } {}
	int rowCount(const QModelIndex &index) const override {
		return all.size();
	}
	int columnCount(const QModelIndex &index)const override {
		return 4;
	}
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
		if (role == Qt::DisplayRole) {
			if (orientation == Qt::Horizontal) {
				if (section == 0)
					return QString("Nume");
				if (section == 1)
					return QString("Tip");
				if (section == 2)
					return QString("Pret");
				if (section == 3)
					return QString("Producator");
			}
			else {
				return QString("%1").arg(section+1);
			}
		}
		return QVariant();
	}
	QVariant data(const QModelIndex &index, int role) const {
		int row = index.row();
		int column = index.column();
		if (role == Qt::DisplayRole) {
			if (column == 0)
				return QString::fromStdString(all[row].get_name());
			if (column == 1)
				return QString::fromStdString(all[row].get_type());
			if (column == 2)
				return QString::number(all[row].get_price());
			if (column == 3)
				return QString::fromStdString(all[row].get_producer());
		}
		return QVariant();
	}
};

class gui_elements
{
public:
	QMenuBar *menu_bar;
	QMenu *menuEdit, *menuExit;
	QAction *actionUndo,*actionRedo;
	QWidget *central_widget;
	QVBoxLayout *vLayout_sort_filter, *vLayout_lineEdits, *vLayout_central, *vLayout_labels;
	QHBoxLayout *hLayout_display, *hLayout_asc_desc, *hLayout_sort_filter, *hLayout_lineEdits, *hLayout_buttons, *hLayout_filter_by, *hLayout_buttons_cos;
	QLabel *label_name, *label_type, *label_price, *label_prod;
	QLineEdit *lineEdit_name[2], *lineEdit_type[2], *lineEdit_price[2], *lineEdit_prod[2], *lineEdit_filter_by, *lineEdit_populate, *lineEdit_export;
	QPushButton *button_add, *button_update[2], *button_delete, *button_filter,*button_add_cos, *button_populate, *button_clear, *button_addw_crud, *button_addw_paint;
	QRadioButton *radio_desc, *radio_asc, *radio_filter, *radio_sort;
	QStackedWidget *stacked_update, *stacked_update_lineEdits[4];
	QButtonGroup *bGroup_asc_desc, *bGroup_sort_filter;
	QComboBox *comboBox;
	QTableWidget *display_table;
	QTableView *cos_table;
	QStatusBar *status_bar;
	Table_Model *model;
	QTableView *display_table_cos;

	void setup(QMainWindow *window)
	{
		window->resize(960, 540);
		window->setMinimumSize(640, 360);
		
		actionUndo = new QAction(window);
		actionRedo = new QAction(window);

		central_widget = new QWidget(window);
		vLayout_central = new QVBoxLayout(central_widget);
		vLayout_central->setSpacing(7);

		hLayout_lineEdits = new QHBoxLayout();
		hLayout_lineEdits->setSpacing(7);
		vLayout_labels = new QVBoxLayout();
		vLayout_labels->setSpacing(7);

		label_name = new QLabel(central_widget);
		vLayout_labels->addWidget(label_name);

		label_type = new QLabel(central_widget);
		vLayout_labels->addWidget(label_type);

		label_price = new QLabel(central_widget);
		vLayout_labels->addWidget(label_price);

		label_prod = new QLabel(central_widget);
		vLayout_labels->addWidget(label_prod);


		hLayout_lineEdits->addLayout(vLayout_labels);
		hLayout_lineEdits->addItem(new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum));
		vLayout_lineEdits = new QVBoxLayout();
		vLayout_lineEdits->setSpacing(7);

		stacked_update_lineEdits[0] = new QStackedWidget();
		lineEdit_name[0] = new QLineEdit(central_widget);
		stacked_update_lineEdits[0]->addWidget(lineEdit_name[0]);

		stacked_update_lineEdits[1] = new QStackedWidget();
		lineEdit_type[0] = new QLineEdit(central_widget);
		stacked_update_lineEdits[1]->addWidget(lineEdit_type[0]);
		stacked_update_lineEdits[2] = new QStackedWidget();
		lineEdit_price[0] = new QLineEdit(central_widget);
		stacked_update_lineEdits[2]->addWidget(lineEdit_price[0]);
		stacked_update_lineEdits[3] = new QStackedWidget();
		lineEdit_prod[0] = new QLineEdit(central_widget);
		stacked_update_lineEdits[3]->addWidget(lineEdit_prod[0]);
		lineEdit_name[1] = new QLineEdit(central_widget);
		stacked_update_lineEdits[0]->addWidget(lineEdit_name[1]);
		lineEdit_type[1] = new QLineEdit(central_widget);
		stacked_update_lineEdits[1]->addWidget(lineEdit_type[1]);
		lineEdit_price[1] = new QLineEdit(central_widget);
		stacked_update_lineEdits[2]->addWidget(lineEdit_price[1]);
		lineEdit_prod[1] = new QLineEdit(central_widget);
		stacked_update_lineEdits[3]->addWidget(lineEdit_prod[1]);

		stacked_update_lineEdits[0]->setMaximumSize(16777215, 22);
		stacked_update_lineEdits[1]->setMaximumSize(16777215, 22);
		stacked_update_lineEdits[2]->setMaximumSize(16777215, 22);
		stacked_update_lineEdits[3]->setMaximumSize(16777215, 22);

		vLayout_lineEdits->addWidget(stacked_update_lineEdits[0]);
		vLayout_lineEdits->addWidget(stacked_update_lineEdits[1]);
		vLayout_lineEdits->addWidget(stacked_update_lineEdits[2]);
		vLayout_lineEdits->addWidget(stacked_update_lineEdits[3]);

		
		hLayout_lineEdits->addLayout(vLayout_lineEdits);


		vLayout_central->addLayout(hLayout_lineEdits);

		hLayout_buttons = new QHBoxLayout();
		hLayout_buttons->setSpacing(7);

		button_add = new QPushButton(central_widget);
		button_add->setIcon(QIcon("add.png"));
		button_add->setMaximumSize(123, 28);
		
		hLayout_buttons->addStretch();
		hLayout_buttons->addWidget(button_add);

		button_update[0] = new QPushButton(central_widget);
		button_update[0]->setMaximumSize(123, 28);
		button_update[0]->setIcon(QIcon("update-arrows.png"));
		button_update[1] = new QPushButton(central_widget);
		button_update[1]->setIcon(QIcon("update-arrows2.png"));
		button_update[1]->setMaximumSize(123, 28);
		stacked_update = new QStackedWidget(central_widget);
		stacked_update->addWidget(button_update[0]);
		stacked_update->addWidget(button_update[1]);
		stacked_update->setMaximumSize(123, 28);
		//button_update[1]->setStyleSheet("background-color: green");
		hLayout_buttons->addWidget(stacked_update);
		//stacked_update->setCurrentIndex(1);
		button_delete = new QPushButton(central_widget);
		button_delete->setIcon(QIcon("cancel.png"));
		button_delete->setMaximumSize(123, 28);
		
		hLayout_buttons->addWidget(button_delete);


		vLayout_central->addLayout(hLayout_buttons);

		hLayout_display = new QHBoxLayout();
		hLayout_display->setSpacing(7);
		
		vLayout_sort_filter = new QVBoxLayout();
		vLayout_sort_filter->setSpacing(7);
		

		display_table_cos = new QTableView;
		display_table_cos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		display_table_cos->setSelectionBehavior(QAbstractItemView::SelectRows);
		display_table_cos->setSelectionMode(QAbstractItemView::SingleSelection);
		vLayout_sort_filter->addWidget(display_table_cos);

		button_add_cos = new QPushButton(central_widget);
		button_populate = new QPushButton(central_widget);
		button_clear = new QPushButton(central_widget);
		button_addw_crud = new QPushButton(central_widget);
		button_addw_crud->setIcon(QIcon("plus.png"));
		button_addw_paint = new QPushButton(central_widget);
		button_addw_paint->setIcon(QIcon("plus.png"));

		hLayout_buttons_cos = new QHBoxLayout();
		//hLayout_buttons_cos->addStretch();
		hLayout_buttons_cos->addWidget(button_add_cos);
		hLayout_buttons_cos->addWidget(button_populate);
		hLayout_buttons_cos->addWidget(button_clear);
		hLayout_buttons_cos->addWidget(button_addw_crud);
		hLayout_buttons_cos->addWidget(button_addw_paint);
		lineEdit_populate = new QLineEdit;
		vLayout_sort_filter->addWidget(lineEdit_populate);
		//vLayout_sort_filter->addWidget();
		vLayout_sort_filter->addLayout(hLayout_buttons_cos);
		
		vLayout_sort_filter->addStretch();
		hLayout_sort_filter = new QHBoxLayout();
		hLayout_sort_filter->setSpacing(7);
		
		bGroup_sort_filter = new QButtonGroup();
		radio_sort = new QRadioButton(central_widget);
		radio_sort->setChecked(true);
		hLayout_sort_filter->addWidget(radio_sort);
		
		radio_filter = new QRadioButton(central_widget);
		
		bGroup_sort_filter->addButton(radio_sort);
		bGroup_sort_filter->addButton(radio_filter);

		hLayout_sort_filter->addItem(new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum));
		hLayout_sort_filter->addWidget(radio_filter);

		vLayout_sort_filter->addLayout(hLayout_sort_filter);

		hLayout_asc_desc = new QHBoxLayout();
		hLayout_asc_desc->setSpacing(7);
		
		radio_asc = new QRadioButton(central_widget);
		radio_asc->setChecked(true);
		bGroup_asc_desc = new QButtonGroup();

		hLayout_asc_desc->addWidget(radio_asc);
		hLayout_sort_filter->addItem(new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum));
		
		radio_desc = new QRadioButton(central_widget);
		hLayout_asc_desc->addWidget(radio_desc);

		bGroup_asc_desc->addButton(radio_asc);
		bGroup_asc_desc->addButton(radio_desc);

		vLayout_sort_filter->addLayout(hLayout_asc_desc);
		hLayout_filter_by = new QHBoxLayout();
		lineEdit_filter_by = new QLineEdit(central_widget);
		lineEdit_filter_by->setEnabled(false);
		hLayout_filter_by->addWidget(lineEdit_filter_by);
		button_filter = new QPushButton(central_widget);
		button_filter->setIcon(QIcon("filter.png"));
		button_filter->setMaximumSize(123, 22);
		button_filter->setEnabled(false);
		hLayout_filter_by->addWidget(button_filter);
		vLayout_sort_filter->addLayout(hLayout_filter_by);
		comboBox = new QComboBox();

		vLayout_sort_filter->addWidget(comboBox);
		
		hLayout_display->addLayout(vLayout_sort_filter);

		display_table = new QTableWidget(central_widget);
		display_table->setColumnCount(4);
		display_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
		display_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
		display_table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
		display_table->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
		display_table->setSelectionBehavior(QAbstractItemView::SelectRows);
		display_table->setSelectionMode(QAbstractItemView::SingleSelection);
		display_table->setHorizontalHeaderLabels(QString("Nume;Tip;Pret;Producator").split(";"));
		hLayout_display->addWidget(display_table);

		vLayout_central->addLayout(hLayout_display);
		window->setCentralWidget(central_widget);
		status_bar = new QStatusBar(window);

		window->setStatusBar(status_bar);
		menu_bar = new QMenuBar(window);

		menu_bar->setGeometry(QRect(0, 0, 960, 26));
		menuEdit = new QMenu(menu_bar);
		menuEdit->setTitle("Edit");

		menuExit = new QMenu(menu_bar);
		menuEdit->setTitle("Exit");

		window->setMenuBar(menu_bar);

		menu_bar->addAction(menuEdit->menuAction());
		menu_bar->addAction(menuExit->menuAction());
		actionUndo->setIcon(QIcon("undo-arrow.png"));
		actionRedo->setIcon(QIcon("redo-arrow.png"));
		menuEdit->addAction(actionUndo);
		menuEdit->addAction(actionRedo);

		display_text(window);

		
	}
	void display_text(QMainWindow *window)
	{
		window->setWindowTitle("Graphic UI");
		actionUndo->setText("Undo");
		actionRedo->setText("Redo");
		label_price->setText("Nume");
		label_name->setText("Tip");
		label_prod->setText("Pret");
		label_type->setText("Producator");
		lineEdit_name[0]->setPlaceholderText("Introduceti numele");
		lineEdit_type[0]->setPlaceholderText("Introduceti tipul");
		lineEdit_price[0]->setPlaceholderText("Introduceti pretul");
		lineEdit_prod[0]->setPlaceholderText("Introduceti producatorul");
		lineEdit_name[1]->setPlaceholderText("Introduceti numele");
		lineEdit_type[1]->setPlaceholderText("Introduceti tipul");
		lineEdit_price[1]->setPlaceholderText("Introduceti pretul");
		lineEdit_prod[1]->setPlaceholderText("Introduceti producatorul");
		lineEdit_populate->setPlaceholderText("Introduceti numarul cu cat sa se populeze");
		button_add->setText("Adauga");
		button_update[0]->setText("Actualizeaza");
		button_update[1]->setText("Actualizeaza");
		button_delete->setText("Sterge");
		button_filter->setText("Filtreaza");
		radio_sort->setText("Sortare");
		radio_filter->setText("Filtrare");
		radio_asc->setText("Crescator");
		radio_desc->setText("Descrescator");
		button_add_cos->setText("Adauga in cos");
		button_populate->setText("Populeaza");
		button_clear->setText("Goleste");
		button_addw_crud->setText("Windnow CRUD");
		button_addw_paint->setText("Window Paint");
		comboBox->clear();
		comboBox->addItems(QStringList()
			<< "0.Nimic"
			<< "1.Dupa nume"
			<< "2.Dupa pret"
			<< "3.Dupa nume si pret"
		);
		menuEdit->setTitle("Edit");
		menuExit->setTitle("Exit");
	}

	void update_table(std::vector<Product> products) const
	{
		int count_rows = display_table->rowCount();
		int row = 0;
		for (auto& product : products) {
			if(row>=count_rows)
				add_row_table(row);
			display_table->item(row, 0)->setText(QString::fromStdString(product.get_name()));
			display_table->item(row, 1)->setText(QString::fromStdString(product.get_type()));
			display_table->item(row, 2)->setText(QString::number(product.get_price()));
			display_table->item(row, 3)->setText(QString::fromStdString(product.get_producer()));
			row++;
		}
		if (count_rows > row)
			while (count_rows >= row)
			{
				display_table->removeRow(count_rows);
				count_rows--;
			}
		
	}
	void add_row_table(int row) const
	{
		display_table->insertRow(row);
		QTableWidgetItem *item0 = new QTableWidgetItem();
		item0->setTextAlignment(Qt::AlignRight| Qt::AlignVCenter);
		item0->setFlags(item0->flags() ^ Qt::ItemIsEditable);
		display_table->setItem(row, 0, item0);

		QTableWidgetItem *item1 = new QTableWidgetItem();
		item1->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		item1->setFlags(item1->flags() ^ Qt::ItemIsEditable);
		display_table->setItem(row, 1, item1);

		QTableWidgetItem *item2 = new QTableWidgetItem();
		item2->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		item2->setFlags(item2->flags() ^ Qt::ItemIsEditable);
		display_table->setItem(row, 2, item2);

		QTableWidgetItem *item3 = new QTableWidgetItem();
		item3->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		item3->setFlags(item3->flags() ^ Qt::ItemIsEditable);
		display_table->setItem(row, 3, item3);
	}

	void update_lineEdits()
	{
		int row = display_table->currentRow();
		lineEdit_name[0]->setText(display_table->item(row, 0)->text());
		lineEdit_type[0]->setText(display_table->item(row, 1)->text());
		lineEdit_price[0]->setText(display_table->item(row, 2)->text());
		lineEdit_prod[0]->setText(display_table->item(row, 3)->text());

	}
	void update_lineEdits_cos()
	{
		auto row = display_table_cos->selectionModel()->selectedIndexes();
		lineEdit_name[0]->setText(display_table_cos->model()->data(row[0]).toString());
		lineEdit_type[0]->setText(display_table_cos->model()->data(row[1]).toString());
		lineEdit_price[0]->setText(display_table_cos->model()->data(row[2]).toString());
		lineEdit_prod[0]->setText(display_table_cos->model()->data(row[3]).toString());
	}
	void update_table_cos(const std::vector<Product>& products)
	{
		model = new Table_Model{ products };
		display_table_cos->setModel(model);
	}
};
QT_END_NAMESPACE
