#include "validators.h"


std::ostream& operator<<(std::ostream & out, const Validate_Exception & except)
{
	for (const auto& msg : except.msgs) {
		out << msg << "\n";
	}
	return out;
}

std::ostream & operator<<(std::ostream & out,const Repository_Exception& except)
{
	out << except.get_msg();
	return out;
}

std::ostream & operator<<(std::ostream & out, const Undo_Redo_Exception & except)
{
	out << except.get_msg();
	return out;
}

const std::string & Repository_Exception::get_msg() const
{
	return msg;
}

void Product_Validator::validate(const Product & prod)
{
	std::vector<std::string> error_messeges;
	if (prod.get_name().size() == 0) error_messeges.push_back("Numele nu poate fi vid!");
	if (prod.get_type().size() == 0) error_messeges.push_back("Tipul nu poate fi vid!");
	if (prod.get_price() < 0) error_messeges.push_back("Pretul nu poate fi negativ!");
	if (prod.get_producer().size() == 0) error_messeges.push_back("Producatorul nu poate fi vid");
	if (error_messeges.size() > 0)
		throw Validate_Exception(error_messeges);
}

const std::string & Undo_Redo_Exception::get_msg() const
{
	return msg;
}
