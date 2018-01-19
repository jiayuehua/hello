#include <folly/json.h>
#include <string>
#include <iostream>
void json()
{
  using namespace folly;
  std::string jsonFormat = R"([true,{"hello":3}, 132, 2.33, "hi" ])";
  dynamic d = parseJson(jsonFormat);
  std::cout<<d.isArray()<<std::endl;
  std::cout<<d[2]<<std::endl;
  std::cout<<d[0]<<std::endl;
  //std::cout<<d[4]["hi"]<<std::endl;
  dynamic darray = dynamic::array("hi",  true, 11);
  darray.push_back("world");
  //dynamic darraya = dynamic::array("1")(true)(11);
  std::cout<<toJson(darray)<<std::endl;
  for (const auto &i : darray)
  {
    if (i.isString())
    {
      std::cout<<i.getString()<<std::endl;
    }

  }

  dynamic dobj = dynamic::object("hi",  true)("go",nullptr)("owrld",3.22);
  for (auto& i: dobj.keys())
  {
    std::cout<<i<<std::endl;
  }

  for (auto& i: dobj.values())
  {
    if (i.isDouble())
    {
      std::cout<<i.getDouble()<<std::endl;
    }
  }
  auto i = dobj.find("hi");
  if (i != dobj.items().end())
  {
    std::cout<<i->first<<std::endl;
    if (i->second.isBool())
    {
      std::cout<<i->second.getBool()<<std::endl;
    }
  }
  dobj.erase("hi");
  std::cout<<toJson(dobj)<<std::endl;


}
//void json()
//{
//  using namespace folly;
//  // Parsing JSON strings and using them.
//  std::string jsonDocument = R"({"key":12,"key2":[false, null, true, "yay"]})";
//  dynamic parsed = folly::parseJson(jsonDocument);
//  assert(parsed["key"] == 12);
//  assert(parsed["key2"][0] == false);
//  assert(parsed["key2"][1] == nullptr);
//
//  // Building the same document programatically.
//  dynamic sonOfAJ = dynamic::object
//  ("key", 12)
//    ("key2", dynamic::array(false, nullptr, true, "yay"));
//
//  // Printing.  (See also folly::toPrettyJson)
//  auto str = folly::toJson(sonOfAJ);
//  assert(jsonDocument.compare(str) == 0);
//
//}
int main()
{
  json();
}