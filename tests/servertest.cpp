#include "../chat/include/server.hpp"
#include "../chat/include/data.hpp"
#include <fstream>

// gtest
#include <gtest/gtest.h>

class ServerTest : public ::testing::Test
{
protected:
    asio::io_context io_c;

    ucs::Server* srv;
    ucd::Data _data;

    int quant;
    std::vector<std::string> test_msg;

protected:
    ServerTest()
    {
        std::ifstream cin("/testcases/messagesserver.txt");

        std::string port = "1000";
        srv = new ucs::Server(io_c, port, &_data); 

        cin >> quant;

        for (int i = 0; i < quant; ++i)
        {
            std::string msg;
            cin >> msg;

            test_msg.push_back(std::move(msg));

            srv->SendTo( _data.SetMessage(test_msg[i]) );
        }

        cin.close();
    }

    ~ServerTest()
    {
        delete srv;
    }

};

TEST(ServerConnectionTest, isConnected)
{
    asio::io_context io_c;
    ucd::Data _data;

    std::string port = "1000";
    ucs::Server srv(io_c, port, &_data);        

    ASSERT_EQ(srv.isConnected(), true);   
}   

TEST_F(ServerTest, DoesMessage)
{
    ASSERT_GT(quant, 0);

    for (int element = 0; element < quant; ++element)
        EXPECT_EQ(test_msg[element], _data.GetMsgFromMsgBuffer(element));
}   

// for (int element = 0; element < quant; ++element)
//     srv->SendTo( _data.SetMessage(test_msg[element]) );

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}