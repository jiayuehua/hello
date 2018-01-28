#include <folly/SocketAddress.h>
#include <iostream>
#include <sys/socket.h>
int connectMy(int& fd)
{
  fd = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
  folly::IPAddress ip ("123.56.148.48");
  folly::SocketAddress s(ip, 80);
  sockaddr_storage ss;
  socklen_t l = s.getAddress(&ss);
  std::cout<<l<<std::endl;
  return connect(fd, (const struct sockaddr* )&ss, l);
}
void socketAddress()
{
  {

  folly::IPAddress ip ("192.168.43.129");
  folly::SocketAddress s(ip, 80);
  std::cout<<"isInitialized"<<s.isInitialized()<<std::endl;
  std::cout<<"isprivate"<<s.isPrivateAddress()<<std::endl;
  std::cout<<"isLoopback"<<s.isLoopbackAddress()<<std::endl;
  s.setFromHostPort("www.baidu.com",80);
  }
  {
    folly::SocketAddress s;
    s.setFromLocalPort(22);
  }

  {
    folly::SocketAddress s;
    s.setFromLocalIpPort("192.168.48.129:22");
    std::cout<<s.isFamilyInet()<<std::endl;
    std::cout<<s.getFullyQualified()<<std::endl;
    std::cout<<s.getPort()<<std::endl;
    std::cout<<s.getHostStr()<<std::endl;
    std::cout<<s.describe()<<std::endl;



  }

  {
    folly::SocketAddress s;
    s.setFromLocalIpPort("192.168.43.129:22");
    sockaddr_storage sto;
    socklen_t l = s.getAddress(&sto);
  }
  {
    int fd ;
    int r = connectMy(fd );
    {
      std::cout<<"======\n";
      std::cout<<fd<<std::endl;

    folly::SocketAddress s;
    s.setFromPeerAddress(fd);
    std::cout<<s.getAddressStr()<<":"<<s.getPort()<<std::endl;
    }
    folly::SocketAddress s;
    s.setFromLocalAddress(fd);
    std::cout<<s.getAddressStr()<<":"<<s.getPort()<<std::endl;
  }




}
int main()
{
  socketAddress();
}