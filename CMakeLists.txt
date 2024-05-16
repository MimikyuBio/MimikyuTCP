cmake_minimum_required(VERSION 3.22)
project(MimikyuPCAP C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DMIMIKYU_DEBUG")

include_directories(src)

set(MIMIKYU_PCAP_SOURCE     src/mimikyu/pcap.c)
set(MIMIKYU_PCAP_HEADER     src/mimikyu/pcap.h)

add_library(mimikyutcp ${MIMIKYU_PCAP_SOURCE}
                       ${MIMIKYU_PCAP_HEADER})


add_executable(example-mimikyutcp-packet-capture example/packet-capture.c)
target_link_libraries(example-mimikyutcp-packet-capture mimikyutcp -lpcap)
