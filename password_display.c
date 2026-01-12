#include<reg51.h>
#define LCD P1

sbit rs = P2^7;
sbit e = P2^6;

sbit R1 = P3^0;
sbit R2 = P3^1;
sbit R3 = P3^2;
sbit R4 = P3^3;

sbit C1 = P3^4;
sbit C2 = P3^5;
sbit C3 = P3^6;

 

void delay(unsigned int d)
{
	int i,j;
	for(i=0;i<d;i++)
	{
		for(j=0;j<1000;j++);
	
	}
}
void cmd(unsigned char c)
{
	LCD = c;
	rs =0;
	e = 1;
	delay(5);
	e=0;
}
void display(unsigned char c)
{
	LCD = c;
	rs =1;
	e =1;
	delay(5);
	e = 0;
}

void inti()
{
	cmd(0x38);
	cmd(0x0c);
	cmd(0x01);
	delay(20);
	
	cmd(0x80);
}
void lcd_string(char *p)
{
	while(*p)
	{
		display(*p++);
	}
}
char keypad()
{
	R1=0; R2=R3=R4=1;
  if(C1==0)
	{
		while(C1==0);
		delay(20);
	return '1';
	}
  if(C2==0){while(C2==0);delay(20);return '2';}
	if(C3==0){while(C3==0);delay(20);return '3';}
 
 
		R2=0; R1=R3=R4=1;
  if(C1==0){while(C1==0);delay(20);return '4';}
  if(C2==0){while(C2==0);delay(20);return '5';}
	if(C3==0){while(C3==0);delay(20);return '6';}
  
	
	R3=0; R1=R2=R4=1;
  if(C1==0){while(C1==0);delay(20);return '7';}
  if(C2==0){while(C2==0);delay(20);return '8';}
	if(C3==0){while(C3==0);delay(20);return '9';}

	
	R4=0; R1=R3=R2=1;
  if(C1==0){while(C1==0);delay(20);return '*';}
  if(C2==0){while(C2==0);delay(20);return '0';}
	if(C3==0){while(C3==0);delay(20);return '#';}
 
	
	return 0;
}
	
int main()
{
	char key;
	char password[4]={'1','2','3','4'};
    char input[4];
    int i;

    inti();
    lcd_string("ENTER PASSWORD");
    cmd(0xC0);

    for(i=0;i<4;i++)
    {
        while((key = keypad()) == 0);
        input[i] = key;
        display('*');
    }

    delay(500);
    cmd(0x01);

    if(input[0]==password[0] &&
       input[1]==password[1] &&
       input[2]==password[2] &&
       input[3]==password[3])
    {
        lcd_string("ACCESS GRANTED");
    }
    else
    {
        lcd_string("ACCESS DENIED");
    }

    while(1);

}