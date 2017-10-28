//To Do list:
//1. Fix the LP running when it isn't followed by digits. - DONE/FIXED
    //- The thing it will return with a NULL value aka a '0' value - DONE/FIXED
//2. Fix the 2 lines of the test harness that return with a fail. - Doing now.
    //- Testing with =|%%=%=@ %^|%|%=% Received A  EEF  (A# EEF  ) Doesn't match. (==Fail==) - DONE/FIXED
      //- Fixed by adding the ability to produce a hash from the given CAM that seems to present a CAM in what was expected.
    //- Testing with   % = @  Received    @===@   (  E A T  ) Doesn't match. (==Fail==) - DONE/FIXED
//3. Finish the Write up. - Later
//4. Get new screenshots of the ouput and annotate them. - Later


//The defining of the pre-processing so that the relevant pins works with the names instead of the pins.
//#define DEBUG
#define BLUELED 11
#define GREENLED 10
#define YELLOWLED 9
#define ORANGELED 6
#define REDLED 5
#define IR_EMITTER A1
#define IR_RECIEVER 2
#define POT_PIN A0
#define JACK A2

//-----------------------------------------------------------------------
//Functions and global variables for part 1:

//Defining char arrays so that they can be called in a switch and if/else statements later on.
//They are required to be global because they are being used in more than one place.
char cam_a[] = "=";
char cam_b[] = "%%=";
char cam_c[] = "%=@";
char cam_d[] = "%=";
char cam_e[] = "%";
char cam_f[] = "%=%"; 
char cam_g[] = "==";
char cam_h[] = "%==";
char cam_i[] = "%%";
char cam_j[] = "=%%";
char cam_k[] = "%@";
char cam_l[] = "%%@";
char cam_m[] = "=%";
char cam_n[] = "=@";
char cam_o[] = "@=";
char cam_p[] = "@%";
char cam_q[] = "==@";
char cam_r[] = "%@=";
char cam_s[] = "%@%";
char cam_t[] = "@";
char cam_u[] = "@@";
char cam_v[] = "==%";
char cam_w[] = "=%@";
char cam_x[] = "=@%";
char cam_y[] = "%@@";
char cam_z[] = "===";
char cam_1[] = "@%%=";
char cam_2[] = "@%%@";
char cam_3[] = "@%=%";
char cam_4[] = "@%==";
char cam_5[] = "@%=@";
char cam_6[] = "@%@%";
char cam_7[] = "@%@=";
char cam_8[] = "@%@@";
char cam_9[] = "@=%%";
char cam_0[] = "@%%%";
char cam_fullstop[] = "@%%";
char cam_comma[] = "@%=";
char cam_apost[] = "@=%";
char cam_quesMark[] = "@==";
char cam_exclamMark[] = "@=@";
char cam_plus[] = "@@%";
char cam_minus[] = "@@=";
char cam_multiply[] = "@@@";
char cam_divide[] = "@%@";
char cam_equals[] = "@===@";
char cam_space[] = " ";
char cam_hash[] = "%%=%=@";

//This function will translate one normal charecter into a CAM charecter.
char * char2cam(char c){
  //the input is made to be lower case to reduce the arguements in the switch statement and processing.
  //This makes it more efficient.
  c = tolower(c);
  switch (c) {
    case 'a':
      return cam_a;
      break;

    case 'b':
      return cam_b;
      break;

    case 'c':
      return cam_c;
      break;

    case 'd':
      return cam_d;
      break;

    case 'e':
      return cam_e;
      break;

    case 'f':
      return cam_f;
      break;

    case 'g':
      return cam_g;
      break;

    case 'h':
      return cam_h;
      break;

    case 'i':
      return cam_i;
      break;

    case 'j':
      return cam_j;
      break;

    case 'k':
      return cam_k;
      break;

    case 'l':
      return cam_l;
      break;

    case 'm':
      return cam_m;
      break;

    case 'n':
      return cam_n;
      break;

    case 'o':
      return cam_o;
      break;

    case 'p':
      return cam_p;
      break;

    case 'q':
      return cam_q;
      break;

    case 'r':
      return cam_r;
      break;

    case 's':
      return cam_s;
      break;

    case 't':
      return cam_t;
      break;

    case 'u':
      return cam_u;
      break;

    case 'v':
      return cam_v;
      break;

    case 'w':
      return cam_w;
      break;

    case 'x':
      return cam_x;
      break;

    case 'y':
      return cam_y;
      break;

    case 'z':
      return cam_z;
      break;

    case '1':
      return cam_1;
      break;

    case '2':
      return cam_2;
      break;

    case '3':
      return cam_3;
      break;

    case '4':
      return cam_4;
      break;

    case '5':
      return cam_5;
      break;

    case '6':
      return cam_6;
      break;

    case '7':
      return cam_7;
      break;

    case '8':
      return cam_8;
      break;

    case '9':
      return cam_9;
      break;

    case '0':
      return cam_0;
      break;

    case '.':
      return cam_fullstop;
      break;

    case ',':
      return cam_comma;
      break;

    case '\'':
      return cam_apost;
      break;

    case '?':
      return cam_quesMark;
      break;

    case '!':
      return cam_exclamMark;
      break;

    case '+':
      return cam_plus;
      break;

    case '-':
      return cam_minus;
      break;

    case '*':
      return cam_multiply;
      break;

    case '/':
      return cam_divide;
      break;

    case '=':
      return cam_equals;
      break;

    case ' ':
      return cam_space;
      break;

    case '#':
      return cam_hash;
      break;

    default:
    //Prints when DEBUG is defined if the error is from this function
      #ifdef DEBUG
      Serial.println("ERROR IN THE CHAR2CAM FUNCTION");
      #endif
      break;
  }
}

