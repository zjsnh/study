﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

/*宏定义*/
#define PROCESS_NAME_LEN     32        /*进程名称的最大长度*/
#define MIN_SLICE            10        /*最小碎片的大小*/
#define DEFAULT_MEM_SIZE     1024      /*默认内存的大小*/
#define DEFAULT_MEM_START    0         /*默认内存的起始位置*/

/* 内存分配算法 */
#define MA_FF      1
#define MA_BF      2
#define MA_WF      3

int mem_size = DEFAULT_MEM_SIZE;         /*内存大小*/
int ma_algorithm = MA_FF;              /*当前分配算法*/
int flag = 0;            		       	 /*设置内存大小标志*/
static int pid = 0;                    /*初始pid*/
int algorithm;

/*描述每一个空闲块的数据结构*/
struct free_block_type {
    int size;
    int start_addr;
    struct free_block_type* next;
};

/*指向内存中空闲块链表的首指针*/
struct free_block_type* free_block = NULL;

/*每个进程分配到的内存块的描述*/
struct allocated_block {
    int pid;
    int size;
    int start_addr;
    char process_name[PROCESS_NAME_LEN];
    struct allocated_block* next;
};
/*进程分配内存块链表的首指针*/
struct allocated_block* allocated_block_head = NULL;

struct allocated_block* find_process(int id)
{
    struct allocated_block* p;
    p = allocated_block_head;
    while (p != NULL)
    {
        if (p->pid == id)
            return p;
        p = p -> next;
    }
    return NULL;
}

void swap(int* p, int* q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
    return;
}

void do_exit()
{
    exit(0);
}

/*初始化空闲块，默认为一块，可以指定大小及起始地址*/
struct free_block_type* init_free_block(int mem_size) {
    struct free_block_type* fb;

    fb = (struct free_block_type*)malloc(sizeof(struct free_block_type));
    if (fb == NULL) {
        printf("No mem\n");
        return NULL;
    }
    fb->size = mem_size;
    fb->start_addr = DEFAULT_MEM_START;
    fb->next = NULL;
    return fb;
}

/*显示菜单*/
display_menu() {
    printf("\n");
    printf("1 - Set memory size (default=%d)\n", DEFAULT_MEM_SIZE);
    printf("2 - Select memory allocation algorithm\n");
    printf("3 - New process \n");
    printf("4 - Terminate a process \n");
    printf("5 - Display memory usage \n");
    printf("0 - Exit\n");
}

/*设置内存的大小*/
set_mem_size() {
    int size;
    if (flag != 0) {  //防止重复设置
        printf("Cannot set memory size again\n");
        return 0;
    }
    printf("Total memory size =");
    scanf("%d", &size);
    if (size > 0) {
        mem_size = size;
        free_block->size = mem_size;
    }
    flag = 1;  return 1;
}

/*按FF算法重新整理内存空闲块链表*/
rearrange_FF() {
    struct free_block_type* tmp, * work;
    printf("Rearrange free blocks for FF \n");
    tmp = free_block;
    while (tmp != NULL) {
        work = tmp->next;
        while (work != NULL) {
            if (work->start_addr < tmp->start_addr)
            { /*地址递增*/
                swap(&work->start_addr, &tmp->start_addr);
                swap(&work->size, &tmp->size);
            }
            work = work->next;
        }
        tmp = tmp->next;
    }
}

/*按BF最佳适应算法重新整理内存空闲块链表*/
rearrange_BF() {
    struct free_block_type* tmp, * work;
    printf("Rearrange free blocks for BF \n");
    tmp = free_block;
    while (tmp != NULL) {
        work = tmp->next;
        while (work != NULL) {
            if (work->size < tmp->size) { /*容量递增*/
                swap(&work->start_addr, &tmp->start_addr);
                swap(&work->size, &tmp->size);
            }
            work = work->next;
        }
        tmp = tmp->next;
    }
}

/*按WF算法重新整理内存空闲块链表*/
rearrange_WF() {
    struct free_block_type* tmp, * work;
    printf("Rearrange free blocks for WF \n");
    tmp = free_block;
    while (tmp != NULL) {
        work = tmp->next;
        while (work != NULL) {
            if (work->size > tmp->size) { /*容量递减*/
                swap(&work->start_addr, &tmp->start_addr);
                swap(&work->size, &tmp->size);
            }
            work = work->next;
        }
        tmp = tmp->next;
    }
}

/*按指定的算法整理内存空闲块链表*/
rearrange(int algorithm) {
    switch (algorithm) {
    case MA_FF:  rearrange_FF(); break;
    case MA_BF:  rearrange_BF(); break;
    case MA_WF:  rearrange_WF(); break;
    }
}

/* 设置当前的分配算法 */
set_algorithm() {
    printf("\t1 - First Fit\n");
    printf("\t2 - Best Fit \n");
    printf("\t3 - Worst Fit \n");
    scanf("%d", &algorithm);
    if (algorithm >= 1 && algorithm <= 3) ma_algorithm = algorithm;
    //按指定算法重新排列空闲区链表
    rearrange(ma_algorithm);
}

