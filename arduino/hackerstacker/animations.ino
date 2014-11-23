




  
  void flash(int rounds)
  {
  

  
   
    const int on=80;
    const int off=30;
    
    const int lsound =200;
    const int hsound =900;    
    
   for (int i=0;i<rounds;i++)
   {
     
    tone(BUZZERPIN,random(lsound,hsound),on);       
    matrix.fillScreen(matrix.Color(255,0,0));
    delay(on);

    tone(BUZZERPIN,random(lsound,hsound),off); 
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show();    
    
    tone(BUZZERPIN,random(lsound,hsound),on); 
    matrix.fillScreen(matrix.Color(0,255,0));
    delay(on);
    tone(BUZZERPIN,random(lsound,hsound),off); 
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show();  
    

    tone(BUZZERPIN,random(lsound,hsound),on); 
    matrix.fillScreen(matrix.Color(0,0,255));
    delay(on);
     tone(BUZZERPIN,random(lsound,hsound),off);    
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show();  
      
    tone(BUZZERPIN,random(lsound,hsound),on);     
    matrix.fillScreen(matrix.Color(255,255,255));
    delay(on);
    tone(BUZZERPIN,random(lsound,hsound),off);     
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show(); 
    
    
   } 
   
   
  }
  
  
  
  
  
  
  
  
const uint16_t  colortable[] ={
 matrix.Color(255,0,0),
 matrix.Color(255,255,0),
 matrix.Color(255,0,255),
 matrix.Color(0,255,255),
 matrix.Color(0,255,0),
 matrix.Color(0,0,255),
 matrix.Color(255,255,255),

};


void display_load_animation()
{
  
  
  //up - down
  for (int i=0;i<16;i++)
  {
  
    uint16_t col = colortable[random(0,7)];
  
    for (int j=0;j<8;j++)
    {
     matrix.drawPixel(j, i, col);
     matrix.show(); 
    }  
    tone(BUZZERPIN,50*(i+1),10);
    delay(10);  
  } 
  
  
  
  //left right
  for (int i=0;i<8;i++)
  {
  
    uint16_t col = colortable[random(0,7)];
  
    for (int j=0;j<16;j++)
    {
     matrix.drawPixel(i, j, col);
     matrix.show(); 
    }  
    tone(BUZZERPIN,80*(i+1),10);
    delay(10);
   
    
  } 
  
  
  
  
  
  
  //sweep.
  for (int i=0;i<16;i++)
  {
    for (int j=0;j<8;j++)
    {
     matrix.drawPixel(j, i, 0);
     matrix.show(); 
    }  
    tone(BUZZERPIN,50*(i+1),10);
    delay(10);
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
  matrix.setTextColor(matrix.Color(0,0,255));
  matrix.print(F(" Hacker"));
  
  
  
  if(--x < -44) {
    x = matrix.width();
      
    
  }
  
  
  
  matrix.setCursor(x, 9);
  matrix.setTextColor(matrix.Color(0,255,0));
  matrix.print(F("Stacker"));
  
  matrix.show();
  delay(60);


    
   return; 
  }
  







const unsigned int herzilein[] = {
  

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
  0,  0,  0,  0,  0,  0,  0,  0,
  
 
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
    
    if(button_pressed) return;
            
        matrix.show();
       
    
    }
  }
 
 
}




void show_highscore()
{
  

  button_pressed=0;
  score=0;
 
  
  // get score
  for (int i=0;i<128;i++)
  {
   if(matrix_background[i]>0)  score++;   
  }
  
  
  uint32_t starttime = millis();
  
  // display score
  for (int  i=0; i<1000;i++)
  {
  
    delay(10);
    if(button_pressed) 
    {
      if((millis()-starttime)>200)
         break;
    }

  }
  
  
   button_pressed=0;

  
  starttime = millis();
    x=8;
  
  
  
  for (int  i=0; i<100;i++)
  {
  
    
    if(button_pressed) 
    {
      if((millis()-starttime)>200)
         break;
    }
   button_pressed=0;
 
  
  
  
    
   matrix.fillScreen(0); 
  matrix.setCursor(x, 4);
  matrix.setTextColor(matrix.Color(0,255,0));
  matrix.print(score);
  
  matrix.show();
  delay(90);
  
    if(--x < -14) {
    x = matrix.width(); 
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



