#ifndef UPDATER_HPP_
#define UPDATER_HPP_

namespace UUpdater
{
class Update
{
private:
    asio::io_context io_c;
    asio::ip::tcp::resolver rslvr;

    asio::ip::tcp::resolver::result_type endpnt;
    asio::error_code er_code;

    asio::ip::tcp::socket sckt;

private:
    void CurrentStateDeleter();
    void RequestNewState()    

    void Connect();

public:
    Update(std::string&, std::string&);
    ~Update() = default;

};
}

#endif /* UPDATER_HPP_ */