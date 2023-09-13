/*linker script
eng:ibrahim*/
MEMORY
{
flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
sran(RWX) : ORIGIN = 0x02000000, LENGTH = 20K
}
SECTIONS 
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		} > flash
	.data :
		{
		*(.data)
	} > flash
	.bss :
		{
			*(.bss)
	} > sram	
	
} 