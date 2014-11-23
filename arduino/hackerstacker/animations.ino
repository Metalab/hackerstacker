




  
  void flash(int rounds)
  {
  

  
   
    int on=80;
    int off=30;
    
   for (int i=0;i<rounds;i++)
   {
    matrix.fillScreen(matrix.Color(255,0,0));
    delay(on);
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show();    
    
    
    matrix.fillScreen(matrix.Color(0,255,0));
    delay(on);
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show();  
    
    matrix.fillScreen(matrix.Color(0,0,255));
    delay(on);
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show();  
      
    
    matrix.fillScreen(matrix.Color(255,255,255));
    delay(on);
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show(); 
    
    
   } 
   
   
  }
  
  
  
  
  
  
  
  
  


void display_load_animation()
{
  
  for (int i=0;i<16;i++)
  {
  
    uint16_t col = matrix.Color(random(10,255),random(10,255),random(10,255));
  
    for (int j=0;j<8;j++)
    {
     matrix.drawPixel(j, i, col);
     matrix.show(); 
    }  
    delay(10);
  } 
  
  
  for (int i=0;i<16;i++)
  {
    for (int j=0;j<8;j++)
    {
     matrix.drawPixel(j, i, 0);
     matrix.show(); 
    }  
    delay(20);
  } 
 
}






  
void   show_startup_animation()
{
  // FADE led on button
  analogWrite(LED_PIN, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  
                            


  matrix.fillScreen(0);
  matrix.setCursor(x, 1);
  matrix.setTextColor(matrix.Color(255,255,0));
  matrix.print(F(" Hacker"));
  
  
  
  if(--x < -44) {
    x = matrix.width();
  }
  
  
  
  matrix.setCursor(x, 9);
  matrix.setTextColor(matrix.Color(0,255,255));
  matrix.print(F("Stacker"));
  
  matrix.show();
  delay(60);


    
   return; 
  }
  







const unsigned int herzilein[] = {
  
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  1,  1,  0,  1,  1,  0,
  0,  1,  0,  0,  1,  0,  0,  1,
  0,  1,  0,  0,  0,  0,  0,  1,
  0,  0,  1,  0,  0,  0,  1,  0,
  0,  0,  0,  1,  0,  1,  0,  0,
  0,  0,  0,  0,  1,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  1,  1,  0,  1,  1,  0,  0,
  1,  0,  0,  1,  0,  0,  1,  0,
  1,  0,  0,  0,  0,  0,  1,  0,
  0,  1,  0,  0,  0,  1,  0,  0,
  0,  0,  1,  0,  1,  0,  0,  0,
  0,  0,  0,  1,  0,  0,  0,  0,
  
 
};




void show_sunshine_anim()
{
   
  int wait=100;
  
  
  
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < 16; i=i+3) {
          for (int col=0;col<8;col++)
          {
                matrix.drawPixel(col, i+q, Wheel( (i+j) % 255));
          }
            
         
      
    }
    
    
    for (int row=0; row<16;row++)
    {
      for (int column=0; column<16;column++)
      {
        if(herzilein[(row*8)+column]) 
         {
            matrix.drawPixel(column, row, matrix.Color(255,0,0));
       
         }
      }    
    }
    
    
        matrix.show();
       
    
    }
  }
 
 
}













uint16_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return matrix.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return matrix.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return matrix.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}



