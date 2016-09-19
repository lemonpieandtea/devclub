#include <iostream>

#include "IPv4Address.h"

#define TEST_CASE(a, b) std::cout << (a) << " -> " << (b) << std::endl;

int main() {
    IPv4Address ip = IPv4Address("127.12.45.22");
    TEST_CASE(ip.toString(), "127.12.45.22");
    TEST_CASE(ip.toInt(), "2131504406");

    ip = IPv4Address(2131504406);
    TEST_CASE(ip.toString(), "127.12.45.22");
    TEST_CASE(ip.toInt(), "2131504406");

    TEST_CASE(ip.equals(IPv4Address("127.12.45.22")), "true");
    TEST_CASE(ip.equals(IPv4Address(2131504406L)), "true");
    TEST_CASE(ip.equals(IPv4Address(0xF834AD02L)), "false");
    TEST_CASE(ip.equals(IPv4Address("189.11.23.211")), "false");
    TEST_CASE(ip.greaterThan(IPv4Address("131.16.34.66")), "false");
    TEST_CASE(ip.lessThan(IPv4Address("131.16.34.66")), "true");

    try {
        ip = IPv4Address("172.22.999.01");
    } catch (IllegalIPv4AddressArgumentException) {
        std::cout << "Exception #1!" <<  std::endl;
    }

    try {
        ip = IPv4Address("172.22.0.01.1");
    } catch (IllegalIPv4AddressArgumentException) {
        std::cout << "Exception #2!" <<  std::endl;
    }

    try {
        ip = IPv4Address("172.AB.5.01");
    } catch (IllegalIPv4AddressArgumentException) {
        std::cout << "Exception #3!" <<  std::endl;
    }

    return 0;
}
