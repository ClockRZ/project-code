/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   Һ����ʾBMPͼƬ
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� ISO-MINI STM32 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
	*/
#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "bsp_ili9341_lcd.h"
#include "bsp_sdfs_app.h"
#include "bsp_bmp.h"
#include "bsp_SysTick.h"
#include "bsp_led.h"


#define BUKA_PIC_NUM 27
#define FILE_NAME_MAX_SIZE 32

int i=0;
static char buka_pic_file[FILE_NAME_MAX_SIZE];

/*
 * Ҫ��ͼƬ��ʾ�ɹ�
 * ����ֿ⿽����sd���ϣ�Ȼ���sd���嵽������Ŀ�����
 */
int main(void)
{
		LCD_Init();	
		LCD_Clear(0, 0, 240, 320, BACKGROUND);		
	
		LED_GPIO_Config();

		SysTick_Init();

		/* USART1 config */
		USART1_Config();  
		printf("\r\n this is a fatfs test demo \r\n");
		
	/* ��ʼ��sd���ļ�ϵͳ����Ϊ���ֵ��ֿ������sd������ */
		Sd_fs_init();	
	
		/* ����Lcd Gram ɨ�跽��Ϊ: ���Ͻ� -> ���½�*/
		Lcd_GramScan( 1 );
//		LCD_DispStr(5, 5, (uint8_t *)"fatfs init success", RED);
//		LCD_DispStr(5, 25, (uint8_t *)"insure the sdcard has insert......", RED);
//	  LCD_DispStrCH(50, 50, (uint8_t *)"Ұ�𿪷���", RED);
//	  LCD_DispEnCh(5, 90, "Welcome to use Ұ�� ISO Stm32 ������ bigo------", RED);
	
		LCD_DispStrCH(40, 5, (uint8_t *)"��ܰ��Ϣ�Ƽ����޹�˾", BLACK);  
		/* ��ʾBMPͼƬ */
//		Lcd_show_bmp(0, 0,"/wildfire.bmp");
//		Lcd_show_bmp( 10,10,"/pic1.bmp");		
//    Lcd_show_bmp( 170,0,"/pic2.bmp");
	
		Lcd_GramScan( 0 );
		while(1)
		{
			for(i=0; i<BUKA_PIC_NUM; i++)
			{
				sprintf(buka_pic_file, "/%d.bmp", i);
				user_lcd_show_bmp ( 60, 160, (uint8_t *)buka_pic_file);
				Delay_ms(1000/13);
			}
		}
}

	  
