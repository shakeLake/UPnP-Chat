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

    int quant = 0;
    std::vector<std::string> test_msg;
    std::thread thrd;

protected:
    ServerTest()
    {
        std::string port = "1000";
        srv = new ucs::Server(io_c, port, &_data);        

        thrd = std::thread( [this](){ io_c.run(); } );
    }

    ~ServerTest()
    {
        delete srv;
        thrd.join();
    }

};

TEST_F(ServerTest, DoesMessage)
{
    // connection
    ASSERT_EQ(srv->isConnected(), true);   

    std::ifstream cin("messages.txt");

    cin >> quant;
    ASSERT_GT(quant, 0);

    for (int i = 0; i < quant; ++i)
    {
        std::string msg;
        cin >> msg;

        test_msg.push_back(std::move(msg));

        srv->SendTo( _data.SetMessage(test_msg[i]) );
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // file is open
    ASSERT_EQ(test_msg.size(), quant);

    // data received
    ASSERT_EQ(_data.GetMsgBufferSize(), quant);

    for (int element = 0; element < quant; ++element)
        EXPECT_EQ(test_msg[element], _data.GetMsgFromMsgBuffer(element));
}   

// TEST_F(ServerTest, DoesFile)
// {
//     // connection
//     ASSERT_EQ(srv->isConnected(), true);   

//     std::ifstream cin("files.txt");

//     cin >> quant;
//     ASSERT_GT(quant, 0);

//     std::this_thread::sleep_for(std::chrono::seconds(10));

//     std::array<std::string, 3> fns {{"background.png", "game.ch8", "ocoft.ciso"}};
//     for (int i = 0; i < quant; ++i)
//     {
//         std::fstream file("folder/" + fns[i]);
//         EXPECT_EQ(file.is_open(), true);
//     }
// }   

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}