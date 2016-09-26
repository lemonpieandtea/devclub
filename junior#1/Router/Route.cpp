#include "Route.h"

int Route::metricvalidate(int metric) {
    if ( metric < 0 ) {
        throw IllegalRouteArgumentException();
    }

    return metric;
}

Route::Route(Network network, IPv4Address gateway, const std::string& interfaceName, int metric) :
        network {network},
        gateway {gateway},
        interfaceName {interfaceName},
        routeName {"net: "+(network.toString())+", gateway: "+gateway.toString()+
                   ", interface: "+interfaceName+", metric: "+std::to_string(metric)},
        metric {metricvalidate(metric)},
        gatewayPresent {true} {}

Route::Route(Network network, const std::string& interfaceName, int metric) :
        network {network},
        gateway {IPv4Address(0)},
        interfaceName {interfaceName},
        routeName {"net: "+(network.toString())+", interface: "+interfaceName+", metric: "+
                   std::to_string(metric)},
        metric {metricvalidate(metric)},
        gatewayPresent {false} {}

bool Route::operator==(const Route& other) const {
    bool gatewaysEqual;

    try {
        gatewaysEqual = (gateway == other.getGateway());
    } catch ( NoGatewayPresentException() ) {
        if ( gatewayPresent ) {
            return false;
        }

        gatewaysEqual = true;
    }

    return (network == other.getNetwork() &&
            gatewaysEqual &&
            interfaceName == other.getInterfaceName() &&
            metric == other.getMetric());
}

bool Route::operator!=(const Route& other) const {
    return (*this == other);
}

IPv4Address Route::getGateway() const {
    if ( !gatewayPresent ) {
        throw NoGatewayPresentException();
    }

    return gateway;
}

const std::string& Route::getInterfaceName() const {
    return interfaceName;
}

int Route::getMetric() const {
    return metric;
}

Network Route::getNetwork() const {
    return network;
}

const std::string& Route::toString() const {
    return routeName;
}
