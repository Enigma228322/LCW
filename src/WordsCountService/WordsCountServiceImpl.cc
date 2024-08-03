#include "WordsCountService/WordsCountServiceImpl.hh"

namespace wordscount {

WordsCountServiceImpl::WordsCountServiceImpl(const char* in_filename, const char* out_filename): in(std::ifstream(in_filename)), out(std::ofstream(out_filename)) {
    words_map.reserve(MAX_UNIQUE_WORDS);
};

void WordsCountServiceImpl::count_words() {
    while (!in.eof()) {
        std::string s;
        in >> s;
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        ++words_map[s];
    }
    in.close();
}

void WordsCountServiceImpl::write_result() {
    std::vector<std::pair<std::string, uint32_t>> temporary_vector(words_map.begin(), words_map.end());
    std::sort(temporary_vector.begin(), temporary_vector.end(), [](std::pair<std::string, uint32_t>& a, std::pair<std::string, uint32_t>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });
    for (const auto& [k, v] : temporary_vector) {
        out << k << ' ' << v << '\n';
    }
    out.close();
}

WordsCountServiceImpl::~WordsCountServiceImpl() {}

} // namespace wordscount;