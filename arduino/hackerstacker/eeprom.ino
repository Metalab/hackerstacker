#include <EEPROM.h>








//inits rom when the machine ist turned on for the first time ever ..
int init_eeprom_on_firstrun()
{
    save_highscore_name('O','V','R','F');
    save_highscore(133);    
    
    // magic byte at p[osition 100 is set to 1 .. now we will never again do anything in the function run_for_the_first_time()
    EEPROM.write(100, 1); 
}






void save_highscore(int score)
{

  
//  Serial.print("Called for writing with eeprom: ");
//  Serial.println(score);
  
  
  byte sb1 = score;
  byte sb2 =0;


  if(score>255)
  {
    sb2=255;
    sb1=score-255;   
  }

    
  
//  Serial.print("Writing highscore to eeprom: ");
//  Serial.println(score);
//  Serial.println("------------");

//  Serial.print("Byte 1: ");
//  Serial.print(sb1);
//  Serial.print(" - ");
//  Serial.print(sb1,DEC);
//  Serial.print(" - ");
//  Serial.println(sb1,HEX);

//  Serial.print("Byte 2: ");
//  Serial.print(sb2);
//  Serial.print(" - ");
//  Serial.print(sb2,DEC);
//  Serial.print(" - ");
//  Serial.println(sb2,HEX);

//  Serial.println("------------");
  
//  Serial.println(sb1+sb2);





      EEPROM.write(0, sb1);
      EEPROM.write(1, sb2);

      
}

void save_highscore_name (char a, char b, char c,char d)
{
  
  
  // should be ok
      EEPROM.write(2, a);
      EEPROM.write(3, b);
      EEPROM.write(4, c);  
      EEPROM.write(5, d);   
}





int get_highscore()
{
  

  byte sb1 = EEPROM.read(0);
  byte sb2 = EEPROM.read(1);
  
  
  int hs =  (int) sb1 + (int) sb2;
  
  

 
 
 // Serial.print("GETTING highscore from eeprom: ");
 // Serial.println(hs);
 // Serial.println("------------");

 // Serial.print("Byte 1: ");
 // Serial.print(sb1);
 // Serial.print(" - ");
 // Serial.print(sb1,DEC);
 // Serial.print(" - ");
 // Serial.println(sb1,HEX);

//  Serial.print("Byte 2: ");
//  Serial.print(sb2);
//  Serial.print(" - ");
//  Serial.print(sb2,DEC);
//  Serial.print(" - ");
//  Serial.println(sb2,HEX);

//  Serial.println("------------");

 
 
 
     
  
  return hs;
  
  
}



String get_highscore_name()
{

  
  String highscore_name="";
  char c1,c2,c3,c4;
  
  c1 = EEPROM.read(2);
  c2 = EEPROM.read(3);
  c3 = EEPROM.read(4);  
  c4 = EEPROM.read(5);
  
  //TODO
  // combine byte 1 and 2
    
  if(c1==0xFFFFFFFF) c1 ='W';  
  if(c2==0xFFFFFFFF) c2 ='T'; 
  if(c3==0xFFFFFFFF) c3 ='F';   
  if(c4==0xFFFFFFFF) c4 =' ';   
  
     
  //Serial.print("EEPROM READS:");
  //Serial.print(c1,HEX);  
  //Serial.print(" ");       
  //Serial.print(c2,HEX);  
  //Serial.print(" ");  
  //Serial.print(c3,HEX);  
  //Serial.print(" ");  
  //Serial.println(c4,HEX);    
     
     
  highscore_name = String(c1) + String(c2) + String(c3) + String(c4);   
  
  return highscore_name;

  
}
