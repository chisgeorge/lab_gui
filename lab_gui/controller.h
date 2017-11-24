#pragma once
#include "product.h"
#include "cos.h"
#include "repository.h"
#include <functional>
#include <algorithm>
#include <random>
#include "undo_redo.h"
#include <memory>
#include "file_repository.h"
#include "observer.h"

template<class List>
class Controller
{
	File_Repository<Product,List>& repository;
	Product_Validator validator;
	Cos<Product, List> cos;
	std::vector<std::shared_ptr<Undo_Redo<Product, List>>> undo_list;
	int index_undo_redo;
public:
	Controller(File_Repository<Product, List>& repository, Product_Validator& validator, Cos<Product, List>& cos) : repository{ repository }, validator{ validator }, cos{ cos }, undo_list{ std::make_shared<Undo_Redo<Product, List>>(Undo_Redo<Product, List>()), std::make_shared<Undo_Redo<Product, List>>(Undo_Redo<Product, List>()) }, index_undo_redo{0} {};
	Controller(const Controller& other) = delete;
	void add_prod(const std::string& name, const std::string& type, const double& price, const std::string& producer);
	void delete_prod(const std::string& name, const std::string& type, const double& price, const std::string& producer);
	void update_prod(const std::string& name, const std::string& type, const double& price, const std::string& producer, const std::string& new_name, const std::string&	new_type, const double& new_price, const std::string& new_producer);
	
	const List& get_list() const;
	const List sort(bool(*compare_f)(const Product&, const Product&));
	const List filter(std::function<bool(const Product&)> compare_f);

	void add_cos(const std::string& nume);
	void erase_cos();
	void random_populate(int how_much);
	void export_cos(const std::string& filename);
	const List& get_cos() const;
	double get_cos_total();

	void undo();
	void redo();
	
};

/*
 * Adauga produs in Repository, se foloseste de functia din repository add_elem
 */
template<class List>
void Controller<List>::add_prod(const std::string & name, const std::string & type, const double & price, const std::string & producer)
{
	Product prod{name,type,price,producer};
	validator.validate(prod);
	repository.add_elem(prod);
	if(index_undo_redo != undo_list.size()-2)
		undo_list.erase(undo_list.begin() + index_undo_redo + 1, undo_list.end() - 1);
	undo_list.insert(undo_list.end()-1, std::make_shared<Undo_Redo_Add<Product, List>>(Undo_Redo_Add<Product, List>(prod)));
	index_undo_redo++;

}

/*
 * Sterge produs din Repository, se foloseste de functia din repository delete_elem
 */
template<class List>
void Controller<List>::delete_prod(const std::string & name, const std::string & type, const double & price, const std::string & producer)
{
	Product prod{ name,type,price,producer };
	validator.validate(prod);
	repository.delete_elem(prod);
	if (index_undo_redo != undo_list.size() - 2)
		undo_list.erase(undo_list.begin() + index_undo_redo + 1, undo_list.end() - 1);
	undo_list.insert(undo_list.end()-1, std::make_shared<Undo_Redo_Delete<Product, List>>(Undo_Redo_Delete<Product, List>(prod)));
	index_undo_redo++;
}

/*
 * Actualizeaza produs in Repository, se foloseste de functia din repository update_elem
 */
template<class List>
void Controller<List>::update_prod(const std::string & name, const std::string & type, const double & price, const std::string & producer, const std::string & new_name, const std::string & new_type, const double & new_price, const std::string & new_producer)
{
	Product prod{ name,type,price,producer};
	validator.validate(prod);
	Product new_prod{new_name,new_type,new_price,new_producer};
	validator.validate(new_prod);
	repository.update_elem(prod,new_prod);
	if (index_undo_redo != undo_list.size() - 2)
		undo_list.erase(undo_list.begin() + index_undo_redo + 1, undo_list.end() - 1);
	undo_list.insert(undo_list.end()-1, std::make_shared<Undo_Redo_Update<Product, List>>(Undo_Redo_Update<Product, List>(new_prod,prod)));
	index_undo_redo++;
}

/*
 * Getter pentru lista din Repository, returneaza referinta constanta la lista List
 */
template<class List>
const List& Controller<List>::get_list() const
{
	return repository.get_all();
}
/*
 * Sortare cu functie de comparare
 * Returneaza o copie a listei sortate
 */
/*template<class List>
const List Controller<List>::sort(bool(*compare_f)(const Product&, const Product&))
{
	List Lista = repository.get_all();
		for (auto i = 0; i < Lista.size(); i++) {
			for (auto j = i + 1; j < Lista.size(); j++) {
				if (!compare_f(Lista[i], Lista[j])) {
					Product aux = Lista[i];
					Lista[i] = Lista[j];
					Lista[j] = aux;
				}
			}
		}
		return Lista;
	}*/
template<class List>
const List Controller<List>::sort(bool(*compare_f)(const Product&, const Product&))
{
	List rez = repository.get_all();
	std::sort(rez.begin(), rez.end(), compare_f);
	return rez;
}
/*
 * Filtrare cu functie de comparare
 * Returneaza o copie a listei filtrate
 */

/*template<class List>
const List Controller<List>::filter(std::function<bool(const Product&)> compare_f)
{
	List rez;
	for (const auto& prod : repository.get_all()) {
		if (compare_f(prod)) {
			rez.push_back(prod);}
	}
	return rez;}*/

template<class List>
const List Controller<List>::filter(std::function<bool(const Product&)> compare_f)
{
	List rez(repository.get_size());
	auto it = std::copy_if(repository.get_all().begin(), repository.get_all().end(), rez.begin(), compare_f);
	rez.resize(std::distance(rez.begin(), it));
	return rez;
}
template<class List>
void Controller<List>::add_cos(const std::string & nume)
{	
	auto exist = repository.find_name(nume);
	cos.adauga(exist);
}

template<class List>
void Controller<List>::erase_cos()
{
	cos.goleste();
}

template <class List>
void Controller<List>::random_populate(int how_much)
{
	if (repository.get_size() > 1)
	{
		std::mt19937 mt{ std::random_device{}() };
		std::uniform_int_distribution<int> dist(0, repository.get_size() - 1);
		int i = 0;
		while (i < how_much)
		{
			cos.adauga(repository.get_all()[dist(mt)]);
			i++;
		}
	}
	else throw "Nu se poate genera, nu exista produse\n";
}

template<class List>
void Controller<List>::export_cos(const std::string & filename)
{
	cos.export_in(filename);
}

template<class List>
const List& Controller<List>::get_cos() const
{
	return cos.get_cos();
}

template<class List>
double Controller<List>::get_cos_total()
{
	return cos.get_total();
}

template<class List>
void Controller<List>::undo()
{
	auto last_action = undo_list[index_undo_redo];
	last_action->do_undo(repository);
	index_undo_redo--;
}

template<class List>
void Controller<List>::redo()
{
	auto last_action = undo_list[index_undo_redo+1];
	last_action->do_redo(repository);
	index_undo_redo++;
}

void test_controller();