#ifndef P_1_5_TEST
#define P_1_5_TEST

#define TRANSMITTED 5
#define TRANSTATUS 2
#define ACK 1
#define PRINTCHR 2
#define CHAROFFSET 8
#define STATUSMASK 0xFF
#define TERM0ADDR 0x10000250
#define DEVREGSIZE 16
#define READY 1
#define DEVREGLEN 4
#define TRANCOMMAND 3
#define BUSY 3

#define SYS3 3
#define STEPS 6
#define GANTT_SIZE 20

void log_process_order(int process);

void test1();
void test2();
void test3();

#endif
