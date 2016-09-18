#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <set>
#include "id.h"
#include "order.h"

class Order;

class WrongOrderCustomerException {};

class Customer : public Id {
    private:
        std::string title;
        std::set<Order*> orders;
        static std::set<Customer*> customers;
        
    public:
        Customer(const std::string& title);
        Customer(const Customer& originalCustomer);
        const std::string& getTitle() const;
        const std::set<Order*>& getOrders() const;
        static const std::set<Customer*>& getCustomers();
        void addOrder(Order* newOrder);
        void removeOrder(Order* oldOrder);
        ~Customer();
};

std::ostream& operator<<(std::ostream& out, const Customer& customer);

#endif // CUSTOMER_H
