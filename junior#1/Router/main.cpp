#include <iostream>
#include <list>

#include "IPv4Address.h"
#include "Network.h"
#include "Route.h"
#include "Router.h"

#define TEST_CASE(a, b) std::cout << (a) << " -> " << (b) << std::endl;

int main() {
    std::list<Route> routes = {
        Route(Network(IPv4Address("0.0.0.0"), 0), IPv4Address("192.168.0.1"), "en0", 10),
        Route(Network(IPv4Address("192.168.0.0"), 24), "en0", 10),
        Route(Network(IPv4Address("10.0.0.0"), 8), IPv4Address("10.123.0.1"), "en1", 10),
        Route(Network(IPv4Address("10.123.0.0"), 20), "en1", 10)
    };
    Router router = Router(routes);

    Route route = router.getRouteForAddress(IPv4Address("192.168.0.176"));

    TEST_CASE(route.getMetric(), "10");
    TEST_CASE(route.getInterfaceName(), "en0");

    Network net = route.getNetwork();

    TEST_CASE(net.toString(), "192.168.0.0/24");
    TEST_CASE(net.getAddress().toString(), "192.168.0.0");

    route = router.getRouteForAddress(IPv4Address("10.0.1.1"));

    TEST_CASE(route.getMetric(), "10");
    TEST_CASE(route.getInterfaceName(), "en1");

    net = route.getNetwork();

    TEST_CASE(net.toString(), "10.0.0.0/8");
    TEST_CASE(net.getAddress().toString(), "10.0.0.0");

    std::cout << std::endl;

    for ( Route route : router.getRoutes() ) {
       Network net = route.getNetwork();

       std::cout << net.toString() << std::endl;
    }

    std::cout << std::endl;

    routes = {
        Route(Network(IPv4Address("0.0.0.0"), 0), IPv4Address("192.168.0.1"), "en0", 10),
        Route(Network(IPv4Address("192.168.0.0"), 24), "en0", 10),
        Route(Network(IPv4Address("10.0.0.0"), 8), IPv4Address("10.123.0.1"), "en1", 10),
        Route(Network(IPv4Address("192.168.0.176"), 32), "en2", 1),
        Route(Network(IPv4Address("10.123.0.0"), 20), "en1", 10)
    };
    router = Router(routes);

    route = router.getRouteForAddress(IPv4Address("192.168.0.176"));

    TEST_CASE(route.getMetric(), "1");
    TEST_CASE(route.getInterfaceName(), "en2");

    net = route.getNetwork();

    TEST_CASE(net.toString(), "192.168.0.176/32");
    TEST_CASE(net.getAddress().toString(), "192.168.0.176");

    std::cout << std::endl;

    for ( Route route : router.getRoutes() ) {
       Network net = route.getNetwork();

       std::cout << net.toString() << std::endl;
    }
}
