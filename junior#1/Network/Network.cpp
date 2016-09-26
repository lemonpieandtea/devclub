#include "Network.h"

#define MASK_32_BITS   32
#define MASK_31_BITS   31
#define MASK_16_BITS   16
#define MASK_12_BITS   12
#define MASK_8_BITS    8
#define MASK_0_BITS    0
#define IP_10_0_0_0    0x0A000000
#define IP_172_16_0_0  0xAC100000
#define IP_192_168_0_0 0xC0A80000

IPv4Address& Network::addressValidate(IPv4Address& address) const {
    if ( address.toInt() & ~mask.toInt() ) {
        throw IllegalNetworkArgumentException();
    }

    return address;
}

uint8_t Network::maskLengthValidate(uint8_t maskLength) const {
    if ( maskLength > MASK_32_BITS ) {
        throw IllegalNetworkArgumentException();
    }

    return maskLength;
}

IPv4Address Network::firstUsableAddressCalculate() {
    uint32_t address {this->address.toInt()};

    if ( maskLength < MASK_31_BITS ) {
        address += 1;
    }

    return IPv4Address(address);
}

IPv4Address Network::lastUsableAddressCalculate() {
    uint32_t address {this->address.toInt()|~mask.toInt()};

    if ( maskLength < MASK_31_BITS ) {
        address -= 1;
    }

    return IPv4Address(address);
}

uint32_t Network::totalHostsCalculate() {
    if ( maskLength == MASK_32_BITS ) {
        return 1;
    } else if ( maskLength == MASK_31_BITS ) {
        return 2;
    }

    return ~mask.toInt() - 1;
}

Network::Network(IPv4Address address, uint8_t maskLength) :
        maskLength {maskLengthValidate(maskLength)},
        mask {IPv4Address(~MASK_0_BITS<<(MASK_32_BITS-maskLength))},
        address {addressValidate(address)},
        broadcastAddress {IPv4Address(address.toInt()|~mask.toInt())},
        firstUsableAddress {firstUsableAddressCalculate()},
        lastUsableAddress {lastUsableAddressCalculate()},
        networkName {address.toString()+"/"+std::to_string(maskLength)},
        totalHosts {totalHostsCalculate()} {}

bool Network::isPublic() const {
    uint32_t address {this->address.toInt()};

    if ( (address == IP_10_0_0_0 && maskLength >= MASK_8_BITS) ||
         (address == IP_172_16_0_0 && maskLength >= MASK_12_BITS) ||
         (address == IP_192_168_0_0 && maskLength >= MASK_16_BITS) ) {
        return false;
    }

    return true;
}

bool Network::operator==(const Network& other) const {
    return (mask == other.getMask() && address == other.getAddress());
}

bool Network::operator!=(const Network& other) const {
    return !(*this == other);
}

bool Network::contains(IPv4Address address) const {
    return (address >= getFirstUsableAddress() && address <= getLastUsableAddress());
}

const std::string& Network::toString() const {
    return networkName;
}

const IPv4Address& Network::getAddress() const {
    return address;
};

const IPv4Address& Network::getBroadcastAddress() const {
    return broadcastAddress;
}

const IPv4Address& Network::getFirstUsableAddress() const {
    return firstUsableAddress;
}

const IPv4Address& Network::getLastUsableAddress() const {
    return lastUsableAddress;
}

const IPv4Address& Network::getMask() const {
    return mask;
}

uint8_t Network::getMaskLength() const {
    return maskLength;
}

std::vector<Network> Network::getSubnets() const {
    uint8_t newMaskLength {maskLengthValidate(maskLength+1)};

    if ( maskLength == MASK_32_BITS ) {
        throw NoSubnetsException();
    }

    return { Network(IPv4Address(address.toInt()), newMaskLength),
             Network(IPv4Address(address.toInt()+(1<<(MASK_32_BITS-newMaskLength))), newMaskLength) };
}

uint32_t Network::getTotalHosts() const {
    return totalHosts;
}
