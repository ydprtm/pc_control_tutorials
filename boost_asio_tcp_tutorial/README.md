# Source Code

### main.cpp

The block

```cpp
#include <iostream>
#include <boost/asio.hpp>
```

instructs the preprocessor to copy the contents of iostream and asio.hpp to main.cpp. The iostream header defines the standard Input and Output (I/O) stream objects. The asio header defines network and low-level I/O objects. In this sample, we use iostream's and asio.hpp's contents to display text to the user and communicate over a network via the Transmission Control Protocol (TCP).

The block

```cpp
 int main(int argc, char* argv[]) {
     ...
 }
```

defines the program's entry point. main() has two parameters, int argc, and char* argv[], and returns an int type. argc is the number of command-line parameters; argv is an array of the command-line parameters. In this sample, we don't use either parameter.

The block

```cpp
try {
    ...
} catch(std::exception& e) {
    ...
}
```

defines a try block and a catch block. In this sample, we try to send a message to an endpoint. If an exception is raised, the program's execution proceeds to the catch handler, which processes a std::exception data type.

The line

```cpp
boost::asio::io_context io;
```

defines an instance of the boost::asio library's io_context class. It provides core synchronous and asynchronous I/O functionality. More information about io_context can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/io_context.html).

The line

```cpp
boost::asio::ip::tcp::resolver resolver(io);
```

defines an instance of the boost::asio library's TCP resolver class. It provides the ability to resolve a query to a list of endpoints. More information about ip::tcp::resolver can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/ip__tcp/resolver.html).

The line

```cpp

```