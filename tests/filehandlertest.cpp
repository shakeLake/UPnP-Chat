#include "../chat/include/filehandler.hpp"
#include <gtest/gtest.h>
#include <array>

TEST(FileHandlerTest, FileEQ)
{
    ucd::Data user_data;

    std::ifstream cin("files.txt");

    int quant;
    cin >> quant;
    ASSERT_GT(quant, 0);

    std::array<std::string, 3> fns {{"background.png", "game.ch8", "ocoft.ciso"}};
    std::array<std::string, 3> prop {{"#background.png#1565098*", "#game.ch8#264*", "#ocoft.ciso#1130398272*"}};
    std::array<unsigned, 3> filelength {{1565098, 264, 1130398272}};

    for (int i = 0; i < quant; ++i)
    {
        std::string path;
        cin >> path;

        fh::FileHandler file_handler(path, &user_data);

        EXPECT_EQ(file_handler.GetFileName(), fns[i]);
        EXPECT_EQ(file_handler.GetLength(), filelength[i]);
        EXPECT_EQ(file_handler.GetFilePropertiesStr(), prop[i]);
        EXPECT_EQ(file_handler.GetStreamBufSize(), filelength[i]);
    }
}

TEST(FileHandlerTes, FileUnpackaging)
{
    ucd::Data user_data;

    std::ifstream cin("files.txt");

    int quant;
    cin >> quant;
    ASSERT_GT(quant, 0);

    std::array<std::string, 3> fns {{"background.png", "game.ch8", "ocoft.ciso"}};
    std::array<std::string, 3> prop {{"#background.png#1565098*", "#game.ch8#264*", "#ocoft.ciso#1130398272*"}};
    std::array<unsigned, 3> filelength {{1565098, 264, 1130398272}};

    for (int i = 0; i < quant; ++i)
    {
        std::string path;
        cin >> path;

        fh::FileHandler file_handler(path, &user_data);

        fh::FileHandler backToNormal(file_handler.GetFilePropertiesStr(), file_handler.GetFileUnpack(), &user_data);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}