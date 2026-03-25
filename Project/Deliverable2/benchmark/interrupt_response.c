#include <stdio.h>
#include <stdint.h>

int main() {
    volatile uint32_t sensor_reg = 0x1;
    uint8_t output_buffer[16];

    if (sensor_reg & 0x1) {
        for (int i = 0; i < 16; i++) {
            output_buffer[i] = (uint8_t)(sensor_reg + i);
        }
    }
    printf("Sensor event processed. Buffer[0]=%d\n", output_buffer[0]);
    return 0;
}


// cat > ~/gem5_project/benchmarks/interrupt_response.c << 'EOF'
// #include <stdio.h>
// #include <stdint.h>

// int main() {
//     volatile uint32_t sensor_reg = 0x1;
//     uint8_t output_buffer[16];

//     if (sensor_reg & 0x1) {
//         for (int i = 0; i < 16; i++) {
//             output_buffer[i] = (uint8_t)(sensor_reg + i);
//         }
//     }
//     printf("Sensor event processed. Buffer[0]=%d\n", output_buffer[0]);
//     return 0;
// }
// EOF