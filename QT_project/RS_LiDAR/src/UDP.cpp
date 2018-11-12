
#define PORT 60000
#define SERVER_IP 192.168.1.103

#include <memory.h>
#include <Eigen/Dense>
#include <iostream>
#include <string>

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
// #include "../proto/perceptron.pb.h"

// using namespace std;
typedef sockaddr_in TSOCKADD_IN;
typedef int TSOCKET;

int UDP_for_RS_BOX(void) {
  struct alignas(16) Pose  //
  {
    Eigen::Vector3f pos;   /**< translation, with meter unit*/
    Eigen::Vector3f angle; /**< rotation, with radian unit*/
  };

  struct alignas(16) rs_MsgHeader2 {
    unsigned int frmNumber;
    unsigned int totalMsgCnt;
    unsigned int msgLen;
    Pose poseInfos;
  };

  struct rs_Msg2 {
    double timestamp = 1;
    int id = 2;
    float x = 1;
    float y = 2;
    float z = 3;
    float length = 4;
    float width = 5;
    float height = 6;
  };

  Pose pose;
  rs_Msg2 *rs_msg;
  int m_receiver_sockfd_;
  sockaddr_in m_receiver_dest_addr_;
  rs_MsgHeader2 header;  //接收到的数据存储

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
  // m_receiver_dest_addr_.sin_addr.s_addr = inet_addr("192.168.1.103");

  int err_log =
      ::bind(m_receiver_sockfd_, (struct sockaddr *)&m_receiver_dest_addr_,
             sizeof(m_receiver_dest_addr_));  // 绑定

  if (err_log != 0) {
    printf("Communication: Bind Network Failed, Error: \n");
    close(m_receiver_sockfd_);
    m_receiver_sockfd_ = -1;
    return -1;
  }

  int bufferSize = 2 * 1024 * 1024;
  setsockopt(m_receiver_sockfd_, SOL_SOCKET, SO_RCVBUF,
             (const char *)(&bufferSize), sizeof(int));

  struct sockaddr_in client_addr;

  while (true) {
    int msgMaxLen = 50000;
    void *pMsgData = malloc(msgMaxLen);
    rs_MsgHeader2 header;
    int ret;
    // std::vector<Perceptron> perceptrons;
    // robosense::Perceptron perceptrons;

    socklen_t cliaddr_len = sizeof(client_addr);
    char *pRecvBuffer = new char[msgMaxLen + sizeof(rs_MsgHeader2)];

    //接收
    printf("recvfrom...\n");
    ret = recvfrom(m_receiver_sockfd_, pRecvBuffer,
                   msgMaxLen + sizeof(rs_MsgHeader2), 0,
                   (struct sockaddr *)&client_addr, &cliaddr_len);

    if (ret < 0) {
      // 关闭socket
      printf("Communication: Receive Message Data Failed, Error: \n");
      close(m_receiver_sockfd_);
      m_receiver_sockfd_ = -1;
      usleep(10000);  // 10ms
      return -1;
    }

    rs_MsgHeader2 *pMsgHeader = (rs_MsgHeader2 *)(pRecvBuffer);
    header.frmNumber = pMsgHeader->frmNumber;
    header.totalMsgCnt = pMsgHeader->totalMsgCnt;
    header.poseInfos = pMsgHeader->poseInfos;
    header.msgLen = pMsgHeader->msgLen;

    std::cout << "header.frmNumber: " << header.frmNumber << std::endl;
    std::cout << "header.totalMsgCnt: " << header.totalMsgCnt << std::endl;
    std::cout << "header.msgLen: " << header.msgLen << std::endl;

    if (ret < header.msgLen + sizeof(rs_MsgHeader2)) {
      printf(
          "Communication: Reciver Data not Completely, message size is too "
          "big\n");
      return -1;
    }
    memcpy(pMsgData, pRecvBuffer + sizeof(rs_MsgHeader2), header.msgLen);
    delete[] pRecvBuffer;

    pose = header.poseInfos;  //解析定位信息
    std::cout << "header.pos: " << pose.pos(0) << "  " << pose.pos(1) << "  "
              << pose.pos(2) << std::endl;
    std::cout << "header.angle: " << pose.angle(0) << "  " << pose.angle(1)
              << "  " << pose.angle(2) << std::endl;
    // printf("pose1 = %f\n", header.poseInfos.pos(0));
    // printf("pose2 = %f\n", header.poseInfos.pos(1));
    // printf("pose3 = %f\n", header.poseInfos.pos(2));

    //解析
    rs_msg = (rs_Msg2 *)pMsgData;
    std::cout << "x = " << rs_msg->x << std::endl;
    std::cout << "y = " << rs_msg->y << std::endl;
    std::cout << "z = " << rs_msg->z << std::endl;

    std::cout << "length = " << rs_msg->length << std::endl;
    std::cout << "width = " << rs_msg->width << std::endl;
    std::cout << "height = " << rs_msg->height << std::endl;

    // perceptrons.ParseFromArray(pMsgData, header.msgLen);
    // printf("timestamp = %lf\n", perceptrons.timestamp);
    // printf("id = %d\n", perceptrons.id);
  }

  return 0;
}