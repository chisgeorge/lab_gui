#pragma once
#include "validators.h"

template<typename element_type, class List>
class Repository{
	List storage;
public:
	Repository() = default;
	Repository(const Repository& other) = delete;
	void add_elem(const element_type& elem);
	void update_elem(const element_type& elem, const element_type& new_elem);
	void delete_elem(const element_type& elem);
	int find(const element_type& elem) const;
	const element_type& find_name(const std::string nume);
	unsigned int get_size() const;
	const List& get_all() const;
};

/*
 * Adauga un element_type in lista List
 */
template <typename element_type, class List>
void Repository<element_type, List>::add_elem(const element_type& elem)
{
		auto exist = find(elem);
		if (exist == -1)
			storage.push_back(elem);
		else throw Repository_Exception("Elementul pe care doriti sa il adaugati exista deja");
}

/*
 * Face update la un un element_type in lista List
 */
template <typename element_type, class List>
void Repository<element_type, List>::update_elem(const element_type& elem, const element_type& new_elem)
{
		auto exist = find(elem);
		if (exist == -1)
			throw Repository_Exception("Elementul pe care doriti sa il actualizati nu exista");
		else
		{
			auto exist_new = find(new_elem);
			if (exist_new == -1)
				storage[exist] = new_elem;
			else throw Repository_Exception("Elementul pe care doriti sa il actualizati exista deja");
		}
}

/*
 * Sterge un element_type din lista List 
 */
template <typename element_type, class List>
void Repository<element_type, List>::delete_elem(const element_type& elem)
{
	auto exist = find(elem);
	if (exist == -1)
		throw Repository_Exception("Elementul pe care doriti sa il stergeti nu exista");
	storage.erase(storage.begin() + exist);
}

/*
 * Cauta un un element_type in lista List
 */
template<typename element_type, class List>
int Repository<element_type, List>::find(const element_type & elem) const
{
	unsigned int pos = 0;
	for (const auto& i : storage)
	{
		if(i == elem)
			return pos;
		pos++;
	}
	return -1;
}

template<typename element_type, class List>
const element_type & Repository<element_type, List>::find_name(const std::string nume)
{
	for (const auto& i : storage)
	{
		if (i.get_name() == nume)
			return i;
	}
	throw Repository_Exception("Nu exista produsul cu numele '" + nume + "'");
}

/*
 * Getter pentru lungimea repository-ului
 */
template<typename element_type, class List>
unsigned int Repository<element_type, List>::get_size() const
{
	return storage.size();
}

/*
 *	Getter pentru elementele repository-ului
 */
template<typename element_type, class List>
const List& Repository<element_type, List>::get_all() const
{
	return storage;
}

void test_repository();