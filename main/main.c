#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "led7digit.h"


void app_main(void)
{
    // Cấu hình GPIO output
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << GPIO_NUM_2 | 1ULL << GPIO_NUM_4 | 1ULL << GPIO_NUM_5 |
                         1ULL << GPIO_NUM_18 | 1ULL << GPIO_NUM_20 | 1ULL << GPIO_NUM_39 | 1ULL << GPIO_NUM_40),
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE
    };
    gpio_config(&io_conf);

    while (1) {
        for (int i = 0; i < 10; i++)
        {
            display_digit(i);
            printf("----done------\r\n");
            vTaskDelay(pdMS_TO_TICKS(1000)); // delay 1 giây
        }
    }
}
