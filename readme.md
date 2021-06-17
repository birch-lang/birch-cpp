# Birch C++

This is an experimental version of the birch programming language, written in C++.
The python version is about to be deprecated, so expect all of the new features to
be implemented here rather than there. 

## Contributing

To contribute, just fork the repo and create a pull request!

I need to work on creating a formal style guide, but for now just look at the code
and follow that. The only really big things that I would like to see are these:

```cpp
// Bracket style:
void doSomething() {
    // variable style:
    int camelCase = 42;

    // pointer/reference style:
    std::string* hello;
}

// And for classes, please use this:
class SomethingOrOther : smth() {};
// Rather than this:
class SomethingOrOther
: smth() {};
````
