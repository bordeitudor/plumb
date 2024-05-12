#include <iostream>
#include "lexer.h"

int main()
{
	std::unique_ptr<Lexer> lexer = std::make_unique<Lexer>();

	try {
		lexer->loadFile("./build.plumb");
		lexer->lexFile();
	}
	catch (std::runtime_error &e) {
		std::cout << "plumb: " << e.what() << "\n";
	}

	return 0;
}