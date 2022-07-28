# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 22:46:36 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/07/27 22:46:55 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import requests

TEST1 = "http://google.com,https://nomadcoders.co,impetus.vercel.app"
TEST2 = "http://google.com,   https://nomadcoders.co  , impetus.vercel.app"
TEST3 = "http://google.com,   https://nomadcoders.co,gibberissjjssdoaposdoáw  , impetus.vercel.app"
TEST4 = "http://google.com,   https://nomadcoders.co,,gibberissjjssdoaposdoáw  , impetus.vercel.app"


def get_urls():
  raw_urls = input(
      "Please write the URLs you wanna check separated by commas:\n")

  return raw_urls


def parse_urls(raw_urls):
  return raw_urls.replace(' ', '').split(',')


def clean_url(url):
  url = url.lower()
  if (url.startswith("http://")):
    return url
  if (url.startswith("https://")):
    return url
  return f"http://{url}"


def ask_to_run_again():
  run_again = input("Would you like to check more URLs?(y/n) ")
  if (run_again == "y"):
    return run_is_it_down()
  if (run_again == "yes"):
    return run_is_it_down()
  print("Bye Bye ✌")


def check_urls(urls):
  for url in urls:
    url = clean_url(url)

    try:
      request = requests.get(url)
    except:
      print(f"INVALID URL: {url}")
      continue

    if request.status_code != 200:
      print(f"{url} is down, status code {request.status_code}")
      continue

    print(f"{url} is up, status code {request.status_code}")


def run_is_it_down():
  # raw_urls = TEST1
  # raw_urls = TEST2
  # raw_urls = TEST3
  # raw_urls = TEST4

  raw_urls = get_urls()
  urls = parse_urls(raw_urls)

  print("---")
  check_urls(urls)
  print("---")

  ask_to_run_again()


def main():
  print("Welcome to IsItDown.py!")
  run_is_it_down()


main()
