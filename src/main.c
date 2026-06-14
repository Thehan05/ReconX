#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <CIDR>\n", argv[0]);
        return 1;
    }

    int octet1, octet2, octet3, octet4, prefix_length;
    int n = sscanf(argv[1], "%d.%d.%d.%d/%d", &octet1, &octet2, &octet3, &octet4, &prefix_length);
    if(n != 5) {
        printf("Invalid CIDR format. Please use the format: x.x.x.x/y\n");
        return 1;
    }

    if(octet1 < 0 || octet1 > 255 || octet2 < 0 || octet2 > 255 || octet3 < 0 || octet3 > 255 || octet4 < 0 || octet4 > 255 ) {
        printf("Invalid IP address. Each octet must be between 0 and 255.\n");
        return 1;
    }

    if(prefix_length < 0 || prefix_length > 32) {
        printf("Invalid prefix length. It must be between 0 and 32.\n");
        return 1;
    }

    uint32_t ip = ((uint32_t)octet1 << 24) | ((uint32_t)octet2 << 16) | ((uint32_t)octet3 << 8) | (uint32_t)octet4;
    uint32_t mask = 0xFFFFFFFF << (32 - prefix_length);
    uint32_t net_addr = ip & mask;
    uint32_t broad_addr = net_addr | ~mask;
    printf("Parsed: %d.%d.%d.%d  prefix=%d\n", octet1, octet2, octet3, octet4, prefix_length);
    printf("Packed IP = %u  (hex: %08X)\n", ip, ip);
    printf("Mask = %08X\n", mask);
    printf("Network   = %08X\n", net_addr);
    printf("Broadcast = %08X\n", broad_addr);
    
    return 0;
}
