#include "repository.h"
#include "file_repository.h"
#include "product.h"
#include "linked_list.h"
#include <assert.h>

void test_repository()
{
	Product a{ "a","b",2.5,"c" };
	Product a2{ "a","b",2.5,"c" };
	Product b{ "b","c",2.4,"r" };
	Repository<Product, std::vector<Product>> test;
	test.add_elem(a);
	test.add_elem(b);
	try
	{
		test.add_elem(a2);
		assert(false);
	}
	catch (Repository_Exception exception)
	{
		assert(true);
	}
	assert(test.get_size() == 2);
	test.delete_elem(a);
	test.delete_elem(b);
	assert(test.get_size() == 0);
	test.add_elem(a);
	test.update_elem(a, b);
	try
	{
		test.update_elem(a,b);
		assert(false);
	}
	catch (Repository_Exception exception)
	{
		assert(true);
	}
	try
	{
		test.delete_elem(a);
		assert(false);
	}
	catch (Repository_Exception exception)
	{
		assert(true);
	}
	test.get_all();

}

//void test_file_repository();
//{
//	File_Repository<Product, std::vector<Product>> test;
//	Product a{ "a","b",2.5,"c" };
//	Product a2{ "a","b",2.5,"c" };
//	Product b{ "b","c",2.4,"r" };
//	test.add_elem(a);
//	test.add_elem(b);
//	try
//	{
//		test.add_elem(a2);
//		assert(false);
//	}
//	catch (Repository_Exception exception)
//	{
//		assert(true);
//	}
//	assert(test.get_size() == 2);
//	test.delete_elem(a);
//	test.delete_elem(b);
//	assert(test.get_size() == 0);
//	test.add_elem(a);
//	test.update_elem(a, b);
//	try
//	{
//		test.update_elem(a, b);
//		assert(false);
//	}
//	catch (Repository_Exception exception)
//	{
//		assert(true);
//	}
//	try
//	{
//		test.delete_elem(a);
//		assert(false);
//	}
//	catch (Repository_Exception exception)
//	{
//		assert(true);
//	}
//	test.get_all();
//}
