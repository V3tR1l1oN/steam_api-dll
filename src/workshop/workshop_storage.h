#pragma once
#include <string>
#include <map>
#include <vector>

struct WorkshopItem {
    std::string title;
    std::string description;
    std::string preview;
    std::vector<std::string> tags;
    std::string contentPath;
};

class WorkshopStorage {
public:
    static WorkshopStorage& Instance();

    bool Init(const std::string& basePath);
    bool AddItem(const std::string& itemID, const WorkshopItem& item);
    bool GetItem(const std::string& itemID, WorkshopItem& item) const;
    std::vector<std::string> ListItems() const;
    bool RemoveItem(const std::string& itemID);

private:
    WorkshopStorage() = default;
    std::string m_basePath;
    std::map<std::string, WorkshopItem> m_items;
};