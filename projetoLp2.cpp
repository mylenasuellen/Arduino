/* Sala de Aula Inteligente 

    Funções:

    //>> Reconhecimento de usuário por RFID;
    >> Display de notificações por LCD (Liquid Crystal);
    >> Se ativado, abrir porta, ligar ar condicionado e projetor (LEDs); 
    
    Porta e Reconhecimento de usuário:

    >> Funcionamento da sala em horário delimitado;
    >> Enquanto estiver no horário, o led amarelo é aceso;
    >> Se o usuário NÃO estiver cadastrado, a sala não abre e o led vermelho é aceso;
    >> Se o usuário estiver cadastrado, a sala abre e o led verde é aceso;
    >> Reconhecimento de usuário por RFID e notificação no Display LED;


    Ar condicionado e projetor:
    >> Ao entrar na sala, emitir sinal IR para ar condicionado, com temperatura já pré definida;
    >> Ao entrar na sala, emitir sinal IR para projetor;
   */ 
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int blocked  = 6; //vermelho: a entrada esta bloqueada para este usuário
const int pronto = 7; //azul: em espera 
const int enter = 8; //verde : entrada liberada para o usuario
const int accessButton = 9; //botão
int buttonState = 0; 
int lastButtonState = 0;
//int buttonPushCounter = 0;
long tempo = 0;
long debounce = 250;
int estadoLed = 0;
void setup() {
  
  lcd.begin(16, 2);
  pinMode (blocked,OUTPUT);
  pinMode (pronto,OUTPUT);
  pinMode (enter,OUTPUT);
  pinMode (accessButton,INPUT);

}/*
void display(){
  if(r == LOW && e== HIGH){
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Entrada liberada");
    lcd.setCursor(0,1);
    lcd.print("Bem vindo!");
    delay(25);
  }
  if (r==LOW && e == HIGH){
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Saida Liberada");
    lcd.setCursor(0,1);
    lcd.print("Volte Sempre");
    delay(25);

  }

}

void acesso(){
  
  // lê a entrada do botão pressionado
  buttonState = digitalRead(accessButton);
  // compara o estado do botão com o estado anterior
  if (buttonState != lastButtonState) {
    // se o estado do botão mudar, incrementa o contador
    if (buttonState == HIGH) {
      // se o estado atual for HIGH, acende o LED
      buttonPushCounter += 1;
      
    }
    // delay para evitar um debouncing
    delay(5); 
  }
  // salva o estado atual como estado anterior, para o próximo loop
  lastButtonState = buttonState;
  /*liga o LED a cada dois cliques no botão,
  verificando o módulo do contador de cliques do botão.
  a função de módulo retorna o restante da divisão de dois números
  if (buttonPushCounter % 2 == 0) {
    delay(25);
    digitalWrite(pronto,LOW); //porta sai do standby
    digitalWrite(enter, HIGH); //entrada permitida 
    int r = digitalRead(pronto);
    int e = digitalRead(enter);
    /*display(r,e); 
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Entrada liberada");
    lcd.setCursor(0,1);
    lcd.print("Bem vindo!");
    delay(25); 
  } else {
    delay(25);
    digitalWrite(enter, LOW); //saída liberada
    digitalWrite(pronto,HIGH); //porta entra em standby
    int r = digitalRead(pronto);
    int e = digitalRead(enter);
    /*display(r,e); 
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Saida liberada");
    lcd.setCursor(0,1);
    lcd.print("Volte Sempre!");
    delay(25); 
  }
} */
void loop(){
  acesso();
}
void acesso(){

buttonState = digitalRead(accessButton);
if(buttonState == HIGH && lastButtonState == LOW && millis() - tempo > debounce) {
        		if(estadoLed == HIGH){
          		estadoLed = LOW; 
        		} else {
            	estadoLed = HIGH; 
        		}
    		tempo = millis();
      		}

      	digitalWrite(enter,estadoLed);
      	//display();
        lastButtonState == buttonState;
  

 }
