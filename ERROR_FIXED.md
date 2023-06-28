# The ways how I fixed the errors MEMO
## redefinition of '~'
1. write `#pragma once` at the begining of all HPP files
2. make sure that same files aren't included in a file
### reference : https://nonbiri-tereka.hatenablog.com/entry/2014/02/10/102221

## undefined refernce to 'vtable for ~'
1. maybe you defined virtual deconstructor without details
```c++
class Character {
    private:
    public:
        Character() {};
        // define with {}
        virtual ~Character() {};
}
```
