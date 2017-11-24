#pragma once
#include <fstream>

template<typename element_type,class List>
class Cos
{
	List cos;
public:
	Cos() = default;
	void adauga(const element_type& prod);
	void goleste();
	//void random_populate(List a, int numar);
	void export_in(const std::string& filename);
	int get_size() const;
	const List& get_cos() const;
	double get_total() const;
};

template<typename element_type, class List>
void Cos<element_type, List>::adauga(const element_type& prod)
{
	cos.push_back(prod);
}

template<typename element_type, class List>
void Cos<element_type, List>::goleste()
{
	cos.clear();
}

template<typename element_type, class List>
void Cos<element_type, List>::export_in(const std::string & filename)
{
	std::ofstream of{ filename };
	if (of.fail())
		throw "Exportul a esuat!";
	of << "Nume\tTip\tPret\tProducator\n";
	for (const auto& prod : cos)
		of << prod;
}

template<typename element_type, class List>
int Cos<element_type, List>::get_size() const
{
	return cos.size();
}

template<typename element_type, class List> 
const List& Cos<element_type, List>::get_cos() const
{
	return cos;
}

template<typename element_type, class List>
double Cos<element_type, List>::get_total() const
{
	double total = 0.0;
	for (const auto& i : cos)
		total += i.get_price();
	return total;
}

