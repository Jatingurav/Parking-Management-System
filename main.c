/*
 * Parking_system.c
 *
 * Created: 08-05-2024 12:30:53
 * Author : ADMIN
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATA PORTA
#define ctrl PORTB
#define rs PB0
#define rw PB1
#define en PB2

void init_LCD(void);
void LCD_cmd(unsigned char cmd);
void LCD_write(unsigned char data);
void LCD_write_string(char *str);


int main(void)
{
    DDRA = 0xFF;
	DDRB = 0xFF;
	//DDRB = DDRB | (1<<0) | (1<<1) | (1<<2);  /* LCD Control Pins*/
	
	//DDRB = DDRB | (1<<4) | (1<<5) |(1<<6) | (1<<7) ;
	
	DDRC = DDRC & (~(1<<0)) & (~(1<<1)) & (~(1<<2)) & (~(1<<3));
	/* Make  PC0 PC1 PC2 PC3 as input pin for SLOT 1 & 2 */
	PORTC = PORTC & (~(1<<0)) & (~(1<<1)) & (~(1<<2)) & (~(1<<3));
	/* Enable PC0 PC1 PC2 PC3 by writing 0 to it */
	
	DDRD = DDRD & (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7));
	/* Make PD4 PD5 PD6 PD7 as input pin for SLOT 3 & 4 */
	PORTD = PORTD & (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7));
	/* Enable PD4 PD5 PD6 PD7 PD8 by writing 0 to it */
	
	
	DDRC = DDRC | (1<<4) | (1<<5) | (1<<6) | (1<<7) ;
	/* Make  PC4 PC5 PC6 PC7 as output pin*/
	PORTC = PORTC & (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7));
	/* Initially Parking is empty so Led's are OFF */
	
	init_LCD();
	_delay_ms(2);
	LCD_write_string("WELCOME!");
	LCD_cmd(0xC0);
	LCD_write_string("PARKING SYSTEM");
	_delay_ms(1000);
	
    while (1) 
    {
		if (PINC & (1<<0))
		{
			while (PINC & (1<<0))
			{

				PORTB &= (~(1<<4)); 
				PORTB |= (1<<5);
				PORTB &= (~(1<<6));
				PORTB |= (1<<7); /*Car Starts in Forward Direction*/
				_delay_ms(3000);
				PORTB &= (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7)); /*Car Stops*/
				_delay_ms(500);
				PORTC = PORTC | (1<<4);
				_delay_ms(500);
				
				in_out_func();		
			}

		}
		
		
		else if (PINC & (1<<1))
		{
			while (PINC & (1<<1))
			{
				PORTB |= (1<<4);
				PORTB &= (~(1<<5));
				PORTB |= (1<<6);
				PORTB &= (~(1<<7)); /*Car Starts in Reverse Direction*/
				_delay_ms(3000);
				PORTB &= (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7)); /*Car Stops*/
				_delay_ms(500);
				PORTC = PORTC & (~(1<<4));
				_delay_ms(500);
				
				in_out_func();	

			}
		}
		
		else if (PINC & (1<<2))
		{
			while (PINC & (1<<2))
			{
				PORTB &= (~(1<<4));
				PORTB |= (1<<5);
				PORTB &= (~(1<<6));
				PORTB |= (1<<7); /*Car Starts in Forward Direction*/
				
				_delay_ms(3000);
				PORTB &= (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7)); /*Car Stops*/
				_delay_ms(500);
				PORTC = PORTC | (1<<5);
				_delay_ms(500);
				
				in_out_func();		
			}
		}
		
		else if (PINC & (1<<3))
		{
			while (PINC & (1<<3))
			{
				PORTB |= (1<<4);
				PORTB &= (~(1<<5));
				PORTB |= (1<<6);
				PORTB &= (~(1<<7)); /*Car Starts in Reverse Direction*/
				_delay_ms(3000);
				PORTB &= (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7)); /*Car Stops*/
				_delay_ms(500);
				PORTC = PORTC & (~(1<<5));
				_delay_ms(500);
				
				in_out_func();	
				
			}
		}
		
		else if (PIND & (1<<4))
		{
			while (PIND & (1<<4))
			{
				PORTB &= (~(1<<4));
				PORTB |= (1<<5);
				PORTB &= (~(1<<6));
				PORTB |= (1<<7); /*Car Starts in Forward Direction*/
				
				_delay_ms(3000);
				PORTB &= (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7)); /*Car Stops*/
				_delay_ms(500);
				PORTC = PORTC | (1<<6) ;
				_delay_ms(500);
				
				in_out_func();	
			}
		}
		
		else if (PIND & (1<<5))
		{
			while (PIND & (1<<5))
			{
				PORTB |= (1<<4);
				PORTB &= (~(1<<5));
				PORTB |= (1<<6);
				PORTB &= (~(1<<7)); /*Car Starts in Reverse Direction*/
				
				_delay_ms(3000);
				PORTB &= (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7)); /*Car Stops*/
				_delay_ms(500);
				PORTC = PORTC & (~(1<<6));
				_delay_ms(500);
				
				in_out_func();	
			}
		}
		
		else if (PIND & (1<<6))
		{
			while (PIND & (1<<6))
			{
				PORTB &= (~(1<<4));
				PORTB |= (1<<5);
				PORTB &= (~(1<<6));
				PORTB |= (1<<7); /*Car Starts in Forward Direction*/
				
				_delay_ms(3000);
				PORTB &= (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7)); /*Car Stops*/
				_delay_ms(500);
				PORTC = PORTC | (1<<7);
				_delay_ms(500);
				
				in_out_func();	
			}
			
			
		}
		
		
		else if (PIND & (1<<7))
		{
			while (PIND & (1<<7))
			{
				PORTB |= (1<<4);
				PORTB &= (~(1<<5));
				PORTB |= (1<<6);
				PORTB &= (~(1<<7)); /*Car Starts in Reverse Direction*/
				
				_delay_ms(3000);
				PORTB &= (~(1<<4)) & (~(1<<5)) & (~(1<<6)) & (~(1<<7)); /*Car Stops*/
				_delay_ms(500);
				PORTC = PORTC & (~(1<<7));
				_delay_ms(500);
				
				in_out_func();	
			}
		}
		

    }	
}

