/*
 * packet.c
 *
 *  Created on: Apr 22, 2025
 *      Author: _TTTXN
 */


#include "packet.h"

Packet pk = {0};

bool decode_packet(uint8_t *packet, uint16_t length) {


    if (length < 8 || packet[0] != HEADER_BYTE) {
    	pk.valid = false;
        return pk.valid;
    }

    uint8_t payload_size = packet[1];
    if (length != (payload_size + 2)) {
    	pk.valid = false;
        return pk.valid;
    }

    pk.cmd = packet[2];
    pk.flags = packet[3];

    pk.num_floats = (payload_size - 2 - 4) / 4;

    pk.crc_calculated = HAL_CRC_Calculate(&hcrc, (uint32_t*)&packet[2], (payload_size - 4) / 4);
    memcpy(&pk.crc_received, &packet[2 + payload_size - 4], 4);

    if (pk.crc_calculated != pk.crc_received) {
    	pk.valid = false;
        return pk.valid;
    }

    for (int i = 0; i < pk.num_floats; ++i) {
        memcpy(&pk.values[i], &packet[4 + i * 4], sizeof(float));
    }

    pk.valid = true;
    return pk.valid;
}

void handle_command(uint8_t cmd, float* values, int num_values) {
    switch (cmd) {
        case 0x01:  // Start Accelerometer Calibration Step
            if (num_values >= 1) {
//                float step = values[0];
//                idx = (uint8_t)step;
//                startCalibration = 1;  // set flag ให้ loop ทำงาน
            }
            break;

        case 0x02:  // Start Gyroscope Calibration
//            startGyroCalib = 1;  // ปล่อยให้ Gyro เริ่ม
            break;

        default:
            break;
    }
}

