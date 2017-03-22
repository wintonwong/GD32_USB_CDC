#include "shell.h"
#include "gd32f10x_gpio.h"
#include	"gd32f10x_can.h"
#include <stdint.h>
#include <string.h>

//uint8_t halfbyte_to_hexascii(uint8_t _halfbyte)
//{
//_halfbyte &= 0x0F;
//if(_halfbyte >= 10) return('A' + _halfbyte - 10); 
//else return('0' + _halfbyte); 
//}

//uint8_t hexascii_to_halfbyte(uint8_t _ascii)
//{
//if((_ascii >= '0') && (_ascii <= '9')) return(_ascii - '0'); 
//if((_ascii >= 'a') && (_ascii <= 'f')) return(_ascii - 'a'); 
//if((_ascii >= 'A') && (_ascii <= 'F')) return(_ascii - 'A'); 
//return(0xFF);
//}


	int TimingDelay;

	
	char 		sdstring[64]=" ";

//	extern	CanTxMessage TxMessage;
	extern	uint8_t		USB_DATA_Buffer[];
	uint16_t	test_USB_Rx_Cnt;
	
	uint8_t	cmd,arg4,arg3,arg2,arg1,crc;
	

	char 		strhex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int 		strtoint(char *str);
	int 		strtoargum(char *str);
	void 		initargv(void);
	int			putinbuffer(uint8_t	data);
	int			selectargv(char *str);	
	void		sdinit(void);
	void		USB_Send_Data(uint8_t data);
	void		usb_out(char *pString);
	void 		Delay(uint32_t nTime);
	void		printcan1(void);


//---------------------------------------------------------------------------------------------------
//������ ��������� ��������� Can 1
//
void	printcan1(void)
	{
			char	sdsh,sdsl;
			uint8_t	dshell;

					dshell	= RxMessage.FF;										//���������� IDE ����
					if (dshell == CAN_FF_STANDARD)							//���� ��������� �����������
					{	
						sprintf(sdstring,"\r\n");									//��������� ������
						
//						dshell	= (RxMessage.StdId	&	0x0f00)>>8;		//�������� ������� ���� ������������ ���������
//						sdsh=strhex[((dshell & 0xf0)>>4)];				//������� ������� ������
//						sdsl=strhex[(dshell & 0x0f)];							//������� ������� ������
//							if(sdsh==0){sdsh='0';}									//������� - ������� ���� ��� ������ 0 � ��������
//							if(sdsl==0){sdsl='0';}									//������� - ������� ���� ��� ������ 0 � ��������
//								USB_Send_Data(sdsh);									//�������� � usb-comm
//								USB_Send_Data(sdsl);									//�������� � usb-comm
//								USB_Send_Data(' ');										//���������� ������

//						dshell	= RxMessage.StdId	&	0xff;						//�������� ������� ���� ������������ ���������
//						sdsh=strhex[((dshell & 0xf0)>>4)];				//������� ������� ������
//						sdsl=strhex[(dshell & 0x0f)];							//������� ������� ������
//							if(sdsh==0){sdsh='0';}									//������� - ������� ���� ��� ������ 0 � ��������
//							if(sdsl==0){sdsl='0';}									//������� - ������� ���� ��� ������ 0 � ��������
//								USB_Send_Data(sdsh);									//�������� � usb-comm
//								USB_Send_Data(sdsl);									//�������� � usb-comm
//								USB_Send_Data(' ');										//���������� ������
							
						dshell = RxMessage.Data[0];
						sdsh= strhex[dshell];
							USB_Send_Data(sdsh);
							USB_Send_Data(' ');
						dshell = RxMessage.Data[1];
						sdsh= strhex[dshell];
							USB_Send_Data(sdsh);
							USB_Send_Data(' ');	
						dshell = RxMessage.Data[2];
						sdsh= strhex[dshell];
							USB_Send_Data(sdsh);
							USB_Send_Data(' ');
						dshell = RxMessage.Data[3];
						sdsh= strhex[dshell];
							USB_Send_Data(sdsh);
							USB_Send_Data(' ');		
						dshell = RxMessage.Data[4];
						sdsh= strhex[dshell];
							USB_Send_Data(sdsh);
							USB_Send_Data(' ');
						dshell = RxMessage.Data[5];
						sdsh= strhex[dshell];
							USB_Send_Data(sdsh);
							USB_Send_Data(' ');	
						dshell = RxMessage.Data[6];
						sdsh= strhex[dshell];
							USB_Send_Data(sdsh);
							USB_Send_Data(' ');	
						dshell = RxMessage.Data[7];
						sdsh= strhex[dshell];
							USB_Send_Data(sdsh);
							USB_Send_Data(' ');	
					}
	
	}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
void Delay(uint32_t nTime)
{
  TimingDelay = nTime;
  while(TimingDelay != 0); 
}
//---------------------------------------------------------------------------------------------------


