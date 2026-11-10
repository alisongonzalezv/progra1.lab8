#include "PizzaBuilder.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include "IngredientSelector.h"
#include "TomatoesRepository.h"
#include "CheeseRepository.h"
#include "MeatsRepository.h"

PizzaBuilder::PizzaBuilder() {
}

void PizzaBuilder::WaitForEnterAndClear() {
    std::cout << "\nPresiona Enter para continuar...";
    std::string line;
    std::getline(std::cin, line);
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool PizzaBuilder::QuiereSeguirAgregandoIngrediente(const std::string& ingrediente) {
    while (true) {
        std::cout << "\n¿Quieres seguir agregando " << ingrediente << "?" << std::endl;
        std::cout << "1. Sí" << std::endl;
        std::cout << "2. No, pasar al siguiente ingrediente" << std::endl;
        std::cout << "Elige una opción: ";

        std::string opcion;
        std::getline(std::cin, opcion);

        if (opcion == "1") {
            return true;
        }
        if (opcion == "2") {
            return false;
        }

        std::cout << "Opción no válida. Escribe 1 o 2." << std::endl;
    }
}

void PizzaBuilder::BuildPizza() {
    std::cout << "=== Constructor de pizza ===" << std::endl;
    std::cout << "¡Vamos a armar tu pizza!" << std::endl;

    SelectTomatoes();
    IrAlSiguienteIngrediente();
    WaitForEnterAndClear();
}

void PizzaBuilder::IrAlSiguienteIngrediente() {
    int siguiente = 2;

    switch (siguiente) {
    case 2:
        SelectCheese();
    case 3:
        SelectMeat();
    default:
        std::cout << "No existen más ingredientes para tu pizza." << std::endl;
        break;
    }
}

void PizzaBuilder::MostrarGrupo(const std::string& nombre, const std::vector<std::string>& ingredientes) const {
    std::cout << nombre << " (" << ingredientes.size() << "):" << std::endl;
    if (ingredientes.empty()) {
        std::cout << "- Ninguno" << std::endl;
        return;
    }

    for (const auto& ingrediente : ingredientes) {
        std::cout << "- " << ingrediente << std::endl;
    }
}

int PizzaBuilder::ContarTiposAgregados() const {
    int tipos = 0;
    if (!selectedTomatoes_.empty()) {
        ++tipos;
    }
    if (!selectedCheeses_.empty()) {
        ++tipos;
    }
    if (!selectedMeats_.empty()) {
        ++tipos;
    }
    return tipos;
}

void PizzaBuilder::DisplayFinalPizza() const {
    std::cout << "Tu pizza tiene los siguientes ingredientes:" << std::endl;
    std::cout << std::endl;
    MostrarGrupo("Tomates", selectedTomatoes_);
    MostrarGrupo("Queso", selectedCheeses_);
    MostrarGrupo("Carnes", selectedMeats_);

    std::cout << std::endl;
    switch (ContarTiposAgregados()) {
    case 0:
        std::cout << "No agregaste ingredientes a tu pizza." << std::endl;
        break;
    case 1:
        if (!selectedTomatoes_.empty()) {
            std::cout << "Tu pizza solo tiene tomate." << std::endl;
        } else {
            std::cout << "Tu pizza tiene un solo tipo de ingrediente." << std::endl;
        }
        break;
    case 2:
        std::cout << "Tu pizza ya tiene un segundo ingrediente." << std::endl;
        break;
    default:
        std::cout << "Tu pizza ya tiene los tres ingredientes principales." << std::endl;
        break;
    }

    std::cout << "¡Buen provecho!" << std::endl;
}

void PizzaBuilder::SelectTomatoes() {
    IngredientSelector<TomatoesRepository> selector(tomatoRepo_, availableTomatoes_, "tomate");
    bool yaPregunto = false;

    while (true) {
        std::cout << "\n--- Selección de tomates ---" << std::endl;
        selector.DisplayAvailableIngredients();

        std::cout << "\nIngresa el tipo de tomate (o 'listo' para terminar): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);

        if (userChoice == "listo" || userChoice == "LISTO") {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            break;
        }

        bool exitosa = selector.AddIngredientToPizza(userChoice, selectedTomatoes_);
        if (exitosa) {
            std::cout << "La selección fue exitosa." << std::endl;
        } else {
            std::cout << "La selección no fue exitosa." << std::endl;
        }

        if (exitosa && !yaPregunto) {
            yaPregunto = true;
            if (!QuiereSeguirAgregandoIngrediente("tomate")) {
#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
                return;
            }
        }

        WaitForEnterAndClear();
    }
}

void PizzaBuilder::SelectCheese() {
    IngredientSelector<CheeseRepository> selector(cheeseRepo_, availableCheeses_, "queso");
    bool yaPregunto = false;

    while (true) {
        std::cout << "\n--- Selección de quesos ---" << std::endl;
        selector.DisplayAvailableIngredients();

        std::cout << "\nIngresa el tipo de queso (o 'listo' para terminar): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);

        if (userChoice == "listo" || userChoice == "LISTO") {
            break;
        }

        bool exitosa = selector.AddIngredientToPizza(userChoice, selectedCheeses_);
        if (exitosa) {
            std::cout << "La selección fue exitosa." << std::endl;
        } else {
            std::cout << "La selección no fue exitosa." << std::endl;
        }

        if (exitosa && !yaPregunto) {
            yaPregunto = true;
            if (!QuiereSeguirAgregandoIngrediente("queso")) {
#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
                return;
            }
        }

        WaitForEnterAndClear();
    }
}

void PizzaBuilder::SelectMeat() {
    IngredientSelector<MeatsRepository> selector(meatRepo_, availableMeats_, "carne");
    bool yaPregunto = false;

    while (true) {
        std::cout << "\n--- Selección de carnes ---" << std::endl;
        selector.DisplayAvailableIngredients();

        std::cout << "\nIngresa el tipo de carne (o 'listo' para terminar): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);

        if (userChoice == "listo" || userChoice == "LISTO") {
            break;
        }

        bool exitosa = selector.AddIngredientToPizza(userChoice, selectedMeats_);
        if (exitosa) {
            std::cout << "La selección fue exitosa." << std::endl;
        } else {
            std::cout << "La selección no fue exitosa." << std::endl;
        }

        if (exitosa && !yaPregunto) {
            yaPregunto = true;
            if (!QuiereSeguirAgregandoIngrediente("carne")) {
#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
                return;
            }
        }

        WaitForEnterAndClear();
    }
}