//This function will print out an entire string to the serial port,
//By using the char2cam function made previously.
void printCAM(String s) {
  for(int i = 0; i < s.length(); i++){
    if (s[i] == ' '){
      Serial.print(' ');
    }
    else if (s[i + 1] == ' '){
      Serial.print(char2cam(s[i]));
    }
    else if (s[i + 1] == 0){
      Serial.print(char2cam(s[i]));
      Serial.println("");
    }
    else{
      Serial.print(char2cam(s[i]));
      Serial.print("|");
    }
  }
}
//This function will return a string which is in CAM after recieveing
//a normal charecter string.
String string2cam(String s){
  String inCAM;
  for(int i = 0; i < s.length(); i++){
    if (i == 0) {
      inCAM = char2cam(s[i]);
      if (s[i + 1] == 0){
        //Do nothing
      } 
      else if (s[i + 1] == ' '){
        //Do nothing
      }
      else if (s[i] == ' '){
        //Do nothing
      }
      else{
        inCAM += "|";
      }
    }
    else{
      inCAM += char2cam(s[i]);
      if (s[i + 1] == 0){
        //Do nothing
      }
      else if (s[i] == ' '){
        //Do nothing
      }
      else if (s[i + 1] == ' '){
        //Do nothing
      }
      else{
        inCAM += "|";
      }
    }
  }
  return inCAM;
}

//This function will return a charecter when given a string, of CAM.
char cam2char(String m){
  if (m.equals(cam_a)){
    return 'A';
  }
  else if (m.equals(cam_b)){
    return 'B';
  }
  else if (m.equals(cam_c)){
    return 'C';
  }
  else if (m.equals(cam_d)){
    return 'D';
  }
  else if (m.equals(cam_e)){
    return 'E';
  }
  else if (m.equals(cam_f)){
    return 'F';
  }
  else if (m.equals(cam_g)){
    return 'G';
  }
  else if (m.equals(cam_h)){
    return 'H';
  }
  else if (m.equals(cam_i)){
    return 'I';
  }
  else if (m.equals(cam_j)){
    return 'J';
  }
  else if (m.equals(cam_k)){
    return 'K';
  }
  else if (m.equals(cam_l)){
    return 'L';
  }
  else if (m.equals(cam_m)){
    return 'M';
  }
  else if (m.equals(cam_n)){
    return 'N';
  }
  else if (m.equals(cam_o)){
    return 'O';
  }
  else if (m.equals(cam_p)){
    return 'P';
  }
  else if (m.equals(cam_q)){
    return 'Q';
  }
  else if (m.equals(cam_r)){
    return 'R';
  }
  else if (m.equals(cam_s)){
    return 'S';
  }
  else if (m.equals(cam_t)){
    return 'T';
  }
  else if (m.equals(cam_u)){
    return 'U';
  }
  else if (m.equals(cam_v)){
    return 'V';
  }
  else if (m.equals(cam_w)){
    return 'W';
  }
  else if (m.equals(cam_x)){
    return 'X';
  }
  else if (m.equals(cam_y)){
    return 'Y';
  }
  else if (m.equals(cam_z)){
    return 'Z';
  }
  else if (m.equals(cam_1)){
    return '1';
  }
  else if (m.equals(cam_2)){
    return '2';
  }
  else if (m.equals(cam_3)){
    return '3';
  }
  else if (m.equals(cam_4)){
    return '4';
  }
  else if (m.equals(cam_5)){
    return '5';
  }
  else if (m.equals(cam_6)){
    return '6';
  }
  else if (m.equals(cam_7)){
    return '7';
  }
  else if (m.equals(cam_8)){
    return '8';
  }
  else if (m.equals(cam_9)){
    return '9';
  }
  else if (m.equals(cam_0)){
    return '0';
  }
  else if (m.equals(cam_fullstop)){
    return '.';
  }
  else if (m.equals(cam_comma)){
    return ',';
  }
  else if (m.equals(cam_apost)){
    return '\'';
  }
  else if (m.equals(cam_quesMark)){
    return '?';
  }
  else if (m.equals(cam_exclamMark)){
    return '!';
  }
  else if (m.equals(cam_plus)){
    return '+';
  }
  else if (m.equals(cam_minus)){
    return '-';
  }
  else if (m.equals(cam_multiply)){
    return '*';
  }
  else if (m.equals(cam_divide)){
    return '/';
  }
  else if (m.equals(cam_equals)){
    return '=';
  }
  else if (m.equals(cam_space)){
    return ' ';
  }
  else if (m.equals(cam_hash)){
    return '#';
  }
  else{
    //If DEBUG is defined it will tell me where the error is occuring.
    #ifdef DEBUG
    Serial.println("Error in the cam2char");
    #endif
  }
}

