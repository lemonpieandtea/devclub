#ifndef ROUTE_H
#define ROUTE_H

#include <string>

#include "IPv4Address.h"
#include "Network.h"

class Route {
    private:
        Network network;
        IPv4Address gateway;
        std::string interfaceName;
        std::string routeName;
        int metric;
        bool gatewayPresent;

        int metricvalidate(int metric);

    public:
        Route(Network network, IPv4Address gateway, const std::string& interfaceName, int metric);
        Route(Network network, const std::string& interfaceName, int metric);

        bool operator==(const Route& other) const;
        bool operator!=(const Route& other) const;

        IPv4Address getGateway() const;
        const std::string& getInterfaceName() const;
        int getMetric() const;
        Network getNetwork() const;
        const std::string& toString() const;
};

class IllegalRouteArgumentException {};
class NoGatewayPresentException {};

#endif // ROUTE_H
