#include "customer.h"

std::set<Customer*> Customer::customers;

Customer::Customer(const std::string& title) : title(title) {
    customers.insert(this);
    
    std::cout << title << " created" << std::endl;
}

Customer::Customer(const Customer& originalCustomer) {
    customers.insert(this);
    
    std::cout << title << " created" << std::endl;
}

const std::string& Customer::getTitle() const {
    return title;
}

const std::set<Order*>& Customer::getOrders() const {
    return orders;
}

const std::set<Customer*>& Customer::getCustomers() {
    return customers;
}

void Customer::addOrder(Order* newOrder) {
    if ( newOrder == NULL ) {
        throw WrongOrderCustomerException();
    }
    
    orders.insert(newOrder);
    
    std::cout << newOrder->getTitle() << " was added to " << title << " customer" << std::endl;
}

void Customer::removeOrder(Order* oldOrder) {
    if ( oldOrder == NULL ) {
        throw WrongOrderCustomerException();
    }
    
    if ( orders.find(oldOrder) != orders.end() ) {
        orders.erase(oldOrder);
        
        std::cout << oldOrder->getTitle() << " was removed from " << title << " customer" << std::endl;
        
        delete oldOrder;
    }
}

Customer::~Customer() {
    for ( std::set<Order*>::iterator it = orders.begin(); it != orders.end(); it++ ) {
        Order* oldOrder = *it;
        
        orders.erase(it);
        
        delete oldOrder;
    }
    
    customers.erase(this);
    
    std::cout << title << " customer destroyed..." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Customer& customer) {
    out << customer.getTitle();
    
    return out;
}