//This function will translate CAM and then print out whatever that CAM
//Meant into the serial port.
void printCAMString(String m){
  String tempString;
  String endString;
  for (int i = 0; i < (m.length() + 1); i++){
    if (m[i] == '%'){
      tempString += m[i];
    }
    else if (m[i] == '@'){
      tempString += m[i];
    }
    else if (m[i] == '='){
      tempString += m[i];
    }
    else if (m[i] == '|'){
      endString += cam2char(tempString);
      tempString = "";
    }
    else if (m[i] == ' '){
      endString += cam2char(tempString);
      tempString = "";
      endString += ' ';
    }
    else if (m[i] == 0){
      endString += cam2char(tempString);
      tempString = "";
    }
    else{
      //If DEBUG is defined then it will tell me there is an error in thi
      //Function.
      #ifdef DEBUG
      Serial.println("Error in the loop for function printCAMString");
      #endif
    }
  }
  Serial.println(endString);
}

//Very similar to the printCAMstring function but instead of printing
//the results it will simply return it so that it can be used in other
//functions.
String CAMString2String(String m){
  String tempString;
  String endString;
  for (int i = 0; i < (m.length()+1); i++){
    if (m[i] == '%'){
      tempString += m[i];
    }
    else if (m[i] == '='){
      tempString += m[i];
    }
    else if (m[i] == '@'){
      tempString += m[i];
    }
    else if (m[i] == '|'){
      endString += cam2char(tempString);
      tempString = "";
    }
    else if (m[i] == ' ' && (m[i-1] == 0 || m[i-1] == ' ')){
      tempString = "";
      endString += ' ';
    }
    else if (m[i] == ' '){
      endString += cam2char(tempString);
      tempString = "";
      endString += ' ';
    }
    else if (m[i] == 0){
      endString += cam2char(tempString);
      tempString = "";
    }
    else{
      #ifdef DEBUG
      Serial.println("Error in the loop for function CAMString2String");
      #endif
    }
  }
  return endString;
}

//Returns the value entered into the Serial Monitor
String promptReadIn() {
  String iValue;
  while (!Serial.available());
  //AKA do nothing till an input is recieved.
  iValue = Serial.readString();
  return iValue;
}

bool checkIf(String m){
  for(int i = 0; i < m.length(); i++){
    if(m[i] == ' '){
      //Do nothing
    }
    else if(m[i] == '%' || m[i] == '@' || m[i] == '='){
      return true;
      break;
    }
    else{
      return false;
      break;
    }
  }
}

//------------------------------------------------------------------------------------
//Functions and global variables for part2:
//A function that will act as the dotDelay so that I can make it have a min of 20ms and a max of 500ms whilst scaling linearly
int readPot(){
  int pot;
  pot = analogRead(POT_PIN);
  pot = ((pot - 23) / 2);
  if(pot <= 20){
    pot = 20;
  }
  else if(pot >= 500){
    pot = 500;
  }
  else{
    //Do nothing
  }
  return pot;
}

//CAM input and text input
String camIp;
String textIp;

