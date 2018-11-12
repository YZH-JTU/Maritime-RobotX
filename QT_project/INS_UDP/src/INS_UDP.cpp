#define PORT 45454
#define SERVER_IP 192.168.36.1

#include <memory.h>
#include <iostream>
#include <string>

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

// using namespace std;
typedef sockaddr_in TSOCKADD_IN;
typedef int TSOCKET;

int UDP_for_INS(void) {
  int m_receiver_sockfd_;
  sockaddr_in m_receiver_dest_addr_;

  m_receiver_sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);  // 创建套接字
  if (m_receiver_sockfd_ == -1) {
    printf("Communication: Create Upd Reciver Socket Failed !");
    return -1;
  }

  memset((char *)&m_receiver_dest_addr_, 0, sizeof(m_receiver_dest_addr_));

  m_receiver_dest_addr_.sin_family = AF_INET;    // ipv4
  m_receiver_dest_addr_.sin_port = htons(PORT);  // 端口转换
  m_receiver_dest_addr_.sin_addr.s_addr =
      htonl(INADDR_ANY);  // 绑定网卡所有ip地址，INADDR_ANY为通配地址，值为0

  int err_log =
      ::bind(m_receiver_sockfd_, (struct sockaddr *)&m_receiver_dest_addr_,
             sizeof(m_receiver_dest_addr_));  // 绑定

  if (err_log != 0) {
    printf("Communication: Bind Network Failed, Error: \n");
    close(m_receiver_sockfd_);
    m_receiver_sockfd_ = -1;
    return -1;
  }

  // int bufferSize = 2 * 1024 * 1024;
  // setsockopt(m_receiver_sockfd_, SOL_SOCKET, SO_RCVBUF,
  //            (const char *)(&bufferSize), sizeof(int));

  struct sockaddr_in client_addr;

  while (true) {
    int msgMaxLen = 200;
    int ret;

    socklen_t cliaddr_len = sizeof(client_addr);
    char pRecvBuffer[msgMaxLen] = {0};

    //接收
    // printf("socket = %d\n", m_receiver_sockfd_);
    // printf("recvfrom...\n");
    ret = recvfrom(m_receiver_sockfd_, pRecvBuffer, msgMaxLen, 0,
                   (struct sockaddr *)&client_addr, &cliaddr_len);

    if (ret < 0) {
      // 关闭socket
      printf("Communication: Receive Message Data Failed, Error: \n");
      close(m_receiver_sockfd_);
      m_receiver_sockfd_ = -1;
      usleep(10000);  // 10ms
      return -1;
    }

    std::cout << "receive: " << pRecvBuffer << std::endl;
  }
  return 0;
}