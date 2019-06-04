#include "stm32f7xx.h"
#include "adc.h"

void init_ADC3()
{
	/* configuring ADC3, as it is the only ADC wired out to the headers */
	__HAL_RCC_ADC3_CLK_ENABLE()
	;
	adc3_handle.Instance = ADC3;
	adc3_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	adc3_handle.Init.Resolution = ADC_RESOLUTION_12B;

	/* these 5 settings are closely related */
	adc3_handle.Init.ScanConvMode = DISABLE;
	adc3_handle.Init.ContinuousConvMode = DISABLE;
	adc3_handle.Init.DiscontinuousConvMode = DISABLE;
	adc3_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
	adc3_handle.Init.NbrOfDiscConversion = 1;

	HAL_ADC_Init(&adc3_handle);

	/* configuring a channel belonging to ADC3 */
	adc_channel_config.Channel = ADC_CHANNEL_0;
	adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;

	HAL_ADC_ConfigChannel(&adc3_handle, &adc_channel_config);

}
