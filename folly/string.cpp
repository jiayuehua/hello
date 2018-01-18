#include <folly/String.h>
#include <folly/FBString.h>
#include <iostream>
#include <iterator>
#include <iterator>

void stringfunc()
{
  {

  folly::fbstring fb("facebook ");

  auto s = folly::toStdString(fb);
  fb[1] = '\"';
  fb[2] = '\\';
  fb[3] = (char)254;
  folly::fbstring out;
  folly::cEscape(fb, out);
  std::cout<<"line"<<__LINE__<<std::endl;
  std::cout<<out<<std::endl;
  folly::fbstring fba = folly::cUnescape<folly::fbstring>(out);
  std::cout<<"line"<<__LINE__<<std::endl;
  std::cout<< (fba == fb) <<std::endl;
  std::string str = folly::stringPrintf("%d%snihao%c",100,"HELLO",'A');
  std::cout<<"line"<<__LINE__<<std::endl;
  std::cout<<str<<std::endl;
  }

  {

  folly::fbstring fb;
  folly::fbstring fbout;
  for (int i = 0; i<256 ; ++i)
  {
    fb.push_back((char)i);
  }
  folly::backslashify(fb, fbout);
  std::cout<<"line"<<__LINE__<<std::endl;
  std::cout<<fbout<<std::endl;
  fb = "hello,world";
  folly::hexlify(fb, fbout);
  std::cout<<"line"<<__LINE__<<std::endl;
  std::cout<<fbout<<std::endl;
  std::cout<<folly::prettyPrint(3e10, folly::PrettyType::PRETTY_BYTES);
  std::cout<<folly::prettyPrint(3e10, folly::PrettyType::PRETTY_BYTES_IEC);


  }

  {
  folly::fbstring fb;
  folly::fbstring fbout;
  for (int i = 0; i<256 ; ++i)
  {
    fb.push_back((char)i);
  }
  std::ostream_iterator<std::string> o(std::cout);
  std::cout<<"line"<<__LINE__<<std::endl;
  folly::hexDump(fb.data(),fb.size(),o);
  }

  {
    folly::fbstring fb("   so rt|ls|who|like  ");
    folly::fbstring fba;
    folly::fbvector<folly::fbstring> fbout;
    folly::split("|", fb, fbout);
  std::cout<<"line"<<__LINE__<<std::endl;
    for (auto& i : fbout)
    {
      std::cout << i << std::endl;
    }
  std::cout<<"line"<<__LINE__<<std::endl;
    folly::join(":", fbout, fba);
    std::cout<<ltrimWhitespace(fb)<<std::endl;
    std::cout<<rtrimWhitespace(fb)<<std::endl;
    std::cout<<trimWhitespace(fb)<<std::endl;


  }
  {
  std::cout<<"line"<<__LINE__<<std::endl;
    std::cout<<"tolower Ascii\n";
    std::string fs("Good, Woman");
    folly::toLowerAscii(fs);
    std::cout<<fs<<std::endl;


  }






}
int main()
{
  stringfunc();
}