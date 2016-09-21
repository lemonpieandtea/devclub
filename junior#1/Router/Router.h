#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include <list>

#include "Route.h"

class Router {
    private:
        std::list<Route> routes;

    public:
        Router(std::list<Route> routes);

        void addRoute(Route route);
        void removeRoute(Route route);

        Route getRouteForAddress(IPv4Address address);
        const std::list<Route>& getRoutes() const;
};

class NoRouteFoundException {};

#endif // ROUTER_H
