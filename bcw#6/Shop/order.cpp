#include "order.h"

std::set<Order*> Order::orders;

Order::Order(const std::string& title, Customer* customer, Item* initialItem) : title(title), customer(customer) {
    if ( customer == NULL ) {
        throw WrongCustomerException();
    }
    
    if ( initialItem == NULL ) {
        throw WrongItemOrderException();
    }
    
    std::cout << title << " created" << std::endl;
    
    addItem(initialItem);
    customer->addOrder(this);
    
    orders.insert(this);
    
    std::cout << customer->getTitle() << " was listed to " << title;
    std::cout << " order with " << initialItem->getTitle() << std::endl;
}

Order::Order(const Order& originalOrder) {
    orders.insert(this);
    
    std::cout << title << " created (copy)" << std::endl;
}

const std::string& Order::getTitle() const {
    return title;
}

const Customer* Order::getCustomer() const {
    return customer;
}

const std::set<Item*>& Order::getItems() const {
    return items;
}

const std::set<Order*>& Order::getOrders() {
    return orders;
}

void Order::addItem(Item* newItem) {
    if ( newItem == NULL ) {
        throw WrongItemOrderException();
    }
    
    items.insert(newItem);
    newItem->addOrder(this);
}

void Order::removeItem(Item* oldItem) {
    if ( oldItem == NULL ) {
        throw WrongItemOrderException();
    }
    
    items.erase(oldItem);
    
    if ( items.empty() ) {
        customer->removeOrder(this);
    }
}

Order::~Order() {
    if ( customer != NULL ) {
        Customer* oldCustomer = customer;
        customer = NULL;
    }
    
    for ( std::set<Item*>::iterator it = items.begin(); it != items.end(); it++ ) {
        Item* oldItem = *it;
        
        items.erase(it);
        
        oldItem->removeOrder(this);
    }
    
    orders.erase(this);
    
    if ( this != NULL ) {
        std::cout << title << " order destroyed..." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Order& order) {
    out << order.getTitle();
    
    return out;
}
