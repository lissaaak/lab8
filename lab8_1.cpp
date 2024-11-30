//1
#include <iostream>
#include <cstring> 


char* CopyString(const char* str) {
    if (str == nullptr) { // проверяем, пустая ли строка
        return nullptr; // возвращаем nullptr, если пустая
    }

    size_t length = 0;  // длина строки
    while (str[length] != '\0') { //если символ, расположенный по индексу lenght не является нулевым
        length++; // передвигаемся вперед
    }

    char* copy = new char[length + 1]; // выделяем место для массива символов длиной length + 1 (учитываем нулевой символ)

    std::memcpy(copy, str, length); // копируем length байт из области памяти str  в область памяти copy
    copy[length] = '\0'; // добавляем нулевой символ, чтобы строка была корректной

    return copy;
}


char* ConcatenateStrings(const char* a, const char* b) {
    size_t lengthA = 0, lengthB = 0;  // длины строк a и b

    if (a != nullptr) { // проверяем, существует ли строка a
        while (a[lengthA] != '\0') { // считаем длину строки a, пока строка не приравняется к нулевому символу
            lengthA++;
        }
    }

    if (b != nullptr) {  // тоже самое со строкой b
        while (b[lengthB] != '\0') {
            lengthB++;
        }
    }

    char* copy = new char[lengthA + lengthB + 1]; // выделяем место для массива символов длиной a + b (учитываем нулевой символ)

    std::memcpy(copy, a, lengthA); // копируем длину строки a из а в copy
    std::memcpy(copy + lengthA, b, lengthB); // копируем длину строки b из b в copy + lengthA

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