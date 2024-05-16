#ifndef   __MIMIKYU__PCAP__H__
#define   __MIMIKYU__PCAP__H__

#include <stdio.h>

#include <pcap/pcap.h>

#include <mimikyu.h>

typedef pcap_handler        mimikyu_pcap_handler_t;
typedef struct pcap_pkthdr  mimikyu_pcap_packet_header_t;

extern int mimikyu_pcap_sniff(const char * dev, mimikyu_pcap_handler_t callback);

// #ifdef    MIMIKYU_DEBUG
extern void mimikyu_pcap_debug_print(uint8_t * user, const mimikyu_pcap_packet_header_t * header, const uint8_t * bytes);
extern void mimikyu_pcap_debug_print_packet_header(FILE * stream, const mimikyu_pcap_packet_header_t * header);
// #endif // MIMIKYU_DEBUG

#endif // __MIMIKYU__PCAP__H__
