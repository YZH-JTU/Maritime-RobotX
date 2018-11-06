#include <errno.h>      /*错误号定义*/  
#include <string.h>
#include <unistd.h>     /*Unix 标准函数定义*/ 
#include <stdio.h>
#include "../inc/serial_port.h"
#include "../inc/data_unpack.h"
#include "../inc/globalvar.h"

// int main(int argc, char **argv)
// {
//     int fd;                            //文件描述符  
//     int err;                           //返回调用函数的状态  
//     int len;                          
//     int i;
//     char rcv_buf[200];
//     char send_buf[20]="tiger john";

//     if(argc != 3)
// 	{
// 		printf("Usage: %s /dev/ttySn 0(send data)/1 (receive data) \n",argv[0]);
// 		return FALSE;
// 	}
//     fd = UART0_Open(argv[1]); //打开串口，返回文件描述符

//     do
// 	{
// 		err = UART0_Init(fd,115200,0,8,1,'N');
// 		printf("Set Port Exactly!\n");
// 	}while(FALSE == err || FALSE == fd);

//     if(0 == strcmp(argv[2],"0"))
// 	{
// 		for(i = 0;i < 10;i++)
// 		{
//  			len = UART0_Send(fd,send_buf,10);  
// 			if(len > 0)
// 				printf(" %d time send %d data successful\n",i,len);  
// 			else  
// 				printf("send data failed!\n");  
                            
// 			sleep(2);  
// 		}  
// 		UART0_Close(fd);               
// 	}
//     else
// 	{
// 		while (1) //循环读取数据  
// 		{
// 			len = UART0_Recv(fd, rcv_buf,199);  
//   			if(len > 0)  
// 			{
// 				INS_data_unpack(rcv_buf);
// 				printf("heading_angle = %.2f\n", heading_angle);  
// 				// rcv_buf[len] = '\0';  
// 				// printf("receive data is %s\n",rcv_buf);  
// 				// printf("len = %d\n",len);  
// 			}  
// 			else  
// 			{  
// 				printf("cannot receive data\n");  
// 			}  
// 			//sleep(2);  
// 		}              
// 		UART0_Close(fd);   
// 	}
// }

int main(int argc, char **argv)
{	
	while(1){
		INS_collect();
	}
	return 0;
}