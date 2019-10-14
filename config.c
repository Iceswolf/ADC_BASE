void gpio_config(char d, int b, char *l, char* a, char *c, char *e);

#define  GPIO_A_MODER (unsigned int*) (0x40020000)
#define  GPIO_B_MODER (unsigned int*) (0x40020400)
#define  GPIO_C_MODER (unsigned int*) (0x40020800)
#define  GPIO_D_MODER (unsigned int*) (0x40020c00)
#define  GPIO_E_MODER (unsigned int*) (0x40021000)
#define  GPIO_F_MODER (unsigned int*) (0x40021400)
#define  GPIO_G_MODER (unsigned int*) (0x40021800)
#define  GPIO_H_MODER (unsigned int*) (0x40021c00)
#define  GPIO_I_MODER (unsigned int*) (0x40022000)
#define  GPIO_J_MODER (unsigned int*) (0x40022400)
#define  GPIO_K_MODER (unsigned int*) (0x40022800)

void gpio_config(char d, int b, char *l, char* a, char *c, char *e)
{
unsigned int* puntatore;

if(d=='a') puntatore=GPIO_A_MODER;
else if(d=='b') puntatore=GPIO_B_MODER;
else if(d=='c') puntatore=GPIO_C_MODER;
else if(d=='d') puntatore=GPIO_D_MODER;
else if(d=='e') puntatore=GPIO_E_MODER;
else if(d=='f') puntatore=GPIO_F_MODER;
else if(d=='g') puntatore=GPIO_G_MODER;
else if(d=='h') puntatore=GPIO_H_MODER;
else if(d=='i') puntatore=GPIO_I_MODER;
else if(d=='j') puntatore=GPIO_J_MODER;
else if(d=='k') puntatore=GPIO_K_MODER;

unsigned int  TYPE_X=(1<<b);  
       
unsigned int  SPEED_1=(1<<2*b+1); 
unsigned int  SPEED_0=(1<<2*b); 

if(l=="input"){
	*puntatore &= ~(SPEED_0);
	*puntatore &= ~(SPEED_1);
}
else if(l=="output"){
	*puntatore |=  (SPEED_0);
	*puntatore &= ~(SPEED_1);
}	
else if(l=="analog"){
	*puntatore |=  (SPEED_0);
	*puntatore |=  (SPEED_1);
}	
else if(l=="alternate"){
	*puntatore &= ~(SPEED_0);
	*puntatore |=  (SPEED_1);
}	

puntatore=puntatore+0x04;

if(a=="push-pull"){
*puntatore &= ~(TYPE_X);
}
else if(a=="open-drain"){
*puntatore |= (TYPE_X);		
}

puntatore=puntatore+0x04;

if(c=="low"){
*puntatore &= ~(SPEED_1);
*puntatore &= ~(SPEED_0);	
}
else if(c=="medium"){
*puntatore |= (SPEED_0);
*puntatore &= ~(SPEED_1);		
}
else if(c=="high"){
*puntatore |= (SPEED_1);
*puntatore &= ~(SPEED_0);
}
else if(c=="very-high"){
*puntatore |= (SPEED_1);
*puntatore |= (SPEED_0);		
}

puntatore=puntatore+0x04;

if(e=="no"){
*puntatore &= ~(SPEED_1);
*puntatore &= ~(SPEED_0);	
}
else if(e=="pull-up"){
*puntatore |= (SPEED_0);
*puntatore &= ~(SPEED_1);		
}
else if(e=="pull-down"){
*puntatore |= (SPEED_1);
*puntatore &= ~(SPEED_0);
}
else if(e=="reversed"){
*puntatore |= (SPEED_1);
*puntatore |= (SPEED_0);		
}

}
