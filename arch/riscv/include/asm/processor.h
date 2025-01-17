/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2012 Regents of the University of California
 */

#ifndef _ASM_RISCV_PROCESSOR_H
#define _ASM_RISCV_PROCESSOR_H

#include <linux/const.h>
#include <linux/cache.h>

#include <vdso/processor.h>

#include <asm/ptrace.h>

/*
 * This decides where the kernel will search for a free chunk of vm
 * space during mmap's.
 */
#define TASK_UNMAPPED_BASE	PAGE_ALIGN(TASK_SIZE / 3)

#define STACK_TOP		TASK_SIZE
#ifdef CONFIG_64BIT
#define STACK_TOP_MAX		TASK_SIZE_64
#else
#define STACK_TOP_MAX		TASK_SIZE
#endif
#define STACK_ALIGN		16

#ifndef __ASSEMBLY__

struct task_struct;
struct pt_regs;

/*
 * We use a flag to track in-kernel Vector context. Currently the flag has the
 * following meaning:
 *
 *  - bit 0: indicates whether the in-kernel Vector context is active. The
 *    activation of this state disables the preemption. On a non-RT kernel, it
 *    also disable bh. Currently only 0 and 1 are valid value for this field.
 *    Other values are reserved for future uses.
 */
#define RISCV_KERNEL_MODE_V	0x1

/* CPU-specific state of a task */
struct thread_struct {
	/* Callee-saved registers */
	unsigned long ra;
	unsigned long sp;	/* Kernel mode stack */
	unsigned long s[12];	/* s[0]: frame pointer */
	struct __riscv_d_ext_state fstate;
	unsigned long bad_cause;
	u32 riscv_v_flags;
	u32 vstate_ctrl;
	struct __riscv_v_ext_state vstate;
};

/* Whitelist the fstate from the task_struct for hardened usercopy */
static inline void arch_thread_struct_whitelist(unsigned long *offset,
						unsigned long *size)
{
	*offset = offsetof(struct thread_struct, fstate);
	*size = sizeof_field(struct thread_struct, fstate);
}

#define INIT_THREAD {					\
	.sp = sizeof(init_stack) + (long)&init_stack,	\
}

#define task_pt_regs(tsk)						\
	((struct pt_regs *)(task_stack_page(tsk) + THREAD_SIZE		\
			    - ALIGN(sizeof(struct pt_regs), STACK_ALIGN)))

#define KSTK_EIP(tsk)		(task_pt_regs(tsk)->epc)
#define KSTK_ESP(tsk)		(task_pt_regs(tsk)->sp)


/* Do necessary setup to start up a newly executed thread. */
extern void start_thread(struct pt_regs *regs,
			unsigned long pc, unsigned long sp);

extern unsigned long __get_wchan(struct task_struct *p);


static inline void wait_for_interrupt(void)
{
	__asm__ __volatile__ ("wfi");
}

struct device_node;
int riscv_of_processor_hartid(struct device_node *node, unsigned long *hartid);
int riscv_of_parent_hartid(struct device_node *node, unsigned long *hartid);

extern void riscv_fill_hwcap(void);
extern int arch_dup_task_struct(struct task_struct *dst, struct task_struct *src);
extern struct cpumask ai_core_mask_get(void);

extern unsigned long signal_minsigstksz __ro_after_init;
#endif /* __ASSEMBLY__ */

#endif /* _ASM_RISCV_PROCESSOR_H */
