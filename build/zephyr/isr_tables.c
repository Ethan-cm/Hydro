
/* AUTO-GENERATED by gen_isr_tables.py, do not edit! */

#include <toolchain.h>
#include <linker/sections.h>
#include <sw_isr_table.h>
#include <arch/cpu.h>

#if defined(CONFIG_GEN_SW_ISR_TABLE) && defined(CONFIG_GEN_IRQ_VECTOR_TABLE)
#define ISR_WRAPPER ((uintptr_t)&_isr_wrapper)
#else
#define ISR_WRAPPER NULL
#endif

typedef void (* ISR)(const void *);
uintptr_t __irq_vector_table _irq_vector_table[86] = {
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
	ISR_WRAPPER,
};
struct _isr_table_entry __sw_isr_table _sw_isr_table[86] = {
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x8003618, (ISR)0x8002dcf},
	{(const void *)0x8003618, (ISR)0x8002dbb},
	{(const void *)0x8003618, (ISR)0x8002db1},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x8003618, (ISR)0x8002e15},
	{(const void *)0x8003618, (ISR)0x8002e0b},
	{(const void *)0x8003618, (ISR)0x8002e01},
	{(const void *)0x8003618, (ISR)0x8002df7},
	{(const void *)0x8003618, (ISR)0x8002ded},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x8003618, (ISR)0x8002de3},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x8003630, (ISR)0x800321b},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x8003618, (ISR)0x8002dd9},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x8003618, (ISR)0x8002dc5},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
	{(const void *)0x0, (ISR)&z_irq_spurious},
};
