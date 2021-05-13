#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int upButton = 10;
int downButton = 9;
int selectButton = 8;

int menu = 1;

int LED = 7;
void setup() {
  lcd.begin(16, 2);

  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  
  pinMode(LED, OUTPUT);

  updateMenu();
}

void loop() {
  if (!digitalRead(downButton)) {
    menu++;
    updateMenu();
    delay(100);
  }

  if (!digitalRead(upButton)) {
    menu--;
    updateMenu();
    delay(100);
    
  }

  if (!digitalRead(selectButton)) {
    execute();
    updateMenu();
    delay(100);
    
  }	
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">ENCENDER LED");
      lcd.setCursor(0, 1);
      lcd.print(" APAGAR LED");
      break;
    case 2:
      lcd.clear();
      lcd.print(" ENCENDER LED");
      lcd.setCursor(0, 1);
      lcd.print(">APAGAR LED");
      break;
    case 3:
      lcd.clear();
      lcd.print(">DESVANECER");
      lcd.setCursor(0, 1);
      lcd.print(" PARPADEO");
      break;
    case 4:
      lcd.clear();
      lcd.print(" DESVANECER");
      lcd.setCursor(0, 1);
      lcd.print(">PARPADEO");
      break;
    case 5:
      menu = 4;
      break;
  }
}


void execute() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
  }
}

void action1() {
  lcd.clear();
  lcd.print(">on");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  digitalWrite(LED, HIGH);
  
  delay(500);
}

void action2() {
  lcd.clear();
  lcd.print(">Off");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  digitalWrite(LED, LOW);
  
  delay(500);
}

void action3() {
  lcd.clear();
  lcd.print(">dispel");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  funcDesva(2);
  delay(1500);
  
}

void action4() {
  lcd.clear();
  lcd.print(">flicker");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  delay(150);
  lcd.print(".");
  intermitente();
  delay(1500);
}

void funcDesva(int temp){
  int periodo = temp;
  unsigned long tiempo1 = 0;
  unsigned long tiempo2 = 0;
  int brillo;
  for(brillo = 0; brillo <= 255; brillo++){
    analogWrite(LED,brillo);
    tiempo1 = millis();
    while (millis() < tiempo1 + periodo){
    }
  }
  for(brillo = 255; brillo >= 0; brillo-- ){
    analogWrite(LED,brillo);
    tiempo2 = millis();
    while (millis() < tiempo2 + periodo){
    }

  }
}
void intermitente(){ 
  digitalWrite(LED,HIGH);
  delay(300);
  digitalWrite(LED,LOW);
  delay(300);
  digitalWrite(LED,HIGH);
  delay(300);
  digitalWrite(LED,LOW);
  delay(300);
}
