/* Borrowed from spookian's HelperAI project (https://github.com/spookian/HelperAI.git) */

INCLUDE symbol.ld

ENTRY(HOOK)

OUTPUT_FORMAT("elf32-powerpc")

MEMORY
{
    mem (rwx) : ORIGIN = 0x808D120C, LENGTH = 1M
}

PHDRS
{
	headers PT_LOAD PHDRS ;
	text PT_LOAD ;
}

SECTIONS
{
	.text : 
	{
		KEEP(*(.text .text.*)) 

	} >mem :text
	
	.data : 
	{
		KEEP(*(.rodata .rodata.*))
		KEEP(*(.data .data.*)) 
		KEEP(*(.sdata .sdata.* ))

	} >mem :text

}
