## DSAcourse

this is my Data Structure Class implementation respository.

there are two mainly implementation, one is written in C, and another one is written in Rust which is not being ask to do in class but i did myself.

----

## How to build?

build system: meson

```shell
$ sudo apt-get install meson
```

after install meson and understood what ninja does, you can use

```shell
$ meson build
$ ninja -C build
// execute the program
$ ./build/dsa.out
```

for building and executing. The "build" in the script is the target folder name, you can name whatever you want, and once the meson command been executed, you don't need to do it again, just start from ninja line and the rebuild will work unless changing directory.

----

## Directory tree

below are the implementation that have been made:

- [x] linkedlist
    - [ ] doublylinkedlist
    - [ ] circularlinkedlist
- [x] queue
- [x] stack
- [x] sparsematrix
- [ ] binarytree
    - [ ] threadedbinarytree
    - [x] completebinarytree
    - [ ] avltree
    - [ ] blackredtree
- [ ] heap
    - [ ] maxheap
    - [ ] minheap
- [ ] sorting
    - [ ] quicksort
    - [ ] mergesort
    - [ ] insertionsort
