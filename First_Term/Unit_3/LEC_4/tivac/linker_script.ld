/*linker script
eng:ibrahim*/
MEMORY
{
	flash(RX) : ORIGIN = 0x00000000, LENGTH = 512m
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512m
}
SECTIONS 
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_TEXT = . ;
		} > flash
	.data :
		{
		_S_DATA = . ;
		*(.data)
		_E_DATA = . ;
		
	} > sram AT> flash 
	.bss :
		{
			_S_BSS = . ;
			*(.bss)
			. = ALIGN(4);
			_E_BSS = . ;
			
		} > sram	
	
} 