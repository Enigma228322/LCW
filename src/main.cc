#include <iostream>
#include "WordsCountService/WordsCountService.hh"
#include "WordsCountService/WordsCountServiceImpl.hh"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Pass in.txt and out.txt";
        return 0;
    }
    std::unique_ptr<wordscount::WordsCountService> wordsCountServiceInstance = std::make_unique<wordscount::WordsCountServiceImpl>(argv[1], argv[2]);
    wordsCountServiceInstance->count_words();
    wordsCountServiceInstance->write_result();
    return 0;
}

/*
«адача така€:
Ќапишите на C++ нехитрую считалку частотного словар€.
¬ажно: напишите примерно так, как сегодн€ пишете код дл€ бо€, по-взрослому (часть особо редких проверок в стиле Уа не кончилс€ ли дискФ можно и нужно не писать; но все проверки не писать нельз€). ¬ажно: напишите и/или упакуйте вашу C++ программу так, чтобы мы ее тоже сумели собрать и запустить. (Ќапример, на боевых серверах у нас сегодн€ Debian 9.) ¬ажно: не надо копипастить простыню кода в docx/pdf документ, человечество недавно таки придумало аттачи.
—ловом считаетс€ набор латинских букв, a-zA-Z. Ћюбой (любой) другой символ считаетс€ пробелом. –егистр нужно привести к строчному (lowercase). —ортировать нужно сначала по частоте (по убыванию), потом по алфавиту (по возрастанию). ¬ыводить тоже сначала частоту, потом слово, разделитель - пробел (ровно один)
¬ходные данные нужно считать из файла, результат - записать в файл. »мена файлов нужно прин€ть из аргументов командной строки:
./freq [input_file] [output_file]
¬от пример.
$ cat in.txt
The time has come, the Walrus said,
to talk of many things...
$ freq in.txt out.txt
$ cat out.txt
  2 the
  1 come
  1 has
  1 many
  1 of
  1 said
  1 talk
  1 things
  1 time
  1 to
  1 walrus
P. S.: скорость программы - приоритет номер 1, в первую очередь будет оцениватьс€ именно она, а затем все остальное
P.P.S.: многопоточные решени€ разрешены и приветствуютс€, но такие решени€ должны быстро работать на 1-ом €дре (провер€ем просто - руками оставл€ем 1 поток и замер€ем)
*/