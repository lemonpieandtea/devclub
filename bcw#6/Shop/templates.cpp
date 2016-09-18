#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>
#include <set>

template <class Type>
std::ostream& operator<<(std::ostream& out, const std::set<Type*>& list) {
    
    for ( typename std::set<Type*>::iterator it = list.begin(); it != list.end(); it++ ) {
        out << "-- " << (*it)->getTitle() << " (ID: " << (*it)->getId() << ")" << std::endl;
    }
    
    if ( list.empty() ) {
        out << "-- (none)" << std::endl;
    }
    
    return out;
}

#endif // TEMPLATES_H
