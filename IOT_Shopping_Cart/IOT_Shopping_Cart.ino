#include <ESP8266WiFi.h>
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid     = "tarun";
const char* password = "21071999";

WiFiServer server(80);

String header; 

String Item1 = "39008F9195B2";
String Item2 = "3900906C73B6";
String Item3 = "39008F9199BE";
String Item4 = "39008F93D2F7";
String Item5 = "39008F93CDE8";
String Item6 = "3900906B6FAD";
String Item7 = "39008F919EB9";
String Item8 = "39008F8B6A57";

int Switch1 = D5;
int Switch2 = D6;
int Switch3 = D7;
int Switch4 = D8;

int Q_item1 = 0;
int Q_item2 = 0;
int Q_item3 = 0;
int Q_item4 = 0;
int Q_item5 = 0;
int Q_item6 = 0;
int Q_item7 = 0;
int Q_item8 = 0;

int C_item1 = 60;   // Change The Price
int C_item2 = 80;   // Change The Price
int C_item3 = 120;  // Change The Price
int C_item4 = 40;   // Change The Price
int C_item5 = 10;   // Change The Price
int C_item6 = 23;   // Change The Price
int C_item7 = 109;  // Change The Price
int C_item8 = 201;  // Change The Price

int TC_item1 = 60;   // Change The Price Same As C_item
int TC_item2 = 80;   // Change The Price Same As C_item
int TC_item3 = 120;  // Change The Price Same As C_item
int TC_item4 = 40;   // Change The Price Same As C_item
int TC_item5 = 10;   // Change The Price Same As C_item
int TC_item6 = 23;   // Change The Price Same As C_item
int TC_item7 = 109;  // Change The Price Same As C_item
int TC_item8 = 201;  // Change The Price Same As C_item

int Total_Cost = 0;

String N_item1 = "Item 1 "; // Change The Name " Parle G "
String N_item2 = "Item 2 "; // Change The Name " Parle G "
String N_item3 = "Item 3 "; // Change The Name " Parle G "
String N_item4 = "Item 4 "; // Change The Name " Parle G "
String N_item5 = "Item 5 "; // Change The Name " Parle G "
String N_item6 = "Item 6 "; // Change The Name " Parle G "
String N_item7 = "Item 7 "; // Change The Name " Parle G "
String N_item8 = "Item 8 "; // Change The Name " Parle G "

int P;
int A;
int S;

long TIME;

void setup() {
  Serial.begin(9600);

  Wire.begin();
  lcd.begin();
  lcd.backlight();
  
  lcd.setCursor(0,0); lcd.print("  IOT SHOPPING  ");  
  lcd.setCursor(0,1); lcd.print("      CART      ");
  delay(1000);

  pinMode(Switch1, INPUT_PULLUP);
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  lcd.clear();
  
  lcd.setCursor(0,0); lcd.print("   IP ADDRESS   ");  
  lcd.setCursor(0,1); lcd.print(" "); lcd.print(WiFi.localIP());
  delay(3000);
  lcd.clear();
  
  server.begin();
}

