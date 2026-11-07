#include "PizzaBuilder.h"
#include <cstdlib>
#include <iostream>
#include <string>

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

bool PizzaBuilder::QuiereSeguirAgregando(const std::string& ingredienteNombre) {
    std::cout << "\n¿Deseas agregar otro tipo de " << ingredienteNombre << "? (s/n): ";
    char respuesta;
    std::cin >> respuesta;
    std::cin.ignore(10000, '\n');
    return (respuesta == 's' || respuesta == 'S');
}

void PizzaBuilder::IrAlSiguienteIngrediente() {
    WaitForEnterAndClear();
}

void PizzaBuilder::SelectTomatoes() {
    IngredientSelector<TomatoesRepository> selector(tomatoRepo_, availableTomatoes_, "Tomate");
    do {
        selector.DisplayAvailableIngredients();
        std::cout << "\nIngresa el nombre del tipo de Tomate a agregar: ";
        std::string nombreIngrediente;
        std::getline(std::cin, nombreIngrediente);

        selector.AddIngredientToPizza(nombreIngrediente, selectedTomatoes_);
    } while (QuiereSeguirAgregando("Tomate"));
}

void PizzaBuilder::SelectCheese() {
    IngredientSelector<CheeseRepository> selector(cheeseRepo_, availableCheeses_, "Queso");
    do {
        selector.DisplayAvailableIngredients();
        std::cout << "\nIngresa el nombre del tipo de Queso a agregar: ";
        std::string nombreIngrediente;
        std::getline(std::cin, nombreIngrediente);

        selector.AddIngredientToPizza(nombreIngrediente, selectedCheeses_);
    } while (QuiereSeguirAgregando("Queso"));
}

void PizzaBuilder::SelectMeat() {
    // Implementado por el companero asignado a carnes
}

void PizzaBuilder::SelectHerb() {
    // Implementado por el companero asignado a hierbas
}

void PizzaBuilder::BuildPizza() {
    std::cout << "=== CONSTRUCCION DE PIZZA ===\n\n";

    SelectTomatoes();
    IrAlSiguienteIngrediente();

    SelectCheese();
    IrAlSiguienteIngrediente();
}

void PizzaBuilder::MostrarGrupo(const std::string& nombre, const std::vector<std::string>& ingredientes) const {
    std::cout << "- " << nombre << ": ";
    if (ingredientes.empty()) {
        std::cout << "Ninguno\n";
        return;
    }
    for (size_t i = 0; i < ingredientes.size(); ++i) {
        std::cout << ingredientes[i];
        if (i < ingredientes.size() - 1) std::cout << ", ";
    }
    std::cout << "\n";
}

int PizzaBuilder::ContarTiposAgregados() const {
    return selectedTomatoes_.size() + selectedCheeses_.size() + selectedMeats_.size() + selectedHerbs_.size();
}

void PizzaBuilder::DisplayFinalPizza() const {
    std::cout << "=== RESUMEN DE TU PIZZA ===\n";
    MostrarGrupo("Tomates", selectedTomatoes_);
    MostrarGrupo("Quesos", selectedCheeses_);
    MostrarGrupo("Carnes", selectedMeats_);
    MostrarGrupo("Hierbas", selectedHerbs_);
    std::cout << "Total de tipos de ingredientes elegidos: " << ContarTiposAgregados() << "\n";
    std::cout << "============================\n";
}