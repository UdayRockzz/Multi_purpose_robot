#include<p89v51rd2.h>
#include<uart.h>
#include<lcd.h>
#include<delay.h>
void main()
{
unsigned char c;
LCD_Init();
UART_Init(9600);
while(1)
{
    c=UART_getdata();
    while(c=='F') //fire sensor//
{
    LCD_cmd(0X80);
    LCD_data("fire sensor active");
    if(P1_2==1)
  {
          TX_Data("fire detected and water pump activated");//water pump//
          P2_6=0;
          P2_7=1;
  }
   else 
      {
	     P2_6=0;
         P2_7=0;
	  }
}

   while(c=='S')//smoke// 
{ 
        LCD_cmd(0X80);
        LCD_data("smoke sensor active");
        if(P1_3==1)
{
   TX_Data("smoke detector");
}
}
   while(c=='O')//gripper is opened//
{
       LCD_clrdisp();
	   LCD_cursorpos(1,1);
       LCD_data("Gripper is open");
       TX_Data("Gripper is open");
       P2_2=1;
       P2_3=0;	
       delay_ms(50);
       P2_2=0;
       P2_3=0;
}
   while(c=='L')//light sensor is on//
	   LCD_clrdisp();
	   LCD_cursorpos(1,1);
       LCD_data("LDR is active");
	 if(P1_5==1)
	   TX_Data("LDR is detected");
		{	
		P2_0=1; //forward
		P2_1=0;
		P2_4=1;
		P2_5=0;
	delay_ms(100);
	}
      else
		{
		P2_0=0;    //stop
		P2_1=0;
		P2_4=0;
		P2_5=0;		
		}


  while(c=='C')//gripper is closed//
{
      LCD_clrdisp();
	  LCD_cursorpos(1,1);
      LCD_data("Gripper is closed");
      TX_Data("Gripper is closed");
      P2_2=0;
      P2_3=1;
      delay_ms(50);
      P2_2=0;
      P2_3=0;
}
  while(c=='f')//forward//
{
      LCD_clrdisp();
	  LCD_cursorpos(1,1);
      LCD_data("forward");
      P2_0=1;
	  P2_1=0;
	  P2_4=1;
	  P2_5=0;
	  delay_ms(50);
	  P2_0=0;
	  P2_1=0;
	  P2_4=0;
	  P2_5=0;
      delay_ms(5);
}
  while(c=='r')//reverse//
{
     LCD_clrdisp();
	 LCD_cursorpos(1,1);
     LCD_data("reverse");
     P2_0=0;
     P2_1=1;
     P2_4=0;
     P2_5=1;
    delay_ms(50);
	 P2_0=0;
	 P2_1=0;
	 P2_4=0;
	 P2_5=0;
    delay_ms(5);

}
 while(c=='l')//left//
{
     LCD_cmd(0X80);
     LCD_data("left");
     P2_0=0;
     P2_1=0;
     P2_4=0;
     P2_5=1;
   	 delay_ms(50);
	 P2_0=0;
	 P2_1=0;
	 P2_4=0;
	 P2_5=0;
     delay_ms(5);

}
  while(c=='r')//right//
{
     LCD_clrdisp();
	 LCD_cursorpos(1,1);
     LCD_data("right");
     P2_0=1;
     P2_1=0;
     P2_5=0;
     delay_ms(50);
	 P2_0=0;
	 P2_1=0;
	 P2_4=0;
	 P2_5=0;
     delay_ms(5);

}
 while(c=='H')//pir  sensor// 
{
     LCD_clrdisp();
	 LCD_cursorpos(1,1);
     LCD_data("pir active");
     if(P1_4==1)
{
  TX_Data("human detected");
}
}
  while(c=='W')//Wall sensor//
{
     LCD_clrdisp();
	 LCD_cursorpos(1,1);
     LCD_data("wall sensor active");
     if(P3_2==1 && P3_3==0)
{
     TX_Data("obstacle is in  fornt direction");
            P2_0=0;
			P2_1=0;
			P2_4=0;
			P2_5=0;
	     	delay_ms(20);
	  TX_Data("robot is moving backward");
			P2_0=0;
			P2_1=1;
			P2_4=0;
			P2_5=1;
			delay_ms(40);
	  TX_Data("robot is moving right direction");
			P2_0=1;
			P2_1=0;
			P2_4=1;
			P2_5=1;
	    	delay_ms(100);
     
}
  if(P3_2==1 && P3_3==1)
{   
     TX_Data("obstacle detected on left and fornt direction");
            P2_0=0;
			P2_1=0;
			P2_4=0;
			P2_5=0;
			delay_ms(20);
	  TX_Data("robot is moving backwards");
			P2_0=0;
			P2_1=1;
			P2_4=0;
			P2_5=1;
			delay_ms(40);
	  TX_Data("robot is moving ryt direction");
			P2_0=1;
			P2_1=0;
			P2_4=1;
			P2_5=1;
			delay_ms(100);
  			  
}
 if(P3_2==0 && P3_3==1)
{
  TX_Data("obstacle detected on left direction");
  {				
         	P2_0=1;	 //moving right
			P2_1=0;
			P2_4=1;
			P2_5=1;
			delay_ms(10);
		}	
		else
		{	    
			P2_0=1;	    //moving left
			P2_1=1;
			P2_4=1;
			P2_5=0;
		   delay_ms(10);
  }
}
}
 }
}