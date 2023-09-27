#include "../../chat/include/server.hpp"
#include <fstream>

class ServerTest : public ::testing::Test
{
private:
    asio::io_context io_c;

    ucs::Server* srv;
    ucd::Data server_data;

    int count;
    std::vector<std::string> test_msg;
    std::string current_test;

    std::ifstream cin;

protected:
    ServerTest()
    {
        count = -1;
        cin.open("testcases/messages.txt");

        srv = new ucs::Server(io_c, "1000", &server_data);        

        int quant;
        cin << quant;

        for (int i = 0; i < quant; ++i)
        {
            std::string msg;
            cin << msg;

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
        count += 1;
    }

};

TEST_F(ServerTest, isConnected)
{
    ASSERT_EQ(srv->isConnected(), true);   
}   

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}