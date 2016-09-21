#ifndef IPV4ADDRESS_H
#define IPV4ADDRESS_H

#include <string>
#include <cstdint>

class IPv4Address {
    private:
        uint32_t address;
        std::string addressName;

        void convertToInt();
        void convertToString();
        bool isIPBlock(uint32_t block);
        bool isIPAddr(uint32_t address);
        bool isIPAddr(const std::string& address);

    public:
        IPv4Address(const std::string& address);
        IPv4Address(uint32_t address);

        bool operator==(const IPv4Address& other);
        bool operator<(const IPv4Address& other);
        bool operator<=(const IPv4Address& other);
        bool operator>(const IPv4Address& other);
        bool operator>=(const IPv4Address& other);

        bool lessThan(IPv4Address address) const;
        bool greaterThan(IPv4Address address) const;
        bool equals(IPv4Address address) const;

        const std::string& toString() const;
        uint32_t toInt() const;
};

class IllegalIPv4AddressArgumentException {};

#endif // IPV4ADDRESS_H
