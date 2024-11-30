//1
#include <iostream>
#include <cstring> 


char* CopyString(const char* str) {
    if (str == nullptr) { // ���������, ������ �� ������
        return nullptr; // ���������� nullptr, ���� ������
    }

    size_t length = 0;  // ����� ������
    while (str[length] != '\0') { //���� ������, ������������� �� ������� lenght �� �������� �������
        length++; // ������������� ������
    }

    char* copy = new char[length + 1]; // �������� ����� ��� ������� �������� ������ length + 1 (��������� ������� ������)

    std::memcpy(copy, str, length); // �������� length ���� �� ������� ������ str  � ������� ������ copy
    copy[length] = '\0'; // ��������� ������� ������, ����� ������ ���� ����������

    return copy;
}


char* ConcatenateStrings(const char* a, const char* b) {
    size_t lengthA = 0, lengthB = 0;  // ����� ����� a � b

    if (a != nullptr) { // ���������, ���������� �� ������ a
        while (a[lengthA] != '\0') { // ������� ����� ������ a, ���� ������ �� ������������ � �������� �������
            lengthA++;
        }
    }

    if (b != nullptr) {  // ���� ����� �� ������� b
        while (b[lengthB] != '\0') {
            lengthB++;
        }
    }

    char* copy = new char[lengthA + lengthB + 1]; // �������� ����� ��� ������� �������� ������ a + b (��������� ������� ������)

    std::memcpy(copy, a, lengthA); // �������� ����� ������ a �� � � copy
    std::memcpy(copy + lengthA, b, lengthB); // �������� ����� ������ b �� b � copy + lengthA

    copy[lengthA + lengthB] = '\0';

    return copy;
}

/*
int main() {
    const char* str1 = "jsjdd";
    const char* str2 = "AAAAAAA";

    char* copy = CopyString(str1);
    std::cout << copy << std::endl;
    delete[] copy;

    char* copy1 = ConcatenateStrings(str1, str2);
    std::cout << copy1 << std::endl;
    delete[] copy1;

    return 0;
}*/