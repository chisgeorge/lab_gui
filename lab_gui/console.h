#pragma once
#include "product.h"
#include "controller.h"
#include <iostream>

template<class List>
class UI
{
	Controller<List>& ctr;
	void add_ui();
	void update_ui();
	void delete_ui();
	void print_all();
	void sort_ui();
	void filter_ui();
	void print_list(const List& products);
	void add_cos_ui();
	void empty_cos_ui();
	void random_cos_ui();
	void export_cos_ui();
	void undo_ui();
	void redo_ui();
public:
	UI(Controller<List>& ctr): ctr{ ctr } {}
	UI(const UI& other) = delete;
	
	void start_UI();
};
/*
 * Citeste o comanda pana cand este dat parametrul corect
 */

template<typename type>
const type read_cmd(const char* prompt_msg) {
	type cmd;
	bool fail = true;
	while (fail) {
		std::cout << prompt_msg;
		std::cin >> std::noskipws >> cmd;
		fail = std::cin.fail();
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	return cmd;
}

/*
 * adaugarea din UI
 */
template<typename List>
void UI<List>::add_ui()
{
	std::string name = read_cmd<std::string>("Dati nume: ");
	std::string  type = read_cmd<std::string>("Dati tip: ");
	double price = read_cmd<double>("Dati pret: ");
	std::string product = read_cmd<std::string>("Dati producator: ");
	ctr.add_prod(name, type, price, product);
}

/*
 * Stergerea din UI
 */
template<typename List>
void UI<List>::delete_ui()
{
	std::string name = read_cmd<std::string>("Dati nume: ");
	std::string  type = read_cmd<std::string>("Dati tip: ");
	double price = read_cmd<double>("Dati pret: ");
	std::string product = read_cmd<std::string>("Dati producator: ");
	ctr.delete_prod(name, type, price, product);
}

/*
 * Update din UI
 */
template<typename List>
void UI<List>::update_ui()
{
	std::string name = read_cmd<std::string>("Dati nume: ");
	std::string  type = read_cmd<std::string>("Dati tip: ");
	double price = read_cmd<double>("Dati pret: ");
	std::string product = read_cmd<std::string>("Dati producator: ");
	std::string new_name = read_cmd<std::string>("Dati noul nume: ");
	std::string  new_type = read_cmd<std::string>("Dati noul tip: ");
	double new_price = read_cmd<double>("Dati noul pret: ");
	std::string new_product = read_cmd<std::string>("Dati noul producator: ");
	ctr.update_prod(name, type, price, product, new_name, new_type, new_price, new_product);
}

/*
 * Printeaza toate elementele din UI
 */
template<typename List>
void UI<List>::print_all()
{
	std::cout << "Nume\tTip\tPret\tProducator\n";
	List current_list = ctr.get_list();
	for (const auto& prod : current_list) {
		std::cout << prod;
	}
}

/*
 * Printeaza o lista data prin template la UI List
 */
template<class List>
void UI<List>::print_list(const List& products)
{
	std::cout << "Nume\tTip\tPret\tProducator\n";
	for (const auto& prod : products) {
		std::cout << prod;
	}
}

template<class List>
void UI<List>::add_cos_ui()
{
	std::string name = read_cmd<std::string>("Dati nume: ");
	ctr.add_cos(name);
	print_list(ctr.get_cos());
	std::cout << "Total curent cos: " << ctr.get_cos_total() << "\n";
}

template<class List>
void UI<List>::empty_cos_ui()
{
	ctr.erase_cos();
	std::cout << "Total curent cos: " << ctr.get_cos_total() << "\n";
}

template<class List>
void UI<List>::random_cos_ui()
{
	int how_much = read_cmd<int>("Dati numarul: ");
	ctr.random_populate(how_much);
	print_list(ctr.get_cos());
	std::cout << "Total curent cos: " << ctr.get_cos_total() << "\n";
}

template<class List>
void UI<List>::export_cos_ui()
{
	std::string filename= read_cmd<std::string>("Dati numele fisierului pentru export, cu tot cu extensie:");
	ctr.export_cos(filename);
	std::cout << "Exportul a reusit cu succes!\n";
}

template <class List>
void UI<List>::undo_ui()
{
	ctr.undo();
}

template <class List>
void UI<List>::redo_ui()
{
	ctr.redo();
}

/*
 * Filtrarea din UI
 */
template<typename List>
void UI<List>::filter_ui()
{
	std::cout << "1.Dupa pret\n2.Dupa nume\n3.Dupa producator\n";
	int cmd = read_cmd<int>("Dati comanda: ");
	switch (cmd) {
	case 1:
	{
		double pret = read_cmd<double>("Dati pret: ");
		List rezultat_pret = ctr.filter([&pret](const Product& prod1) {return prod1.get_price() < pret; });
		print_list(rezultat_pret); }
	break;
	case 2:
	{
		std::string nume = read_cmd<std::string>("Dati nume: ");
		List rezultat_nume = ctr.filter([&nume](const Product& prod1) {return prod1.get_name() == nume; });
		print_list(rezultat_nume); }
	break;
	case 3:
	{
		std::string producator = read_cmd<std::string>("Dati producator: ");
		List rezultat_producator = ctr.filter([&producator](const Product& prod) {return prod.get_producer() == producator; });
		print_list(rezultat_producator); }
	break;
	}
}

/*
 * Sortarea din UI
 */
template<typename List>
void UI<List>::sort_ui()
{

	std::cout << "1.Dupa nume\n2.Dupa pret\n3.Dupa nume si pret\n";
	int cmd = read_cmd<int>("Dati comanda: ");
	switch (cmd) {
	case 1:
	{
		List rezultat_pret = ctr.sort([](const Product& prod1, const Product& prod2) {return prod1.get_name() < prod2.get_name(); });
		print_list(rezultat_pret); }
	break;
	case 2:
	{
		List rezultat_nume = ctr.sort([](const Product& prod1, const Product& prod2) {return prod1.get_price() < prod2.get_price(); });
		print_list(rezultat_nume); }
	break;
	case 3:
	{
		List rezultat_producator = ctr.sort([](const Product& prod1, const Product& prod2) {if (prod1.get_name() == prod2.get_name()) return prod1.get_price() < prod2.get_price(); else return prod1.get_name() < prod2.get_name(); });
		print_list(rezultat_producator); }
	break;
	}
}
/*
 * Porneste UI si asteapta comanda
 */
template<typename List>
void UI<List>::start_UI() {
	while (true) {
		std::cout << "Meniu:\n";
		std::cout << "1.Adaugare\n2.Actualizare\n3.Stergere\n4.Tipareste toate\n5.Filtrare\n6.Sortare\n7.Adauga in cos\n8.Goleste cos\n9.Genereaza cos\n10.Exporta cos\n11.Undo\n0.Iesire\n";
		int cmd = read_cmd<int>("Dati comanda: ");
		try {
			switch (cmd) {
			case 1:
				add_ui();
				break;
			case 2:
				update_ui();
				break;
			case 3:
				delete_ui();
				break;
			case 4:
				print_all();
				break;
			case 5:
				{filter_ui();}
				break;
			case 6:
				{sort_ui();}
				break;
			case 7:
				{add_cos_ui(); }
				break;
			case 8:
				{empty_cos_ui(); }
				break;
			case 9:
				{random_cos_ui(); }
				break;
			case 10:
				{export_cos_ui(); }
				break;
			case 11:
				{undo_ui(); }
				break;
			case 12:
				{redo_ui(); }
				break;
			case 0:
				return;
			default:
				std::cout << "Comanda invalida\n";
				break;
			}
		}
		catch (const Repository_Exception& exception)
		{
			std::cout << exception<<"\n";
		}
		catch (const Undo_Redo_Exception& exception)
		{
			std::cout << exception << "\n";
		}
		catch (const Validate_Exception& exception)
		{
			std::cout << exception;
		}
		catch (const char* exception)
		{
			std::cout << exception;
		}
	}
}