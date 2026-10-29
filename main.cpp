#include "PizzaBuilder.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    try {
        PizzaBuilder builder;

        builder.BuildPizza();
        builder.DisplayFinalPizza();

    } catch (const std::exception& ex) {
        std::cerr << "Error fatal: " << ex.what() << std::endl;
        return 1;
    }

    std::cout << "\nPresiona Enter para continuar...";
    std::cin.get();
    return 0;
}