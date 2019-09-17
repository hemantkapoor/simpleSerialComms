# Simple Serial Comms

Simple Serial Comms is a C++ 11 project which spawns a thread to read serial raw data and output to standard console..

## Installation

It is a cmake project.

```bash
cmake .
```

To make the file

```bash
make 
```
To install

```bash
make install
```


## Usage

```bash
./bin/simpleSerialComms
```

## TEST

You can create virtual serial port by using
 
```bash
socat -d -d pty,raw,echo=0 pty,raw,echo=0
```

and use minicom to interact and test
 
```bash
minicom -D /dev/pts/<port number> 
```


## Upcoming changes

* <s>Ability to transmit data</s> - Implemented on 17-September-2019 
* Add version number
* Ability to have a callback on received message
* Serial Comms setting via config.txt
* Debug class to output messages based on levels


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
