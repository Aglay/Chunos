#ifndef _IO_H
#define _IO_H

#include <os/types.h>

static inline u8 __raw_readb(const volatile void *addr)
{
	return *(const volatile u8 *)addr;
}

static inline u16 __raw_readw(const volatile void *addr)
{
	return *(const volatile u16 *)addr;
}

static inline u32 __raw_readl(const volatile void *addr)
{
	return *(const volatile u32 *)addr;
}

static void __raw_writeb(volatile void *addr, u8 b)
{
	*(volatile u8 *)addr = b;
}

static void __raw_writew(volatile void *addr, u16 w)
{
	*(volatile u16 *)addr = w;
}

static void __raw_writel(volatile void *addr, u32 l)
{
	*(volatile u32 *)addr = l;
}

#define readb	__raw_readb
#define readw	__raw_readw
#define readl	__raw_readl

#define writeb	__raw_writeb
#define writew	__raw_writew
#define writel  __raw_writel

static inline u8 inb(unsigned long addr)
{
	return readb((volatile u8 *)addr);
}

static inline u16 inw(unsigned long addr)
{
	return readw((volatile u16 *) addr);
}

static inline u32 inl(unsigned long addr)
{
	return readl((volatile u32 *)addr);
}

static inline void outb(unsigned long addr, u8 b)
{
	writeb((volatile u8 *)addr, b);
}

static inline void outw(unsigned long addr, u16 w)
{
	writew((volatile u16 *)addr, w);
}

static inline void outl(unsigned long addr, u32 l)
{
	writel((volatile u32 *)addr, l);
}

/*
 *read or write on data to a fix addr,usually used to read data 
 *from fifo
 */
static inline void insb(unsigned long addr, void *buffer, int count)
{
	if (count) {
		u8 *buf = buffer;
		do {
			u8 x = inb(addr);
			*buf++ = x;
		} while (--count);
	}
}

static inline void insw(unsigned long addr, void *buffer, int count)
{
	if (count) {
		u16 *buf = buffer;
		do {
			u16 x = inw(addr);
			*buf++ = x;
		} while (--count);
	}
}

static inline void insl(unsigned long addr, void *buffer, int count)
{
	if (count) {
		u32 *buf = buffer;
		do {
			u32 x = inl(addr);
			*buf++ = x;
		} while (--count);
	}
}

static inline void outsb(unsigned long addr, const void *buffer, int count)
{
	if (count) {
		const u8 *buf = buffer;
		do {
			outb(*buf++,addr);
		} while (--count);
	}
}

static inline void outsw(unsigned long addr, const void *buffer, int count)
{
	if (count) {
		const u16 *buf = buffer;
		do {
			outw(*buf++,addr);
		} while (--count);
	}
}

static inline void outsl(unsigned long addr, const void *buffer, int count)
{
	if (count) {
		const u32 *buf = buffer;
		do {
			outl(*buf++,addr);
		} while (--count);
	}
}

#define ioread8(addr)			readb((volatile void *)addr)
#define ioread16(addr)			readw((volatile void *)addr)
#define ioread32(addr)			readl((volatile void *)addr)

#define iowrite8(addr, v)		writeb((volatile void *)(addr), (v))
#define iowrite16(addr, v)		writew((volatile void *)(addr), (v))
#define iowrite32(addr, v)		writel((volatile void *)(addr), (v))

#define ioread8_rep(p, dst, count)	insb((unsigned long)(p), (dst), (count))
#define ioread16_rep(p, dst, count)	insw((unsigned long)(p), (dst), (count))
#define ioread32_rep(p, dst, count)	insl((unsigned long)(p), (dst), (count))

#define iowrite8_rep(p, src, count)	outsb((unsigned long)(p), (src), (count))
#define iowrite16_rep(p, src, count)	outsw((unsigned long)(p), (src), (count))
#define iowrite32_rep(p, src, count)	outsl((unsigned long)(p), (src), (count))

unsigned long iomap_to_addr(unsigned long io_phy, unsigned long vir);

unsigned long iomap(unsigned long io_phy);

int iounmap(unsigned long vir);

#endif
