#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <sstream>

struct File {
	const std::string &path() const noexcept;

	bool valid() noexcept;

	char get() noexcept;

	static File load(const std::string &path);

	void clear() noexcept;

	~File() = default;
	File() = default;
	File &operator=(File &&other) noexcept;
	File &operator=(const File &other) = delete;
	File(File &&other) noexcept;
	File(const File &other) = delete;
private:
	std::ifstream _fd;
	std::string _path;
};

#endif // FILE_H