void loop(){
  if (digitalRead(Switch1) == LOW ) { A = !A; delay(100);}
  
  TC_item1 = C_item1 * Q_item1;
  TC_item2 = C_item2 * Q_item2;
  TC_item3 = C_item3 * Q_item3;
  TC_item4 = C_item4 * Q_item4;
  TC_item5 = C_item5 * Q_item5;
  TC_item6 = C_item6 * Q_item6;
  TC_item7 = C_item7 * Q_item7;
  TC_item8 = C_item8 * Q_item8;

  Total_Cost = TC_item1+TC_item2+TC_item3+TC_item4+TC_item5+TC_item6+TC_item7+TC_item8;
    
  lcd.setCursor(0,0); lcd.print("SCAN CARD  "); if (A == 0 ) {lcd.print("ADD");} else {lcd.print("REM");}
  lcd.setCursor(0,1); lcd.print("TOTAL = "); lcd.print(Total_Cost); lcd.print("  ");

  delay(1000);
  
  if(Serial.available()){
    String S = Serial.readString();
    Serial.println(S);
    if ( A == 0 ){
      if ( S == Item1 ) { Q_item1 = Q_item1 + 1; lcd.setCursor(0,0); lcd.print("ITEM1 ADDED     "); }
      if ( S == Item2 ) { Q_item2 = Q_item2 + 1; lcd.setCursor(0,0); lcd.print("ITEM2 ADDED     "); }
      if ( S == Item3 ) { Q_item3 = Q_item3 + 1; lcd.setCursor(0,0); lcd.print("ITEM3 ADDED     "); }
      if ( S == Item4 ) { Q_item4 = Q_item4 + 1; lcd.setCursor(0,0); lcd.print("ITEM4 ADDED     "); }
      if ( S == Item5 ) { Q_item5 = Q_item5 + 1; lcd.setCursor(0,0); lcd.print("ITEM5 ADDED     "); }
      if ( S == Item6 ) { Q_item6 = Q_item6 + 1; lcd.setCursor(0,0); lcd.print("ITEM6 ADDED     "); }
      if ( S == Item7 ) { Q_item7 = Q_item7 + 1; lcd.setCursor(0,0); lcd.print("ITEM7 ADDED     "); }
      if ( S == Item8 ) { Q_item8 = Q_item8 + 1; lcd.setCursor(0,0); lcd.print("ITEM8 ADDED     "); }
    }

    if ( A == 1 ){
      if ( S == Item1 && Q_item1 > 0 ) { Q_item1 = Q_item1-1; lcd.setCursor(0,0); lcd.print("ITEM1 REMOVE    "); }
      if ( S == Item2 && Q_item2 > 0 ) { Q_item2 = Q_item2-1; lcd.setCursor(0,0); lcd.print("ITEM2 REMOVE    "); }
      if ( S == Item3 && Q_item3 > 0 ) { Q_item3 = Q_item3-1; lcd.setCursor(0,0); lcd.print("ITEM3 REMOVE    "); }
      if ( S == Item4 && Q_item4 > 0 ) { Q_item4 = Q_item4-1; lcd.setCursor(0,0); lcd.print("ITEM4 REMOVE    "); }
      if ( S == Item5 && Q_item5 > 0 ) { Q_item5 = Q_item5-1; lcd.setCursor(0,0); lcd.print("ITEM5 REMOVE    "); }
      if ( S == Item6 && Q_item6 > 0 ) { Q_item6 = Q_item6-1; lcd.setCursor(0,0); lcd.print("ITEM6 REMOVE    "); }
      if ( S == Item7 && Q_item7 > 0 ) { Q_item7 = Q_item7-1; lcd.setCursor(0,0); lcd.print("ITEM7 REMOVE    "); }
      if ( S == Item8 && Q_item8 > 0 ) { Q_item8 = Q_item8-1; lcd.setCursor(0,0); lcd.print("ITEM8 REMOVE    "); }
    }
    delay(1000);
  }
  
  Update_data();
  }

