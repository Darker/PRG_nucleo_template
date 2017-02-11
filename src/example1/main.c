
/* gpio a register */
#define GPIOA_BASE 		((uint32_t)0x40020000)

/* register offsets */
#define GPIO_MODER 		0x00
#define GPIO_OTYPER 	0x04
#define GPIO_OSPEEDR 	0x08
#define GPIO_OPUPDR 	0x0C
#define GPIO_IDR 		0x10
#define GPIO_ODR 		0x14

/* clock register addresses */
#define  RCC_AHB1ENR_GPIOAEN	((uint32_t)0x00000001)
#define  RCC_AHB1ENR			0x30

/* method to delay by busy loop */
void ms_delay(int ms)
{
   while (ms-- > 0) {
      volatile int x=5971;
      while (x-- > 0)
         __asm("nop");
   }
}

/* method to write data to 32 bit register on specified address */
void write_32(uint32_t x, uint32_t addr, uint32_t off){
	*((uint32_t *)(addr + off)) = x;
}

/* method to toggle individual bit on specified address */
void toggle_bit(uint32_t bitnum, uint32_t addr, uint32_t off){
	*((uint32_t *)(addr + off)) ^= (1 << bitnum);
}


/* main loop */
int main(void)
{  
  /* Enable GPIOA Clock (to be able to program the configuration registers) */
  *((uint32_t *)(RCC_BASE+RCC_AHB1ENR)) |= RCC_AHB1ENR_GPIOAEN;
 
  
  /* GPIO_INIT pin PA5 - output, fast, pull-up */
  toggle_bit(10,GPIOA_BASE,GPIO_MODER);	//set pin 5 output 
  toggle_bit(11,GPIOA_BASE,GPIO_OSPEEDR); //set pin 5 speed fast
  toggle_bit(10,GPIOA_BASE,GPIO_OPUPDR);	//set pin 5 pull-up
  
  /* Blink the LED */   
  while (1)
  {
  	ms_delay(100);
  	toggle_bit(5,GPIOA_BASE,GPIO_ODR);

  }
}