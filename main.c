#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>

#define SLEEP_TIME_MS 1


#define SEGMENTS_NODE DT_NODELABEL(gpio_segments)
#define BUTTON_NODE DT_NODELABEL(gpio_buttons)


static const struct gpio_dt_spec segments[] = {
    GPIO_DT_SPEC_GET(SEGMENTS_NODE, segment1),
    GPIO_DT_SPEC_GET(SEGMENTS_NODE, segment2),
    GPIO_DT_SPEC_GET(SEGMENTS_NODE, segment3),
    GPIO_DT_SPEC_GET(SEGMENTS_NODE, segment4),
    GPIO_DT_SPEC_GET(SEGMENTS_NODE, segment5),
    GPIO_DT_SPEC_GET(SEGMENTS_NODE, segment6),
    GPIO_DT_SPEC_GET(SEGMENTS_NODE, segment7),
};

// Definição do botão
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(BUTTON_NODE, button);

static const uint8_t segment_values[16][7] = {
    {1, 1, 1, 1, 1, 1, 0}, 
    {0, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 0, 1, 1, 0, 1}, 
    {1, 1, 1, 1, 0, 0, 1}, 
    {0, 1, 1, 0, 0, 1, 1}, 
    {1, 0, 1, 1, 0, 1, 1}, 
    {1, 0, 1, 1, 1, 1, 1}, 
    {1, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 1, 1, 1, 1, 1}, 
    {1, 1, 1, 1, 0, 1, 1}, 
    {1, 1, 1, 0, 1, 1, 1}, 
    {0, 0, 1, 1, 1, 1, 1}, 
    {1, 0, 0, 1, 1, 1, 0}, 
    {0, 1, 1, 1, 1, 0, 1}, 
    {1, 0, 0, 1, 1, 1, 1}, 
    {1, 0, 0, 0, 1, 1, 1}
};


void display_number(int number)
{
    for (int i = 0; i < 7; i++) {
        gpio_pin_set_dt(&segments[i], segment_values[number][i]);
    }
}

int main(void)
{
    int ret;
    int count = 0;
    int last_button_state = 1; 

  
    for (int i = 0; i < 7; i++) {
        if (!device_is_ready(segments[i].port)) {
            printk("Segment device not ready\n");
            return -1;
        }
        ret = gpio_pin_configure_dt(&segments[i], GPIO_OUTPUT);
        if (ret != 0) {
            return -1;
        }
    }


    if (!device_is_ready(button.port)) {
        return -1;
    }

    ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
    if (ret != 0) {
        return -1;
    }

    while (1) {
        int val = gpio_pin_get_dt(&button);

        if (val == 0 && last_button_state == 1) {
            count++;
            if (count == 16) {
                count = 0;
            }

 
            k_msleep(200); 
        }

        last_button_state = val; 
        display_number(count);
        k_msleep(SLEEP_TIME_MS); 
    }

    return 0;
}
