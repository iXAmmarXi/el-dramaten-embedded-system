/* Initilizes and configure PWM signals, through AD-convertion
*/

#include "gd32vf103.h"
#include "lcd.h"
#include "dma.h"
#include "string.h"
#include "display.h"

#define N 100             //Number of matrix element for AD-convertions

/*Matrisen som lagrar Analog-Digital-omvandligar som kommer från...
 ..DMA(Direct Memory Access)..Så att adc-value[0]:står för AD-omvandlingar som..
 ..fångas upp fån PA3, medan adc-value[1]:står för AD-omvandlingar som fångas upp fån PA4..*/
uint16_t adc_value[2];

int main(void){
    float Voltage_battery[N];
    float Voltage_sum, Voltage_M_Value, Tacke_adc1;
    int v=0, Charging=0, adcr_procent = 0, ms=0, s=0, key, pKey=-1, c=0, mode;
    int adcr, display_timer=0, counter = 0;
    
    t5omsi();                               // Initialize timer5 1kHz
    colinit();                              // Initialize column toolbox
    l88init();                              // Initialize 8*8 led toolbox
    keyinit();   
    //T1powerUpInitPWM(0xF);                  // Timer #1, Ch #0, 1, 2 & 3 PWM (0xF initilize all channels (0-3))
    //ADC3powerUpInit(1);                     // Initialize ADC0, Ch3 & Ch16                           
    
    /* system clocks configuration */
    rcu_config();
    /* GPIO configuration */
    gpio_config();
    /* DMA configuration */
    dma_config();
    /* ADC configuration */
    adc_config();   //....PA2,PA4,PA3

    T1powerUpInitPWM();                     // Initilize Timer #1 and Channels

   
    Lcd_SetType(LCD_INVERTED);                // or use LCD_NORMAL!
    Lcd_Init();
    LCD_Clear(BLACK);
    
    while (1) {
          delay_1ms(1);

          if (adc_flag_get(ADC0,ADC_FLAG_EOC)==SET) { // ...ADC done?
            adcr = adc_regular_data_read(ADC0); // ......get data
            adc_flag_clear(ADC0, ADC_FLAG_EOC); // ......clear IF
          }

          adc_software_trigger_enable(ADC0,ADC_REGULAR_CHANNEL); //Trigger ADC conversion!

        /*Convert ADC to PWM - signal */
          adcr_procent = (adc_value[0]*100)/4096;       // calculate procentage
          T1setPWMmotorB(adcr_procent);                // config timer1 Ch0 & Ch1

        /*Display LCD feature*/
          if (t5expq()) {                             // Manage periodic tasks
            ms++;                                     // ...One second heart beat
            if (ms==1000){
              ms=0;
              display_timer +=1;
              welcome_display(display_timer);
              if (Charging < 10){                   //If battery level < 10 
                goodbye_display(counter);
                counter += 1;
              } 
            } 
        }

          /*Battery inputs*/
          Tacke_adc1 = adc_value[1];                      //Between (00.00-255.00)
          Voltage_battery[v]=Tacke_adc1;                  //Add digital value to matrix
          Voltage_sum= Voltage_sum + Voltage_battery[v]; //Sum matrix
          v++;

          if(v==99){
            Voltage_M_Value=Voltage_sum/100.0;      ///Mean of 100 measurments
            Voltage_M_Value= Voltage_M_Value/819.2;
            
            Voltage_M_Value = Voltage_M_Value*20.0; //Voltage level(0.0%-100.0%)
            Charging = Voltage_M_Value;             //(0%-100%)
            
            battery_display(Charging);              //Display battery icon on LCD
          
            v=0;                                     //Reset all values... 
            Voltage_sum=0;
            Voltage_M_Value=0;
            Voltage_battery[N]=0;                   // ...
            }
          
    }
    
    }
