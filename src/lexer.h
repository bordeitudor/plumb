#ifndef LEXER_H
#define LEXER_H

#include "file.h"
#include "location.h"

class Lexer {
public:
	void lexFile();
	void loadFile(const std::string &file_path);

	Lexer();
	~Lexer() = default;
private:
	bool _advance() noexcept;

	Location _c_loc;
	File _file;
};

#endif // LEXER_H