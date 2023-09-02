#include <stdio.h>
#include <iwlib.h>

int main(int argc, char *argv[]) {
    wireless_scan_head head;
    wireless_scan *result;
    iwrange range;
    int sock;
	int i;
	char *iface = argv[1];

    // Open a socket for wireless operations
    sock = iw_sockets_open();

    // Get the wireless range information
    if (iw_get_range_info(sock, iface, &range) < 0) {
        printf("Failed to get range info.\n");
        return 1;
    }

    // Scan for wireless networks
    if (iw_scan(sock, iface, range.we_version_compiled, &head) < 0) {
        printf("Failed to scan for networks.\n");
        return 1;
    }
	
	printf("list SSID:\n");

    // Iterate over the scan results and print the SSID and signal power
    for (result = head.result, i=1; result; result = result->next, i++) {
        printf("\t %d: %s\n", i,result->b.essid);
    }

    // Close the socket
    iw_sockets_close(sock);

} 
