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
������ �����:
�������� �� C++ �������� �������� ���������� �������.
�����: �������� �������� ���, ��� ������� ������ ��� ��� ���, ��-��������� (����� ����� ������ �������� � ����� �� �� �������� �� ���� ����� � ����� �� ������; �� ��� �������� �� ������ ������). �����: �������� �/��� �������� ���� C++ ��������� ���, ����� �� �� ���� ������ ������� � ���������. (��������, �� ������ �������� � ��� ������� Debian 9.) �����: �� ���� ����������� �������� ���� � docx/pdf ��������, ������������ ������� ���� ��������� ������.
������ ��������� ����� ��������� ����, a-zA-Z. ����� (�����) ������ ������ ��������� ��������. ������� ����� �������� � ��������� (lowercase). ����������� ����� ������� �� ������� (�� ��������), ����� �� �������� (�� �����������). �������� ���� ������� �������, ����� �����, ����������� - ������ (����� ����)
������� ������ ����� ������� �� �����, ��������� - �������� � ����. ����� ������ ����� ������� �� ���������� ��������� ������:
./freq [input_file] [output_file]
��� ������.
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
P. S.: �������� ��������� - ��������� ����� 1, � ������ ������� ����� ����������� ������ ���, � ����� ��� ���������
P.P.S.: ������������� ������� ��������� � ��������������, �� ����� ������� ������ ������ �������� �� 1-�� ���� (��������� ������ - ������ ��������� 1 ����� � ��������)
*/