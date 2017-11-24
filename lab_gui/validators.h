#pragma once
#include <vector>
#include "product.h"

class Validate_Exception {
	std::vector<std::string> msgs;
public:
	Validate_Exception(const std::vector<std::string>& errors) :msgs{ errors } {}
	friend std::ostream& operator<<(std::ostream& out, const Validate_Exception& except);
};

class Product_Validator {
public:
	void validate(const Product& prod);
};

class Repository_Exception {
	std::string msg;
public:
	Repository_Exception(std::string msg) : msg{ msg } {};
	const std::string& get_msg() const;
	friend std::ostream& operator<<(std::ostream& out, const Repository_Exception& except);
};

class Undo_Redo_Exception {
	std::string msg;
public:
	Undo_Redo_Exception(std::string msg) : msg{ msg } {};
	const std::string& get_msg() const;
	friend std::ostream& operator<<(std::ostream& out, const Undo_Redo_Exception& except);
};