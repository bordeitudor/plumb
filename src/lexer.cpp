#include <sstream>
#include "lexer.h"

void Lexer::lexFile()
{
	if (!_file.valid()) {
		throw std::runtime_error("No file was loaded, send a bug report");
	}

	while (_advance()) {
		// TODO: Implement lexing
	}
}

void Lexer::loadFile(const std::string &file_path)
{
	_file = std::move(File::load(file_path));

	if (!_file.valid()) {
		std::stringstream ss;
		ss << "No such file '" << _file.path() << "'";
		throw std::runtime_error(ss.str());
	}
}

bool Lexer::_advance() noexcept
{
	if (_file.valid()) {
		_c_loc.c += 1;

		if (_c_loc.ch == '\n') {
			_c_loc.c = 0;
			_c_loc.l += 1;
		}

		_c_loc.ch = _file.get();
		return true;
	}

	return false;
}

Lexer::Lexer()
	:_c_loc(_file)
{

}