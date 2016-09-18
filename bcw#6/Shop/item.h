#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <set>
#include "id.h"
#include "category.h"
#include "order.h"

class Category;
class Order;

class WrongCategoryException {};
class WrongOrderItemException {};

class Item : public Id {
    private:
        std::string title;
        Category* category;
        std::set<Order*> orders;
        static std::set<Item*> items;
        
    public:
        Item(const std::string& title, Category* category);
        Item(const Item& originalItem);
        const std::string& getTitle() const;
        const Category* getCategory() const;
        const std::set<Order*>& getOrders() const;
        static const std::set<Item*>& getItems();
        void setCategory(Category* newCategory);
        void addOrder(Order* newOrder);
        void removeOrder(Order* oldOrder);
        ~Item();
};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif // ITEM_H
