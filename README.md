# Introduction

This project demonstrates how to log messages t a remote logging system from an Arudiono.

For this example we use Papertrail - https://www.papertrail.com/

[![Demo Video](https://img.youtube.com/vi/GLoXRyAtytY/0.jpg)](https://www.youtube.com/watch?v=GLoXRyAtytY)

# Setup

Sign up for a free Papertail account and click the "Add System" to get your host and port number.

Update the file papertrail_credentials.h with the correct values:

```c
#define PAPERTRAIL_HOST "<REPLACE_ME>"
#define PAPERTRAIL_PORT <REPLACE_ME>
```

Update the file `wifi_credentials.h` with your SSID and PASSWORD.

```c
#define SSID "YOUR_SSID"
#define PASSWORD "YOUR_PASSWORD"
```

Now just compile and run the sketch.

You should see messages appear in Papertrail.