/*分配内存模块*/
int allocate_mem(struct allocated_block* ab) {
    struct free_block_type* fbt, * pre, * temp, * work;
    int request_size = ab->size;
    fbt = free_block;
    while (fbt != NULL) {
        if (fbt->size >= request_size) {
            if (fbt->size - request_size >= MIN_SLICE) /*分配后空闲空间足够大，则分割*/
            {
                mem_size -= request_size;
                fbt->size -= request_size;
                ab->start_addr = fbt->start_addr;
                fbt->start_addr += request_size;
            }
            else if (((fbt->size - request_size) < MIN_SLICE) && ((fbt->size - request_size) > 0))
                /*分割后空闲区成为小碎片，一起分配*/
            {
                mem_size -= fbt->size;
                pre = fbt->next;
                ab->start_addr = fbt->start_addr;
                fbt->start_addr += fbt->size;
                free(fbt);
            }
            else
            {
                temp = free_block;
                while (temp != NULL) {
                    work = temp->next;
                    if (work != NULL)/*如果当前空闲区与后面的空闲区相连，则合并*/
                    {
                        if (temp->start_addr + temp->size == work->start_addr) {
                            temp->size += work->size;
                            temp->next = work->next;
                            free(work);
                            continue;
                        }
                    }
                    temp = temp->next;
                }
                fbt = free_block;
                break;
            }
            rearrange(algorithm); /*重新按当前的算法排列空闲区*/
            return 1;
        }
        pre = fbt;
        fbt = fbt->next;
    }
    return -1;
}

/*创建新的进程，主要是获取内存的申请数量*/
int new_process() {
    struct allocated_block* ab;
    int size;
    int ret;
    ab = (struct allocated_block*)malloc(sizeof(struct allocated_block));
    if (!ab) exit(-5);
    ab->next = NULL;
    pid++;
    sprintf(ab->process_name, "PROCESS-%02d", pid);
    ab->pid = pid;

    printf("Memory for %s:", ab->process_name);
    scanf("%d", &size);
    if (size > 0) ab->size = size;
    ret = allocate_mem(ab);  /* 从空闲区分配内存，ret==1表示分配ok*/
    /*如果此时allocated_block_head尚未赋值，则赋值*/
    if ((ret == 1) && (allocated_block_head == NULL)) {
        allocated_block_head = ab;
        return 1;
    }
    else if (ret == 1) {/*分配成功，将该已分配块的描述插入已分配链表*/
        ab->next = allocated_block_head;
        allocated_block_head = ab;
        return 2;
    }
    else if (ret == -1) { /*分配不成功*/
        printf("Allocation fail\n");
        free(ab);
        return -1;
    }
    return 3;
}

/*将ab所表示的已分配区归还，并进行可能的合并*/
int free_mem(struct allocated_block* ab)
{
    int algorithm = ma_algorithm;
    struct free_block_type* fbt, * work;
    fbt = (struct free_block_type*)malloc(sizeof(struct free_block_type));
    if (!fbt) return -1;
    fbt->size = ab->size;
    fbt->start_addr = ab->start_addr;
    /*插入到空闲区链表的头部并将空闲区按地址递增的次序排列*/
    fbt->next = free_block;
    free_block = fbt;
    rearrange(MA_FF);
    fbt = free_block;
    while (fbt != NULL) {
        work = fbt->next;
        if (work != NULL) {
            /*如果当前空闲区与后面的空闲区相连，则合并*/
            if (fbt->start_addr + fbt->size == work->start_addr) {
                fbt->size += work->size;
                fbt->next = work->next;
                free(work);
                continue;
            }
        }
        fbt = fbt->next;
    }
    rearrange(algorithm); /*重新按当前的算法排列空闲区*/
    return 1;
}

/*释放ab数据结构节点*/
int dispose(struct allocated_block* free_ab) {
    struct allocated_block* pre, * ab;
    if (free_ab == allocated_block_head) { /*如果要释放第一个节点*/
        allocated_block_head = allocated_block_head->next;
        free(free_ab);
        return 1;
    }
    else {
        pre = allocated_block_head;
        ab = allocated_block_head->next;
        while (ab != free_ab) { pre = ab;  ab = ab->next; }
        pre->next = ab->next;
        free(ab);
        return 2;
    }
}

/* 显示当前内存的使用情况，包括空闲区的情况和已经分配的情况 */
display_mem_usage() {
    struct free_block_type* fbt = free_block;
    struct allocated_block* ab = allocated_block_head;
    if (fbt == NULL) return(-1);
    printf("----------------------------------------------------------\n");
    /* 显示空闲区 */
    printf("Free Memory:\n");
    printf("%20s %20s\n", "      start_addr", "       size");
    while (fbt != NULL) {
        printf("%20d %20d\n", fbt->start_addr, fbt->size);
        fbt = fbt->next;
    }
    /* 显示已分配区 */
    printf("\nUsed Memory:\n");
    printf("%10s %20s %10s %10s\n", "PID", "ProcessName", "start_addr", " size");
    while (ab != NULL)
    {
        printf("%10d %20s %10d %10d\n", ab->pid, ab->process_name, ab->start_addr, ab->size);
        ab = ab->next;
    }
    printf("----------------------------------------------------------\n");
    return 0;
}

/*删除进程，归还分配的存储空间，并删除描述该进程内存分配的节点*/
kill_process()
{
    struct allocated_block* ab;
    int pid;
    printf("Kill Process, pid=");
    scanf("%d", &pid);
    ab = find_process(pid);
    if (ab != NULL) {
        free_mem(ab); /*释放ab所表示的分配区*/
        dispose(ab);  /*释放ab数据结构节点*/
    }
}

main()
{
    char choice;
    pid = 0;
    free_block = init_free_block(mem_size); //初始化空闲区
    for (;;) {
        display_menu();	//显示菜单
        fflush(stdin);
        choice = getchar();	//获取用户输入
        switch (choice) {
        case '1': set_mem_size(); break;       			//设置内存大小
        case '2': set_algorithm(); flag = 1; break;	       	//设置分配算法
        case '3': new_process(); flag = 1; break;	       	//创建新进程
        case '4': kill_process();	 flag = 1; break;	       	//删除进程
        case '5': display_mem_usage(); flag = 1; break;     //显示内存使用
        case '0': do_exit(); exit(0); break;	    			//释放链表并退出
        default: break;
        }
    }
}