void in_out_func()
{

	if (PORTC == 0b00010000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("2 3 4 ");
	}
	
	else if (PORTC == 0b00110000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("3 4 ");
	}
	
	else if (PORTC == 0b01110000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("4 ");
	}
	
	else if (PORTC == 0b11110000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("NONE");
	}
	else if (PORTC == 0b00100000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("1 3 4 ");
	}
	
	else if (PORTC == 0b01100000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("1 4 ");
		
	}
	
	else if (PORTC == 0b11100000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("1 ");
	}
	
	else if (PORTC == 0b01000000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("1 2 4 ");
	}
	
	else if (PORTC == 0b11000000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("1 2 ");
	}
	else if (PORTC == 0b11010000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("2 ");
	}
	else if (PORTC == 0b01010000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("2 4 ");
	}
	else if (PORTC == 0b10100000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("1 3 ");
	}
	else if (PORTC == 0b10010000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("2 3 ");
	}
	else if (PORTC == 0b10000000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("1 2 3 ");
	}
	else if (PORTC == 0b10110000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("3 ");
	}
	
	else if (PORTC == 0b00000000)
	{
		init_LCD();
		LCD_cmd(0x0C);
		_delay_ms(1);
		LCD_write_string("AVAILABLE SLOTS :");
		LCD_cmd(0xC0);
		_delay_ms(1);
		LCD_write_string("1 2 3 4 ");
	}
	
}
void init_LCD(void)
{
	LCD_cmd(0x38);
	_delay_ms(1);
	LCD_cmd(0x01);
	_delay_ms(1);
	LCD_cmd(0x0C);
	_delay_ms(1);
	LCD_cmd(0x80);
	_delay_ms(1);
	
	return;
}

void LCD_cmd(unsigned char cmd)
{
	LCD_DATA=cmd;
	ctrl= (0<<rs)|(0<<rw)|(1<<en);
	_delay_ms(1);
	ctrl= (0<<rs)|(0<<rw)|(0<<en);
	_delay_ms(1);
	
	return;
}

void LCD_write(unsigned char data)
{
	LCD_DATA=data;
	ctrl= (1<<rs)|(0<<rw)|(1<<en);
	_delay_ms(1);
	ctrl= (1<<rs)|(0<<rw)|(0<<en);
	_delay_ms(1);
	
	return;
	
}

void LCD_write_string(char *str)
{
	int i=0;
	while(str[i]!='\0')
	{
		LCD_write(str[i]);
		i++;
	}
	return;
}

