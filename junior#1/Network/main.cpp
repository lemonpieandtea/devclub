#include <iostream>
#include <vector>

#include "IPv4Address.h"
#include "Network.h"

#define TEST_CASE(a, b) std::cout << (a) << " -> " << (b) << std::endl;

int main() {
    IPv4Address address = IPv4Address("192.168.1.1");
    Network net = Network(address, 32);

    TEST_CASE(net.toString(), "192.168.0.0/24");
    TEST_CASE(net.getAddress().toString(), "192.168.0.0");
    TEST_CASE(net.getFirstUsableAddress().toString(), "192.168.0.1");
    TEST_CASE(net.getLastUsableAddress().toString(), "192.168.0.254");
    TEST_CASE(net.getMask().toInt(), "4294967040");
    TEST_CASE(net.getMask().toString(), "255.255.255.0");
    TEST_CASE(static_cast<int>(net.getMaskLength()), "24");
    TEST_CASE(net.isPublic(), "false");
    TEST_CASE(net.contains(IPv4Address("10.0.23.4")), "false");
    TEST_CASE(net.contains(IPv4Address("192.168.0.25")), "true");
    TEST_CASE(net.getBroadcastAddress().toString(), "192.168.0.255");
    TEST_CASE(net.getTotalHosts(), "254");

    std::vector<Network> subnets = net.getSubnets();

    TEST_CASE(subnets[0].toString(), "192.168.0.0/25");
    TEST_CASE(subnets[0].getAddress().toString(), "192.168.0.0");
    TEST_CASE(subnets[0].getFirstUsableAddress().toString(), "192.168.0.1");
    TEST_CASE(subnets[0].getLastUsableAddress().toString(), "192.168.0.126");
    TEST_CASE(static_cast<int>(subnets[0].getMaskLength()), "25");
    TEST_CASE(subnets[0].getTotalHosts(), "126")

    TEST_CASE(subnets[1].toString(), "192.168.0.128/25");
    TEST_CASE(subnets[1].getAddress().toString(), "192.168.0.128");
    TEST_CASE(subnets[1].getFirstUsableAddress().toString(), "192.168.0.129");
    TEST_CASE(subnets[1].getLastUsableAddress().toString(), "192.168.0.254");
    TEST_CASE(static_cast<int>(subnets[1].getMaskLength()), "25");
    TEST_CASE(subnets[0].getTotalHosts(), "126");
}
