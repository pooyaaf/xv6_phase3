#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

// syscall for change queue
int sys_chpp(void)
{
  int pid, priority;

  if (argint(0, &pid) < 0 || argint(1, &priority) < 0)
    return -1;

  changepriority(pid, priority);
  return 0;
}

// syscall for print
int sys_printprocs(void)
{
  printprocs();
  return 0;
}

int sys_get_rank_coef(void)
{
  int time_cf, cycle_cf, pri_cf;
  if (argint(0, &time_cf) < 0 || argint(1, &cycle_cf) < 0 || argint(2, &pri_cf))
    return -1;

  get_rank_coef(&time_cf, &cycle_cf, &pri_cf);
  return 0;
}

int sys_fork(void)
{
  return fork();
}

int sys_exit(void)
{
  exit();
  return 0; // not reached
}

int sys_wait(void)
{
  return wait();
}

int sys_kill(void)
{
  int pid;

  if (argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int sys_getpid(void)
{
  return myproc()->pid;
}

int sys_sbrk(void)
{
  int addr;
  int n;

  if (argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if (growproc(n) < 0)
    return -1;
  return addr;
}

int sys_sleep(void)
{
  int n;
  uint ticks0;

  if (argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while (ticks - ticks0 < n)
  {
    if (myproc()->killed)
    {
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
