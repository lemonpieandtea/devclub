#include <iostream>
#include "category.h"
#include "item.h"
#include "order.h"
#include "customer.h"
#include "templates.cpp"

using namespace std;

#define PRINT_EXISTED   cout << "***********************" << endl; \
                        cout << "All existed categories:" << endl; \
                        cout << Category::getCategories(); \
                        cout << "--------------------" << endl; \
                        cout << "All existed items:" << endl; \
                        cout << Item::getItems(); \
                        cout << "--------------------" << endl; \
                        cout << "All existed orders:" << endl; \
                        cout << Order::getOrders(); \
                        cout << "--------------------" << endl; \
                        cout << "All existed customers:" << endl; \
                        cout << "--------------------" << endl; \
                        cout << Customer::getCustomers(); \
                        cout << "***********************" << endl;

#define PRINT_SEPARATOR cout << "***********************" << endl;

int main() {
    PRINT_EXISTED
    
    Category* mobile = new Category("Mobile");
    Category* photo = new Category("Photo");
    Category* laptops = new Category("Laptops");
    
    PRINT_SEPARATOR
    
    Item* nokia3310 = new Item("Nokia 3310", mobile);
    Item* samsungGalaxyNote3 = new Item("Samsung Galaxy Note 3", mobile);
    Item* lgOptimusGE975 = new Item("LG Optimus E975", mobile);
    Item* gygabyteGSmartRioR1 = new Item("Gygabyte GSmart Rio R1", laptops);
    
    PRINT_SEPARATOR
    
    Item* nikonCoolpixS2700 = new Item("Nikon Coolpix S2700", photo);
    Item* samsungDV150 = new Item("Samsung DV150", mobile);
    Item* olympusVH210 = new Item("Olympus VH210", photo);
    Item* canonPoverShotA1400 = new Item("Canon PoverShot A1400", photo);
    
    PRINT_SEPARATOR
    
    Item* hpCompaqPresarioCQ58 = new Item("HP Compaq Presario CQ58", laptops);
    Item* lenovoIdeaPadG580G = new Item("Lenovo Idea Pad G580G", laptops);
    Item* acerAspireE1 = new Item("Acer Aspire E1", photo);
    Item* fujitsuLifebookAH512 = new Item("Fujitsu Lifebook AH512", laptops);
    
    PRINT_SEPARATOR
    
    Customer* petro = new Customer("Petro");
    Customer* andry = new Customer("Andry");
    Customer* dmitry = new Customer("Dmitry");
    
    PRINT_SEPARATOR
    
    Order* workItems = new Order("Work Items", petro, nokia3310);
    Order* giftItems = new Order("Gift Items", andry, nikonCoolpixS2700);
    Order* travelItems = new Order("Travel Items", dmitry, hpCompaqPresarioCQ58);
    
    PRINT_SEPARATOR
    
    workItems->addItem(samsungGalaxyNote3);
    workItems->addItem(canonPoverShotA1400);
    workItems->addItem(acerAspireE1);
    workItems->addItem(fujitsuLifebookAH512);
    
    PRINT_SEPARATOR
    
    giftItems->addItem(nokia3310);
    giftItems->addItem(samsungDV150);
    giftItems->addItem(hpCompaqPresarioCQ58);
    giftItems->addItem(fujitsuLifebookAH512);
    
    PRINT_SEPARATOR
    
    travelItems->addItem(gygabyteGSmartRioR1);
    travelItems->addItem(lgOptimusGE975);
    travelItems->addItem(nokia3310);
    travelItems->addItem(olympusVH210);
    travelItems->addItem(samsungDV150);
    travelItems->addItem(acerAspireE1);
    travelItems->addItem(lenovoIdeaPadG580G);
    travelItems->addItem(fujitsuLifebookAH512);
    
    PRINT_SEPARATOR
    
    cout << *gygabyteGSmartRioR1 << ": " << *gygabyteGSmartRioR1->getCategory() << endl;
    cout << *samsungDV150 << ": " << *samsungDV150->getCategory() << endl;
    cout << *acerAspireE1 << ": " << *acerAspireE1->getCategory() << endl;
    
    PRINT_SEPARATOR
    
    gygabyteGSmartRioR1->setCategory(mobile);
    samsungDV150->setCategory(photo);
    acerAspireE1->setCategory(laptops);
    
    PRINT_SEPARATOR
    
    cout << *nokia3310 << " (" << *nokia3310->getCategory() << ")" << endl;
    cout << nokia3310->getOrders();
    cout << *samsungGalaxyNote3 << " (" << *samsungGalaxyNote3->getCategory() << ")" << endl;
    cout << samsungGalaxyNote3->getOrders();
    cout << *lgOptimusGE975 << " (" << *lgOptimusGE975->getCategory() << ")" << endl;
    cout << lgOptimusGE975->getOrders();
    cout << *gygabyteGSmartRioR1 << " (" << *gygabyteGSmartRioR1->getCategory() << ")" << endl;
    cout << gygabyteGSmartRioR1->getOrders();
    cout << *nikonCoolpixS2700 << " (" << *nikonCoolpixS2700->getCategory() << ")" << endl;
    cout << nikonCoolpixS2700->getOrders();
    cout << *samsungDV150 << " (" << *samsungDV150->getCategory() << ")" << endl;
    cout << samsungDV150->getOrders();
    cout << *olympusVH210 << " (" << *olympusVH210->getCategory() << ")" << endl;
    cout << olympusVH210->getOrders();
    cout << *canonPoverShotA1400 << " (" << *canonPoverShotA1400->getCategory() << ")" << endl;
    cout << canonPoverShotA1400->getOrders();
    cout << *hpCompaqPresarioCQ58 << " (" << *hpCompaqPresarioCQ58->getCategory() << ")" << endl;
    cout << hpCompaqPresarioCQ58->getOrders();
    cout << *lenovoIdeaPadG580G << " (" << *lenovoIdeaPadG580G->getCategory() << ")" << endl;
    cout << lenovoIdeaPadG580G->getOrders();
    cout << *acerAspireE1 << " (" << *acerAspireE1->getCategory() << ")" << endl;
    cout << acerAspireE1->getOrders();
    cout << *fujitsuLifebookAH512 << " (" << *fujitsuLifebookAH512->getCategory() << ")" << endl;
    cout << fujitsuLifebookAH512->getOrders();
    
    PRINT_SEPARATOR
    
    cout << *mobile << ":" << endl;
    cout << mobile->getItems();
    cout << *photo << ":" << endl;
    cout << photo->getItems();
    cout << *laptops << ":" << endl;
    cout << laptops->getItems();
    
    PRINT_SEPARATOR
    
    cout << *workItems << " (" << *workItems->getCustomer() << ")" << endl;
    cout << workItems->getItems();
    cout << *giftItems << " (" << *giftItems->getCustomer() << ")" << endl;
    cout << giftItems->getItems();
    cout << *travelItems << " (" << *travelItems->getCustomer() << ")" << endl;
    cout << travelItems->getItems();
    
    PRINT_SEPARATOR
    
    cout << *petro << endl;
    cout << petro->getOrders();
    cout << *andry << endl;
    cout << andry->getOrders();
    cout << *dmitry << endl;
    cout << dmitry->getOrders();
    
    PRINT_EXISTED
    
    delete mobile;
    PRINT_SEPARATOR
    delete photo;
    PRINT_SEPARATOR
    delete laptops;
    PRINT_SEPARATOR
    delete petro;
    PRINT_SEPARATOR
    delete andry;
    PRINT_SEPARATOR
    delete dmitry;
    
    PRINT_SEPARATOR
    
    Category* food = new Category("Food");
    Item* fish = new Item("Fish", food);
    Customer *leonid = new Customer("Leonid");
    Order *buyList = new Order("Buy list", leonid, fish);
    
    PRINT_SEPARATOR
    
    delete food;
    PRINT_SEPARATOR
    delete leonid;
    
    return 0;
}