//A function that will write digitally to a given pin for the term '%'
//This is however made specifically for an LED
void percentLED(int pin){
  digitalWrite(pin, HIGH);
  delay (readPot());
  digitalWrite(pin, LOW);
  #ifdef DEBUG
  Serial.println("Percentage");
  #endif
}

//A function that will write digitally to a given pin for the term '='
//This is however made specifically for an LED
void equalLED(int pin){
  digitalWrite(pin, HIGH);
  delay (readPot() * 2);
  digitalWrite(pin, LOW);
  #ifdef DEBUG
  Serial.println("Equals");
  #endif
}

//A function that will write digitally to a given pin for the term '@'
//This is however made specifically for an LED
void atLED(int pin){
  digitalWrite(pin, HIGH);
  delay (readPot() * 4);
  digitalWrite(pin, LOW);
  #ifdef DEBUG
  Serial.println("At '@'");
  #endif
}

//This function will write digitally to a pin given a specific string,
//This is done by reading the potentiometer for a minimum delay for time
//units 1, it then transmits this signal on the given pin.
void sendDigital(int pin, String message){
  digitalWrite(pin, LOW);
  for (int i = 0; i < message.length(); i++) {
    digitalWrite(pin, LOW);
    #ifdef DEBUG
    Serial.println(i);
    #endif
    if (message[i] == '='){
      equalLED(pin);
      delay(readPot() * 2);
    }
    else if (message[i] == '@'){
      atLED(pin);
      delay(readPot() * 4);
    }
    else if (message[i] == '%'){
      percentLED(pin);
      delay(readPot());
    }
    else if (message[i] == ' '){
      delay(readPot() * 6);
    }
    else if (message[i] == '|'){
      delay(readPot() * 3);
    }
    else {
      #ifdef DEBUG
      Serial.println("Error in the sendDigital function");
      #endif
    }
  }
  digitalWrite(pin, LOW);
}

//-------------------------------------------------------------------
//Functions for part 3:
//This function in particular is for LP and will light up the 4 LEDs that aren't the blue one.
//Using PWM to give it a brightness that is given in a string or char array input of 12 digits.
void LP(String m){
  #ifdef DEBUG
  Serial.println(m);
  #endif
  String string1 = m.substring(0, 2);
  String string2 = m.substring(3, 5);
  String string3 = m.substring(6, 8);
  String string4 = m.substring(9, 11);
  int pos1 = string1.toInt();
  int pos2 = string2.toInt();
  int pos3 = string3.toInt();
  int pos4 = string4.toInt();
  if(pos1 > 255){
    pos1 = 255;
  }
  else if(pos1 < 0){
    pos1 = 0;
  }
  else{
    //Do nothing
  }
  if(pos2 > 255){
    pos2 = 255;
  }
  else if(pos2 < 0){
    pos2 = 0;
  }
  else{
    //Do nothing
  }
  if(pos3 > 255){
    pos3 = 255;
  }
  else if(pos3 < 0){
    pos3 = 0;
  }
  else{
    //Do nothing
  }
  if(pos4 > 255){
    pos4 = 255;
  }
  else if(pos4 < 0){
    pos4 = 0;
  }
  else{
    //Do nothing
  }
  analogWrite(REDLED, pos1);
  analogWrite(ORANGELED, pos2);
  analogWrite(YELLOWLED, pos3);
  analogWrite(GREENLED, pos4);
}
//The fucntion will turn on the IR emmitter for 2000ms or 2 seconds at a frequency of 38,000Hz
//This function is for part 3 of the assignment.
void ir(){
  tone(IR_EMITTER, 38000);
  delay(2000);
  noTone(IR_EMITTER);
}

//The function RXIR puts into action what is requested in part 3 of the assignment.
//One thing to note is how the IR_RECIEVER is at state 1 or "HIGH" if there is no signal.
void RXIR(){
  int inputState = digitalRead(IR_RECIEVER);
  if (inputState == 0){
    Serial.println("LOW");
  }
  else if (inputState == 1){
    Serial.println("HIGH");
  }
}

//The function PV puts into action what is requested in part 3 of the assignment for part PV.
void PV(){
  String pot = String(analogRead(POT_PIN), DEC);
  if(pot.length() == 3){
    pot = "0" + pot;
  }
  else if(pot.length() == 2){
    pot = "00" + pot;
  }
  else if(pot.length() == 1){
    pot = "000" + pot;
  }
  else{
    //Do nothing
  }
  Serial.println(string2cam(pot));
}

