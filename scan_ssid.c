#include <stdio.h>
#include <iwlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	wireless_scan_head head;
    wireless_scan *result;
    iwrange range;
    int sock;
    char *desired_ssid = argv[2];
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

    // Iterate over the scan results and find the desired SSID
    int found = 0;
    for (result = head.result; result; result = result->next) {
        if (strcmp(result->b.essid, desired_ssid) == 0) {
            printf("SSID: %s, Signal Power: %d\n", result->b.essid, result->stats.qual.level);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("SSID not found.\n");
    }

    // Close the socket
    iw_sockets_close(sock);

    return 0;
}

