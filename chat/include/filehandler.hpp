#ifndef _FILEHANDLER_HPP_
#define _FILEHANDLER_HPP_

#include "../../third-party/asio-1.24.0/include/asio.hpp"

//std::stringstream
#include <sstream>

#include <fstream>
#include <string>

// data
#include "data.hpp"

// unique_ptr
#include <memory>

namespace fh
{

class FileHandler
{
private:
    std::string filename;
    unsigned int length;

    std::ifstream fin;
    std::ofstream fout;
    bool good;

    std::string file;
    std::string file_properties;

	asio::streambuf file_stream_buf;			
	asio::streambuf file_properties_stream_buf;			

    // logs
    ucd::Data* user_data;

private:
    // input
    void SeparateFilename(std::string&);
    void SetLength();
    void Serialization();
    void Packaging();

    // output
    void SeparateProperties(std::string&);
    void Deserialization(asio::streambuf&);

public:
    FileHandler(std::string&, ucd::Data*);
    FileHandler(std::string&, asio::streambuf&, ucd::Data*);

    ~FileHandler();

    asio::streambuf::const_buffers_type GetFileProperties();
    asio::streambuf::const_buffers_type GetFile();
    bool isGood();

    // Testing functons
    std::string GetFileName();
    unsigned GetLength();
    unsigned GetStreamBufSize();
    std::string& GetFilePropertiesStr();
    asio::streambuf& GetFileUnpack();

};

}

#endif /* _FILEHANDLER_HPP_ */