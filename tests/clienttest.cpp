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

protected:
    ClientTest()
    {
        std::string ip = "localhost";
        std::string port = "1000";
        cli = new ucc::Client(io_c, ip, port, &_data);        

        thrd = std::thread( [this](){ io_c.run(); } );
    }

    ~ClientTest()
    {
        delete cli;
        thrd.join();
    }

};

TEST_F(ClientTest, DoesMessage)
{
    // connection
    ASSERT_EQ(cli->isConnected(), true);   

    std::ifstream cin("messages.txt");

    cin >> quant;
    ASSERT_GT(quant, 0);

    for (int i = 0; i < quant; ++i)
    {
        std::string msg;
        cin >> msg;

        test_msg.push_back(std::move(msg));

        cli->SendTo( _data.SetMessage(test_msg[i]) );
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // file is open
    ASSERT_EQ(test_msg.size(), quant);

    // data received
    ASSERT_EQ(_data.GetMsgBufferSize(), quant);

    for (int element = 0; element < quant; ++element)
        EXPECT_EQ(test_msg[element], _data.GetMsgFromMsgBuffer(element));
}   

TEST(FileHandlerTest, FileEQ)
{
    // connection
    // ASSERT_EQ(cli->isConnected(), true);   

    std::ifstream cin("files.txt");

    int quant; //
    cin >> quant;
    ASSERT_GT(quant, 0);

    std::vector<std::string> fns {{"game.ch8", "ocoft.ciso"}};
    std::vector<unsigned> filelength {{264, 1130398536}};
    for (int i = 0; i < quant; ++i)
    {
        std::string path;
        cin >> path;

        fh::FileHandler file_handler(path);

        EXPECT_EQ(file_handler.GetFileName(), fns[i]);
        EXPECT_EQ(file_handler.GetLength(), filelength[i]);

        // cli->SendTo(&file_handler);
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}