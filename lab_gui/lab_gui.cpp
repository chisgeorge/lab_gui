#include "lab_gui.h"

void gui::set_connections()
{
	connect(ui_elements.button_add, &QPushButton::clicked, [&]() {
		add_product();
	});

	connect(ui_elements.button_update[0], &QPushButton::clicked, [&]() {
		prepare_update_product();
	});
	connect(ui_elements.button_update[1], &QPushButton::clicked, [&]() {
		update_product();
	});

	connect(ui_elements.button_delete, &QPushButton::clicked, [&]() {
		delete_product();
	});

	connect(ui_elements.actionUndo, &QAction::triggered, [&]() {
		try {
			controller.undo();
			ui_elements.update_table(controller.get_list());
		}
		catch (Undo_Redo_Exception& exception)
		{
			ui_elements.status_bar->showMessage(QString::fromStdString(exception.get_msg()), 3000);
		}
	});

	connect(ui_elements.actionRedo, &QAction::triggered, [&]() {
		try {
			controller.redo();
			ui_elements.update_table(controller.get_list());
		}
		catch (Undo_Redo_Exception& exception)
		{
			ui_elements.status_bar->showMessage(QString::fromStdString(exception.get_msg()), 3000);
		}
	});

	connect(ui_elements.display_table, &QTableWidget::itemClicked, [&]() {
		ui_elements.update_lineEdits();
	});
	
	QItemSelectionModel *sm = ui_elements.display_table_cos->selectionModel();
	connect(sm, &QItemSelectionModel::selectionChanged,[&]()
	{
		ui_elements.update_lineEdits_cos();
	});
	connect(ui_elements.radio_sort, &QRadioButton::toggled, [&]()
	{
		ui_elements.radio_asc->setEnabled(true);
		ui_elements.radio_desc->setEnabled(true);
		ui_elements.lineEdit_filter_by->setEnabled(false);
		ui_elements.button_filter->setEnabled(false);
		ui_elements.comboBox->setItemText(3, "3.Dupa nume si pret");
		filter_sort();
	});
	connect(ui_elements.radio_filter, &QRadioButton::toggled, [&]()
	{
		ui_elements.lineEdit_filter_by->setEnabled(true);
		ui_elements.button_filter->setEnabled(true);
		ui_elements.radio_asc->setEnabled(false);
		ui_elements.radio_desc->setEnabled(false);
		ui_elements.comboBox->setItemText(3, "3.Dupa producator");
	});
	connect(ui_elements.radio_asc, &QRadioButton::toggled, [&]()
	{
		filter_sort();
	});
	connect(ui_elements.radio_desc, &QRadioButton::toggled, [&]()
	{
		filter_sort();
	});
	connect(ui_elements.button_filter, &QPushButton::clicked, [&]()
	{
		filter_sort();
	});
	connect(ui_elements.comboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [&]()
	{
		filter_sort();
	});
	connect(ui_elements.button_add_cos, &QPushButton::clicked, [&]() {
		controller.add_cos(ui_elements.lineEdit_name[0]->text().toStdString());
		ui_elements.status_bar->showMessage("Produsul a fost adugat in cos cu succes!", 3000);
		notify();
	});
	connect(ui_elements.button_clear, &QPushButton::clicked, [&]() {
		controller.erase_cos();
		ui_elements.status_bar->showMessage("Cosul a fost golit cu succes!", 3000);
		notify();
	});
	connect(ui_elements.button_populate, &QPushButton::clicked, [&]() {
		int how_much = ui_elements.lineEdit_populate->text().toInt();
		controller.random_populate(how_much);
		notify();
	});
	connect(ui_elements.button_addw_crud, &QPushButton::clicked, [&]() {
		CosGRUDGUI *widget = new CosGRUDGUI{ this };
		widget->show();
	});
	connect(ui_elements.button_addw_paint, &QPushButton::clicked, [&]() {
		CosPaint *widget = new CosPaint{ this };
		widget->show();
	});
}
void gui::add_product()
{
	try
	{
		validate_fields(0);
		controller.add_prod(ui_elements.lineEdit_name[0]->text().toStdString(), ui_elements.lineEdit_type[0]->text().toStdString(), ui_elements.lineEdit_price[0]->text().toDouble(), ui_elements.lineEdit_prod[0]->text().toStdString());
		ui_elements.status_bar->showMessage("Produsul a fost adugat cu succes!", 3000);
		ui_elements.update_table(controller.get_list());
	}
	catch(Repository_Exception& exception)
	{
		QMessageBox *error = new QMessageBox();
		error->setWindowTitle("Eroare");
		error->setText(exception.get_msg().c_str());
		error->exec();
	}
	clear_fields(0);
}

