#include <mimikyu/pcap.h>

int main(int argc, char ** argv) {
    return mimikyu_pcap_sniff("eth0", mimikyu_pcap_debug_print);
}