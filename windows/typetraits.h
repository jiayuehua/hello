#pragma once
struct BA{};
struct BB{};
struct DD:BA,private BB{
  void name();
  void school();
};

struct DD :BA, private BB {
  void name();
  void school();
};