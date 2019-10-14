#define  Clock_AHB1_en     (unsigned int*)         (0x40023830)
#define  Clock_APB2_en     (unsigned int*)         (0x40023844)    

#define  iopA_en           (unsigned int)          (1<<0)
#define  iopB_en           (unsigned int)          (1<<1)
#define  iopC_en           (unsigned int)          (1<<2)
#define  iopD_en           (unsigned int)          (1<<3)
#define  iopE_en           (unsigned int)          (1<<4)
#define  iopF_en           (unsigned int)          (1<<5)
#define  iopG_en           (unsigned int)          (1<<6)
#define  iopH_en           (unsigned int)          (1<<7)
#define  iopI_en           (unsigned int)          (1<<8)
#define  iopJ_en           (unsigned int)          (1<<9)
#define  iopK_en           (unsigned int)          (1<<10)

#define  ADC1_en           (unsigned int)          (1<<8)
#define  ADC2_en           (unsigned int)          (1<<9)
#define  ADC3_en           (unsigned int)          (1<<10)
#include <stdio.h>
void attiva_clock(int a, char b);
void attiva_clock(int a, char b){
unsigned int* ffff;

  
switch(a)
{
    case (1):
        ffff = Clock_AHB1_en;
        break;
     
    case (2):
        ffff = Clock_APB2_en;
        break;
}  
  
if(a==1){  

  if (b=='a'){
	*ffff |= iopA_en;
        }
     
if (b=='b'){
	*ffff |= iopB_en;
        }
			
if (b=='c'){
	*ffff |= iopC_en;
		}
     
if (b=='d'){
	*ffff |= iopD_en;
		}	

if (b=='e'){
	*ffff |= iopE_en;
		}
			
if (b=='f'){
	*ffff |= iopF_en;
		}
     
if (b=='g'){
	*ffff |= iopG_en;
		}	
			
if (b=='h'){
	*ffff |= iopH_en;
		}	

if (b=='i'){
	*ffff |= iopI_en;
		}
			
if (b=='j'){
	*ffff |= iopJ_en;
		}
     
if (b=='k'){
	*ffff |= iopK_en;
		}				
	}  

if(a==2){
  if (b=='a'){
	*ffff |= ADC1_en;
		}
     
  if (b=='b'){
	*ffff |= ADC2_en;
		}
			
  if (b=='c'){
	*ffff |= ADC3_en;
		}	
	}	
}
