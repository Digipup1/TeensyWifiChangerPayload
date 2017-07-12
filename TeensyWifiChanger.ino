//Made by Dave https://github.com/Digipup1
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


  //moving to network name selection
  Mouse.move(0, 0); //broken
  delay(ds);
  Mouse.click();
  Keyboard.press(KEY_DOWN); 
  delay(3000);
  Keyboard.releaseAll();
  k(KEY_ENTER);
  typeln("NAMEOFWIFINETWORK"); //replace with your network name
  Mouse.move(0, 0); //broken
  delay(ds);
  Mouse.click();
  //k(KEY_DOWN); //uncomment if your new network uses WEP
  //k(KEY_DOWN); //uncomment if your new network uses WPA/WPA2 Personal 
  //k(KEY_DOWN); //uncomment if your new network uses WPA2 Personal
  //k(KEY_DOWN); //uncomment if your new network uses Dynamic WEP
  //k(KEY_DOWN); //uncomment if your new network uses WPA/WPA2 Enterprise
  //k(KEY_DOWN); //uncomment if your new network uses WPA2 Enterprise
  k(KEY_ENTER);
  delay(ds);

  //exit out of everything
  cmd(KEY_Q);
  cmd(KEY_Q);
  
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



void loop(){}
