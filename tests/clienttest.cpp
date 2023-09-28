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

    int count;
    std::vector<std::string> test_msg;
    std::string current_test;

    std::ifstream cin;

protected:
    ClientTest()
    {
        count = -1;
        cin.open("testcases/messages.txt");

        std::string ip = "localhost";
        std::string port = "1000";
        cli = new ucc::Client(io_c, ip, port, &_data);        

        int quant;
        cin >> quant;

        for (int i = 0; i < quant; ++i)
        {
            std::string msg;
            cin >> msg;

            test_msg.push_back(std::move(msg));
        }
    }

    ~ClientTest()
    {
        cin.close();
        delete cli;
    }

    void SetUp() override
    {
        if (count == -1)
        {
            count = 0;
            return;
        }
        
        current_test = std::move(test_msg[count]);

        cli->SendTo( _data.SetMessage(current_test) );

        count += 1;
    }

};

TEST_F(ClientTest, isConnected)
{
    ASSERT_EQ(cli->isConnected(), true);   
}   

TEST_F(ClientTest, DoesMessage)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    ASSERT_GE(count, 1);
    EXPECT_EQ(current_test, _data.GetMsgFromMsgBuffer(count - 1));   
}   

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}