void Update_data(){
  WiFiClient client = server.available();   
  if (client) { 
    String currentLine = "";  
    TIME = millis();    
    while (client.connected()) {
      if ( millis() - TIME > 1000) { client.stop(); }
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c; 
if (c == '\n') {
  if (currentLine.length() == 0) {
    if ( header.indexOf("GET /Item1_ADD") >= 0 ) { Q_item1 = Q_item1 + 1; } else if ( header.indexOf("GET /Item1_REM") >= 0 ) { Q_item1 = Q_item1 - 1; }
    if ( header.indexOf("GET /Item2_ADD") >= 0 ) { Q_item2 = Q_item2 + 1; } else if ( header.indexOf("GET /Item2_REM") >= 0 ) { Q_item2 = Q_item2 - 1; }
    if ( header.indexOf("GET /Item3_ADD") >= 0 ) { Q_item3 = Q_item3 + 1; } else if ( header.indexOf("GET /Item3_REM") >= 0 ) { Q_item3 = Q_item3 - 1; }
    if ( header.indexOf("GET /Item4_ADD") >= 0 ) { Q_item4 = Q_item4 + 1; } else if ( header.indexOf("GET /Item4_REM") >= 0 ) { Q_item4 = Q_item4 - 1; }
    if ( header.indexOf("GET /Item5_ADD") >= 0 ) { Q_item5 = Q_item5 + 1; } else if ( header.indexOf("GET /Item5_REM") >= 0 ) { Q_item5 = Q_item5 - 1; }
    if ( header.indexOf("GET /Item6_ADD") >= 0 ) { Q_item6 = Q_item6 + 1; } else if ( header.indexOf("GET /Item6_REM") >= 0 ) { Q_item6 = Q_item6 - 1; }
    if ( header.indexOf("GET /Item7_ADD") >= 0 ) { Q_item7 = Q_item7 + 1; } else if ( header.indexOf("GET /Item7_REM") >= 0 ) { Q_item7 = Q_item7 - 1; }
    if ( header.indexOf("GET /Item8_ADD") >= 0 ) { Q_item8 = Q_item8 + 1; } else if ( header.indexOf("GET /Item8_REM") >= 0 ) { Q_item8 = Q_item8 - 1; }

    //header = "";
    
    TC_item1 = C_item1 * Q_item1;
    TC_item2 = C_item2 * Q_item2;
    TC_item3 = C_item3 * Q_item3;
    TC_item4 = C_item4 * Q_item4;
    TC_item5 = C_item5 * Q_item5;
    TC_item6 = C_item6 * Q_item6;
    TC_item7 = C_item7 * Q_item7;
    TC_item8 = C_item8 * Q_item8;

    Total_Cost = TC_item1+TC_item2+TC_item3+TC_item4+TC_item5+TC_item6+TC_item7+TC_item8;
            
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println("Connection: close");
    client.println();
       
    client.println("<!DOCTYPE html><html>");
    client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    client.println("<link rel=\"icon\" href=\"data:,\">");
            
    client.println("<style> table, th, td {border: 1px solid black;} html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");            
    client.println("</style> </head>");
    client.println("<body><h1>IOT BASED SMART SHOPPING SYSTEM</h1>");
      
    client.println("<table class=\"center\">");

    client.println("<tr><th><h2>S. No.</h2></th><th><h2>Product</h2></th><th><h2>Qty.</h2><th><h2>Cost</h2> <th><h2>Total</h2> </th><th><h2>Add</h2></th><th><h2>Remove</h2></th></tr>");

  P = 1;
  for ( int i =1; i < 9; i++){
    String item;
    String SvalA;
    String SvalR;
    
    int Qty;
    int Cost;
    int TCost;
  
    if ( i == 1 ) { item = "Item1"; SvalA = "Item1_ADD\n"; SvalR = "Item1_REM\n"; Qty = Q_item1; Cost = C_item1; TCost = TC_item1;}
    if ( i == 2 ) { item = "Item2"; SvalA = "Item2_ADD\n"; SvalR = "Item2_REM\n"; Qty = Q_item2; Cost = C_item2; TCost = TC_item2;}
    if ( i == 3 ) { item = "Item3"; SvalA = "Item3_ADD\n"; SvalR = "Item3_REM\n"; Qty = Q_item3; Cost = C_item3; TCost = TC_item3;}
    if ( i == 4 ) { item = "Item4"; SvalA = "Item4_ADD\n"; SvalR = "Item4_REM\n"; Qty = Q_item4; Cost = C_item4; TCost = TC_item4;}
    if ( i == 5 ) { item = "Item5"; SvalA = "Item5_ADD\n"; SvalR = "Item5_REM\n"; Qty = Q_item5; Cost = C_item5; TCost = TC_item5;}
    if ( i == 6 ) { item = "Item6"; SvalA = "Item6_ADD\n"; SvalR = "Item6_REM\n"; Qty = Q_item6; Cost = C_item6; TCost = TC_item6;}
    if ( i == 7 ) { item = "Item7"; SvalA = "Item7_ADD\n"; SvalR = "Item7_REM\n"; Qty = Q_item7; Cost = C_item7; TCost = TC_item7;}
    if ( i == 8 ) { item = "Item8"; SvalA = "Item8_ADD\n"; SvalR = "Item8_REM\n"; Qty = Q_item8; Cost = C_item8; TCost = TC_item8;}
  
    if (Qty>0) {
      client.println("<tr><th>" + String(P) + "</th><th>" + item + "</th><th>"+ String(Qty) +"<th>"+ String(Cost)+"<th>"+ String(TCost)+"</th><th><a href="+ SvalA +"> Add </a>  </th><th><a href="+ SvalR +"> Remove </a>  </th></tr>"); P = P +1;
    }
  }
      client.println("<tr><th> </th><th> Total </th><th> <th> <th>"+ String(Total_Cost)+"</th><th></th><th></th></tr>");
      client.println("</table>"); 
      
      client.println("<th> <a href= Pay_Now > <h3>PAY NOW</h3> </a> </th>");
      client.println("</body></html>");
           
      client.println();
      break;
    } 
          
     else {  currentLine = ""; }
    }
          
     else if (c != '\r') { currentLine += c; }
    }
  }

    header = "";

    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
