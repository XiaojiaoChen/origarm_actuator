///**
//*****************************************************************************
//**
//**  File        : syscalls.c
//**
//**  Author	    : Auto-generated by STM32CubeIDE
//**
//**  Abstract    : STM32CubeIDE Minimal System calls file
//**
//** 		          For more information about which c-functions
//**                need which of these lowlevel functions
//**                please consult the Newlib libc-manual
//**
//**  Environment : STM32CubeIDE MCU
//**
//**  Distribution: The file is distributed as is, without any warranty
//**                of any kind.
//**
//*****************************************************************************
//**
//** <h2><center>&copy; COPYRIGHT(c) 2018 STMicroelectronics</center></h2>
//**
//** Redistribution and use in source and binary forms, with or without modification,
//** are permitted provided that the following conditions are met:
//**   1. Redistributions of source code must retain the above copyright notice,
//**      this list of conditions and the following disclaimer.
//**   2. Redistributions in binary form must reproduce the above copyright notice,
//**      this list of conditions and the following disclaimer in the documentation
//**      and/or other materials provided with the distribution.
//**   3. Neither the name of STMicroelectronics nor the names of its contributors
//**      may be used to endorse or promote products derived from this software
//**      without specific prior written permission.
//**
//** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//** DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//** CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//** OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//**
//**
//*****************************************************************************
//*/
//
///* Includes */
//#include <sys/stat.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <stdio.h>
//#include <signal.h>
//#include <time.h>
//#include <sys/time.h>
//#include <sys/times.h>
//#include "myUsartFunction.h"
//
///* Variables */
////#undef errno
//extern int errno;
//extern int __io_putchar(int ch) __attribute__((weak));
//extern int __io_getchar(void) __attribute__((weak));
//
//register char * stack_ptr asm("sp");
//
//char *__env[1] = { 0 };
//char **environ = __env;
//
//
///* Functions */
//void initialise_monitor_handles()
//{
//}
//
//int _getpid(void)
//{
//	return 1;
//}
//
//int _kill(int pid, int sig)
//{
//	errno = EINVAL;
//	return -1;
//}
//
//void _exit (int status)
//{
//	_kill(status, -1);
//	while (1) {}		/* Make sure we hang here */
//}
//
//__attribute__((weak)) int _read(int file, char *ptr, int len)
//{
//	int DataIdx;
//
//	for (DataIdx = 0; DataIdx < len; DataIdx++)
//	{
//		*ptr++ = __io_getchar();
//	}
//
//return len;
//}
//
//
///*Redirect printf() by implementing (weak) _write function.
// *Every printf() call would store the output string in TxBuf[], ready for Usart DMA output instead of directly output*/
//int _write(int file, char *pSrc, int len)
//{
//	uint8_t *pDes=Usart1Device.TxBuf[Usart1Device.producerTxBufNum];
//
//	//store the string to next buffer
//	memcpy(pDes,pSrc,len);
//	*(pDes+len)='\0';
//	Usart1Device.countTxBuf[Usart1Device.producerTxBufNum] = len;
//
//	//add one bufferedTxNum, recording how many buffered strings that haven't been sent
//	Usart1Device.bufferedTxNum++;
//
//	//Try to send just buffered string if this is the only one
//	if(Usart1Device.bufferedTxNum == 1){
//		HAL_UART_Transmit_DMA(Usart1Device.huart,pDes,Usart1Device.countTxBuf[Usart1Device.producerTxBufNum]);
//	//	Usart1Device.TxStart = micros();
//	}
////	else{
////	//TO DO, There is a bug here, when the builtInPWMFrequency is changed, the Usart1Devices would somehow suddenly lost the configurations
////		Usart1Device.bufferedTxNum=Usart1Device.bufferedTxNum;
////	}
//	//move producerTxBufNum forward
//	Usart1Device.producerTxBufNum++;
//	Usart1Device.producerTxBufNum%=UART_TX_BUF_NUM;
//
////	//Buffered term full, wait for consumer to reduce producerTxBufNum
////	while(Usart1Device.bufferedTxNum > (UART_TX_BUF_NUM-2)){
////		//Danger! May block the main program continuously !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////		//This waiting mechanism is to take care of the high frequency output within a short period during the Ethercat Initialization
////		//If the producer is always quicker than consumer, for example a high frequency output ,this function would block the program permanently
////	};
//	return len;
//}
//
////__attribute__((weak)) int _write(int file, char *ptr, int len)
////{
////	int DataIdx;
////
////	for (DataIdx = 0; DataIdx < len; DataIdx++)
////	{
////		__io_putchar(*ptr++);
////	}
////	return len;
////}
//
//int _close(int file)
//{
//	return -1;
//}
//
//
//int _fstat(int file, struct stat *st)
//{
//	st->st_mode = S_IFCHR;
//	return 0;
//}
//
//int _isatty(int file)
//{
//	return 1;
//}
//
//int _lseek(int file, int ptr, int dir)
//{
//	return 0;
//}
//
//int _open(char *path, int flags, ...)
//{
//	/* Pretend like we always fail */
//	return -1;
//}
//
//int _wait(int *status)
//{
//	errno = ECHILD;
//	return -1;
//}
//
//int _unlink(char *name)
//{
//	errno = ENOENT;
//	return -1;
//}
//
//int _times(struct tms *buf)
//{
//	return -1;
//}
//
//int _stat(char *file, struct stat *st)
//{
//	st->st_mode = S_IFCHR;
//	return 0;
//}
//
//int _link(char *old, char *new)
//{
//	errno = EMLINK;
//	return -1;
//}
//
//int _fork(void)
//{
//	errno = EAGAIN;
//	return -1;
//}
//
//int _execve(char *name, char **argv, char **env)
//{
//	errno = ENOMEM;
//	return -1;
//}