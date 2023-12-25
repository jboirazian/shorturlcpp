# shorturlcpp
A tinyurl dashboard that uses C++ and HTMX 


## Prerequisites

Before running the program, make sure you have the following:

- g++ (GNU C++ compiler)
- libpthread (POSIX threads library)
- libjsoncpp (JSON library for C++)
- libcurl (URL transfer library)
- TinyURL API token (Get it from [TinyURL Developer](https://tinyurl.com/tools/apideveloper))

## Building

To build the ShortURLCPP executable, run the following command:

```bash
make
```

This will compile the program using g++ with the necessary flags.

## Set TinyURL API Token

Export your TinyURL API token as an environment variable:

```bash
export TINYURL_TOKEN=YOUR_TOKEN_HERE
```

Replace `YOUR_TOKEN_HERE` with your actual TinyURL API token.

## Running

Once the program is built and the token is set, run the executable:

```bash
./shorturlcpp
```

This will execute the ShortURLCPP program and use the TinyURL API to shorten a URL