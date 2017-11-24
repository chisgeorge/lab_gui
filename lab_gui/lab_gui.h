#pragma once
#include <QtWidgets/QMainWindow>
#include "product.h"
#include "controller.h"
#include "gui_elements.h"

class gui : public QMainWindow , public Observable
{
	Q_OBJECT
	gui_elements ui_elements;
	void set_connections();
public:
	 Controller<std::vector<Product>>& controller;
	 explicit gui(Controller<std::vector<Product>>& controller,QWidget *parent = nullptr): QMainWindow(parent), controller {controller}
	 {
		 controller.random_populate(20);
		 ui_elements.setup(this);
		 ui_elements.update_table(controller.get_list());
		 ui_elements.update_table_cos(controller.get_cos());
		 set_connections();
	 };
	void add_product();
	void update_product();
	void prepare_update_product();
	void delete_product();
	void filter_sort();
	void clear_fields(int stacked);
	void validate_fields(int stacked);
	void notify() override
	{
		Observable::notify();
		ui_elements.update_table_cos(controller.get_cos());
	}
};

class CosGRUDGUI : public QWidget, public Observer
{
	gui *parent_main;
	QTableView* display_table;
	QHBoxLayout* layout;
	Table_Model* model;
	QPushButton* buttonPopulate;
	QPushButton* golesteCos;
	QLineEdit* lineEditPopulate;
	QVBoxLayout* secondLayout;
	void set_connections();
public:
	CosGRUDGUI(gui *parent = nullptr) : QWidget(parent, Qt::Window), parent_main{ parent } {
		if (parent_main != nullptr)
		{
			//this->setWindowModality()
			model = new Table_Model{ parent_main->controller.get_cos() };
			parent_main->add_observer(this);
		}
		else
		{
			model = new Table_Model{std::vector<Product>()};
		}
		this->resize(640, 360);
		this->setMinimumSize(320, 240);
		display_table = new QTableView;
		display_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		display_table->setSelectionBehavior(QAbstractItemView::SelectRows);
		display_table->setSelectionMode(QAbstractItemView::SingleSelection);
		layout = new QHBoxLayout(this);
		secondLayout = new QVBoxLayout;
		buttonPopulate = new QPushButton("Populeaza cos");
		golesteCos = new QPushButton("Goleste cos");
		lineEditPopulate = new QLineEdit; lineEditPopulate->setPlaceholderText("Introduceti numarul");
		set_connections();
		update_table();
		secondLayout->addStretch();
		secondLayout->addWidget(lineEditPopulate);
		secondLayout->addWidget(buttonPopulate);
		secondLayout->addWidget(golesteCos);
		layout->addWidget(display_table,2);
		layout->addLayout(secondLayout);
	}
	void update_table();
	void update() override;
};
class CosPaint : public QWidget, public Observer {
	gui *parent_main;
public:
	CosPaint(gui* parent = nullptr) : QWidget(parent, Qt::Window), parent_main{ parent }
	{
		this->resize(640, 360);
		this->setMinimumSize(320, 240);
		if(parent != nullptr)
			parent_main->add_observer(this);
	}
	void paintEvent(QPaintEvent* ev) override {
		QPainter p{ this };
		p.setBrush(Qt::red);
		std::mt19937 mt{ std::random_device{}() };
		std::uniform_int_distribution<> dist(0, width() - 30);
		std::uniform_int_distribution<> dist2(0, height() - 30);

		for (auto el : parent_main->controller.get_cos()) {
			p.fillRect(dist(mt), dist2(mt), 30, 30, Qt::red);
		}

	}
	void update() override {
		QWidget::update();
	}
};