void gui::update_product()
{
	try
	{
		validate_fields(1);
		controller.update_prod(ui_elements.lineEdit_name[0]->text().toStdString(), ui_elements.lineEdit_type[0]->text().toStdString(), ui_elements.lineEdit_price[0]->text().toDouble(), ui_elements.lineEdit_prod[0]->text().toStdString(), ui_elements.lineEdit_name[1]->text().toStdString(), ui_elements.lineEdit_type[1]->text().toStdString(), ui_elements.lineEdit_price[1]->text().toDouble(), ui_elements.lineEdit_prod[1]->text().toStdString());
		ui_elements.status_bar->showMessage("Produsul a fost actualizat cu succes!", 3000);
		ui_elements.update_table(controller.get_list());
	}
	catch (Repository_Exception& exception)
	{
		QMessageBox *error = new QMessageBox();
		error->setWindowTitle("Eroare");
		error->setText(exception.get_msg().c_str());
		error->exec();
	}
	ui_elements.button_add->setEnabled(true);
	ui_elements.button_delete->setEnabled(true);
	ui_elements.stacked_update_lineEdits[0]->setCurrentIndex(0);
	ui_elements.stacked_update_lineEdits[1]->setCurrentIndex(0);
	ui_elements.stacked_update_lineEdits[2]->setCurrentIndex(0);
	ui_elements.stacked_update_lineEdits[3]->setCurrentIndex(0);
	ui_elements.stacked_update->setCurrentIndex(0);
	clear_fields(0);
	clear_fields(1);
}

void gui::prepare_update_product()
{
	try {
		validate_fields(0);
		ui_elements.lineEdit_name[1]->setText(ui_elements.lineEdit_name[0]->text());
		ui_elements.lineEdit_type[1]->setText(ui_elements.lineEdit_type[0]->text());
		ui_elements.lineEdit_price[1]->setText(ui_elements.lineEdit_price[0]->text());
		ui_elements.lineEdit_prod[1]->setText(ui_elements.lineEdit_prod[0]->text());
		ui_elements.button_add->setEnabled(false);
		ui_elements.button_delete->setEnabled(false);
		ui_elements.stacked_update_lineEdits[0]->setCurrentIndex(1);
		ui_elements.stacked_update_lineEdits[1]->setCurrentIndex(1);
		ui_elements.stacked_update_lineEdits[2]->setCurrentIndex(1);
		ui_elements.stacked_update_lineEdits[3]->setCurrentIndex(1);
		ui_elements.stacked_update->setCurrentIndex(1);
	}
	catch (Repository_Exception& exception)
	{
		QMessageBox *error = new QMessageBox();
		error->setWindowTitle("Eroare");
		error->setText(exception.get_msg().c_str());
		error->exec();
	}
}

void gui::delete_product()
{
	try
	{
		validate_fields(0);
		controller.delete_prod(ui_elements.lineEdit_name[0]->text().toStdString(), ui_elements.lineEdit_type[0]->text().toStdString(), ui_elements.lineEdit_price[0]->text().toDouble(), ui_elements.lineEdit_prod[0]->text().toStdString());
		ui_elements.status_bar->showMessage("Produsul a fost sters cu succes!", 3000);
		ui_elements.display_table->removeRow(ui_elements.display_table->currentRow());
	}
	catch (Repository_Exception& exception)
	{
		QMessageBox *error = new QMessageBox();
		error->setWindowTitle("Eroare");
		error->setText(exception.get_msg().c_str());
		error->exec();
	}
	clear_fields(0);
}

