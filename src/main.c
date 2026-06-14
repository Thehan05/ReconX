#include <stdio.h>
#include <stdlib.h>

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
    
    printf("Parsed: %d.%d.%d.%d  prefix=%d\n", octet1, octet2, octet3, octet4, prefix_length);

    return 0;
}
