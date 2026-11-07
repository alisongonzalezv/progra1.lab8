#include "Headers/PizzaBuilder.h"
#include <iostream>

// 1. Incluir windows.h solo en Windows
#ifdef _WIN32
    #include <windows.h>
#endif

int main() {
    // 2. Configurar la consola a UTF-8 solo en Windows
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
