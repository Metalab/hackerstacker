/*

stacker. stacker stacker.

You need:
2x 8x8 RGB-123 matrix  (http://www.hackerspaceshop.com/rgb-123.html)
A button preferably with background light.


I used one of those cheap chinese arduino pro micro clones.
A teensy 2.0 or 3.1 will work just as well.



GPL 2.0,  thrown together by overflo from hackerspaceshop.com / metalab.at

*/



#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>



// where is the matrix?
#define PIN 8


// where is the BUTTON?
#define BUTTON_PIN 2

// the led on the button
#define LED_PIN 9


// the led on the button
#define BUZZERPIN 16



// can change not static..
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by










// MATRIX DECLARATION:
// Parameter 1 = width of EACH NEOPIXEL MATRIX (not total display)
// Parameter 2 = height of each matrix
// Parameter 3 = number of matrices arranged horizontally
// Parameter 4 = number of matrices arranged vertically
// Parameter 5 = pin number (most are valid)
// Parameter 6 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the FIRST MATRIX; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs WITHIN EACH MATRIX are
//     arranged in horizontal rows or in vertical columns, respectively;
//     pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns WITHIN
//     EACH MATRIX proceed in the same order, or alternate lines reverse
//     direction; pick one.
//   NEO_TILE_TOP, NEO_TILE_BOTTOM, NEO_TILE_LEFT, NEO_TILE_RIGHT:
//     Position of the FIRST MATRIX (tile) in the OVERALL DISPLAY; pick
//     two, e.g. NEO_TILE_TOP + NEO_TILE_LEFT for the top-left corner.
//   NEO_TILE_ROWS, NEO_TILE_COLUMNS: the matrices in the OVERALL DISPLAY
//     are arranged in horizontal rows or in vertical columns, respectively;
//     pick one or the other.
//   NEO_TILE_PROGRESSIVE, NEO_TILE_ZIGZAG: the ROWS/COLUMS OF MATRICES
//     (tiles) in the OVERALL DISPLAY proceed in the same order for every
//     line, or alternate lines reverse direction; pick one.  When using
//     zig-zag order, the orientation of the matrices in alternate rows
//     will be rotated 180 degrees (this is normal -- simplifies wiring).
//   See example below for these values in action.
// Parameter 7 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 pixels)
//   NEO_GRB     Pixels are wired for GRB bitstream (v2 pixels)
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA v1 pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)

// Example with three 10x8 matrices (created using NeoPixel flex strip --
// these grids are not a ready-made product).  In this application we'd
// like to arrange the three matrices side-by-side in a wide display.
// The first matrix (tile) will be at the left, and the first pixel within
// that matrix is at the top left.  The matrices use zig-zag line ordering.
// There's only one row here, so it doesn't matter if we declare it in row
// or column order.  The matrices use 800 KHz (v2) pixels that expect GRB
// color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 1, 2, PIN,
  NEO_TILE_TOP   + NEO_TILE_LEFT   + NEO_TILE_ROWS   + NEO_TILE_PROGRESSIVE +
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB + NEO_KHZ800);




 
 
 

 
 
 
 
 
 
 





void setup() {


  
  
  Serial.println("GO!");
  
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);    
  pinMode(BUZZERPIN,OUTPUT);
 
  digitalWrite(BUZZERPIN,LOW);  
    
    
    
  attachInterrupt(1,buttonpressed_LOW_isr,FALLING);
  
  
  
  
  
  
  
  //remove this in PCB design..
  // should vonnect to vcc ..  
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);

  
  
  
}





//default do not much
int waitforactivation =1;

//default the button is not pressed
int button_pressed =0;


void buttonpressed_LOW_isr()
{
  
  
  waitforactivation=0;
  button_pressed=1;
  
  
  analogWrite(LED_PIN, 255);  
    
}










int x    = matrix.width();
int pass = 0;


