#include "display.h"
#include "lcd.h"


void welcome_display(int display_timer){
    if (display_timer < 3){
     LCD_ShowStr(10, 10, "Welcome", WHITE, TRANSPARENT);
    }            
    if (display_timer == 6){
    LCD_ShowStr(10, 10, "Welcome", BLACK,TRANSPARENT);
    }
}

void goodbye_display(int counter){
    if ((counter % 2 == 1) ){
     LCD_ShowStr(10, 40, "Low battery", RED, TRANSPARENT);
    }  
    else {
     LCD_ShowStr(10, 40, "Low battery", BLACK, TRANSPARENT);
    }
          
}

void battery_display(int Charging){
            if(Charging < 25)
            {
              
              LCD_ShowStr(100, 20, "%", WHITE, TRANSPARENT);//**PA4
              LCD_ShowChar(70,20, 126, 0, WHITE);
              
      
            }else if(Charging > 25 && Charging < 50){
            
              
              LCD_ShowStr(100, 20, "%", WHITE, TRANSPARENT);
              LCD_ShowChar(70,20, 127, 0, WHITE);
              
            }
            else if(Charging> 50 && Charging< 75)
            { 
             
              LCD_ShowStr(100, 20, "%", WHITE, TRANSPARENT);
              LCD_ShowChar(70,20, 128, 0, WHITE);
              
            }
            else if(Charging >75 && Charging < 96)
            {
              
              LCD_ShowStr(100, 20, "%", WHITE,TRANSPARENT);
              LCD_ShowChar(70,20, 129, 0, WHITE);
              
            }
            else if(Charging >=96 )
            {
              
              LCD_ShowStr(100, 20, "%", GREEN, TRANSPARENT);
              LCD_ShowChar(70,20, 130, 0, GREEN);
              
            }
}