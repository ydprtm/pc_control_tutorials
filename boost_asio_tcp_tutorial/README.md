# Network Programming with Boost

Welcome to my tutorial on how to communicate over a network using Boost's Asio library.

## Section 1: Introduction

Consider the following situation: you are an engineer working at a large factory. Your office is on one side of the factory; a machine you need to monitor is on the other side. Your employer requires regular measurements of the machine's state. What do you do?

Here are some potential solutions:

1. You walk over to the machine and manually make a measurement.
1. You develop a system to automatically make a measurement and save the machine's state locally. You walk over at the end of the day and copy the day's log file.
1. You develop a system to automatically make a measurement and transmit the machine's state to your office's computer. You develop an application that displays the machine's state and record it locally.

Given a desired number and frequency of measurements, and the physical distance between your office and the machine, there's a number of issues with the first two options: you may spend too much time walking between your office and the machine, you may mis-count the number of measurements you've made, the machine may experience a fault before the end of the day and you wouldn't know, etc. A more satisfactory solution is the last option: you don't need to constantly walk between your office and the machine, you get consistent, continuous measurements, and you'll know there's been a fault immediately. The last solution could be extended further to include remote operation.

How do you communicate with a remote system? Fortunately, there are a number of tools, e.g. [PuTTY](https://www.putty.org/), and software frameworks and libraries, e.g. [Qt](https://www.qt.io/) and [Boost](https://www.boost.org/), which have been developed to facilitate this. PuTTY allows users to connect to a desired end-point and send raw data, e.g. a string. Qt provides its networking module and Boost provides the Asio library, which both allow for network communication.

In this tutorial, I show you how to use Boost's Asio library to communicate over a network using the Transmission Control Protocal (TCP) and Internet Prototcol (IP), i.e. TCP/IP. The remainder of this tutorial is structured as follows: Section 2 describes the tutorial's requirements; Section 3 describes how to build the tutorial's samples; Section 4 presents and describes sample 1's source code; Section 5 presents and describes sample 2's source code; Section 5 presents an activity for you to complete; Section 7 present and describe sample 3's sample code; Section 8 presents an activity for you complete; and Section 8 concludes the tutorial.

## Section 2: Requirements

## Section 3: Build Instructions

## Section 4: Sample 1

## Section 5: Sample 2

## Section 6: Activity 1

## Section 7: Sample 3

## Section 8: Activity 2

## Section 9: Conclusion

## Credit



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
     return 0;
 }
```

defines the program's entry point. ```main()``` has two parameters, ```int argc```, and ```char* argv[]```, and returns an ```int``` value. ```argc``` is the number of command-line parameters; ```argv``` is an array of the command-line parameters. In this sample, we don't use either parameter. If the program completes successfully, the program returns 0.

The block

```cpp
try {
    ...
} catch(std::exception& e) {

    std::cout << e.what() << std::endl;
    return 1;

}
```

defines a try block and a catch block. In this sample, we try to send a message to an endpoint. If an exception is raised, the program's execution proceeds to the catch handler, which processes a std::exception data type. If the catch handler handles a ```std::exception```, the program returns 1.

The line

```cpp
boost::asio::io_context io;
```

defines an instance of the asio library's ```io_context``` class. It provides core synchronous and asynchronous I/O functionality. More information about ```io_context``` can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/io_context.html).

The line

```cpp
boost::asio::ip::basic_resolver<boost::asio::ip::tcp> resolver(io);
```

defines a tcp-type instance of the asio library's ```basic_resolver``` class template. It provides the ability to resolve a query to a list of endpoints. More information about ```basic_resolver``` can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/ip__basic_resolver.html).

The line

```cpp
boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> query("127.0.0.1", "9601");
```

defines a tcp-type instance of the asio library's ```basic_resolver_query``` class template. It describes a query that can be passed to a resolver. More information about ```basic_resolver_query``` can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/ip__basic_resolver_query.html).

The line

```cpp
boost::asio::ip::basic_resolver_results<boost::asio::ip::tcp> end_point = resolver.resolve(query);
```

defines a tcp-type instance of the asio library's ```basic_resolver_results``` class template. It defines a range over the results returned by a resolver. More information about ```basic_resolver_results``` can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/ip__basic_resolver_results.html).

The line

```cpp
boost::asio::basic_stream_socket<boost::asio::ip::tcp> socket(io);
```

defines an tcp-type instance of the asio library's ```basic_stream_socket``` class template. It provides synchronous and asynchronous stream-orientated socket functionality. More information about ```basic_stream_socket``` can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/basic_stream_socket.html).

The line

```cpp
boost::asio::connect(socket, end_point);
```

establishes a socket connection with the endpoint. ```connect()``` is a template function and has 12 overloads. Here, it is used with two parameters, ```basic_socket<Protocol, Executor>& s``` and ```const EndpointSequence& endpoints```, and returns the successfully connected endpoint. ```s``` is the socket to be connected. ```endpoints``` is a sequence of endpoints. More information about ```connect()``` can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/connect.html).

The line

```cpp
std::string message{ "Hello World!\r\n" };
```

defines an instance of a string. In this sample, "Hello World!\r\n" is the message that is sent to the endpoint.

The line

```cpp
boost::asio::const_buffer buffer = boost::asio::buffer(message);
```

defines an instance of the asio library's ```const_buffer``` class. It holds a buffer that cannot be modified. Here, the asio library's ```buffer()``` is used used to create a non-modifiable buffer from an existing string. ```buffer``` is a template function and has 32 overloads. Here, it is used with one parameter, ```const std::basic_string<Elem, Traits, Allocator>& data```, and returns a ```const_buffer``` buffer. More information about ```buffer()``` can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/buffer.html).

The block

```cpp
try {

    boost::asio::write(socket, buffer);

}
catch (std::exception& e) {

    std::cout << e.what() << std::endl;

}
```

defines a try block and a catch block. In this block, we try to write the buffer to the connected socket. If an exception is raised, the program's execution proceeds to the catch handler, and displays the exception to the user. Here, the asio library's ```write()``` is used to write all the supplied data to a stream before returning. ```write()``` is a template function and has 16 overloads. Here, it is used with two parameters, ```SyncWriteStream& s``` and ```const ConstBufferSequence& buffers```, and returns a ```size_t``` value of bytes written. More information about ```write()``` can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/write.html). 

Note, it's worth wrapping ```write()``` in a try block and a catch block. Consider the case where the endpoint doesn't accept a connection, e.g. the server running on the endpoint may not have started: ```write()``` will throw an exception; which, if not caught, will cause your program to abort. Catching the exception will allow you to do something more useful, e.g. trying to connect with the server again in 10 minutes.

The line

```cpp
socket.close();
```

uses ```socket```'s ```close``` member function to close the connected socket.