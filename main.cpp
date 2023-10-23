#include <iostream>
#include <boost/asio.hpp>

int main()
{
  boost::asio::io_context io;

  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
  std::cout << "timer waiting for 5 seconds ...\n";
  t.wait();

  std::cout << "Hello, world!" << std::endl;

  return 0;
}
