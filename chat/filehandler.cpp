#include "include/filehandler.hpp"

fh::FileHandler::FileHandler(std::string& file_path, ucd::Data* u_d)
{
    user_data = u_d;

    fin.open(file_path, std::ios_base::binary);

    if (fin.is_open())
        good = true;
    else  
        good = false;

    SetLength();

    SeparateFilename(file_path);

    file_properties = '#' + filename + '#' + std::to_string(length) + '*';

    Serialization();
    Packaging();
}

fh::FileHandler::FileHandler(std::string& prop, asio::streambuf& strbuffile, ucd::Data* u_d)
{
    user_data = u_d;

    SeparateProperties(prop);
    Deserialization(strbuffile);
}

fh::FileHandler::~FileHandler()
{
	user_data->Log("File Handler destroyed");
    fin.close();
}

void fh::FileHandler::SeparateFilename(std::string& path)
{
	user_data->Log("Separate Filename");

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

void fh::FileHandler::SetLength()
{
	user_data->Log("Set Length");

    fin.seekg(0, fin.end);
    length = fin.tellg();
    fin.seekg(0, fin.beg);
}

void fh::FileHandler::Serialization()
{
	user_data->Log("Serialization");

    std::stringstream str_stream;
    str_stream << fin.rdbuf();

    file = std::move(str_stream.str()); 
}

void fh::FileHandler::Packaging()
{
	user_data->Log("Packaging");

    std::ostream prop(&file_properties_stream_buf);
    prop << file_properties;

    std::ostream fl(&file_stream_buf);
    fl << file;
}

void fh::FileHandler::SeparateProperties(std::string& prop)
{
	user_data->Log("Separate Properties");

    for (unsigned let = 1; let < prop.size(); ++let)
    {
        if (prop[let] == '#')
            filename = prop.substr(1, let - 1);
        else if (prop[let] == '*')
            length = stoi(prop.substr(filename.size() + 2, let - 1));
    }
}

void fh::FileHandler::Deserialization(asio::streambuf& strbuffile)
{
	user_data->Log("Deserialization");

    std::istream is(&strbuffile);

    file.resize(length);
    for (int i = 0; i < length; ++i)
        is.get(file[i]);

    std::string path = "folder/" + filename;

    fout.open(path, std::ios_base::binary);

    if (fout.is_open())
        good = true;
    else  
        good = false;

    fout.write(file.c_str(), length);

    fout.close();

	user_data->Log("Deserialization finished");
}

asio::streambuf::const_buffers_type fh::FileHandler::GetFileProperties()
{
    return file_properties_stream_buf.data();
}

asio::streambuf::const_buffers_type fh::FileHandler::GetFile()
{
    return file_stream_buf.data();
}

std::string fh::FileHandler::GetFileName()
{
    return filename;
}

unsigned fh::FileHandler::GetLength()
{
    return length;
}

asio::streambuf& fh::FileHandler::GetFileUnpack()
{
    return file_stream_buf;
}

unsigned fh::FileHandler::GetStreamBufSize()
{
    return file_stream_buf.size();
}

std::string& fh::FileHandler::GetFilePropertiesStr()
{
    return file_properties;
}

bool fh::FileHandler::isGood()
{
    return good;
}