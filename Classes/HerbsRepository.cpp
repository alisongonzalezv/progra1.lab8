#include "HerbsRepository.h"
#include <stdexcept>

HerbsRepository::HerbsRepository() {
    auto data = DataLoader::LoadFromFile("herbs.txt");
    data_ = std::move(data);
}

int HerbsRepository::GetAvailableQuantity(const std::string& herbType) const {
    auto it = data_.find(herbType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de hierba desconocido: " + herbType);
    }
    return std::stoi(it->second[0]);
}

void HerbsRepository::UpdateQuantity(const std::string& herbType, int newQuantity) {
    auto it = data_.find(herbType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de hierba desconocido: " + herbType);
    }
    it->second[0] = std::to_string(newQuantity);
}