void loop() {


  
  
  // fade led wait for interruptroutine to set waitforactivation to zero
   
  while(waitforactivation)  show_startup_animation(); 
  button_pressed=0; 
  
  
  display_load_animation();

  
   


   run_game();  
    
  }
    
    
  
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  


////////////  THE GAME


int current_row =15;
int direction=1; // from left to right
int current_position=0;





//how fast does each line move
const int linedelay[] = {
  40, 45, 45, 45, 50, 55,
  60, 65, 70, 75, 80, 85,
  90, 95, 100, 105, 110, 115,
  120
  };




// for testing
//const int linedelay[] = {
//200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200
//  };



//what color is each line

int m1=160;
int m2=220;





// each line has its own color

const uint16_t linecolors[] = {
  matrix.Color(255,0,255),  
  
  matrix.Color(220, 0, 255),  
  
  
  matrix.Color(m1, 0, 255), 
  matrix.Color(0,0,255), 
  matrix.Color(0, m1, 255),   
  matrix.Color(0,m2,255),  
  
  matrix.Color(0, 255, 255),  
  
  matrix.Color(0, 255,m2), 
  
  
  
  matrix.Color(0, 255, m1),  
  matrix.Color(0, 255, 0),   
  matrix.Color(m1, 255, 0),  
  matrix.Color(m2, 255, 0),  
  
  
  matrix.Color(255, 255, 0),
 
 
 
  matrix.Color(255, m2, 0),  
  matrix.Color(255, m1,0),     
  matrix.Color(255, 0, 0)

};











int blocksize=4;
int blockposition=0;
int moving_direction=1;
int force_blocksize=4;



int current_row_setpixels[] = {
  -1,-1,-1,-1
  };

int last_row_setpixels[] = {
  -1,-1,-1,-1
 };



void run_game()
{

  while(!waitforactivation)
  {
    button_pressed=0;
    
    // how big is the block in this row  by default?
    
    blocksize=1;      
    if(current_row>2)  blocksize=2;    
    if(current_row>6)  blocksize=3; 
    if(current_row>10) blocksize=4;     

    if(force_blocksize<blocksize)
      blocksize=force_blocksize;
    
    if(blocksize<force_blocksize)
     force_blocksize=blocksize;
    
    
    
    
    //draw backgound
    draw_background();
    
    //draw current line
    draw_blockline(current_row);

    
    //display current frame
    matrix.show();


    delay(linedelay[current_row]);
    
    
   
    
    
    
    
    if(button_pressed)
    {
 
      // Serial.println("Button pressed");
      // we wait till button is released again
      while(!digitalRead(BUTTON_PIN)){}
       delay(50);
      analogWrite(LED_PIN, 0);  

    // display animation
    close_current_row(current_row);
    
    //setup background
    setup_backgound(current_row);
    
    current_row--;       

     //  we reached the top ..
    if(current_row==-1)
    {
     win_game();
     current_row=15;
    }   
    
    button_pressed=0;
    
    
    } // if button pressed
    
   } // while

}













 // display animation
 void  close_current_row(int current_row)
 {
   // nothing happens on bottom row
   if(current_row==15)
     return;
   
   
   Serial.print("---- ROW ");  
   Serial.println(current_row);
   
   
  
   
   
   
   // find out which pixels are alright here
   for(int i=0;i<4;i++)
   {
    
    int ok=0; 
    // is the pixel on position i in previous row?
    for(int j=0;j<4;j++)
    {    
       
       if(current_row_setpixels[i] == last_row_setpixels[j]  &&  (current_row_setpixels[i] != -1)) 
       { 
        Serial.print("Pixel ");
        Serial.print(current_row_setpixels[i]);
        Serial.println(" is in row! :)");
        ok=1;
       }

     
     
      }
      
    if(!ok &&  (current_row_setpixels[i] != -1))
    {

      Serial.print("Pixel ");
      Serial.print(current_row_setpixels[i]);
      Serial.println(" DIES!");     

      
      kill_pixel(current_row,current_row_setpixels[i]);
      current_row_setpixels[i]=-1;
      
      //set new force_blocksize
      force_blocksize -= 1;
      
      if(force_blocksize==0) lose_game();        
            
    } // !ok :(
     
   } // for i++  ..  
  
  
  Serial.println("------");
 }





















