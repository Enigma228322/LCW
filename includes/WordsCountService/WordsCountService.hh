#pragma once

#include <fstream>
#include <string>
#include <unordered_map>

namespace wordscount {

class WordsCountService {
public:
    virtual void count_words() = 0;
    virtual void write_result() = 0;
    virtual ~WordsCountService() = default;
};

} // namespace wordscount;