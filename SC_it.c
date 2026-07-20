/**
 *****************************************************************************************************
  * @copyright	(c)  Shenzhen Saiyuan Microelectronics Co., Ltd
  * @file	         SC_it.c
  * @author
  * @version
  * @date
  * @brief
  * @details         Interrupt Service Routine
 *****************************************************************************************************
 * @attention
 *
 *****************************************************************************************************
 */

#include "SC_it.h"
#include "sc32_conf.h"
#include "HeadFiles\SC_itExtern.h"
#include "SCDriver_List.h"

uint8_t send_buff[4] = {1,2,3,4};
uint8_t rxd_buff[4];//接收固定包长度为4的数据包缓冲区
uint8_t rxd_flag = 0;//接收完成标志
uint8_t rxd_indx = 0;//接收字节索引

uint32_t timebase_cnt = 0;

void send_byte(uint8_t byte)
{
	UART_SendData(UART0,byte);
	//等待发送完毕
	while(UART_GetFlagStatus(UART0,UART_Flag_TX) == RESET);
	UART_ClearFlag(UART0, UART_Flag_TX);
}
void send_string(uint8_t *str)
{
	while(*str!='\0')
	{
		send_byte(*str++);
	}
}
void send_buf(uint8_t *buf,uint16_t len)
{
	uint16_t i;
	for(i = 0;i<len;i++)
	{
		send_byte(buf[i]);
	}
}

int fputc(int ch,FILE *f)
{
	send_byte(ch);
	return ch;
}
uint8_t get_recv_flag(void)
{
	if(rxd_flag == 1)
	{
		rxd_flag = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}
//进行处理
void send_pack(void)
{
	//帧头
	send_byte(0xFE);
	
	send_buf(rxd_buff,4);
	//帧尾
	send_byte(0xEF);
}



void INT0_IRQHandler(void)
{


}

void INT1_7_IRQHandler(void)
{


}

void INT8_11_IRQHandler(void)
{


}

void INT12_15_IRQHandler(void)
{


}

void RCC_IRQHandler(void)
{


}


void UART1_IRQHandler(void)
{


}

#if !defined (TK_USE_UART1_3)
void UART1_3_IRQHandler(void)
{


}
#endif

#if !defined (TK_USE_UART1_3_5)
void UART1_3_5_IRQHandler(void)
{


}
#endif

#if !defined (TK_USE_UART0_2)
void UART0_2_IRQHandler(void)
{
	uint8_t recv_dat;
	static uint8_t recv_state = 0;//状态标志 只初始化一次
	if(UART_GetFlagStatus(UART0,UART_Flag_RX)!=RESET)
	{
		recv_dat = UART_ReceiveData(UART0);
		switch(recv_state)
		{
			case 0:
					//判断包头
					if(recv_dat == 0x01)
					{
						//改变状态
						recv_state =1;
						rxd_indx = 0;
					}
					else
					{
						//没收到包头 一直等待包头
						recv_state = 0;
					}
				break;
			case 1:
					rxd_buff[rxd_indx] = recv_dat;
					rxd_indx++;
					if(rxd_indx >=4)
					{
						//切换状态
						recv_state = 2;
					}
				break;
			case 2:
					if(recv_dat == 0xEF)
					{
						//接受完了
						rxd_flag = 1;
						recv_state = 0;
					}
				break;
		}
		UART_ClearFlag(UART0,UART_Flag_RX);
	}
	
}
#endif

#if !defined (TK_USE_UART0_2_4)
void UART0_2_4_IRQHandler(void)
{


}
#endif


#if !defined (TK_USE_BTM)
void BTM_IRQHandler(void)
{


}
#endif

void DMA0_IRQHandler(void)
{


}

void DMA1_IRQHandler(void)
{


}


void DMA2_IRQHandler(void)
{


}

void DMA3_IRQHandler(void)
{


}


void TIMER0_IRQHandler(void)
{


}

void TIMER1_IRQHandler(void)
{


}

void TIMER2_IRQHandler(void)
{


}

void TIMER3_IRQHandler(void)
{


}


void TIMER4_5_IRQHandler(void)
{


}

void TIMER6_7_IRQHandler(void)
{


}



void QEP0_IRQHandler(void)
{


}

void QEP1_IRQHandler(void)
{


}

void OP1_OP2_IRQHandler(void)
{


}

void SPI1_TWI1_IRQHandler(void)
{


}

void CAN_IRQHandler(void)
{


}

void EPWM_IRQHandler(void)
{


}

void PCAP_IRQHandler(void)
{


}


void TWI0_IRQHandler(void)
{


}

void TWI1_IRQHandler(void)
{


}

void PWM0_IRQHandler(void)
{


}

void LEDPWM_IRQHandler(void)
{


}

void ADC_IRQHandler(void)
{


}

void CMP0_1_2_IRQHandler(void)
{


}

void CMP3_IRQHandler(void)
{


}

void CMP_IRQHandler(void)
{


}


void SysTick_IRQHandler(void)
{
	SC_IncTick();

}

void SPI0_IRQHandler(void)
{


}

void SPI1_IRQHandler(void)
{


}

void SPI1_2_IRQHandler(void)
{


}

void TWIx_QSPIx_0_2_IRQHandler(void)
{


}

void TWIx_QSPIx_1_3_IRQHandler(void)
{


}
