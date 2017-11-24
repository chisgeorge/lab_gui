//#include <sstream>
#include "product.h"
#include <assert.h>
#include <sstream>

const std::string& Product::get_name() const
{
	return name;
}
void Product::set_name(const std::string& name)
{
	this->name = name;
}

const std::string& Product::get_type() const
{
	return type;
}

void Product::set_type(const std::string& type)
{
	this->type = type;
}

double Product::get_price() const
{
	return price;
}

void Product::set_price(double price)
{
	this->price = price;
}


const std::string& Product::get_producer() const
{
	return producer;
}

void Product::set_producer(const std::string& producer)
{
	this->producer = producer;
}

bool Product::operator == (const Product& ot_prod) const
{
	return name == ot_prod.name && type == ot_prod.type && price == ot_prod.price && producer == ot_prod.producer;
}

bool Product::operator != (const Product& ot_prod) const
{
	return name != ot_prod.name || type != ot_prod.type || price != ot_prod.price || producer != ot_prod.producer;
}


std::ostream& operator<< (std::ostream& output_stream, const Product& prod)
{
	output_stream << prod.get_name() << "\t" << prod.get_type() << "\t" << prod.get_price() << "\t" << prod.get_producer()<<"\n";
	return output_stream;
}

std::istream& operator>> (std::istream &input_stream, Product &prod)
{
	input_stream >> prod.name >> prod.type >> prod.price >> prod.producer;
	return input_stream;
}


/*std::istream& operator >> (std::istream& is, Product& prod)
{
	std::string line, token;
	int apartment;
	float amount;

	is >> line;
	std::istringstream ss(line);

	getline(ss, token, ',');
	std::stringstream(token) >> apartment;
	prod.set_apartment(apartment);

	getline(ss, token, ',');
	std::stringstream(token) >> amount;
	prod.set_amount(amount);

	getline(ss, token, ',');
	prod.set_type(token);

	return is;
}
*/

void test_product()
{
	test_get_set();
	test_operators();
}

void test_get_set()
{
	Product a{ "a","b",2.5,"c" };
	assert(a.get_name() == "a");
	assert(a.get_price() == 2.5);
	assert(a.get_producer() == "c");
	assert(a.get_type() == "b");
	a.set_name("arc");
	a.set_price(1.2);
	a.set_producer("abc");
	a.set_type("rag");
	assert(a.get_name() == "arc");
	assert(a.get_price() == 1.2);
	assert(a.get_producer() == "abc");
	assert(a.get_type() == "rag");
}
void test_operators()
{
	Product a{ "a","b",2.5,"c" };
	Product a2{ "a","b",2.5,"c" };
	Product b{ "b","c",2.4,"r" };
	assert(a != b);
	assert(a == a2);
	std::stringstream test;
	test << a;
	test >> a;
	/*std::stringstream test;
	test << "a\tb\t2.5\tc";
	assert(out.str() == test.str());*/
}