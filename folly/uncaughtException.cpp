#include <folly/UncaughtExceptions.h>
#include <folly/ScopeGuard.h>
#include <iostream>
/*
* Copyright 2016-present Facebook, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


/*
* Test helper class, when goes out of scope it validaes that
* folly::uncaught_exceptions() returns the specified
* value.
*/
class Validator {
public:
  Validator(int expectedCount, const std::string& msg)
    : expectedCount_(expectedCount), msg_(msg) {}

  // Automatic validation during destruction.
  ~Validator() {
    validate();
  }

  // Invoke to validate explicitly.
  void validate() {
    std::cout<< msg_ << ", expected " << expectedCount_ << ", is "
      << folly::uncaught_exceptions();
  }

private:
  const int32_t expectedCount_;
  const std::string msg_;
};


struct ThrowingConstructor {
  ThrowingConstructor() noexcept(false) {
    throw std::runtime_error("exception");
  }
};

struct InheritsThrowingConstructor : public Validator,
  public ThrowingConstructor {
  InheritsThrowingConstructor() try
    : Validator(1, "one_exception_in_ctor_initializer_expression"),
    ThrowingConstructor() {
  }
  catch (...) {
    // This is being re-thrown once the catch block ends, so I guess
    // it's similar to a catch/throw; (re-throw) behavior and thus the value
    // is 0.
    std::cout<< folly::uncaught_exceptions()<<std::endl;
  }
};

template <int N>
struct S {
  ~S()
  {
    try
    {
      S<N-1> s;
      auto f = folly::makeGuard([]{std::cout<<N<<folly::uncaught_exceptions()<<std::endl;});
      throw std::runtime_error("error\n");
    }
    catch (const std::exception&)
    {

      auto f = folly::makeGuard([]{std::cout<<"catch"<<N<<folly::uncaught_exceptions()<<std::endl;});
    }
  }
};

template <>
struct S <0>{
  ~S()
  {
    try
    {
      auto f = folly::makeGuard([]{std::cout<<0<<folly::uncaught_exceptions()<<std::endl;});
      throw std::runtime_error("error\n");
    }
    catch (const std::exception&)
    {
      auto f = folly::makeGuard([]{std::cout<<"catch"<<0<<folly::uncaught_exceptions()<<std::endl;});
    }
  }
};

void uncaughtExceptions()
{
  try
  {
    //S<4> s;
    InheritsThrowingConstructor c;
    //auto f = folly::makeGuard([]{std::cout<<folly::uncaught_exceptions()<<std::endl;});
    //throw std::runtime_error("world");
  }
  catch (const std::exception&)
  {
    std::cout<<folly::uncaught_exceptions<<std::endl;
  }

}
int main()
{
  uncaughtExceptions();
}