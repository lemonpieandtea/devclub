#include "man.h"
#include "spider.h"
#include "spiderMan.h"
#include <iostream>

using namespace std;

int main() {
    Man man;
    Spider spider;
    SpiderMan spiderMan;
    
    man.walk();
    man.jump();
    cout << endl;
    spider.walk();
    spider.jump();
    cout << endl;
    spiderMan.walk();
    spiderMan.jump();
    
    spiderMan.Man::walk();
    spiderMan.Man::jump();
    
    spiderMan.Spider::walk();
    spiderMan.Spider::jump();
    
    spiderMan.Thing::walk();
    spiderMan.Thing::jump();
    
    return 0;
}
