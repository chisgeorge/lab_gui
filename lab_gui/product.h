#pragma once
#include <string>

class Product
{
	std::string name;
	std::string type;
	double price;
	std::string producer;
	
public:
	/*
	* Constructor default (fara parametrii)
	*/
	Product():name {""}, type{""}, price{ -1 }, producer{""}{};
	/*
	 * Constructor cu parametrii:
	 *		const std::string& name - referinta constanta la nume;
	 *		const std::string& type - referinta constanta la tip;
	 *		const double& price - referinta constanta la pret
	 *		const std::string& producer - - referinta constanta la producator
	 */
	Product(const std::string& name, const std::string& type, const double& price, const std::string& producer):name{ name }, type{ type }, price{ price }, producer{ producer } {}
	/*
	 * Constructor care primeste un alt produs va ramane default
	 */
	Product(const Product& other) = default;
	/*
	 * Getter pentru nume
	 */
	const std::string& get_name() const;
	/*
	 *	Setter pentru nume
	 */
	void set_name(const std::string& name);

	/*
	* Getter pentru tip
	*/
	const std::string& get_type() const;
	/*
	 * Setter pentru nume
	 */
	void set_type(const std::string& type);

	/*
	 * Getter pentru pret
	 */
	double get_price() const;
	/*
	 * Setter pentru pret
	 */
	void set_price(double price);

	/*
	 * Getter pentru producator
	 */
	const std::string& get_producer() const;
	/*
	 * Setter pentru producator
	 */
	void set_producer(const std::string& producer);

	/*
	 * Suprascriere operator ==
	 */
	bool operator ==(const Product& prod) const;
	/*
	 * Suprascriere operator !=
	 */
	bool operator !=(const Product& prod) const;
	/*
	 * Destructorul ramane default deoarece nu am alocat dinamic nici un camp
	 */
	~Product() = default;

	/*
	 * Suprascriere operator <<
	 */
	friend std::ostream& operator << (std::ostream& output_stream, const Product& prod);
	friend std::istream& operator >> (std::istream&, Product&);
};

//tests
void test_product();
void test_get_set();
void test_operators();