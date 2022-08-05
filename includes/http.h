/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:27:26 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/04 22:41:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_H
# define HTTP_H

/******************************************************************************\
 * HTTP
\******************************************************************************/

# define HTTP "HTTP"
# define HTTP_IDENTIFIER "HTTP"

# define HTTP_FIELD_COUNT 6

# define HTTP_NAME_INDEX 0
# define HTTP_PROTOCOL_INDEX 1
# define HTTP_ADDRESS_INDEX 2
# define HTTP_METHOD_INDEX 3
# define HTTP_CODE_INDEX 4
# define HTTP_FREQUENCY_INDEX 5

# define HTTP_URL_PREFIX "http://"

# define HTTP_SERVER_PORT 80
# define HTTP_SOCKET_TIMEOUT_SECS 1
# define HTTP_BUFFER_SIZE 4096

/******************************************************************************\
 * HTTPS
\******************************************************************************/

# define HTTPS "HTTPS"
# define HTTPS_IDENTIFIER "HTTPS"

# define HTTPS_FIELD_COUNT 6

# define HTTPS_NAME_INDEX 0
# define HTTPS_PROTOCOL_INDEX 1
# define HTTPS_ADDRESS_INDEX 2
# define HTTPS_METHOD_INDEX 3
# define HTTPS_CODE_INDEX 4
# define HTTPS_FREQUENCY_INDEX 5

# define HTTPS_URL_PREFIX "https://"

/******************************************************************************\
 * METHODS
\******************************************************************************/

# define HTTP_METHOD_GET "GET"
# define HTTP_METHOD_HEAD "HEAD"
# define HTTP_METHOD_POST "POST"
# define HTTP_METHOD_PUT "PUT"
# define HTTP_METHOD_DELETE "DELETE"
# define HTTP_METHOD_CONNECT "CONNECT"
# define HTTP_METHOD_OPTIONS "OPTIONS"
# define HTTP_METHOD_TRACE "TRACE"
# define HTTP_METHOD_PATCH "PATCH"

/******************************************************************************\
 * CODES
\******************************************************************************/

# define HTTP_CODE_100 "100"
# define HTTP_CODE_101 "101"
# define HTTP_CODE_102 "102"
# define HTTP_CODE_103 "103"

# define HTTP_CODE_200 "200"
# define HTTP_CODE_201 "201"
# define HTTP_CODE_202 "202"
# define HTTP_CODE_203 "203"
# define HTTP_CODE_204 "204"
# define HTTP_CODE_205 "205"
# define HTTP_CODE_206 "206"
# define HTTP_CODE_207 "207"
# define HTTP_CODE_208 "208"
# define HTTP_CODE_226 "226"

# define HTTP_CODE_300 "300"
# define HTTP_CODE_301 "301"
# define HTTP_CODE_302 "302"
# define HTTP_CODE_303 "303"
# define HTTP_CODE_304 "304"
# define HTTP_CODE_305 "305"
# define HTTP_CODE_306 "306"
# define HTTP_CODE_307 "307"
# define HTTP_CODE_308 "308"

# define HTTP_CODE_400 "400"
# define HTTP_CODE_401 "401"
# define HTTP_CODE_402 "402"
# define HTTP_CODE_403 "403"
# define HTTP_CODE_404 "404"
# define HTTP_CODE_405 "405"
# define HTTP_CODE_406 "406"
# define HTTP_CODE_407 "407"
# define HTTP_CODE_408 "408"
# define HTTP_CODE_409 "409"
# define HTTP_CODE_410 "410"
# define HTTP_CODE_411 "411"
# define HTTP_CODE_412 "412"
# define HTTP_CODE_413 "413"
# define HTTP_CODE_414 "414"
# define HTTP_CODE_415 "415"
# define HTTP_CODE_416 "416"
# define HTTP_CODE_417 "417"
# define HTTP_CODE_418 "418"
# define HTTP_CODE_421 "421"
# define HTTP_CODE_422 "422"
# define HTTP_CODE_423 "423"
# define HTTP_CODE_424 "424"
# define HTTP_CODE_425 "425"
# define HTTP_CODE_426 "426"
# define HTTP_CODE_428 "428"
# define HTTP_CODE_429 "429"
# define HTTP_CODE_431 "431"
# define HTTP_CODE_451 "451"

# define HTTP_CODE_500 "500"
# define HTTP_CODE_501 "501"
# define HTTP_CODE_502 "502"
# define HTTP_CODE_503 "503"
# define HTTP_CODE_504 "504"
# define HTTP_CODE_505 "505"
# define HTTP_CODE_506 "506"
# define HTTP_CODE_507 "507"
# define HTTP_CODE_508 "508"
# define HTTP_CODE_510 "510"
# define HTTP_CODE_511 "511"

/******************************************************************************\
 * REQUESTS
\******************************************************************************/

# define HTTP_DELIMITER "\r\n"
# define HTTP_HEADER_END "\r\n\r\n"

# define HTTP_GET_REQUEST "\
GET / HTTP/1.1\r\n\r\n\
"

# define HTTP_HEAD_REQUEST "\
HEAD / HTTP/1.1\r\n\r\n\
"

# define HTTP_POST_REQUEST "\
POST / HTTP/1.1\r\n\
Host: host.name\r\n\
Content-type: text/html\r\n\
Content-Length: 0\r\n\
\r\n\
"

# define HTTP_PUT_REQUEST "\
PUT / HTTP/1.1\r\n\
Host: host.name\r\n\
Content-type: text/html\r\n\
Content-Length: 0\r\n\
\r\n\
"

# define HTTP_DELETE_REQUEST "\
DELETE / HTTP/1.1\r\n\
Host: host.name\r\n\
\r\n\
"

# define HTTP_CONNECT_REQUEST "\
CONNECT / HTTP/1.1\r\n\
Host: host.name\r\n\
\r\n\
"

# define HTTP_OPTIONS_REQUEST "\
OPTIONS / HTTP/1.1\r\n\
Host: host.name\r\n\
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n\
Accept-Language: en-us,en;q=0.5\r\n\
Accept-Encoding: gzip,deflate\r\n\
Connection: keep-alive\r\n\
Origin: https://host.name\r\n\
Access-Control-Request-Method: POST\r\n\
Access-Control-Request-Headers: X-PINGOTHER, Content-Type\r\n\
\r\n\
"

# define HTTP_TRACE_REQUEST "\
TRACE / HTTP/1.1\r\n\r\n\
"

# define HTTP_PATCH_REQUEST "\
PATCH / HTTP/1.1\r\n\
Host: host.name\r\n\
Content-type: text/html\r\n\
Content-Length: 0\r\n\
\r\n\
"

#endif
