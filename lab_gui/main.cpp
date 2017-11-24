#include "lab_gui.h"
#include <QtWidgets/QApplication>
#include "controller.h"
#include "linked_list.h"

void run_tests()
{
	test_linked_list();
	test_product();
	test_repository();
	test_controller();

}

int main(int argc, char *argv[])
{

	QApplication application(argc, argv);
	run_tests();
	File_Repository<Product, std::vector<Product>> repository{ "repository.dat" };
	Product_Validator validator;
	Cos<Product, std::vector<Product>> cos;
	Controller<std::vector<Product>> controller{ repository,validator,cos };
	gui interface(controller);
	interface.show();
	return application.exec();
}
