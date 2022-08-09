<h3 align="center">42 São Paulo - Labs, 3rd Edition</h3>

<div align="center">

![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/librity/ft_labs_v3?color=yellow)
![Code size in bytes](https://img.shields.io/github/languages/code-size/librity/ft_labs_v3?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/librity/ft_labs_v3?color=blueviolet)
![Top language](https://img.shields.io/github/languages/top/librity/ft_labs_v3?color=ff69b4)
![Last commit](https://img.shields.io/github/last-commit/librity/ft_labs_v3?color=orange)

</div>

<div align="center">

[![Build](https://github.com/librity/ft_labs_v3/actions/workflows/build.yml/badge.svg)](https://github.com/librity/ft_labs_v3/actions/workflows/build.yml)
[![Norminette v3](https://github.com/librity/ft_labs_v3/actions/workflows/norminette_v3.yml/badge.svg)](https://github.com/librity/ft_labs_v3/actions/workflows/norminette_v3.yml)

</div>

<p align="center"> A network monitoring service with <code>pthreads</code> in pure C.
  <br>
</p>

---

## 📜 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Checklist](#checklist)
- [42 São Paulo](#ft_sp)
- [Resources](#resources)

## 🧐 About <a name = "about"></a>

<!-- - [Specs (English)](./.github/specs_en.md) -->
- [Specs (Portuguese)](./.github/specs_pt.md)

This is a network monitor that periodically sends request
and saves the results to a `.log` file.
It currently handles `HTTP`, `HTTPS`, `PING` and `DNS` requests.

It can be configured im multiple ways with the `monitoring.db` file.
Each line in the file specifies a target, protocol,
and request frequency (period between requests).
Columns are tab-separated and must conform to the format:

```elixir
====================================================================================================
| PROTOCOL | ROWS (tab separated)                                                                  |
====================================================================================================
| HTTP     | name    HTTP     address    http_method    expected_http_code    frequency_in_seconds |
| HTTPS    | name    HTTPS    address    http_method    expected_http_code    frequency_in_seconds |
| PING     | name    PING     address    frequency_in_seconds                                      |
| DNS      | name    DNS      address    frequency_in_seconds        dns_server_ipv4               |
====================================================================================================
```

The program parses the file and spawns a scheduler thread for each target
that periodically enqueues a new request in the request pool.
It also spawns worker threads that dequeue and perform the requests.

The worker then prints a simplified result of the request to `STDOUT`
and saves all the relevant data to the specified `.log` file.

It can also parse the log file and print it to `STDOUT`
in simple form with the flag `--simplify`.

The thread pool implementation is based on CodeVault's video:

- https://www.youtube.com/watch?v=_n2hE2gyPxU&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=28

I handled `HTTPS` request with `libcurl`,
and made my own implementation of `HTTP`, `PING` and `DNS` based on:

- https://www.youtube.com/watch?v=bdIiTxtMaKA&list=PL9IEJIKnBJjH_zM5LnovnoaKlXML5qh17&index=2
- https://www.geeksforgeeks.org/ping-in-c/
- https://www.theinsanetechie.in/2016/02/dns-lookup-implementation-in-c.html

This program uses Raw Sockets for the `PING` implementation
and must be executed with root privileges
(or any other user with `CAP_NET_ADMIN` capability).

## 🏁 Getting Started <a name = "getting_started"></a>

### ⚙️ Prerequisites

To compile and run this program you will need:

- A shell and a C compiler (`gcc` ideally).
- `GNU Make` installed in your computer.

You will also need to install `libcurl` as a dev dependency.
You can get it through apt-get (recommended):

```bash
$ sudo apt-get install libcurl4-openssl-dev
```

Or you can install it manually:

```bash
$ wget https://curl.se/download/curl-7.84.0.zip
$ unzip curl-7.84.0.zip
$ cd curl-7.84.0
$ ./configure --with-openssl --prefix=$HOME/.local
$ make
$ make install
```

### 🖥️ Installing

Clone the repo and build with `make`:

```bash
$ git clone --recurse-submodules https://github.com/42sp/ft_labs_v3.git ft_labs_v3
$ cd ft_labs_v3
$ make
```

It should create a `monitoring` executable that you can run with `sudo ./monitoring`.

### 🏳️ Options and Flags

- `-h` and `--help`: Print the help message.
- `-s` and `--simplify`: Parse the `.log` file and print it to `STDOUT` in simple form.
- `-d` and `--debug`: Verbose, prints debug throughout runtime.
- `--config-file <file>`: Specify the config file path (default `./monitoring.db`).
- `--log-file <file>`: Specify the log file path (default `./monitoring.log`).
- `--workers <number>`: Set the initial number of worker threads (default `8`).

## ✅ Checklist <a name = "checklist"></a>

### Mandatory

- [x] Follows `norminette 3.3.51`
- [x] Makefile rules: `$(NAME)` `all` `clean` `fclean` `re`
- [x] Compile an executable named `monitoring`.
- [x] Compiles with `-Wall -Wextra -Werror`
- [x] Should not quit unexpectedly (segmentation fault, bus error, double free, etc.)
- [x] All allocated heap memory properly freed, no memory leaks.
  - [x] Check memory leaks with `valgrind`
- [x] Allowed functions:
  - [x] Anything you want, as long as you can reasonably justify it.
- [x] Handle flags
  - [x] `-h` and `—help` display help message and exits cleanly.
  - [x] `-s` and `—simplify` reads the log file, prints it in simple form to `STDOUT` and exits cleanly.
  - [x] `-d` and `—debug` flags that print debug info through runtime.
  - [x] `—config-file <file>` Set the config file path (default `./monitoring.db`)
  - [x] `--log-file <file>` Set the log file path (default `./monitoring.log`)
  - [x] `--workers <number>` Set the initial number of worker threads (default `8`).
- [x] Validate config file `monitoring.db`:
  - [x] Handle comments with `#`.
  - [x] Validate `HTTP` configs:
    - [x] Should have 6 tab-separated fields
    - [x] Validate `HTTP_METHOD`.
    - [x] Validate expected `HTTP_CODE`.
    - [x] Validate timeout in seconds (`unsigned int` > 0).
  - [x] Validate `PING` configs:
    - [x] Should have 4 tab-separated fields
    - [x] Validate timeout in seconds (`unsigned int` > 0).
  - [x] Validate `DNS` configs:
    - [x] Should have 5 tab-separated fields
    - [x] Validate timeout in seconds (`unsigned int` > 0).
    - [x] Validate IPv4 address
- [x] Parse configs for each protocol:
  - [x] Parse `HTTP` targets
  - [x] Parse `PING` targets
  - [x] Parse `DNS` targets
- [x] Each monitoring service/request must use the configurations defined in `monitoring.db`.
- [x] Handle request with a Thread Pool
  - [x] Spawn workers that:
    - [x] Dequeue task safely (`mutex` and `cond`)
    - [x] Perform network requests
    - [x] Display the simplified result to `STDOUT`.
    - [x] Save all relevant request data to log file in parsable form.
  - [x] Spawn a scheduler for every target in config file:
    - [x] Enqueue target request safely (`mutex` and `cond`)
    - [x] Enqueue every `timeout` seconds.
  - [x] All threads exit cleanly and join main thread on `CONTROL+Q` with no deadlocks.
    - [x] Enable tty raw mode and manually handle key presses.
- [x] Requests:
  - [x] `HTTP`
    - [x] Get IP with **`getaddrinfo()`**
    - [x] My own implementation with `sys/socket.h`
    - [x] Save all relevant request data to log file in parsable form.
  - [x] `HTTPS`
    - [x] Use `libcurl` for the entire thing
    - [x] Save all relevant request data to log file in parsable form.
  - [x] `PING`
    - [x] Get IP with **`getaddrinfo()`**
    - [x] My own implementation with `sys/socket.h`
    - [x] Save all relevant request data to log file in parsable form.
  - [x] `DNS`
    - [x] My own implementation with `sys/socket.h`
    - [x] Save all relevant request data to log file in parsable form.
- [x] `monitoring.log` should contain all available request data.
- [x] `monitoring.log` should be saved in parsable form, such that it can be displayed simply with the `--simplify` flag.
- [x] Should work as an useful and professional network monitoring service.
- [x] Clean and readable code.
- [x] Add a beautiful `README.md` explaining how the program works.
- [x] Come up with simple and creative solutions.
- [x] Follow specs as much as possible.

### Bonus

- [x] Parse add extra flags
  - [x] Add help message.
  - [x] Set custom config path.
  - [x] Set custom log path.
- [x] Take special care with optimizations, code quality and design patterns.
- [x] Use external tools to plan and track various stages of development.
- [ ] Notify bad request through Discord, email, Slack or Webhook.
- [ ] Thoroughly test the application:
  - [ ] Flag tests
  - [ ] Config tests
  - [ ] Thread Pool tests
  - [ ] Request handler tests
  - [ ] Logger tests
- [ ] Identifies odd behaviors in target services, like and increase in latency.
- [ ] Aggregate analysis of `monitoring.log` data, with diagrams and graphs on the CLI.
- [ ] Handle `MQTT` and `TCP` requests/monitoring:
  - [ ] `TCP`
    - [ ] My own implementation with `sys/socket.h`
    - [ ] Save all relevant request data to log file in parsable form.
  - [ ] `MQTT`
    - [ ] Use `libcurl` for the entire thing
    - [ ] Save all relevant request data to log file in parsable form.
- [ ] Supervisor threads:
  - [ ] Restart worker and scheduler threads that exit with an error.

## 🛸 42 São Paulo <a name = "ft_sp"></a>

Part of the larger [42 Network](https://www.42.fr/42-network/),
[42 São Paulo](https://www.42sp.org.br/) is a software engineering school
that offers a healthy alternative to traditional education:

- It doesn't have any teachers and classes.
- Students learn by cooperating
  and correcting each other's work (peer-to-peer learning).
- Its focus is as much on social skills as it is on technical skills.
- It's completely free to anyone that passes its selection process -
  [**The Piscine**](https://42.fr/en/admissions/42-piscine/)

It's an amazing school, and I'm grateful for the opportunity.

## 📚 Resources <a name = "resources"></a>

### `HTTP` and `HTTPS`

- [https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol](https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol)
- [https://developer.mozilla.org/en-US/docs/Web/HTTP/Status](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)
- [https://en.wikipedia.org/wiki/List_of_HTTP_status_codes](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes)
- [https://stackoverflow.com/questions/5133968/using-libcurl-to-monitor-state-of-a-network](https://stackoverflow.com/questions/5133968/using-libcurl-to-monitor-state-of-a-network)

### `HTTP` Methods

- [https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods)
- [https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/POST#example](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/POST#example)
- [https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/GET#syntax](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/GET#syntax)

### `HTTP` Headers

- [https://stackoverflow.com/questions/69998964/http-headers-as-string-which-delimiter-to-use/70005319](https://stackoverflow.com/questions/69998964/http-headers-as-string-which-delimiter-to-use/70005319)
- [https://datatracker.ietf.org/doc/html/rfc7230#section-3](https://datatracker.ietf.org/doc/html/rfc7230#section-3)
- [https://medium.com/swlh/looking-under-the-hood-http-over-tcp-sockets-952a944c99da](https://medium.com/swlh/looking-under-the-hood-http-over-tcp-sockets-952a944c99da)

### `HTTP` Implementations

- [https://stackoverflow.com/questions/30470505/http-request-using-sockets-in-c](https://stackoverflow.com/questions/30470505/http-request-using-sockets-in-c)
- [https://www.youtube.com/watch?v=bdIiTxtMaKA&list=PL9IEJIKnBJjH_zM5LnovnoaKlXML5qh17&index=2](https://www.youtube.com/watch?v=bdIiTxtMaKA&list=PL9IEJIKnBJjH_zM5LnovnoaKlXML5qh17&index=2)
- [https://stackoverflow.com/questions/30470505/http-request-using-sockets-in-c](https://stackoverflow.com/questions/30470505/http-request-using-sockets-in-c)

### `PING`

- [https://en.wikipedia.org/wiki/Ping\_(networking_utility)](<https://en.wikipedia.org/wiki/Ping_(networking_utility)>)
- [https://www.geeksforgeeks.org/internet-control-message-protocol-icmp/](https://www.geeksforgeeks.org/internet-control-message-protocol-icmp/)
- [https://www.opensourceforu.com/2015/03/a-guide-to-using-raw-sockets/](https://www.opensourceforu.com/2015/03/a-guide-to-using-raw-sockets/)
- [https://www.geeksforgeeks.org/error-detection-in-computer-networks/](https://www.geeksforgeeks.org/error-detection-in-computer-networks/)
- [https://www.geeksforgeeks.org/domain-name-system-dns-in-application-layer/](https://www.geeksforgeeks.org/domain-name-system-dns-in-application-layer/)
- [https://en.wikipedia.org/wiki/Internet_Control_Message_Protocol](https://en.wikipedia.org/wiki/Internet_Control_Message_Protocol)
- [https://curl.se/mail/lib-2012-11/0103.html](https://curl.se/mail/lib-2012-11/0103.html)

### `PING` Implementations

- [https://www.geeksforgeeks.org/ping-in-c/](https://www.geeksforgeeks.org/ping-in-c/)
- [https://github.com/sryze/ping/blob/master/src/ping.c](https://github.com/sryze/ping/blob/master/src/ping.c)
- [https://stackoverflow.com/questions/9688899/sending-icmp-packets-in-a-c-program](https://stackoverflow.com/questions/9688899/sending-icmp-packets-in-a-c-program)
- [https://www.mycplus.com/source-code/c-source-code/ping/](https://www.mycplus.com/source-code/c-source-code/ping/)
- [https://github.com/a-khakimov/ping](https://github.com/a-khakimov/ping)
- [https://github.com/sryze/ping](https://github.com/sryze/ping)

### `DNS`

- [https://en.wikipedia.org/wiki/Domain_Name_System](https://en.wikipedia.org/wiki/Domain_Name_System)
- [https://stackoverflow.com/questions/1128409/how-might-i-perform-dns-lookups-using-c-c-on-linux](https://stackoverflow.com/questions/1128409/how-might-i-perform-dns-lookups-using-c-c-on-linux)

### `DNS` Implementations

- [https://gist.github.com/deltheil/6183330](https://gist.github.com/deltheil/6183330)
- [https://programmersought.com/article/85444274234/](https://programmersought.com/article/85444274234/)
- [https://www.binarytides.com/dns-query-code-in-c-with-linux-sockets/](https://www.binarytides.com/dns-query-code-in-c-with-linux-sockets/)
- [https://www.theinsanetechie.in/2016/02/dns-lookup-implementation-in-c.html](https://www.theinsanetechie.in/2016/02/dns-lookup-implementation-in-c.html)
- [https://gist.github.com/fffaraz/9d9170b57791c28ccda9255b48315168](https://gist.github.com/fffaraz/9d9170b57791c28ccda9255b48315168)

### `DNS` Libs

- [https://man7.org/linux/man-pages/man3/gethostbyname.3.html](https://man7.org/linux/man-pages/man3/gethostbyname.3.html)
- [https://linux.die.net/man/3/res_query](https://linux.die.net/man/3/res_query)
- [https://github.com/rofl0r/firedns](https://github.com/rofl0r/firedns)

### `MQTT`

- [https://mqtt.org/](https://mqtt.org/)
- [https://en.wikipedia.org/wiki/MQTT](https://en.wikipedia.org/wiki/MQTT)
- [https://mongoose.ws/documentation/#mg_mqtt_ping](https://mongoose.ws/documentation/#mg_mqtt_ping)
- [http://www.steves-internet-guide.com/mqtt/](http://www.steves-internet-guide.com/mqtt/)

### `TCP`

- [https://stackoverflow.com/questions/57950145/is-it-possible-to-use-libcurl-to-manage-raw-tcp-connections](https://stackoverflow.com/questions/57950145/is-it-possible-to-use-libcurl-to-manage-raw-tcp-connections)
- [https://curl.se/libcurl/c/sendrecv.html](https://curl.se/libcurl/c/sendrecv.html)

### **[`getaddrinfo](https://gist.github.com/jirihnidek/bf7a2363e480491da72301b228b35d5d#file-getaddrinfo_example-c)()`**

- [https://en.wikipedia.org/wiki/Getaddrinfo](https://en.wikipedia.org/wiki/Getaddrinfo)
- [https://man7.org/linux/man-pages/man3/getaddrinfo.3.html](https://man7.org/linux/man-pages/man3/getaddrinfo.3.html)
- [https://gist.github.com/jirihnidek/bf7a2363e480491da72301b228b35d5d](https://gist.github.com/jirihnidek/bf7a2363e480491da72301b228b35d5d)
- [http://alas.matf.bg.ac.rs/manuals/lspe/snode=77.html](http://alas.matf.bg.ac.rs/manuals/lspe/snode=77.html)
- [https://stackoverflow.com/questions/755308/whats-the-hints-mean-for-the-addrinfo-name-in-socket-programming](https://stackoverflow.com/questions/755308/whats-the-hints-mean-for-the-addrinfo-name-in-socket-programming)

### `arpa/inet.h`

- [https://stackoverflow.com/questions/318236/how-do-you-validate-that-a-string-is-a-valid-ipv4-address-in-c](https://stackoverflow.com/questions/318236/how-do-you-validate-that-a-string-is-a-valid-ipv4-address-in-c)
- [https://man7.org/linux/man-pages/man3/inet_pton.3.html](https://man7.org/linux/man-pages/man3/inet_pton.3.html)
- [https://linux.die.net/man/3/inet_addr](https://linux.die.net/man/3/inet_addr)

### `sockaddr_in`

- [https://programmersought.com/article/76814417359/](https://programmersought.com/article/76814417359/)
- [https://stackoverflow.com/questions/23146286/how-to-initialize-sockaddr-in-using-addrinfo](https://stackoverflow.com/questions/23146286/how-to-initialize-sockaddr-in-using-addrinfo)
- [https://pubs.opengroup.org/onlinepubs/009695399/functions/inet_pton.html](https://pubs.opengroup.org/onlinepubs/009695399/functions/inet_pton.html)
- [https://stackoverflow.com/questions/1705885/why-inet-ntoa-is-designed-to-be-a-non-reentrant-function](https://stackoverflow.com/questions/1705885/why-inet-ntoa-is-designed-to-be-a-non-reentrant-function)

### `sys/socket.h`

- [https://man7.org/linux/man-pages/man2/connect.2.html](https://man7.org/linux/man-pages/man2/connect.2.html)
- [https://man7.org/linux/man-pages/man7/tcp.7.html](https://man7.org/linux/man-pages/man7/tcp.7.html)
- [https://linux.die.net/man/7/socket](https://linux.die.net/man/7/socket)
- [https://man7.org/linux/man-pages/man7/socket.7.html](https://man7.org/linux/man-pages/man7/socket.7.html)

### Time to Live

- [https://en.wikipedia.org/wiki/Time_to_live](https://en.wikipedia.org/wiki/Time_to_live)

### **`CAP_NET_ADMIN` and** `SOCK_RAW`

- [https://man7.org/linux/man-pages/man7/capabilities.7.html](https://man7.org/linux/man-pages/man7/capabilities.7.html)
- [https://stackoverflow.com/questions/30780082/sock-raw-option-in-socket-system-call](https://stackoverflow.com/questions/30780082/sock-raw-option-in-socket-system-call)
- [https://linux.die.net/man/7/raw](https://linux.die.net/man/7/raw)
- [https://www.tenouk.com/Module43a.html](https://www.tenouk.com/Module43a.html)
- [https://austinmarton.wordpress.com/2011/09/14/sending-raw-ethernet-packets-from-a-specific-interface-in-c-on-linux/](https://austinmarton.wordpress.com/2011/09/14/sending-raw-ethernet-packets-from-a-specific-interface-in-c-on-linux/)

### `sys/capability.h`

- [https://man7.org/linux/man-pages/man3/libcap.3.html](https://man7.org/linux/man-pages/man3/libcap.3.html)
- [https://man7.org/linux/man-pages/man3/cap_from_text.3.html](https://man7.org/linux/man-pages/man3/cap_from_text.3.html)
- [https://stackoverflow.com/questions/8338379/ubuntu-and-libcap-capabilities-undefined-reference](https://stackoverflow.com/questions/8338379/ubuntu-and-libcap-capabilities-undefined-reference)
- [https://gist.github.com/sbz/1090868](https://gist.github.com/sbz/1090868)
- [http://unixetc.co.uk/2016/05/30/linux-capabilities-and-ping/](http://unixetc.co.uk/2016/05/30/linux-capabilities-and-ping/)

### `setsockopt()`

- [https://stackoverflow.com/questions/2876024/linux-is-there-a-read-or-recv-from-socket-with-timeout](https://stackoverflow.com/questions/2876024/linux-is-there-a-read-or-recv-from-socket-with-timeout)
- [https://linux.die.net/man/3/setsockopt](https://linux.die.net/man/3/setsockopt)

### `pthread.h`

- [https://en.wikipedia.org/wiki/Pthreads](https://en.wikipedia.org/wiki/Pthreads)
- [https://www.geeksforgeeks.org/thread-functions-in-c-c/](https://www.geeksforgeeks.org/thread-functions-in-c-c/)
- https://www.man7.org/linux/man-pages/man0/pthread.h.0p.html
- https://iq.opengenus.org/multithreading-and-pthread-in-c/
- https://www.geeksforgeeks.org/multithreading-c-2/
- https://www.tutorialspoint.com/multithreading-in-c
- https://github.com/samuelpio01/multithreading-in-c/blob/master/pthread_multithreading.c
- [https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [https://www.youtube.com/watch?v=9axu8CUvOKY](https://www.youtube.com/watch?v=9axu8CUvOKY)

### `pthread_create`

- [https://man7.org/linux/man-pages/man3/pthread_create.3.htmlhttps://man7.org/linux/man-pages/man3/pthread_create.3.html](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
- [http://www.cse.cuhk.edu.hk/~ericlo/teaching/os/lab/9-PThread/Pass.html](http://www.cse.cuhk.edu.hk/~ericlo/teaching/os/lab/9-PThread/Pass.html)
- [https://stackoverflow.com/questions/39117674/how-to-pass-arguments-when-using-pthread-create](https://stackoverflow.com/questions/39117674/how-to-pass-arguments-when-using-pthread-create)

### **`pthread_detach**()`

- [https://man7.org/linux/man-pages/man3/pthread_detach.3.html](https://man7.org/linux/man-pages/man3/pthread_detach.3.html)

### `pthread_mutex_t`

- [https://linux.die.net/man/3/pthread_mutex_init](https://linux.die.net/man/3/pthread_mutex_init)
- [https://stackoverflow.com/questions/20487752/how-to-handle-error-conditions-of-pthread-mutex-destroy](https://stackoverflow.com/questions/20487752/how-to-handle-error-conditions-of-pthread-mutex-destroy)

### **`pthread_cond_t`**

- [https://linux.die.net/man/3/pthread_cond_init](https://linux.die.net/man/3/pthread_cond_init)
- [https://manpages.org/pthread_cond_timedwait/3](https://manpages.org/pthread_cond_timedwait/3)
- [https://linux.die.net/man/3/pthread_cond_init](https://linux.die.net/man/3/pthread_cond_init)
- [https://stackoverflow.com/questions/11000331/how-does-pthread-cond-broadcast-works](https://stackoverflow.com/questions/11000331/how-does-pthread-cond-broadcast-works)
- [https://linux.die.net/man/3/pthread_cond_broadcast](https://linux.die.net/man/3/pthread_cond_broadcast)
- [https://linux.die.net/man/3/pthread_mutex_destroy](https://linux.die.net/man/3/pthread_mutex_destroy)
- [https://docs.oracle.com/cd/E19455-01/806-5257/6je9h032r/index.html](https://docs.oracle.com/cd/E19455-01/806-5257/6je9h032r/index.html)

### `pthread_exit()`

- [https://www.thegeekstuff.com/2012/04/terminate-c-thread/](https://www.thegeekstuff.com/2012/04/terminate-c-thread/)
- [https://stackoverflow.com/questions/12207684/how-do-i-terminate-a-thread-in-c11](https://stackoverflow.com/questions/12207684/how-do-i-terminate-a-thread-in-c11)
- [https://stackoverflow.com/questions/16320838/when-do-i-really-need-to-use-atomicbool-instead-of-bool](https://stackoverflow.com/questions/16320838/when-do-i-really-need-to-use-atomicbool-instead-of-bool)

### **`pthread_cancel**()`

- [https://man7.org/linux/man-pages/man3/pthread_cancel.3.html](https://man7.org/linux/man-pages/man3/pthread_cancel.3.html)
- [https://stackoverflow.com/questions/15641145/thread-cancel-and-blocking-function-as-cond-wait](https://stackoverflow.com/questions/15641145/thread-cancel-and-blocking-function-as-cond-wait)
- [https://linux.die.net/man/3/pthread_cleanup_push](https://linux.die.net/man/3/pthread_cleanup_push)
- [https://man7.org/linux/man-pages/man3/pthread_setcanceltype.3.html](https://man7.org/linux/man-pages/man3/pthread_setcanceltype.3.html)
- [https://stackoverflow.com/questions/20304366/how-to-fix-gcc-error-expected-while-before-void](https://stackoverflow.com/questions/20304366/how-to-fix-gcc-error-expected-while-before-void)

### _`pthread_key_create_()`

- [https://linux.die.net/man/3/pthread_key_create](https://linux.die.net/man/3/pthread_key_create)

### Request Scheduling Options

- [ ] `while`/`sleep`
- [ ] `timer_create`
- [ ] Wild threads
- [x] Thread Pool + Thread Schedulers + Thread Supervisor

### Thread Pools

- [https://en.wikipedia.org/wiki/Thread_pool](https://en.wikipedia.org/wiki/Thread_pool)
- [https://github.com/ericomeehan/libeom/blob/main/Systems/ThreadPool.c](https://github.com/ericomeehan/libeom/blob/main/Systems/ThreadPool.c)
- [https://github.com/Pithikos/C-Thread-Pool](https://github.com/Pithikos/C-Thread-Pool)
- [https://nachtimwald.com/2019/04/12/thread-pool-in-c/](https://nachtimwald.com/2019/04/12/thread-pool-in-c/)
- [https://stackoverflow.com/questions/15752659/thread-pooling-in-c11](https://stackoverflow.com/questions/15752659/thread-pooling-in-c11)
- [https://www.youtube.com/watch?v=\_n2hE2gyPxU&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=29](https://www.youtube.com/watch?v=_n2hE2gyPxU&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=29)
- [https://www.youtube.com/watch?v=w6dQQt10Dxo](https://www.youtube.com/watch?v=w6dQQt10Dxo)
- [https://www.youtube.com/watch?v=Pg_4Jz8ZIH4](https://www.youtube.com/watch?v=Pg_4Jz8ZIH4)
- [https://www.youtube.com/watch?v=WmDOHh7k0Ag](https://www.youtube.com/watch?v=WmDOHh7k0Ag)
- [https://www.youtube.com/watch?v=FMNnusHqjpw](https://www.youtube.com/watch?v=FMNnusHqjpw)
- [https://www.geeksforgeeks.org/thread-functions-in-c-c/](https://www.geeksforgeeks.org/thread-functions-in-c-c/)

### Thread-safe `time.h`

- [https://stackoverflow.com/questions/7411301/how-to-introduce-date-and-time-in-log-file](https://stackoverflow.com/questions/7411301/how-to-introduce-date-and-time-in-log-file)
- [https://linux.die.net/man/3/localtime_r](https://linux.die.net/man/3/localtime_r)
- [https://en.cppreference.com/w/c/chrono/localtime](https://en.cppreference.com/w/c/chrono/localtime)
- [https://linux.die.net/man/3/time](https://linux.die.net/man/3/time)
- [https://stackoverflow.com/questions/17982366/localtime-and-asctime-are-unsafe-but-the-safe-functions-dont-have-the-same-par](https://stackoverflow.com/questions/17982366/localtime-and-asctime-are-unsafe-but-the-safe-functions-dont-have-the-same-par)
- [https://stackoverflow.com/questions/42861913/why-use-usleep-and-not-sleep](https://stackoverflow.com/questions/42861913/why-use-usleep-and-not-sleep)
- [https://man7.org/linux/man-pages/man3/clock.3.html](https://man7.org/linux/man-pages/man3/clock.3.html)

### `time_t` vs. `clock_t`

- [https://stackoverflow.com/questions/12240059/what-is-the-difference-between-clock-t-time-t-and-struct-tm](https://stackoverflow.com/questions/12240059/what-is-the-difference-between-clock-t-time-t-and-struct-tm)
- [https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/](https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/)

### `strftime`

- [https://stackoverflow.com/questions/7411301/how-to-introduce-date-and-time-in-log-file](https://stackoverflow.com/questions/7411301/how-to-introduce-date-and-time-in-log-file)
- [https://man7.org/linux/man-pages/man3/strftime.3.html](https://man7.org/linux/man-pages/man3/strftime.3.html)

### Thread-safe `read()`, `write()` and `printf()`

- [https://stackoverflow.com/questions/467938/stdout-thread-safe-in-c-on-linux](https://stackoverflow.com/questions/467938/stdout-thread-safe-in-c-on-linux)
- [https://man7.org/linux/man-pages/man3/flockfile.3.html](https://man7.org/linux/man-pages/man3/flockfile.3.html)
- [https://linux.die.net/man/3/fprintf](https://linux.die.net/man/3/fprintf)
- [https://linux.die.net/man/3/asprintf](https://linux.die.net/man/3/asprintf)
- [https://man7.org/linux/man-pages/man3/stdio.3.html](https://man7.org/linux/man-pages/man3/stdio.3.html)
- [https://en.cppreference.com/w/c/io/fopen](https://en.cppreference.com/w/c/io/fopen)
- [https://man7.org/linux/man-pages/man3/fclose.3.html](https://man7.org/linux/man-pages/man3/fclose.3.html)
- [https://man7.org/linux/man-pages/man3/fopen.3.html](https://man7.org/linux/man-pages/man3/fopen.3.html)
- [https://en.wikipedia.org/wiki/C_file_input/output](https://en.wikipedia.org/wiki/C_file_input/output)
- [https://stackoverflow.com/questions/61911258/difference-between-file-pointer-stream-file-descriptor-and-file](https://stackoverflow.com/questions/61911258/difference-between-file-pointer-stream-file-descriptor-and-file)

### `timer_create`

- [https://stackoverflow.com/questions/8714016/calling-a-function-at-exact-every-second-using-a-timer](https://stackoverflow.com/questions/8714016/calling-a-function-at-exact-every-second-using-a-timer)
- [https://linux.die.net/man/2/timer_create](https://linux.die.net/man/2/timer_create)

### Wild threads

- [https://stackoverflow.com/questions/13923885/execute-a-method-every-x-seconds-in-c](https://stackoverflow.com/questions/13923885/execute-a-method-every-x-seconds-in-c)

### Thread Supervisor

- [https://github.com/asherikov/thread_supervisor](https://github.com/asherikov/thread_supervisor)
- [https://stackoverflow.com/questions/27594027/supervising-c-multithread-process-using-monit](https://stackoverflow.com/questions/27594027/supervising-c-multithread-process-using-monit)

### `libcurl`

- [https://curl.se/libcurl/](https://curl.se/libcurl/)
- [https://github.com/curl/curl](https://github.com/curl/curl)
- [https://curl.se/libcurl/c/getinmemory.html](https://curl.se/libcurl/c/getinmemory.html)
- [https://www.youtube.com/watch?v=DVR8N9ob_ZY&list=PLpXAyWkDQy40u-xT-Zr6Rab6EdEFOjO2W&index=6](https://www.youtube.com/watch?v=DVR8N9ob_ZY&list=PLpXAyWkDQy40u-xT-Zr6Rab6EdEFOjO2W&index=6)
- [https://www.youtube.com/watch?v=daA-KBKfJ_o](https://www.youtube.com/watch?v=daA-KBKfJ_o)
- [https://hub.docker.com/r/curlimages/curl](https://hub.docker.com/r/curlimages/curl)
- [https://stackoverflow.com/questions/57950145/is-it-possible-to-use-libcurl-to-manage-raw-tcp-connections](https://stackoverflow.com/questions/57950145/is-it-possible-to-use-libcurl-to-manage-raw-tcp-connections)
- [https://stackoverflow.com/questions/16476196/undefined-reference-to-curl-global-init-curl-easy-init-and-other-functionc](https://stackoverflow.com/questions/16476196/undefined-reference-to-curl-global-init-curl-easy-init-and-other-functionc)
- [https://curl.se/libcurl/c/CURLOPT_DNS_SERVERS.html](https://curl.se/libcurl/c/CURLOPT_DNS_SERVERS.html)

```bash
# LIBCURL WORKSPACE INSTALL
$ wget https://curl.se/download/curl-7.84.0.zip
$ unzip -d curl-7.84.0.zip
$ ./configure --with-openssl --prefix=$HOME/.local
$ make
$ make install
# Lib in ~/.local/lib
# Includes in ~/.local/include
$ curl-config --cflags
$ curl-config --libs
```

- [x] `HTTP`
- [x] `HTTPS`
- [x] `MQTT`

### `Mongoose`

- [https://github.com/cesanta/mongoose](https://github.com/cesanta/mongoose)
- [https://mongoose.ws/documentation/#minimal-tcp-echo-server](https://mongoose.ws/documentation/#minimal-tcp-echo-server)
- [https://mongoose.ws/tutorials/http-client/](https://mongoose.ws/tutorials/http-client/)
- [https://mongoose.ws/tutorials/mqtt-client/](https://mongoose.ws/tutorials/mqtt-client/)
- [https://mongoose.ws/documentation/#user-guide](https://mongoose.ws/documentation/#user-guide)
- [https://mongoose.ws/tutorials/http-server/#using-mg_printf](https://mongoose.ws/tutorials/http-server/#using-mg_printf)
- [https://mongoose.ws/tutorials/](https://mongoose.ws/tutorials/)
- [x] `HTTP`
- [x] `HTTPS`
- [x] `MQTT`

### `Paho MQTT Client`

- [https://github.com/eclipse/paho.mqtt.c](https://github.com/eclipse/paho.mqtt.c)
- [x] `MQTT`
- [ ] `HTTP`
- [ ] `HTTPS`

### `Mosquito`

- [https://mosquitto.org/](https://mosquitto.org/)
- [https://www.youtube.com/watch?v=ERPhUsmbhMo](https://www.youtube.com/watch?v=ERPhUsmbhMo)
- [x] `MQTT`
- [ ] `HTTP`
- [ ] `HTTPS`

### Doxygen style documentation

- [https://www.doxygen.nl/](https://www.doxygen.nl/)
- [https://stackoverflow.com/questions/8889942/how-to-write-documentation-comments-in-ansi-c](https://stackoverflow.com/questions/8889942/how-to-write-documentation-comments-in-ansi-c)
- [https://github.com/vcwild/feminist-api/blob/main/sources/cli.c#L3](https://github.com/vcwild/feminist-api/blob/main/sources/cli.c#L3)

### URLs

- [https://www.geeksforgeeks.org/check-if-an-url-is-valid-or-not-using-regular-expression/](https://www.geeksforgeeks.org/check-if-an-url-is-valid-or-not-using-regular-expression/)
- [https://en.wikipedia.org/wiki/URL](https://en.wikipedia.org/wiki/URL)
- [https://developer.mozilla.org/en-US/docs/Learn/Common_questions/What_is_a_URL](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/What_is_a_URL)

### `lalloc` - Listed Memory Allocation

A linked list in the control structure with all the allocated memory pointers.
The interface function `ft_lalloc` allocates memory and adds the pointer to the list.
The interface function `ft_free_lalloc` frees all pointers and the list.

### `realloc`

- [https://codereview.stackexchange.com/questions/151019/implementing-realloc-in-c](https://codereview.stackexchange.com/questions/151019/implementing-realloc-in-c)
- [https://manpages.org/realloc](https://manpages.org/realloc)
- [https://stackoverflow.com/questions/10864593/implementation-of-realloc-in-c](https://stackoverflow.com/questions/10864593/implementation-of-realloc-in-c)

### Git `submodule`

- `git clone --recurse-submodule REMOTE_REPO`
- `git submodule add REMOTE_REPO PATH`
- `git submodule foreach git pull`
- `git submodule update --init --recursive`
- [https://stackoverflow.com/questions/33714063/how-to-update-submodules-in-git](https://stackoverflow.com/questions/33714063/how-to-update-submodules-in-git)
- [https://stackoverflow.com/questions/59271919/how-to-clone-public-submodule-in-github-actions](https://stackoverflow.com/questions/59271919/how-to-clone-public-submodule-in-github-actions)
- [https://stackoverflow.com/questions/50254184/git-submodule-and-fetch](https://stackoverflow.com/questions/50254184/git-submodule-and-fetch)
- [https://www.w3docs.com/snippets/git/how-to-add-a-submodule-in-git.html](https://www.w3docs.com/snippets/git/how-to-add-a-submodule-in-git.html)
- [https://stackoverflow.com/questions/1260748/how-do-i-remove-a-submodule#1260982](https://stackoverflow.com/questions/1260748/how-do-i-remove-a-submodule#1260982)
- [https://stackoverflow.com/questions/2006172/git-how-to-reset-a-remote-git-repository-to-remove-all-commits](https://stackoverflow.com/questions/2006172/git-how-to-reset-a-remote-git-repository-to-remove-all-commits)

### Log Formats

- [https://stackoverflow.com/questions/1765689/what-is-the-best-practice-for-formatting-logs](https://stackoverflow.com/questions/1765689/what-is-the-best-practice-for-formatting-logs)
- [https://www.ibm.com/docs/en/i/7.1?topic=logging-log-formats](https://www.ibm.com/docs/en/i/7.1?topic=logging-log-formats)
- [https://www.sentinelone.com/blog/log-formatting-best-practices-readable/](https://www.sentinelone.com/blog/log-formatting-best-practices-readable/)
- [https://en.wikipedia.org/wiki/Syslog](https://en.wikipedia.org/wiki/Syslog)

```bash
$ bat /var/log/syslog
```

### Github Actions `libcurl`

- [https://github.com/actions/virtual-environments/issues/5470](https://github.com/actions/virtual-environments/issues/5470)
- [https://github.com/actions/virtual-environments/issues/3640](https://github.com/actions/virtual-environments/issues/3640)
- [https://github.com/asozialesnetzwerk/an-website/blob/main/.github/workflows/check.yml](https://github.com/asozialesnetzwerk/an-website/blob/main/.github/workflows/check.yml)

### `DNS` Servers

- [https://www.lifewire.com/free-and-public-dns-servers-2626062](https://www.lifewire.com/free-and-public-dns-servers-2626062)
- [https://developers.google.com/speed/public-dns/docs/using](https://developers.google.com/speed/public-dns/docs/using)

### VSCode

- [https://code.visualstudio.com/docs/editor/debugging](https://code.visualstudio.com/docs/editor/debugging)
- [https://code.visualstudio.com/docs/editor/tasks](https://code.visualstudio.com/docs/editor/tasks)
- [https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference](https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference)

### C JSON Libs

- [https://github.com/cesanta/mjson](https://github.com/cesanta/mjson)

### `json-c`

- [https://github.com/json-c/json-c](https://github.com/json-c/json-c)
- [https://github.com/rbtylee/tutorial-jsonc/blob/master/tutorial/index.md](https://github.com/rbtylee/tutorial-jsonc/blob/master/tutorial/index.md)
- [https://progur.com/2018/12/how-to-parse-json-in-c.html](https://progur.com/2018/12/how-to-parse-json-in-c.html)
- [https://github.com/json-c/json-c/wiki/List-of-json-c-tutorials](https://github.com/json-c/json-c/wiki/List-of-json-c-tutorials)

### Mock Server

- [https://learning.postman.com/docs/designing-and-developing-your-api/mocking-data/setting-up-mock/](https://learning.postman.com/docs/designing-and-developing-your-api/mocking-data/setting-up-mock/)
- [https://mock-server.com/mock_server/running_mock_server.html](https://mock-server.com/mock_server/running_mock_server.html)
- [https://httptoolkit.tech/](https://httptoolkit.tech/)

### Multi-threaded Web Server

- [https://github.com/nhanhoangtran/3_multithreaded_webserver_using_condition_variables](https://github.com/nhanhoangtran/3_multithreaded_webserver_using_condition_variables)
- [https://github.com/dolev146/JACOB-SORBER-multithreaded-server-all-parts/blob/master/part1/client.rb](https://github.com/dolev146/JACOB-SORBER-multithreaded-server-all-parts/blob/master/part1/client.rb)

### C Quirks

- [https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-170](https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-170)
- [https://stackoverflow.com/questions/3053561/how-do-i-assign-an-alias-to-a-function-name-in-c](https://stackoverflow.com/questions/3053561/how-do-i-assign-an-alias-to-a-function-name-in-c)
- [https://stackoverflow.com/questions/32698293/assign-values-to-structure-variables](https://stackoverflow.com/questions/32698293/assign-values-to-structure-variables)
- [https://stackoverflow.com/questions/41304497/print-the-structure-fields-and-values-in-c](https://stackoverflow.com/questions/41304497/print-the-structure-fields-and-values-in-c)
- [https://stackoverflow.com/questions/4949254/const-char-const-versus-const-char](https://stackoverflow.com/questions/4949254/const-char-const-versus-const-char)

### C Libs

- [https://stackoverflow.com/questions/668501/are-there-any-open-source-c-libraries-with-common-data-structures](https://stackoverflow.com/questions/668501/are-there-any-open-source-c-libraries-with-common-data-structures)
- [https://github.com/nothings/single_file_libs](https://github.com/nothings/single_file_libs)
- [https://github.com/oz123/awesome-c#concurrency-and-parallelism](https://github.com/oz123/awesome-c#concurrency-and-parallelism)

### `regex.h`

- [https://stackoverflow.com/questions/1085083/regular-expressions-in-c-examples](https://stackoverflow.com/questions/1085083/regular-expressions-in-c-examples)
- [https://manpages.ubuntu.com/manpages/trusty/man7/regex.h.7posix.html](https://manpages.ubuntu.com/manpages/trusty/man7/regex.h.7posix.html)

### Testing

- [https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C](https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C)
- [https://github.com/siu/minunit](https://github.com/siu/minunit) (minimal)
- [https://github.com/ThrowTheSwitch/Unity](https://github.com/ThrowTheSwitch/Unity) (average)
- [https://stackoverflow.com/questions/242926/comparison-of-c-unit-test-frameworks](https://stackoverflow.com/questions/242926/comparison-of-c-unit-test-frameworks)
- [https://github.com/google/googletest](https://github.com/google/googletest) (very robust)
- [https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2022](https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2022) (very robust)

### ASCII Art

- [https://www.asciiart.eu/art-and-design/escher](https://www.asciiart.eu/art-and-design/escher)
- [https://www.asciiart.eu/art-and-design/borders](https://www.asciiart.eu/art-and-design/borders)
- [https://www.asciiart.eu/art-and-design/geometries](https://www.asciiart.eu/art-and-design/geometries)
- [https://www.text-image.com/convert/ascii.html](https://www.text-image.com/convert/ascii.html)
- [https://textfancy.com/multiline-text-art/](https://textfancy.com/multiline-text-art/)

### Services

- [https://statuspage.freshping.io/22651-42Network](https://statuspage.freshping.io/22651-42Network)
- [https://www.freshworks.com/website-monitoring/](https://www.freshworks.com/website-monitoring/)
- [https://github.com/Liurunex/WebSite_Monitoring](https://github.com/Liurunex/WebSite_Monitoring)
