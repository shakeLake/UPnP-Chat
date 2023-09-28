#include "../chat/include/client.hpp"
#include "../chat/include/data.hpp"
#include <fstream>

// gtest
#include <gtest/gtest.h>

class ClientTest : public ::testing::Test
{
protected:
    asio::io_context io_c;

    ucc::Client* cli;
    ucd::Data _data;

    int quant = 0;
    std::vector<std::string> test_msg;

public:
    ClientTest()
    {
        std::ifstream cin("/testcases/messagesclient.txt");

        std::string ip = "localhost";
        std::string port = "1000";
        cli = new ucc::Client(io_c, ip, port, &_data);        

        cin >> quant;

        for (int i = 0; i < quant; ++i)
        {
            std::string msg;
            cin >> msg;

            test_msg.push_back(std::move(msg));

            cli->SendTo( _data.SetMessage(test_msg[i]) );
        }
    }

    ~ClientTest()
    {
        delete cli;
    }

};

TEST(ClientConnectionTest, isConnected)
{
    asio::io_context io_c;
    ucd::Data _data;

    std::string ip = "localhost";
    std::string port = "1000";
    ucc::Client cli(io_c, ip, port, &_data);        

    ASSERT_EQ(cli.isConnected(), true);   
}   

TEST_F(ClientTest, DoesMessage)
{
    ASSERT_GT(quant, 0);

    for (int element = 0; element < quant; ++element)
        EXPECT_EQ(test_msg[element], _data.GetMsgFromMsgBuffer(element));
}   

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}