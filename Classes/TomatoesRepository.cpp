#include "TomatoesRepository.h"
#include "DataLoader.h"
#include <string>
#include <stdexcept>
#include <utility>

TomatoesRepository::TomatoesRepository() {
    auto data = DataLoader::LoadFromFile("tomatoes.txt");
    data_ = std::move(data);
}

int TomatoesRepository::GetAvailableQuantity(const std::string& tomatoType) const {
    auto it = data_.find(tomatoType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de tomate desconocido: " + tomatoType);
    }
    return std::stoi(it->second[0]);
}

void TomatoesRepository::UpdateQuantity(const std::string& tomatoType, int newQuantity) {
    auto it = data_.find(tomatoType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de tomate desconocido: " + tomatoType);
    }
    it->second[0] = std::to_string(newQuantity);
}