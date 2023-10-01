#ifndef _FILEHANDLER_HPP_
#define _FILEHANDLER_HPP_

#include "../../third-party/asio-1.24.0/include/asio.hpp"

//std::stringstream
#include <sstream>

#include <fstream>
#include <string>

namespace fh
{

class FileHandler
{
private:
    std::string filename;
    unsigned int length;

    std::ifstream fin;

    std::string file;
    std::string file_properties;

	asio::streambuf file_stream_buf;			
	asio::streambuf file_properties_stream_buf;			

private:
    void SeparateFilename(std::string);
    void SetLength();
    void Serialization();
    void Packaging();

public:
    FileHandler(std::string);
    ~FileHandler();

    asio::streambuf::const_buffers_type GetFileProperties();
    asio::streambuf::const_buffers_type GetFile();

};

}

#endif /* _FILEHANDLER_HPP_ */