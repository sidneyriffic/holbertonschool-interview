#!/usr/bin/python3
"""Parse titles of hot articles on reddit and get count of given words"""


import requests as rq


def count_words(subreddit, word_list):
    """Parse titles of hot articles on reddit and get count of given words"""
    if len(word_list) < 1:
        return
    hots = rq.get("https://api.reddit.com/r/{}/hot".format(subreddit))
    if hots.status_code != 200:
        return None
    data_list = hots.json()["data"]["children"]
    titlelist = list(map(lambda x: x["data"]["title"], data_list))
    sep = " "
    titlestring = " " + sep.join(titlelist) + " "
    counts = list(map(lambda x: titlestring.count(" " + x + " "), word_list))
    results = sorted(zip(counts, word_list), reverse=True)
    print_results(results)


def print_results(results):
    """I am required to have at least one recursive function in this project"""
    if len(results) < 1:
        return
    print("{}: {}".format(results[0][1], results[0][0]))
    print_results(results[1:])
