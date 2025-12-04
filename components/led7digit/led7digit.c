#include "led7digit.h"
#include "driver/gpio.h"

int seg_pins[NUMBER_SEGMENTS] = {2, 4, 5, 18, 20, 39, 40}; // a,b,c,d,e,f,g

// Bảng code cho LED common-cathode
const uint8_t seg_code[10] = {
    
    /*-----------Cathone (Âm chung)--------*/ 
    // 0x3F, // 0 -> 0011 1111
    // 0x06, // 1
    // 0x5B, // 2
    // 0x4F, // 3
    // 0x66, // 4
    // 0x6D, // 5
    // 0x7D, // 6
    // 0x07, // 7
    // 0x7F, // 8
    // 0x6F  // 9

    /*-----------Anode (Dương chung)--------*/ 
    0x40, // 0 → 0100 0000 (a-f = 0 sáng, g = 1 tắt)
    0x79, // 1
    0x24, // 2
    0x30, // 3
    0x19, // 4
    0x12, // 5
    0x02, // 6
    0x78, // 7
    0x00, // 8
    0x10  // 9
};

// Hàm hiển thị 1 chữ số
void display_digit(uint8_t num)
{
    uint8_t data = seg_code[num];
    for (int i = 0; i < NUMBER_SEGMENTS; i++)
    {
        // Với common-cathode: 1 -> sáng, 0 -> tắt
        gpio_set_level(seg_pins[i], (data >> i) & 0x01);
    }
}
