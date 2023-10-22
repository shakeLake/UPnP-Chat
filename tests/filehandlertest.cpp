#include "../chat/include/filehandler.hpp"
#include <gtest/gtest.h>
#include <array>

TEST(FileHandlerTest, FileEQ)
{
    std::ifstream cin("files.txt");

    int quant;
    cin >> quant;
    ASSERT_GT(quant, 0);

    std::array<std::string, 2> fns {{"game.ch8", "ocoft.ciso"}};
    std::array<unsigned, 2> filelength {{264, 1130398272}};
    for (int i = 0; i < quant; ++i)
    {
        std::string path;
        cin >> path;

        fh::FileHandler file_handler(path);

        EXPECT_EQ(file_handler.GetFileName(), fns[i]);
        EXPECT_EQ(file_handler.GetLength(), filelength[i]);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}