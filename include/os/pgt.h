/*
 * include/os/pgt.h
 *
 * Created by Le Min at 2.14/12/01
 *
 */

#ifndef _PGT_H_
#define _PGT_H_

#include <os/mm.h>
#include <os/kernel.h>
#include <os/mmu.h>
#include <os/task_mm.h>

/*
 * lvl1_pgt_base: the level 1 pgt base address
 * lvl2_pgt_list: the memory for lvl2 page table
 * lvl2_alloc_size: alloc size of lvl2 page table
 * lvl2_free_size: free size of lvl2 pgt current
 * lvl2_free_base: base address of current lvl2 pgt
 */
struct task_page_table {
	unsigned long lvl1_pgt_base;

	struct list_head lvl2_pgt_list;
	size_t lvl2_alloc_size;
	size_t lvl2_free_size;
	size_t lvl2_current_free;
	struct list_head *lvl2_current_page;
	unsigned long lvl2_free_base;
};

int map_task_address(struct task_page_table *table,
		unsigned long va, unsigned long user_addr);
void free_task_page_table(struct task_page_table *pgt);
#endif
