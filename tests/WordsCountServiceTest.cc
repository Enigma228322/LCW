#include "WordsCountService/WordsCountServiceImpl.hh"

#include <gtest/gtest.h>

class WordsCountServiceTests : public ::testing::Test{
};

TEST_F(WordsCountServiceTests, count_words)
{
	std::string in_filename = "in.txt";
	std::string out_filename = "out.txt";
	{
		// prepare input text
		std::ofstream out(in_filename);
		out << "bdS bdS bdS bdS BDS asd asd asd asd fds fd fds asd asd bdS asd asd fds fd fds ASD bdS bdS bdS";
	}

	wordscount::WordsCountServiceImpl wordsCountService(in_filename.c_str(), out_filename.c_str());
	wordsCountService.count_words();
	wordsCountService.write_result();

	std::string expected_result = "asd 9\nbds 9\nfds 4\nfd 2\n";
	std::ifstream in(out_filename);
	std::string result_string;
	result_string.reserve(expected_result.size());
	{
		std::ifstream in(out_filename);
		while (!in.eof()) {
			std::string word;
			std::string num;
			in >> word >> num;
			if (word.size() > 0 || num.size() > 0) {
				result_string += word + " " + num + '\n';
			}
		}
	}

	EXPECT_EQ(result_string, expected_result);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}