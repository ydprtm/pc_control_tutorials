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

defines a try block and a catch block. In this block, we try to write the buffer to the connected socket. If an exception is raised, the program's execution proceeds to the catch handler, and displays the exception to the user. Here, the asio library's ```write()``` is used to write all the supplied data to a stream before returning. ```write()``` is a template function and has 16 overloads. Here, it is used with two parameters, ```SyncWriteStream& s``` and ```const ConstBufferSequence& buffers```, and returns a ```size_t``` of bytes written. More information about ```write()``` can be found [here](https://www.boost.org/doc/libs/1_70_0/doc/html/boost_asio/reference/write.html). 

Note, it's worth wrapping ```write()``` in a try block and a catch block. Consider the case where the endpoint doesn't accept a connection, e.g. the server running on the endpoint may not have started: ```write()``` will throw an exception; which, if not caught, will cause your program to abort. Catching the exception will allow you to do something, e.g. try communicating again in 10 minutes.

The line

```cpp
socket.close();
```

uses ```socket```'s ```close``` member function to close the connected socket.