#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <set>
#include "id.h"
#include "item.h"

class Item;

class WrongItemCategoryException {};

class Category : public Id {
    private:
        std::string title;
        std::set<Item*> items;
        static std::set<Category*> categories;
        
    public:
        Category(const std::string& title);
        Category(const Category& originalCategory);
        const std::string& getTitle() const;
        const std::set<Item*>& getItems() const;
        static const std::set<Category*>& getCategories();
        void addItem(Item* newItem);
        void removeItem(Item* oldItem);
        ~Category();
};

std::ostream& operator<<(std::ostream& out, const Category& category);

#endif // CATEGORY_H
