#include "workshop_storage.h"
#include <fstream>
#include <sstream>
#include <filesystem>
namespace fs = std::filesystem;

WorkshopStorage& WorkshopStorage::Instance() {
    static WorkshopStorage instance;
    return instance;
}

bool WorkshopStorage::Init(const std::string& basePath) {
    m_basePath = basePath;
    if (!fs::exists(m_basePath)) {
        fs::create_directories(m_basePath);
    }
    // Загружаем существующие items из файлов
    // Для простоты пока просто создаём директорию
    return true;
}

bool WorkshopStorage::AddItem(const std::string& itemID, const WorkshopItem& item) {
    m_items[itemID] = item;
    // В реальной реализации нужно сохранять в файл
    return true;
}

bool WorkshopStorage::GetItem(const std::string& itemID, WorkshopItem& item) const {
    auto it = m_items.find(itemID);
    if (it != m_items.end()) {
        item = it->second;
        return true;
    }
    return false;
}

std::vector<std::string> WorkshopStorage::ListItems() const {
    std::vector<std::string> result;
    for (auto& pair : m_items) {
        result.push_back(pair.first);
    }
    return result;
}

bool WorkshopStorage::RemoveItem(const std::string& itemID) {
    return m_items.erase(itemID) > 0;
}