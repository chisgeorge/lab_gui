#pragma once
#include "repository.h"
#include <fstream>

template<typename element_type,class List>
class File_Repository : public Repository<element_type,List>{
	std::string filename;
	bool failed;
	void load_repository();
	void update_file(element_type elem,element_type new_elem);
	void delete_from_file(element_type elem);
public:
	File_Repository() : Repository<element_type, List>{}, failed{ true } {};
	File_Repository(const char* filename) : Repository<element_type, List>{}, filename{ filename }{
		std::ofstream file_out{ filename, std::ios::app };;
		std::ifstream file_in{ filename };
		failed = file_in.fail() || file_out.fail();
		load_repository();
	};
	void add_elem(const element_type& elem);
	void update_elem(const element_type& elem, const element_type& new_elem);
	void delete_elem(const element_type& elem);
	~File_Repository() = default;
};

template<typename element_type, class List>
void File_Repository<element_type, List>::load_repository()
{
	std::ifstream file_in{ filename };
	element_type elem;
	while (file_in >> elem)
	{
		Repository<element_type, List>::add_elem(elem);
	}
}

template<typename element_type, class List>
void File_Repository<element_type, List>::update_file(element_type old_elem, element_type new_elem)
{
	std::ifstream file_in{ filename };
	element_type elem;
	{
		std::ofstream aux("transfer.dat");
		while (file_in >> elem)
		{
			if (elem == old_elem)
				aux << new_elem;
			else aux << elem;
		}
		aux.close();
	}
	std::ofstream file_out{ filename };
	std::ifstream aux{ "transfer.dat" };
	std::string line;
	while (aux >> elem)
	{
		file_out << elem;
	}
	aux.close();
}

template<typename element_type, class List>
void File_Repository<element_type, List>::delete_from_file(element_type elem_to_delete)
{
	std::ifstream file_in{ filename };
	element_type elem;
	{
		std::ofstream aux{ "transfer.dat" };
		while (file_in >> elem)
		{
			if (elem == elem_to_delete)
				;
			else aux << elem;
		}
		aux.close();
	}
	std::ofstream file_out{ filename };
	std::ifstream aux{ "transfer.dat" };
	std::string line;
	while (aux >> elem)
	{
		file_out << elem;
	}
	aux.close();
}

template<typename element_type, class List>
void File_Repository<element_type, List>::add_elem(const element_type & elem)
{
	std::ofstream file_out{ filename, std::ios::app };
	Repository<element_type, List>::add_elem(elem);
	if(!failed)
		file_out << elem;
}

template<typename element_type, class List>
void File_Repository<element_type, List>::update_elem(const element_type & elem, const element_type & new_elem)
{
	Repository<element_type, List>::update_elem(elem,new_elem);
	if (!failed)
		update_file(elem, new_elem);
}

template<typename element_type, class List>
void File_Repository<element_type, List>::delete_elem(const element_type & elem)
{
	Repository<element_type, List>::delete_elem(elem);
	if (!failed)
		delete_from_file(elem);
}
