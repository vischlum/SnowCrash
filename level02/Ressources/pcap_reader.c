//
// Created by Xavier-Emmanuel Moreau on 26/03/2020.
//

#include "pcap_reader.h"

//void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header) {
//	printf("Packet capture length: %d\n", packet_header.caplen);
//	printf("Packet total length %d\n", packet_header.len);
//}

void study_handle(pcap_t *handle)
{
	const u_char *packet;
	struct pcap_pkthdr packet_header;

	packet = pcap_next(handle, &packet_header);
	if (packet == NULL) {
		printf("No packet found.\n");
		return ;
	}

	/* Our function to output some info */
//	print_packet_info(packet, packet_header);
}

int main(int ac, char **av)
{
	FILE *file;

	pcap_t *handle;
	char error_buffer[PCAP_ERRBUF_SIZE];

	if (ac < 2)
		return (1);
	file =fopen(av[1], "r");
	handle = pcap_fopen_offline(file, error_buffer);
	if (handle == NULL)
	{
		printf("%s\n", error_buffer);
		printf("no handle");
		return (18);
	}
	study_handle(handle);
	pcap_close(handle);
	fclose(file);
	return (0);
}