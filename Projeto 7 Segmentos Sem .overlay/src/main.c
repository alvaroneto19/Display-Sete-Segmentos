#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>

#define SLEEP_TIME_MS 1


#define BUTTON_GPIO_NODE DT_NODELABEL(gpioc) 
#define BUTTON_PIN       13                  

static const struct gpio_dt_spec segments[] = {
    {.port = DEVICE_DT_GET(DT_NODELABEL(gpioa)), .pin = 4}, 
    {.port = DEVICE_DT_GET(DT_NODELABEL(gpiob)), .pin = 0}, 
    {.port = DEVICE_DT_GET(DT_NODELABEL(gpiob)), .pin = 3}, 
    {.port = DEVICE_DT_GET(DT_NODELABEL(gpioc)), .pin = 0}, 
    {.port = DEVICE_DT_GET(DT_NODELABEL(gpioc)), .pin = 1}, 
    {.port = DEVICE_DT_GET(DT_NODELABEL(gpioa)), .pin = 1}, 
    {.port = DEVICE_DT_GET(DT_NODELABEL(gpioa)), .pin = 0}, 
};

static const struct gpio_dt_spec button = {
    .port = DEVICE_DT_GET(BUTTON_GPIO_NODE),
    .pin = BUTTON_PIN,
    .dt_flags = GPIO_INPUT,
};

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
        gpio_pin_set(segments[i].port, segments[i].pin, segment_values[number][i]);
    }
}

int main(void)
{
    int ret;
    int count = 0;
    int last_button_state = 0; 

    for (int i = 0; i < 7; i++) {
        if (!device_is_ready(segments[i].port)) {
            return 0;
        }
        ret = gpio_pin_configure(segments[i].port, segments[i].pin, GPIO_OUTPUT_ACTIVE);
        if (ret != 0) {
            return 0;
        }
    }

    if (!device_is_ready(button.port)) {
        return 0;
    }

    ret = gpio_pin_configure(button.port, button.pin, GPIO_INPUT | button.dt_flags);
    if (ret != 0) {
        return 0;
    }

    while (1) {
        int val = gpio_pin_get(button.port, button.pin);

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

