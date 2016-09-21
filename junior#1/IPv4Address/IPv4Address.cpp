#include "IPv4Address.h"

#define MAX_IP     UINT32_MAX
#define BYTE_MASK  0xFF
#define BYTE_MAX   256
#define IPV4_BYTES 4

bool IPv4Address::isIPBlock(uint32_t block) {
    if ( block > BYTE_MAX ) {
        return false;
    }

    return true;
}

bool IPv4Address::isIPAddr(uint32_t address) {
    if ( address > MAX_IP ) {
        return false;
    }

    return true;
}

bool IPv4Address::isIPAddr(const std::string& address) {
    int dots {0};
    int groupDigits {0};

    for ( int i = 0; i < address.length(); ++i ) {
        char addrElement = address[i];

        if ( addrElement == '.' && i != 0 ) {
            dots += 1;
            groupDigits = 0;
        } else if ( addrElement >= '0' && addrElement <= '9' ) {
            groupDigits += 1;
        } else {
            return false;
        }

        if ( dots > 3 || groupDigits > 3 ) {
            return false;
        }
    }

    return true;
}

void IPv4Address::convertToInt() {
    std::string addrHolder {addressName};
    int highAddressFindIndex {IPV4_BYTES-1};
    uint32_t tmpAddress {0};
    uint32_t ipBlock;

    for ( int i = 0; i < highAddressFindIndex; ++i ) {
        std::size_t pos = addrHolder.find(".");
        ipBlock = std::stol(addrHolder.substr(0, pos));

        if ( !isIPBlock(ipBlock) ) {
            throw IllegalIPv4AddressArgumentException();
        }

        tmpAddress += ipBlock;
        tmpAddress <<= 8;

        addrHolder.erase(0, pos+1);
    }

    ipBlock = std::stol(addrHolder);

    if ( !isIPBlock(ipBlock) ) {
        throw IllegalIPv4AddressArgumentException();
    }

    tmpAddress += ipBlock;

    address = tmpAddress;
}

void IPv4Address::convertToString() {
    uint32_t addrHolder {address};
    std::string tmpAddress {std::to_string(addrHolder & BYTE_MASK)};

    for ( int i {1}; i < IPV4_BYTES; ++i ) {
        addrHolder >>= 8;
        tmpAddress.insert(0, std::to_string(addrHolder & BYTE_MASK)+".");
    }

    addressName = tmpAddress;
}

IPv4Address::IPv4Address(const std::string& address) {
    if ( !isIPAddr(address) ) {
        throw IllegalIPv4AddressArgumentException();
    }

    addressName = address;

    convertToInt();
}

IPv4Address::IPv4Address(uint32_t address) {
    if ( !isIPAddr(address) ) {
        throw IllegalIPv4AddressArgumentException();
    }

    this->address = address;

    convertToString();
}

bool IPv4Address::operator==(const IPv4Address& other) {
    return equals(other);
}

bool IPv4Address::operator<(const IPv4Address& other) {
    return lessThan(other);
}

bool IPv4Address::operator<=(const IPv4Address& other) {
    return this->address <= other.toInt();
}

bool IPv4Address::operator>(const IPv4Address& other) {
    return greaterThan(other);
}

bool IPv4Address::operator>=(const IPv4Address& other) {
    return this->address >= other.toInt();
}

bool IPv4Address::lessThan(IPv4Address address) const {
    return this->address < address.toInt();
}

bool IPv4Address::greaterThan(IPv4Address address) const {
    return this->address > address.toInt();
}

bool IPv4Address::equals(IPv4Address address) const {
    return this->address == address.toInt();
}

const std::string& IPv4Address::toString() const {
    return addressName;
}

uint32_t IPv4Address::toInt() const {
    return address;
}
