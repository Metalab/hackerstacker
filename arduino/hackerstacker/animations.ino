




  
  void flash(int rounds)
  {
  

   
    const int on=80;
    const int off=30;
    
    const int lsound =200;
    const int hsound =900;    
    
   for (int i=0;i<rounds;i++)
   {
    if(button_pressed)
    {
      button_pressed=0;
      return;
    }
    
    tone(BUZZERPIN,random(lsound,hsound),on);       
    matrix.fillScreen(matrix.Color(255,0,0));
    
    
      
    if(!digitalRead(LED_ENABLE)) for(int i=0;i<BORDER_PIXELCOUNT;i++){border.setPixelColor(i, matrix.Color(0,255,0)); }; border.show(); 
   
  
    
    
    delay(on);

    tone(BUZZERPIN,random(lsound,hsound),off); 
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show();    
    
    tone(BUZZERPIN,random(lsound,hsound),on); 
    matrix.fillScreen(matrix.Color(0,255,0));
    
    
    if(!digitalRead(LED_ENABLE)) for(int i=0;i<BORDER_PIXELCOUNT;i++){border.setPixelColor(i, matrix.Color(255,0,0)); }; border.show(); 
   
    
    delay(on);
    tone(BUZZERPIN,random(lsound,hsound),off); 
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show();  
    

    tone(BUZZERPIN,random(lsound,hsound),on); 
    matrix.fillScreen(matrix.Color(0,0,255));
    
    if(!digitalRead(LED_ENABLE)) for(int i=0;i<BORDER_PIXELCOUNT;i++){border.setPixelColor(i, matrix.Color(0,0,255)); }; border.show(); 
    
    
    delay(on);
     tone(BUZZERPIN,random(lsound,hsound),off);    
    matrix.show();
    matrix.fillScreen(0);
    delay(off);
    matrix.show();  
      
    tone(BUZZERPIN,random(lsound,hsound),on);     
    matrix.fillScreen(matrix.Color(255,255,255));
    
    
    
    if(!digitalRead(LED_ENABLE))  for(int i=0;i<BORDER_PIXELCOUNT;i++){border.setPixelColor(i, matrix.Color(255,255,255)); }; border.show(); 
    
    
    
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
  
  matrix.fillScreen(0);
  
  //up - down
  for (int i=0;i<16;i++)
  {
  
    uint16_t col = colortable[random(0,7)];
  
    for (int j=0;j<8;j++)
    {
      
     if(button_pressed)
     {
      button_pressed=0;
      return;
     } 
      
      
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
     if(button_pressed)
     {
      button_pressed=0;
      return;
     } 
     
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
      
     if(button_pressed)
     {
      button_pressed=0;
      return;
     }  
      
     matrix.drawPixel(j, i, 0);
     matrix.show(); 
    }  
    tone(BUZZERPIN,50*(i+1),10);
    delay(10);
  } 
 
}







int x    = 8;  
  
void   show_startup_animation()
{
  
  
  
  //while(digitalRead(BUTTON_PIN)){} // debounce button
  //delay(100);
  //button_pressed=0;


  
  
  
  int counter=0;
  
  while(!button_pressed)
  {

    
   for(int i=0;i<BORDER_PIXELCOUNT;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    border.setPixelColor(i, border.Color(brightness,0,0)); // Moderately bright green color.

  } 
  if(!digitalRead(LED_ENABLE))  border.show(); // This sends the updated pixel color to the hardware.
    

  // FADE led on button
  if(!digitalRead(LED_ENABLE)) analogWrite(LED_PIN, brightness);    

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
    counter++;
  }    
  
  
  if(counter >=5)
  {
   //flash(1);
   show_highscore(53);
   counter=0;
  }  
  
  
  
  matrix.setCursor(x, 9);
  matrix.setTextColor(matrix.Color(0,255,0));
  matrix.print(F("Stacker"));
  
  matrix.show();
  delay(60);

  }
    
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




void show_score()
{
  

  
  set_pxl_score();
  
  
  button_pressed=0;  
  // display tower for 2 seconds .. may be interrupted any time 
  for (int  i=0; i<200;i++)
  {
  
    delay(10);
    if(button_pressed) 
    {
         button_pressed=0;
         break;
    }

  }  
  button_pressed=0;
  
 
  
  

  
  
  
  
  // display score strig
  int totalscore = (score+rowscore);
  String scorestring ="";
  scorestring = scorestring + score + "+" + rowscore+ "=" + totalscore;
  
  show_one_line(scorestring,matrix.Color(0,255,0),85);
  

}



void show_highscore(int timer)
{
  
  
    String scorestring ="Highscore";
    show_one_line(scorestring,matrix.Color(255,255,255),60);  
    
    
    scorestring = get_highscore_name() + ":" + get_highscore() ; 
    show_one_line(scorestring,matrix.Color(255,255,0),timer); 
  
  
}










void show_one_line(String str, uint16_t color, int timeout)
{
  
  

  
  

   int strlen =  str.length();  
  
   uint32_t starttime = millis();
   int x=8;
  
  
  
   // display string for given time..
   for (int  i=0; i<timeout;i++)
   {
    if(button_pressed) 
    {
      if((millis()-starttime)>200)
         break;
    }
    button_pressed=0; 
  

    matrix.fillScreen(0); 
    matrix.setCursor(x, 4);
    matrix.setTextColor(color);
    matrix.print(str);
    matrix.show();
    delay(100);
  
  
    // one character is average 7 wide .
    if(--x < int ((strlen*7)*(-1))  ) 
     x = matrix.width(); 
     
   } // for .. timeout
   
}














int check_highscore()
{
  
    set_pxl_score();
  
   int totalscore = (score+rowscore);
   
   // if we got no new highscore we return in shame :(
   if(get_highscore() >  totalscore) return 0;
   
   
   
 
   
   // show NEW HIGHSCORE in one scroll .. 
   String str = "NEW HIGHSCORE:    ";
//   Serial.println(totalscore);
 
 
   show_one_line(str, matrix.Color(0,0,255), 90);
   
   
   
   
   
   
   // then get data to insert new entry;
   
   //set input chars to space by default
   char a,b,c,d =0x20; 
   
   char currentchar=0xFFFFFFDA;
   
   int charcount=0;
   int char_input_done=0;
   
 
   button_pressed=0;
    
   uint32_t lastinput = 0;
  
   int inputfinished=0;  
  
  
  
  
       
     
 
     
     

  
  
  
   while(!char_input_done)
   {
     
     
    // display current character
    
    
           //blink current character blue and white
     matrix.fillScreen(0); 
     matrix.setCursor(2, 5);
     matrix.setTextColor(matrix.Color(0,0,255));
     matrix.print(currentchar);
     matrix.show();
     delay(100);
     matrix.fillScreen(0); 
     matrix.setCursor(2, 5);
     matrix.setTextColor(matrix.Color(127,127,127));
     matrix.print(currentchar);
     matrix.show();
     delay(50);   
     
     
     
     
     
     

     
     
     
     // ah the button was pressed.. 
     // was it pressed for long?
    
     
     
     // or..update the displayed char
     if(button_pressed>0)
     {
       
       
       
       lastinput = millis();
   //    Serial.println("pressed");
       
          
          
       while(!digitalRead(BUTTON_PIN) && !inputfinished)
       { 

         // Serial.println("hier"); 
         
 
         // deep blue 
        matrix.fillScreen(0); 
        matrix.setCursor(2, 5);
        matrix.setTextColor(matrix.Color(0,0,255));
        matrix.print(currentchar);
        matrix.show();

         
         
         
         // button down
 //        Serial.println("DOWN");
        if(millis()-lastinput > 800)
        {
         // button was pressd for > 1 second
         // save the current character 
          
   //                Serial.println("saveloop");  
          
         // fadeout current character      
         for(int i=255;i>0;i--)
         { 
           matrix.fillScreen(0); 
           matrix.setCursor(2, 5);
           matrix.setTextColor(matrix.Color(i,0,0));
           matrix.print(currentchar);
           matrix.show();       
         } 
          
       
         // to display something if we enter a space we use a monolith, but we rather save a space in the eeprom
         if(currentchar == 0xFFFFFFDA)
         {
          currentchar= 0x20; // replace block with space
          char_input_done=1;  //assume we are done if there is a space before the 4 chars..
         }
      
      
         // update the 4 parameters to save in eeprom later
         if(charcount==0) a = currentchar; 
         if(charcount==1) b = currentchar;
         if(charcount==2) c = currentchar; 
      
         // last char .. we are outta here.
         if(charcount==3)
         { 
          d = currentchar; 
          char_input_done=1;
         }
    
  //   Serial.print("Saving char:" );
  //   Serial.println(currentchar);
  
       
         charcount++;
      
      // next char will be a monolith again
      currentchar= 0xFFFFFFDA; 
      
      // reset the timer for next char   
      lastinput = 0;
   
   
       // is set on save 
      inputfinished=1;
          
          
          
          
 
        } // if button down > 1.5 sec
   
   
      

   
   
       }   // while button down
       // button was released       


      while(inputfinished && !digitalRead(BUTTON_PIN))
      {
       // input finished but button still down?
      //do nothing. 
        delay(10); 
      }


       inputfinished=0;

              
       // increment character
       currentchar++;
       
      // 0x20 = " "
      // 0xFFFFFFDA  = BLOCK
      if(currentchar >=  0xFFFFFFDA ) currentchar='A'; // 65 DEC  (90 =Z)
      if(currentchar>'Z') currentchar=0xFFFFFFDA; // set to monolith
      
       button_pressed=0; 
          
     }
     
     
     
     
     
     


    
    
    } // while input not done ..
   
    // input done? great!
    
    
    Serial.println("SAVE THE SCORE");
    
    //delay(100);
    save_highscore_name (a,b,c,d);
    save_highscore (totalscore);   
 
 
 
 
 
        button_pressed=0; 
 
   // we set a new highscore .. show it!
   return 1; 
  
}




















/// color helpers





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




