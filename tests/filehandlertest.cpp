#include "../chat/include/filehandler.hpp"
#include <gtest/gtest.h>

class FileHandlerTest : public ::testing::Test
{
protected:
    std::vector<std::string> file_paths;

    std::ifstream fin;
    int quant;

protected:
    FileHandlerTest()
    {
        fin.open("testcases/files.txt"); 

        fin >> quant;
        for (int i = 0; i < quant; ++i)
        {
            std::string path;
            fin >> path;

            file_paths.push_back(path);
        }
    }

    ~FileHandler()
    {
        fin.close();
    }

};

TEST_F(FileHandlerTest, FilePropertiesChecker)
{
    ASSERT_GT(quant, 0);
    ASSERT_EQ(file_paths.size(), quant);

    for (int it = 0; it < quant; ++it)
    {

    }
}

TEST(FileHandlerTest, FilePropertiesChecker)
{
    for ()
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}