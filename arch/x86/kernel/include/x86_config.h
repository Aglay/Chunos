/*
 * arch/x86/kernel/x86_config.h
 *
 * Created by Le Min at 2014/12/26
 */

#ifndef __X86_CONFIG_H_
#define __X86_CONFIG_H_

#define KERNEL_PDE_BASE			0xa0000000
#define KERNEL_PDE_SIZE			0x1000

#define X86_KERNEL_STACK_SIZE		0x2000
#define X86_KERNEL_STACK_BASE		(KERNEL_PDE_BASE + KERNEL_PDE_SIZE + X86_KERNEL_STACK_SIZE)

#define SYSTEM_GDT_BASE			(X86_KERNEL_STACK_BASE + X86_KERNEL_STACK_SIZE)
#define SYSTEM_GDT_SIZE			0x1000

#define SYSTEM_IDT_BASE			(SYSTEM_GDT_BASE + SYSTEM_GDT_SIZE)
#define SYSTEM_IDT_SIZE			0x1000

#endif
