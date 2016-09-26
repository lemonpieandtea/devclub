#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <vector>

#include "IPv4Address.h"

class Network {
    private:
        uint8_t maskLength;
        IPv4Address mask;
        IPv4Address address;
        IPv4Address broadcastAddress;
        IPv4Address firstUsableAddress;
        IPv4Address lastUsableAddress;
        std::string networkName;
        uint32_t totalHosts;

        IPv4Address& addressValidate(IPv4Address& address) const;
        uint8_t maskLengthValidate(uint8_t maskLength) const;
        IPv4Address firstUsableAddressCalculate();
        IPv4Address lastUsableAddressCalculate();
        uint32_t totalHostsCalculate();

    public:
        Network(IPv4Address address, uint8_t maskLength);

        bool operator==(const Network& other) const;
        bool operator!=(const Network& other) const;

        bool isPublic() const;
        bool contains(IPv4Address address) const;
        const std::string& toString() const;

        const IPv4Address& getAddress() const;
        const IPv4Address& getBroadcastAddress() const;
        const IPv4Address& getFirstUsableAddress() const;
        const IPv4Address& getLastUsableAddress() const;
        const IPv4Address& getMask() const;
        uint8_t getMaskLength() const;
        std::vector<Network> getSubnets() const; // produce two half-sized subnets
        uint32_t getTotalHosts() const; // excluding network and broadcast
};

class IllegalNetworkArgumentException {};
class NoSubnetsException {};

#endif // NETWORK_H