void gui::filter_sort()
{
	if (ui_elements.radio_filter->isChecked())
	{
		switch (ui_elements.comboBox->currentIndex()) {
		case 0:
			ui_elements.update_table(controller.get_list());
			break;
		case 1:
		{
			std::string nume = ui_elements.lineEdit_filter_by->text().toStdString();
			std::vector<Product> rezultat = controller.filter([&nume](const Product& prod) {return prod.get_name() == nume; });
			ui_elements.update_table(rezultat);
		}
		break;
		case 2:
		{
			double pret = ui_elements.lineEdit_filter_by->text().toDouble();
			std::vector<Product> rezultat = controller.filter([&pret](const Product& prod) {return prod.get_price() < pret; });
			ui_elements.update_table(rezultat);
		}
		break;
		case 3:
		{
			std::string producator = ui_elements.lineEdit_filter_by->text().toStdString();
			std::vector<Product> rezultat = controller.filter([&producator](const Product& prod) {return prod.get_producer() == producator; });
			ui_elements.update_table(rezultat);
		}
		break;
		}

	}
	else
	{
		switch (ui_elements.comboBox->currentIndex()) {
		case 0:
			ui_elements.update_table(controller.get_list());
			break;
		case 1:
		{
			std::vector<Product> rezultat;
			if (ui_elements.radio_asc->isChecked())
				rezultat = controller.sort([](const Product& prod1, const Product& prod2) {return prod1.get_name() < prod2.get_name(); });
			else
				rezultat = controller.sort([](const Product& prod1, const Product& prod2) {return prod1.get_name() > prod2.get_name(); });
			ui_elements.update_table(rezultat);
		}
		break;
		case 2:
		{
			std::vector<Product> rezultat;
			if (ui_elements.radio_asc->isChecked())
				rezultat = controller.sort([](const Product& prod1, const Product& prod2) {return prod1.get_price() < prod2.get_price(); });
			else
				rezultat = controller.sort([](const Product& prod1, const Product& prod2) {return prod1.get_price() > prod2.get_price(); });
			ui_elements.update_table(rezultat);
		}
		break;
		case 3:
		{
			std::vector<Product> rezultat;
			if (ui_elements.radio_asc->isChecked())
				rezultat = controller.sort([](const Product& prod1, const Product& prod2) {if (prod1.get_name() == prod2.get_name()) return prod1.get_price() < prod2.get_price(); else return prod1.get_name() < prod2.get_name(); });
			else
				rezultat = controller.sort([](const Product& prod1, const Product& prod2) {if (prod1.get_name() == prod2.get_name()) return prod1.get_price() > prod2.get_price(); else return prod1.get_name() < prod2.get_name(); });
			ui_elements.update_table(rezultat);
		}
		break;
		}
	}
}

void gui::validate_fields(int stacked)
{
	bool number;
	if(ui_elements.lineEdit_name[stacked]->text() == "" || ui_elements.lineEdit_type[stacked]->text() == "" || ui_elements.lineEdit_prod[stacked]->text() == "")
		throw Repository_Exception("Toate campurile trebuie sa fie completate!");
	ui_elements.lineEdit_price[stacked]->text().toDouble(&number);
	if (!number)
		throw Repository_Exception("Pretul trebuie sa fie numar!");
}
void gui::clear_fields(int stacked)
{
	ui_elements.lineEdit_name[stacked]->setText("");
	ui_elements.lineEdit_type[stacked]->setText("");
	ui_elements.lineEdit_price[stacked]->setText("");
	ui_elements.lineEdit_prod[stacked]->setText("");
}

void CosGRUDGUI::set_connections()
{
	connect(golesteCos, &QPushButton::clicked, [&]() {
		parent_main->controller.erase_cos();
		update_table();
		parent_main->notify();
	});
	connect(buttonPopulate, &QPushButton::clicked, [&]() {
		parent_main->controller.random_populate(lineEditPopulate->text().toInt());
		lineEditPopulate->clear();
		parent_main->notify();
	});
}

void CosGRUDGUI::update_table()
{
	if (parent_main != nullptr)
	{
		model = new Table_Model{ parent_main->controller.get_cos() };
		display_table->setModel(model);
	}
}

void CosGRUDGUI::update()
{
	update_table();
}
