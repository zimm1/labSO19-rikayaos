#ifndef _TYPES11_H
#define _TYPES11_H

#include <umps/types.h>
#include "listx.h"
#include "const_rikaya.h"

typedef unsigned int memaddr;

/* Process Control Block (PCB) data structure */
typedef struct pcb_t {
	/*process queue fields */
	struct list_head	p_next;

	/*process tree fields */
	struct pcb_t		*p_parent;
	struct list_head	p_child,
						p_sib;
	
	/* processor state, etc */
	state_t       		p_s;
	state_t*			exceptionVector[6];     

	/* process priority */
	int					priority;
	int					original_priority;
	
	/* key of the semaphore on which the process is eventually blocked */
	int					*p_semkey;

	int					time_start;
	int					time_user;
	int					time_kernel;

	int					tutor;
} pcb_t;



/* Semaphore Descriptor (SEMD) data structure */
typedef struct semd_t {
	struct list_head	s_next;
	
	// Semaphore key
	int					*s_key;
	
	// Queue of PCBs blocked on the semaphore
	struct list_head	s_procQ;
} semd_t;

typedef struct semdev {
	 semd_t disk[DEV_PER_INT];
	 semd_t tape[DEV_PER_INT];
	 semd_t network[DEV_PER_INT];
	 semd_t printer[DEV_PER_INT];
	 semd_t terminalR[DEV_PER_INT];
	 semd_t terminalT[DEV_PER_INT];
} semdev;

#endif