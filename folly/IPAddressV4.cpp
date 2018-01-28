#include <folly/IPAddressV4.h>
#include <folly/IPAddress.h>
#include <folly/Range.h>
#include <iostream>
#include <cstdint>
#include <stack>
#include <string>
template<class T>
std::string outBinary(T t)
{
  char * a[] = {
    "0000",
    "0001",
    "0010",
    "0011",
    "0100",
    "0101",
    "0110",
    "0111",
    "1000",
    "1001",
    "1010",
    "1011",
    "1100",
    "1101",
    "1110",
    "1111",
  };
  std::stack<int> s;
  while (t != 0)
  {
    s.push(t%16);
    t /=16;
  }
  if (s.size()%2)
  {
    s.push(0);
  }
  std::string r;
  while (!s.empty())
  {
    r+= a[s.top()];
    s.pop();
    r+= a[s.top()];
    s.pop();
    r+=" ";
  }
  return r;
}
union Addr {
  uint32_t u;
  u_char c[4];
};

void MyMethod(folly::IPAddressV4 &ip)
{
  std::cout <<"ip.isLoop"<< ip.isLoopback() << std::endl;
  std::cout <<"ip.isLink"<< ip.isLinkLocalBroadcast() << std::endl;
  std::cout <<"ip.isLink"<< ip.isLinkLocal() << std::endl;
  std::cout <<"ip.isNonr"<< ip.isNonroutable() << std::endl;
  std::cout <<"ip.isPriv"<< ip.isPrivate() << std::endl;
  std::cout <<"ip.isMult"<< ip.isMulticast() << std::endl;
  std::cout <<"ip.isZero"<< ip.isZero() << std::endl;
}

void ipAddressV4(folly::StringPiece s)
{
  folly::IPAddressV4 ip(s);
  folly::IPAddressV4 ipmask("61.135.168.0");
  auto b = ip.toBinary();
  for (auto i :b)
  {
    std::cout<<(int)(i)<<std::endl;
  }
  std::cout<<"line: "<<__LINE__<<std::endl;
  Addr a;
  a.u = ip.toLongHBO();
  std::cout<<a.u<<std::endl;
  std::cout<<"out Binary:";
  std::cout<<outBinary(a.u)<<std::endl;
  for (int i = 0; i<4; ++i)
  {
    //11 168 ...
    std::cout<<(int)a.c[i]<<std::endl;
  }
  std::cout<<"line: "<<__LINE__<<std::endl;
  std::cout<<ip.bitCount()<<std::endl;
  std::cout<<ip.toJson()<<std::endl;
  std::cout<<ip.inSubnet(ipmask,24)<<std::endl;
  std::cout<<ip.inSubnet("61.135.168.0/16")<<std::endl;
  std::cout<<"line: "<<__LINE__<<std::endl;
  MyMethod(ip);

  std::cout<<"line: "<<__LINE__<<std::endl;
  std::cout<<ip.toInverseArpaName()<<std::endl;
  auto mask = ip.mask(8);

  {

  auto b = mask.toBinary();
  for (auto i :b)
  {
    std::cout<<(int)(i)<<std::endl;
  }
  }
  std::cout<<mask.str()<<std::endl;
  std::cout<<ip.version()<<std::endl;
  std::cout<<"line: "<<__LINE__<<std::endl;
  for (int i = 0; i<4; ++i)
  {
    std::cout<<(int)ip.bytes()[i]<<std::endl;
  }
  for (int i = 0; i<4; ++i)
  {
    std::cout<<(int)ip.getNthLSByte(i)<<std::endl;
  }
  for (int i = 0; i<ip.bitCount();++i)
  {
    std::cout<<ip.getNthMSBit(i);
    if ((i+1) %8 == 0)
    {
      std::cout<<" ";
    }
  }
  std::cout<<std::endl;
}



int main()
{
  //std::cout<<outBinary(165)<<std::endl;
  //std::cout<<outBinary(0xffff)<<std::endl;
  //std::cout<<outBinary(0xf0ea)<<std::endl;
  {
  folly::StringPiece s("61.135.168.11");
  std::cout<<s<<std::endl;
  folly::IPAddressV4 v(s);
  MyMethod(v);
  ipAddressV4(s);
  }
  {
  folly::StringPiece s("241.135.168.11");
  std::cout<<s<<std::endl;
  folly::IPAddressV4 v(s);
  MyMethod(v);
  }
  {
  folly::StringPiece s("0.0.0.0");
  std::cout<<s<<std::endl;
  folly::IPAddressV4 v(s);
  MyMethod(v);

  }
  {

  folly::StringPiece s("169.254.255.255");
  std::cout<<s<<std::endl;
  folly::IPAddressV4 v(s);
  MyMethod(v);
  }
  {

  folly::StringPiece s("169.254.0.1");
  std::cout<<s<<std::endl;
  folly::IPAddressV4 v(s);
  MyMethod(v);
  }
  {

  folly::StringPiece s("192.168.0.1");
  std::cout<<s<<std::endl;
  folly::IPAddressV4 v(s);
  MyMethod(v);
  }
  {

  folly::StringPiece s("127.0.0.1");
  std::cout<<s<<std::endl;
  folly::IPAddressV4 v(s);

  MyMethod(v);
  }
}