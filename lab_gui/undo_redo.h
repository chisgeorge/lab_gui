#pragma once
#include <iostream>
#include "product.h"
#include "validators.h"
#include "file_repository.h"

template<typename element_type, class List>
class Undo_Redo {
protected:
	element_type to_undo_redo;
public:
	Undo_Redo() = default;
	Undo_Redo(const element_type& to_undo_redo) : to_undo_redo{ to_undo_redo }
	{
		std::cout << to_undo_redo;
	};
	void virtual do_undo(File_Repository<element_type, List>& repository);
	void virtual do_redo(File_Repository<element_type, List>& repository);
	virtual ~Undo_Redo() = default;
};

template<typename element_type, class List>
class Undo_Redo_Add : public Undo_Redo<element_type, List> {
public:
	Undo_Redo_Add(const element_type& to_undo_redo) : Undo_Redo{ to_undo_redo } {};
	void do_undo(File_Repository<element_type, List>& repository) override;
	void do_redo(File_Repository<element_type, List>& repository) override;
	~Undo_Redo_Add() = default;
};
template<typename element_type, class List>
class Undo_Redo_Update : public Undo_Redo<element_type, List> {
protected:
	element_type to_undo_redo_new;
public:
	Undo_Redo_Update(const element_type& to_undo_redo, const Product& to_undo_redo_new) : Undo_Redo{ to_undo_redo }, to_undo_redo_new{ to_undo_redo_new } {};
	void do_undo(File_Repository<element_type, List>& repository) override;
	void do_redo(File_Repository<element_type, List>& repository) override;
	~Undo_Redo_Update() = default;
};

template<typename element_type, class List>
class Undo_Redo_Delete : public Undo_Redo<element_type, List> {
public:
	Undo_Redo_Delete(const element_type& to_undo_redo) : Undo_Redo{ to_undo_redo } {};
	void do_undo(File_Repository<element_type, List>& repository) override;
	void do_redo(File_Repository<element_type, List>& repository) override;
	~Undo_Redo_Delete() = default;
};

template<typename element_type, class List>
void Undo_Redo<element_type,List>::do_undo(File_Repository < element_type, List>& repository)
{
	throw Undo_Redo_Exception("Nu se mai poate face undo!");
}

template<typename element_type, class List>
inline void Undo_Redo<element_type, List>::do_redo(File_Repository<element_type, List>& repository)
{
	throw Undo_Redo_Exception("Nu se mai poate face redo!");
}

template<typename element_type, class List>
void Undo_Redo_Add<element_type, List>::do_undo(File_Repository<element_type,List>& repository)
{
	repository.delete_elem(to_undo_redo);
}

template<typename element_type, class List>
inline void Undo_Redo_Add<element_type, List>::do_redo(File_Repository<element_type, List>& repository)
{
	repository.add_elem(to_undo_redo);
}

template<typename element_type, class List>
void Undo_Redo_Update<element_type, List>::do_undo(File_Repository<element_type, List>& repository)
{
	repository.update_elem(to_undo_redo, to_undo_redo_new);
}

template<typename element_type, class List>
inline void Undo_Redo_Update<element_type, List>::do_redo(File_Repository<element_type, List>& repository)
{
	repository.update_elem(to_undo_redo_new, to_undo_redo);
}

template<typename element_type, class List>
void Undo_Redo_Delete<element_type, List>::do_undo(File_Repository<element_type, List>& repository)
{
	repository.add_elem(to_undo_redo);
}

template<typename element_type, class List>
inline void Undo_Redo_Delete<element_type, List>::do_redo(File_Repository<element_type, List>& repository)
{
	repository.delete_elem(to_undo_redo);
}
