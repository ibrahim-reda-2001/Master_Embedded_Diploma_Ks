//startup.c
// eng:ibrahim reda
#include<stdint.h>
extern int main(void);
extern unsigned int _stack_top;
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


uint32_t vectors[] __attribute__((section(".vectors"))) =
{
	(uint32_t) &_stack_top,
	(uint32_t) &reset_handler,
	(uint32_t) &nmi_handler,
	(uint32_t) &h_fault_handler,
	(uint32_t) &mm_fault_handler,
	(uint32_t) &bus_fault_handler,
	(uint32_t) &usage_fault_handler
};

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void reset_handler (void) 
{
	// .data from rom to ram
	unsigned int data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char *d_src = (unsigned char*)&_E_text;
	unsigned char *d_dst = (unsigned char*)&_S_data;
	for(int i =0; i<data_size; i++){
		*((unsigned char*)d_dst++) = *((unsigned char*)d_src++); 
	}

	//resrve .bss in ram 
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	unsigned char *b_dst = (unsigned char*)&_S_bss;
	for(int i =0; i<bss_size; i++){
		*((unsigned char*)b_dst++) = (unsigned char) 0; 
	}

	// branch main
	main();
}