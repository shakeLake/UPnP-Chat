#include "../chat/include/server.hpp"
#include "../chat/include/data.hpp"
#include <fstream>
#include <chrono>

// gtest
#include <gtest/gtest.h>

class ServerTest : public ::testing::Test
{
protected:
    asio::io_context io_c;

    ucs::Server* srv;
    ucd::Data _data;

    int count;
    std::vector<std::string> test_msg;
    std::string current_test;

    std::ifstream cin;

protected:
    ServerTest()
    {
        count = -1;
        cin.open("testcases/messages.txt");

        std::string port = "1000";
        srv = new ucs::Server(io_c, port, &_data);        

        int quant;
        cin >> quant;

        for (int i = 0; i < quant; ++i)
        {
            std::string msg;
            cin >> msg;

            test_msg.push_back(std::move(msg));
        }
    }

    ~ServerTest()
    {
        cin.close();
        delete srv;
    }

    void SetUp() override
    {
        if (count == -1)
        {
            count = 0;
            return;
        }

        current_test = std::move(test_msg[count]);
        
        srv->SendTo( _data.SetMessage(current_test) );

        count += 1;
    }

};

TEST_F(ServerTest, isConnected)
{
    ASSERT_EQ(srv->isConnected(), true);   
}   

TEST_F(ServerTest, DoesMessage)
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