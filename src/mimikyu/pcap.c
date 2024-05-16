#include "pcap.h"

extern int mimikyu_pcap_sniff(const char * dev, mimikyu_pcap_handler_t callback) {
    pcap_t * handle   = nil;
    const int snaplen = BUFSIZ;
    const int promisc = 1;
    const int timeout = 1000;
    char errbuf[PCAP_ERRBUF_SIZE];

    mimikyu_string_init(errbuf);

    if((handle = pcap_open_live(dev, snaplen, promisc, timeout, errbuf)) != nil) {
        pcap_loop(handle, 0, callback, nil);

        pcap_close(handle);
        handle = nil;

        return success;
    }

    fprintf(stderr, "error: fail to pcap_open_live(...) caused by %s\n", errbuf);
    return fail;
}

// #ifdef    MIMIKYU_DEBUG
extern void mimikyu_pcap_debug_print(uint8_t * user, const mimikyu_pcap_packet_header_t * header, const uint8_t * bytes) {
    mimikyu_pcap_debug_print_packet_header(stdout, header);

    fprintf(stdout, "\n");
}

extern void mimikyu_pcap_debug_print_packet_header(FILE * stream, const mimikyu_pcap_packet_header_t * header) {
    fprintf(stream, "%ld.%06ld ", header->ts.tv_sec, header->ts.tv_usec);
}
// #endif // MIMIKYU_DEBUG
