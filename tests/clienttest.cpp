#include "../chat/include/client.hpp"
#include "../chat/include/data.hpp"
#include <fstream>
#include <chrono>

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
    std::thread thrd;

public:
    ClientTest()
    {
        std::ifstream cin("messages.txt");

        std::string ip = "localhost";
        std::string port = "1000";
        cli = new ucc::Client(io_c, ip, port, &_data);        

        thrd = std::thread( [this](){ io_c.run(); } );

        cin >> quant;

        for (int i = 0; i < quant; ++i)
        {
            std::string msg;
            cin >> msg;

            test_msg.push_back(std::move(msg));

            cli->SendTo( _data.SetMessage(test_msg[i]) );
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    ~ClientTest()
    {
        delete cli;
        thrd.join();
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
    // file is open
    ASSERT_GT(quant, 0);
    ASSERT_EQ(test_msg.size(), quant);

    // data received
    ASSERT_GT(_data.GetMsgBufferSize(), 0);

    for (int element = 0; element < quant; ++element)
        EXPECT_EQ(test_msg[element], _data.GetMsgFromMsgBuffer(element));
}   

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}