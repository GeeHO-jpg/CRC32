/*
 * packet.h
 *
 *  Created on: Apr 22, 2025
 *      Author: _TTTXN
 */

#ifndef INC_PACKET_H_
#define INC_PACKET_H_

#include "main.h"
#include "string.h"
#include "usbd_cdc_if.h"
#include "crc.h"
#include <stdbool.h>

#define HEADER_BYTE     0xAA
#define MAX_FLOATS      64
#define MAX_PACKET_SIZE (1 + 1 + MAX_FLOATS * sizeof(float) + 4)

// ✅ Packet structure
typedef struct {
    uint8_t  cmd;
    uint8_t  flags;
    float    values[MAX_FLOATS];
    uint8_t  num_floats;
    uint32_t crc_calculated;
    uint32_t crc_received;
    bool     valid;
} Packet;

extern Packet pk;

bool decode_packet(uint8_t *packet, uint16_t length);
void handle_command(uint8_t cmd, float* values, int num_values);
#endif /* INC_PACKET_H_ */
