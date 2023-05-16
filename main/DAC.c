#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/dac.h"

void app_main(void)
{
  dac_output_enable(DAC_CHANNEL_1);

  // int volt = (float)3.3;
  // int PCM = (int)((float)(255 * volt) / 3.3);

  while (1)
  {
    for (int i = 0; i < 255; i++)
    {
      dac_output_voltage(DAC_CHANNEL_1, i);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
  }
}
