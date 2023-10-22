#include<Keypad.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);
const int  ROWS = 4;
const int COLS = 4;
int row = 0;
int col = 0;
char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //定義列的腳位
byte colPins[COLS] = {7, 6, 5, 4}; //定義行的腳位

//初始化鍵盤
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Serial.println("KeyPad Test...");
  lcd.begin(16,2);
  // put your setup code here, to run once:
  lcd.setBacklight(255);
  lcd.clear();
  lcd.setCursor(col, row);
}

void loop() {
  char key = customKeypad.getKey();
  //判斷按了哪一個鍵
  if(key){
    Serial.println(key);
    lcd.print(key);
    if(col < 16){
      col++;
    }
    else{
      col = 0;
      if(row > 0){
        row = 0;
        lcd.clear();
      }
      else{
        row = 1;
      }
    }
    lcd.setCursor(col, row);
    
    delay(100);
    //lcd.clear();
  }

  delay(10);
}
                                                                                                                                 