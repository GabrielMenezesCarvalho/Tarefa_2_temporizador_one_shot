#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define LED_AZUL 11
#define LED_VERMELHO 12
#define LED_VERDE 13
#define BOTAO 5

static volatile uint32_t ultimo_tempo = 0;
bool leds_ativos = false;
uint8_t etapa_led = 0;

// Callback para sequência de desligamento dos LEDs
int64_t led_sequence_callback(alarm_id_t id, void *user_data) {
    switch (etapa_led) {
        case 1:
            gpio_put(LED_AZUL, false);
            break;
        case 2:
            gpio_put(LED_VERMELHO, false);
            break;
        case 3:
            gpio_put(LED_VERDE, false);
            leds_ativos = false; // Permite reiniciar o ciclo
            return 0;
    }
    etapa_led++;
    add_alarm_in_ms(3000, led_sequence_callback, NULL, false);
    return 0;
}

static void gpio_irq_handler(uint gpio, uint32_t events);

int main() {
    stdio_init_all();
    
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    
    while (true) {
        tight_loop_contents(); // Mantém o processador ativo
    }
    return 0;
}

void gpio_irq_handler(uint gpio, uint32_t events) {
    uint32_t tempo_atual = to_us_since_boot(get_absolute_time());
    if (tempo_atual - ultimo_tempo > 100000) { // 100ms de debounce
        ultimo_tempo = tempo_atual;
        if (gpio_get(BOTAO) == 0 && !leds_ativos) {
            leds_ativos = true;
            etapa_led = 1;
            gpio_put(LED_AZUL, true);
            gpio_put(LED_VERMELHO, true);
            gpio_put(LED_VERDE, true);
            add_alarm_in_ms(3000, led_sequence_callback, NULL, false);
        }
    }
}
