# Demo/sample for GoogleTest/gMock

This is a demo for using GoogleTest/gMock on a trivially simple project - an Internet connected pet door controller.

A pet door controller listens for tag scans from the RFID tag reader. Each tag's UID is verified against a database in the Internet - if the database returns true, then it's our pet and the controller opens the door. If the dabase returns false, then it's someone else's pet and we close the door.

There are a total of 4 units.

- `PetSec` is the controller implementing the logic of the project.
- `TagReader` is the RFID reader. Upon scanning a tag it calls an event handler with composite string "UID:PetName".
- `Database` holds the database of pet UID-s and can be queried for ownership. It's hardcoded so that we own pet with UID "DEADBEEF".
- `Door` is the pet door.

## Build and run the main application

The main application is built using CMake and whatever compiler you have installed:

```
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
```

To run it, pass a string argument with format "UID:pet name" which imitates a single RFID scan.

```
$ ./pet_sec "FOOFBAAB:Stray Cat"
Stray Cat: unknown pet, shooo!
Close door
$ ./pet_sec "DEADBEEF:Kitty the cat"
Kitty the cat: is my pet, welcome
Open door
```

## Build and run the unit test

Built similarly to the main application:

```
$ mkdir ut/build && cd ut/build
$ cmake ..
$ cmake --build .
```

To run the unit test:

```
$ ./pet_sec
```

# Documentation

[Tutorial and reference for GoogleTest and gMock](https://google.github.io/googletest/)
