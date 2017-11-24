#include "repository.h"
#include "product.h"
#include "linked_list.h"
#include "controller.h"
#include <assert.h>
#include "file_repository.h"

void test_controller()
{
	remove("test.dat");
	File_Repository<Product, std::vector<Product>> test("test.dat");
	Cos<Product, std::vector<Product>> test_cos;
	Product_Validator validator;
	Controller<std::vector<Product>> test_c{ test, validator, test_cos };
	test_c.add_prod("a","b",2.5,"c" );
	test_c.add_prod("c", "b", 2.4, "d");
	test_c.update_prod("a", "b", 2.5, "c", "c", "b", 1.4, "d");
	assert(test_c.get_list().size() == 2);
	test_c.delete_prod("c", "b", 2.4, "d");
	std::string nume = "c";
	std::vector<Product> a = test_c.filter([&nume](const Product& prod1) {return prod1.get_name() == nume; });
	Product prod{ "c", "b", 1.4, "d" };
	assert(a[0] == prod);
	test_c.add_prod("a", "b", 0.5, "c");
	Product prod2{ "a", "b", 0.5, "c" };
	std::vector<Product> b = test_c.sort([](const Product& prod1, const Product& prod2) {return prod1.get_price() < prod2.get_price(); });
	assert(b[0] == prod2);
}
