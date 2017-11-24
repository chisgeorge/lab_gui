#include "linked_list.h"
#include <assert.h>
#include "product.h"

void test_linked_list()
{
	dlinked_list<int> test_list;
	test_list.push_back(1);
	assert(test_list.size() == 1);
	dlinked_list<int> test_list2{ test_list };
	assert(test_list2.size() == 1);
	test_list2 = test_list;
	test_list.push_back(2);
	test_list.push_back(3);
	test_list.push_back(4);
	test_list.push_back(5);
	dlinked_list<int> test_list3 = test_list;
	assert(test_list3.at(1) == test_list[1]);
	test_list3[1] = 10;
	assert(test_list3[1] == 10);
	dlinked_list<Product> test_list4;
	Product a{ "a","b",3.4,"c" };
	Product b{ "a","b",5.4,"c" };
	test_list4.push_back(a);
	assert(test_list4[0] == a);
	dlinked_list<Product> test_list5;
	test_list5 = test_list4;
	assert(test_list4[0] == test_list5[0]);
	test_list5[0] = b;
	assert(test_list5[0] == b);
	auto it = test_list3.begin();
	it += 1;
	it + 1;
	test_list3.erase(it);
	assert(test_list3[2] == 4);
	int ai=0;
	for(auto i : test_list3)
	{
		ai++;
	}
	assert(ai == 4);
	try
	{
		test_list4[2] = b;
		assert(false);
	}
	catch(std::out_of_range)
	{
		assert(true);
	}
	auto it2 = test_list4.begin();
	test_list4.erase(it2);

	dlinked_list<int> test_list6;
	test_list6.push_back(1);
	test_list6.push_back(2);
	test_list6.push_back(3);
	test_list6.push_back(4);
	dlinked_list<int> test_list7 = test_list6;
	for(dlinked_list<int>::iterator ita=test_list6.begin(),itb=test_list7.begin();ita!=test_list6.end(),itb!=test_list7.end();++ita,++itb)
	{
		if (*ita != *itb)
			assert(false);
	}
}
