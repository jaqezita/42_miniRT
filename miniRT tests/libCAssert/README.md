# libCAssert

Did you know that C has a macro function that checks a test for you? Well it doesn't work very well because if something wents wrong it will abort the program, so i decided to make this library.   

<img src="https://github.com/andreyvdl/libCAssert/assets/81233149/820a9c2b-2c5f-434b-992e-791c7140ac55">   


## Dependencies

* C compiler (gcc, clang, cc, etc);   
* 64 bits system (because all tests with int will be using int64_t);   

## Compile it

```sh
git clone https://github.com/andreyvdl/libCAssert
cd libCAssert
make
```

Now move the `libcassert.a` to any project you want to use it.   
You can also combine it to another `.a` that you are using in your project by rename/copy it or by:   

```sh
ar -x libcassert.a
mv *.o /path/where/you/want
```

## THE FUCKING MANUAL

You can do quick tests and group tests:    

### Group

Group tests are for pointers, int64_t and doubles.   
They receive an array of instances (t_inst), two arrays of their type (one for your results and the other for your expects) and the size of these arrays (if the size is wrong the behaivor is undefined).   
Group tests only print the title and description of the first instance (instance\[0]).   

### Quick

Quick tests are almost equal to Group tests, but don't receive arrays nor the size (for obvious reasons).   
Quick tests will always print the title and description of their instance.   

### Typedefs

There are 2 structs and 1 enum:   

* `t_comp` an enum that represents less-equal than (<=), less than (<), equal (==), greater than (>) and greater-equal than (>=), (different (!=) was not added because is just the oposite of equal).   
* `t_text` a struct that contains a text field and a color field (macros for the colors are on libassert.h, if you want to use your own colors the program expects an ANSI pattern).   
* `t_inst` the main struct for instances, it takes 4 t_texts for title, description, ok message and ko messages, and a t_comp with the comparision type of that instance.   
