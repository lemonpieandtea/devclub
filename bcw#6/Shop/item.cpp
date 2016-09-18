#include "item.h"

std::set<Item*> Item::items;

Item::Item(const std::string& title, Category* category) : title(title), category(category) {
    if ( category == NULL ) {
        throw WrongCategoryException();
    }
    
    std::cout << title << " created" << std::endl;
    
    category->addItem(this);
    
    items.insert(this);
}

Item::Item(const Item& originalItem) {
    items.insert(this);
    
    std::cout << title << " created (copy)" << std::endl;
}

const std::string& Item::getTitle() const {
    return title;
}

const Category* Item::getCategory() const {
    return category;
}

const std::set<Order*>& Item::getOrders() const {
    return orders;
}

const std::set<Item*>& Item::getItems() {
    return items;
}

void Item::setCategory(Category* newCategory) {
    if ( newCategory == NULL ) {
        delete this;
        
        return;
    }
    
    if ( newCategory != category ) {
        std::cout << title << " changes categoty..." << std::endl;
        
        category->removeItem(this);
        category = newCategory;
        category->addItem(this);
    }
}

void Item::addOrder(Order* newOrder) {
    if ( newOrder == NULL ) {
        throw WrongOrderItemException();
    }
    
    orders.insert(newOrder);
    
    std::cout << title << " was added to " << newOrder->getTitle() << " order" << std::endl;
}

void Item::removeOrder(Order* oldOrder) {
    if ( oldOrder == NULL ) {
        throw WrongOrderItemException();
    }
    
    orders.erase(oldOrder);
    
    std::cout << title << " was removed from " << oldOrder->getTitle() << " order" << std::endl;
}

Item::~Item() {
    if ( category != NULL ) {
        Category* oldCategory = category;
        
        category = NULL;
        oldCategory->removeItem(this);
    }
    
    for ( std::set<Order*>::iterator it = orders.begin(); it != orders.end(); it++ ) {
        Order* oldOrder = *it;
        
        orders.erase(it);
        oldOrder->removeItem(this);
        
    }
    
    items.erase(this);
    
    std::cout << title << " item destroyed..." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.getTitle();
    
    return out;
}
