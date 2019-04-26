#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "arm_math.h"                   // ARM::CMSIS:DSP

/************************************* Defines and prototypes ************************************/

#define SIG_LENGTH				200
#define IMP_RSP_LENGTH		29

extern void SystemClock_Config (void);
extern float32_t inputSignal_f32_1kHz_15kHz[SIG_LENGTH];
extern float32_t impulse_response[IMP_RSP_LENGTH];

void plot_input_signal(void);
void plot_impulse_signal (void);
void plot_output_signal(void);
void plot_both_signal(void);
void plot_all(void);
void calc_running_sum(float32_t *sig_src_arr, float32_t *sig_dest_arr, uint32_t sig_length);
void calc_frist_difference(float32_t *sig_src_arr, float32_t *sig_dest_arr, uint32_t sig_length);

uint32_t freq;
float32_t inputSample;
float32_t inputStd;
float32_t imp_rspSample;
float32_t outputSample;
float32_t outputSignal_arr[SIG_LENGTH];

/*************************************** use functions *******************************************/

int main(void) {
	
	HAL_Init();
	SystemClock_Config();
	freq = HAL_RCC_GetHCLKFreq();
	
	calc_frist_difference(&inputSignal_f32_1kHz_15kHz[0], &outputSignal_arr[0], SIG_LENGTH);
  plot_both_signal();

	
	while (1) {
		
		
		
	}
	
}


void plot_input_signal(void) {
	
	int i, j;
	for (i = 0; i < SIG_LENGTH; i++)
	{
		inputSample = inputSignal_f32_1kHz_15kHz[i];
		for (j = 0; j < 3000; j++) {}
	}
	
}

void calc_frist_difference(float32_t *sig_src_arr, float32_t *sig_dest_arr, uint32_t sig_length) {
	
	sig_dest_arr[0] = 0;
	int i;
	for(i = 0; i < sig_length; i++)
	{
		sig_dest_arr[i] = sig_src_arr[i] - sig_src_arr[i - 1];
	}
	
}

void calc_running_sum(float32_t *sig_src_arr, float32_t *sig_dest_arr, uint32_t sig_length) {
	
	int i;
	sig_src_arr[0] = sig_dest_arr[0];
	for(i=0; i < sig_length; i++)
	{
		sig_dest_arr[i] = sig_dest_arr[i-1] + sig_src_arr[i];
	}
	
}

void plot_output_signal(void) {
	
	int i, j;
	for (i = 0; i < (SIG_LENGTH); i++)
	{
		outputSample = outputSignal_arr[i];
		for (j = 0; j < 3000; j++) {}
	}
	
}

void plot_both_signal(void) {
	
	int i, j;
	for (i = 0; i < (SIG_LENGTH); i++)
	{
		outputSample = outputSignal_arr[i];
		inputSample = inputSignal_f32_1kHz_15kHz[i];
		for (j = 0; j < 3000; j++) {}
	}
	
}

void SysTick_Handler (void) {
	
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
	
}


