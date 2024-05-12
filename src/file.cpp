#include "file.h"

const std::string &File::path() const noexcept
{
	return _path;
}

bool File::valid() noexcept
{
	return _fd.good() && _fd.is_open();
}

char File::get() noexcept
{
	return _fd.get();
}

File File::load(const std::string &path)
{
	File f;
	f._fd.open(path);
	f._path = path;
	return f;
}

void File::clear() noexcept
{
	_path = "";
	_fd.clear();
}

File &File::operator=(File &&other) noexcept
{
	if (this != &other) {
		_fd = std::move(other._fd);
		_path = std::move(other._path);
	}
	return *this;
}

File::File(File &&other) noexcept
{
	*this = std::move(other);
}