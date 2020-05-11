## Compiling Your Protocol Buffers

Type the following into your command prompt and press <kbd>Enter</kbd>

    protoc -I="." --cpp_out="." person.proto

Afterwards, `person.pb.cc` and `person.pb.h` will be created in the current directory.