// background frame
uint16_t matrix_background[128]={
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0

};








// shows animation of pixel that drops out..
void kill_pixel(int row, int col)
{
  
  
  
  for (int i=0;i<3;i++)
  {
    tone(BUZZERPIN,700+(i*10),50);
    matrix.drawPixel(col, row, matrix.Color(255,255,255));
    matrix.show();
    delay(50); 
    matrix.drawPixel(col, row, 0);
    matrix.show();
    delay(30);    
  
  } 
 
  for(int i=0; i<15;i++)
  {
  
    if(row+i >15) return;
     tone(BUZZERPIN,800+(i*10),50);
     matrix.drawPixel(col, row+i, matrix.Color(255,255,255));
     matrix.show();
     delay(50); 
     matrix.drawPixel(col, row+i, 0);
     matrix.show();
     delay(30);  
   
     // remove lines from background
     matrix_background[((row+i)*8)+col]=0;
   
  } 
}





























// this function is responsible for creating each line segment that moves left right and back ..
void draw_blockline(int row)
{ 
  
  // moving L to R
  if(moving_direction)
  {
    for(int i=0;i<blocksize;i++)
    {   
      current_row_setpixels[i] = blockposition+i;
      matrix.drawPixel(blockposition+i, row, linecolors[row]);     
    }
  
    // increment position
    blockposition++;
  
    // reset direction
    if(blockposition>(8-blocksize-1))
    {
      tone(BUZZERPIN,523,100); 
      moving_direction=0;
    }
  } 
  else
  {
    
   // FROM R to L    
   for(int i=0;i<blocksize;i++)
   {
      current_row_setpixels[i] = blockposition+i;

      matrix.drawPixel(blockposition+i, row, linecolors[row]);     

   }
   
   // decrement position
   blockposition--;
   // reset direction
   if(blockposition==0)
   {
    tone(BUZZERPIN,784,100);  
    moving_direction=1;
   }
   
   
  }  
      
}
















// setup background 
// background is painted before we draw our lines on it and shows all the previous lines
void  setup_backgound(int current_row){
    
   for(int x=0;x<4;x++)
   {    
     int setpixel = current_row_setpixels[x];
     if( (setpixel > -1)  && (setpixel<8) )  matrix_background[(current_row*8)+setpixel]=linecolors[current_row];    
   }

  
   for(int i=0;i<4;i++)
   {
    last_row_setpixels[i] =  current_row_setpixels[i];
    current_row_setpixels[i]=-1;
   }
 
}











// fills framebuffer
void draw_background()
{
   for(int y=0;y<16;y++)
   {
    for(int x=0;x<8;x++)
    {
      // fill frame with background
      matrix.drawPixel(x, y, matrix_background[(y*8)+x]);     
    }     
   }  
}





// clear backgorund
void reset_background()
{
   for(int x=0;x<128;x++)
   {
      matrix_background[x]=0;     
   }
}





// this happens if you make it to the top!
void win_game()
{
   finish_game();
   flash(1);  
   
   while(!button_pressed) show_sunshine_anim(); 

  
}




// this happens when you lose :(
void lose_game()
{
   flash(3); 
   finish_game();  
}





// reset variables, clean up.. finish a game.
void finish_game()
{

 reset_background();
 
 /// clear all buffers and variables set during game
 
 // start next round from bottom
 current_row=16;
 
 // with 4 blocks
 force_blocksize=4; 
 
 // no press ..
 button_pressed=0; 
 
 // fill buffers with emptyness
 for(int i=0;i<4;i++)
 {
    last_row_setpixels[i]   = 99;
    current_row_setpixels[i]= 99;
 }
 
  // display anim
  waitforactivation=1;
  
}



