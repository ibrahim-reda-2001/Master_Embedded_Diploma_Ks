//startup.c
// eng:ibrahim reda
#include<stdint.h>
extern int main(void);

void reset_handler ();

void defualt_handler ()
{
	reset_handler();
}
void nmi_handler () __attribute__((weak,alias("defualt_handler")));;
void h_fault_handler () __attribute__((weak,alias("defualt_handler"))) ;;
void mm_fault_handler () __attribute__((weak,alias("defualt_handler")));;
void bus_fault_handler () __attribute__((weak,alias("defualt_handler")));;
void usage_fault_handler () __attribute__((weak,alias("defualt_handler")));;
static unsigned long stack_top[256];

void (*const g_p_fn_vectors[])() __attribute__((section(".vectors"))) =
{
	(void(*)()) ((unsigned long)stack_top + sizeof(stack_top)),
	 reset_handler,
	 nmi_handler,
	 h_fault_handler,
	 mm_fault_handler,
	 bus_fault_handler,
	 usage_fault_handler
};


extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;

void reset_handler (void) 
{
	// .data from rom to ram
	unsigned int data_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char *d_src = (unsigned char*)&_E_TEXT;
	unsigned char *d_dst = (unsigned char*)&_S_DATA;
	for(int i =0; i<data_size; i++){
		*((unsigned char*)d_dst++) = *((unsigned char*)d_src++); 
	}

	//resrve .bss in ram 
	unsigned int bss_size = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS;
	unsigned char *b_dst = (unsigned char*)&_S_BSS;
	for(int i =0; i<bss_size; i++){
		*((unsigned char*)b_dst++) = (unsigned char) 0; 
	}

	// branch main
	main();
}