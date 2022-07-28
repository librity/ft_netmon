# 42 Labs 3rd Edition

This is the technical challenge of the selection process for the 3rd Edition of 42 Labs. It is at this moment that you will be able to apply your knowledge, working with other Cadets to develop an application that aims to present knowledge that passes through the areas of web development and networks, which will be especially important at 42 Labs.

## Challenge

In one line: Web service monitoring application.

We will monitor web services using 3 protocols: _HTTP_, _PING_ and _DNS_. For each protocol, there will be settings that define how the monitoring will happen, as well as the address of the monitored service. The monitoring settings will be in a file named `monitoring.db`, ​​where each line represents a kind of monitoring based on the settings defined on the same line. The `monitoring` program will look for and analyze this file, starting the monitoring process.

Old acquaintance of you, _C_ will be used for development.

### monitoring.db

The `monitoring.db` file defines how your application will act. This file has a strict structure and must be rejected if it does not match that structure.

The structure is defined by rows and columns, where each row will have the settings separated by a TAB, which define the columns. For each monitoring, the settings up to the 3rd column will be the same, as of the 4th the configuration is specific, based on the protocol chosen in the 2nd column.

The settings for each protocol are:

| Protocol | Settings                                                        |
| -------- | --------------------------------------------------------------- |
| HTTP     | name, protocol, address, HTTP method, expected HTTP code, range |
| PING     | Name, Protocol, Address, Range                                  |
| DNS      | Name, Protocol, Address, Range, DNS Server                      |

Below is an example of the file described above:

```txt
# monitoring.db

intra HTTP intra.42.fr GET 200 120
game ping test PING game.42sp.org.br 60
workspaces monitoring PING workspaces.42sp.org.br 60
```

### monitoring

The `monitoring` program is where everything will happen. By reading the configuration file, the services should start to be monitored in the same way they were configured.

Information from monitored services should be displayed on the standard output in a succinct form and more detailed information for in-depth analysis should be stored in the `monitoring.log` file using a strict and standardized structure that you define. It should also be possible to get the succinct information, the same as it was on standard output, just by using the `--simplify` argument in the program.

A healthy service is one that can respond to the monitoring request as expected, in contrast to an unhealthy service that does not respond as expected. As a monitoring service, your application must be able to correctly identify and display this information.

### Specs

- That the program is works as a useful network monitoring service.
- That there is a program called `monitoring`.
- The `monitoring.db` file must be analyzed and validated by the program.
- Services configured for monitoring must follow the defined settings.
- The `monitoring.log` file must store all possible monitoring information and it must be possible to translate its structure in a summarized, succinct form using the argument to the `--simplify` program.

### What will be evaluated

- Well written and clean code.
- Code documentation.
- Tools that were used and why.
- Your creativity and ability to deal with different problems.
- Alignment of your project with the proposal.

### Minimum requirements

- `README.md` with documentation containing project information.

### Bonus

The following items are not mandatory, but they are features that will add value to your program.

- Notification of unhealthy service on Discord, email, Slack or Webhook.
- Tests.
- Identification of unusual behavior of monitored services, such as increased response latency.
- Aggregate analysis of data from the `monitoring.log` file, displaying diagrams and graphs from the CLI.
- Parsing of UNIX-Like arguments, being able to filter or change application behavior.
- Special care with optimization and code patterns.
- Possibility of monitoring MQTT and TCP.
- Use of external tools for planning in the development stages.

<sub><sup>[Important](https://imgs.xkcd.com/comics/networking_problems.png)</sup></sub>
