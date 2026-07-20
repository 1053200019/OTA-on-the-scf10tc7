/**
 *****************************************************************************************************
  * @copyright	(c)  Shenzhen Saiyuan Microelectronics Co., Ltd
  * @file	         main.c
  * @author	 
  * @version 	
  * @date	
  * @brief	         
  * @details         Contains the MCU initialization function and its H file
 *****************************************************************************************************
 * @attention
 *
 *****************************************************************************************************
 */
/*******************Includes************************************************************************/

#include "SC_Init.h"
#include "SC_it.h"
#include "..\Drivers\SCDriver_List.h"
#include "HeadFiles\SysFunVarDefine.h"




/**
  * @brief This function implements main function.
  * @note 
  * @param
  */
int main(void)
{
    
    
    IcResourceInit();
    
    
    /*****MainLoop*****/
    while(1)
    {
			
	
        //SC_Delay(2000);
				//send_pack();
        /***User program***/
			if(get_recv_flag()==1)
			{
				send_pack();
			}
        
        
    }
    
    
}
