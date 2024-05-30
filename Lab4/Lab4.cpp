#include <iostream>
#include <cstring>
#include <cstdlib>

// Определение длины строки
size_t my_strlen(const char* str) {
    size_t length = 0;
    while (*str++) {
        ++length;
    }
    return length;
}

// Конкатенация строк
char* my_strcat(char* dest, const char* src) {
    char* ptr = dest + my_strlen(dest);
    while (*src) {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}

// Копирование строки
char* my_strcpy(char* dest, const char* src) {
    char* ptr = dest;
    while ((*ptr++ = *src++));
    return dest;
}

// Сравнение строк
int my_strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// Изменение функций так, чтобы они использовали динамическую память
char* my_strdup(const char* str) {
    char* new_str = (char*)malloc(my_strlen(str) + 1);
    if (new_str) {
        my_strcpy(new_str, str);
    }
    return new_str;
}

void my_free(char* str) {
    free(str);
}

int main() {
    // Исходные строки
    char str1[] = "Hello, ";
    char str2[] = "world!";
    char str3[50];
    char str4[50];

    // Демонстрация работы функций
    std::cout << "Length of str1: " << my_strlen(str1) << std::endl;

    my_strcpy(str3, str1);
    std::cout << "Copy of str1: " << str3 << std::endl;

    my_strcat(str3, str2);
    std::cout << "Concatenation of str1 and str2: " << str3 << std::endl;

    std::cout << "Comparison of str1 and str2: " << my_strcmp(str1, str2) << std::endl;

    // Использование динамической памяти
    char* dyn_str1 = my_strdup(str1);
    char* dyn_str2 = my_strdup(str2);

    std::cout << "Dynamic copy of str1: " << dyn_str1 << std::endl;
    std::cout << "Dynamic copy of str2: " << dyn_str2 << std::endl;

    // Освобождение динамической памяти
    my_free(dyn_str1);
    my_free(dyn_str2);

    return 0;
}
