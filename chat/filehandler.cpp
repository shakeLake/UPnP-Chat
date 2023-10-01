#include "include/filehandler.hpp"

fh::FileHandler::FileHandler(std::string file_path)
{
    fin.open(file_path);

    SetLength();

    SeparateFilename(file_path);

    file_properties = '#' + filename + '#' + length + '*';

    Serialization();

    Packaging();
}

fh::FileHandler::~FileHandler()
{
    fin.close();
}

void fh::FileHandler::SeparateFilename(std::string& path)
{
    int begin = -1;
    for (unsigned symbol = path.size() - 1; symbol > 0; --symbol)
    {
        char buf = path[symbol];

        if (buf == '\\' || buf == '/')
        {
            begin = symbol + 1;
            break; 
        }
    }

    if (begin == -1)
    {
        filename = path.substr(0, path.size() - 1);
        return;
    }

    filename = path.substr(begin, path.size() - begin + 1);
}

void fh::FileHandler::GetLength()
{
    fin.seekg(0, file_prop.fin.end);
    length = file_prop.fin.tellg();
    fin.seekg(0, file_prop.fin.beg);
}

void fh::FileHandler::Serialization()
{
    std::stringstream str_stream;
    str_stream << fin.rdbuf();

    file = std::move(str_stream.str()); 
}

void fh::FileHandler::Packaging()
{
    std::ofstream prop(&file_properties_stream_buf);
    prop << file_properties;

    std::ofstream fl(&file_stream_buf);
    prop << file;
}

asio::streambuf::const_buffers_type fh::FileHandler::GetFileProperties()
{
    return file_properties_stream_buf.data();
}

asio::streambuf::const_buffers_type fh::FileHandler::GetFile()
{
    return file_stream_buf.data();
}