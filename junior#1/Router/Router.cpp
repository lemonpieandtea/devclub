#include "Router.h"

Router::Router(std::list<Route> routes) : routes {routes} {}

void Router::addRoute(Route route) {
    routes.push_back(route);
}

void Router::removeRoute(Route route) {
    routes.remove(route);
}

Route Router::getRouteForAddress(IPv4Address address) {
    std::list<Route>::iterator bestRoute;
    bool routeFound {false};

    for ( std::list<Route>::iterator it = routes.begin(); it != routes.end(); it++ ) {
        bool isInNetwork = address >= (*it).getNetwork().getFirstUsableAddress() &&
                           address <= (*it).getNetwork().getLastUsableAddress();

        if ( !routeFound && isInNetwork ) {
            bestRoute = it;

            routeFound = true;
        } else if ( isInNetwork && (*it).getNetwork().getMaskLength() > (*bestRoute).getNetwork().getMaskLength() ) {
            bestRoute = it;
        }
    }

    return routeFound ? *bestRoute : throw NoRouteFoundException();
}

const std::list<Route>& Router::getRoutes() const {
    return routes;
}