//This function will determine if a string has one of the four functions
//for part 3 of the code and if it has them then run the functions relating
//to them.
void ifUse(char input[40]){
  input += '\0';
  String stringOfInput = "";
  for(int i = 0; i < 40; i++){
    stringOfInput.concat(input[i]);
  }
  int lpPos = stringOfInput.indexOf("LP");
  if(strstr(input, "LP") > 0){
    String stringOutput = "";
    for(int i = 0; i < 12; i++){
      stringOutput += input[(lpPos + (i + 2))];
    }   
    #ifdef DEBUG
    Serial.println(stringOfInput);
    Serial.println(lpPos);
    Serial.println("LP");
    Serial.println(stringOutput);
    #endif
    LP(stringOutput);
  }
  else if(strstr(input, "IR*") > 0){
    //Run function ir
    ir();
    #ifdef DEBUG
    Serial.println("IR");
    #endif
  }
  else if(strstr(input, "RXIR") > 0){
    //Run function RXIR
    RXIR();
    #ifdef DEBUG
    Serial.println("RXIR");
    #endif
  }
  else if(strstr(input, "PV") > 0){
    //Run function PV
    PV();
    #ifdef DEBUG
    Serial.println("PV");
    #endif
  }
  else{
    //Do nothing
    #ifdef DEBUG
    Serial.println("Did nothing");
    #endif
  }
}

//----------------------------------------------------------------------------------
//This is where the setup starts and the loop shortly after that.

void setup(){
  //Sets up the Serial port
  Serial.begin(9600);
  Serial.setTimeout(50);

  //Pinmode defintion for the various used for LEDs
  pinMode(GREENLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(ORANGELED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(REDLED, OUTPUT);

  //pinMode definitions for the non-LED input/output pins
  pinMode(POT_PIN, INPUT);
  pinMode(JACK, OUTPUT);
  pinMode(IR_EMITTER, OUTPUT);
  pinMode(IR_RECIEVER, INPUT);

  //This is where a large portion of the Debug code has been put to run on startup to make sure things work.
  #ifdef DEBUG
  //Testing the decoding
  //testing printCAM
  String testString = "cam code";
  Serial.println("The Print CAM output");
  printCAM(testString);

  //Testing string2cam
  testString = string2cam(testString);
  Serial.println("string2CAM printed");
  Serial.println(testString);

  //Testing the encoding
  //Check for the cam2char
  Serial.println("CAM to char test: ");
  char super = cam2char("@");
  Serial.println(super);

  //Check for print CAM String
  Serial.println("Print string from CAM test: ");
  char t[] = "=%|@=|%@=|%@%|% %=@|@=|%=|%";
  printCAMString(t);

  //Check for CAMString2String functionality
  Serial.println("Print string after translating into a stored string: ");
  Serial.println(CAMString2String(t));
  
  //Check for LP function functionality
  Serial.println("The LP function working with input digits 000100150255");
  LP("000100150255");

  //Checking to see if PV()
  Serial.println("The PV function test:");
  PV();

  //Checking to see if RXIR() works
  Serial.println("The RXIR function test:");
  RXIR();

  //Checking to see if the IR() works
  Serial.println("The IR function test:");
  ir();

  Serial.println("The potentiometer reads:");
  Serial.println(readPot());
  #endif
}

void loop() {
  //Main code
  //Debug code so that I know when the code is waiting for a prompt in the serial monitor.
  #ifdef DEBUG
  Serial.println();
  Serial.println("Please enter the text to be translated to CAM and/or processed");
  #endif

  //This is the peice of code that most of the assignment is based of where it all comes together and make sure that it works.
  String ip = promptReadIn();
  //If the first charecter is CAM:
  if ((ip[0] == '=' || ip[0] == '%' || ip[0] == '@') || checkIf(ip)){
    camIp = ip;
    textIp = CAMString2String(ip);
    #ifdef DEBUG
    Serial.println(camIp);
    #endif
    Serial.println(textIp);
    sendDigital(BLUELED, camIp);
    char textIpchar[50];
    for (int i = 0; i < (textIp.length()); i++){
      textIpchar[i] = textIp[i];
    }
    #ifdef DEBUG
    Serial.println(textIp);
    Serial.println(textIpchar);
    Serial.println("---");
    #endif
    //This function will use part 3, (and will only execute if the recieved message is in CAM):
    ifUse(textIpchar);
  }
  //If the first charecter is not CAM:
  else {
    textIp = ip;
    camIp = string2cam(ip);
    Serial.println(camIp);
    sendDigital(REDLED, camIp);
  }
  //Some debug code to show the textIp and camIp variables everytime the code successfully loops.
  #ifdef DEBUG
  Serial.println(textIp);
  Serial.println(camIp);
  Serial.println();
  #endif
}
