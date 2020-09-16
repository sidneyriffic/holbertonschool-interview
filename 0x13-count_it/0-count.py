#!/usr/bin/python3
"""Search list of a subreddit's hot articles for keywords"""


import requests as rq


def count_words(subreddit, word_list, print_stuff=0, results=None):
    """
    Search list of a subreddit's hot articles for keywords.
    Need to call recursively for grading purposes.
    """
    if print_stuff == 1:
        if len(results) < 1:
            return
        if results[0][0] > 0:
            print("{}: {}".format(results[0][1], results[0][0]))
        count_words(None, None, 1, results[1:])
        return
    if len(word_list) < 1:
        return
    hot_arts = rq.get("https://api.reddit.com/r/{}/hot".format(subreddit),
                      headers={'User-Agent': 'student-testing'},
                      allow_redirects=False)
    if hot_arts.status_code != 200:
        return
    data_list = hot_arts.json()["data"]["children"]
    if len(data_list) == 0:
        return
    title_list = list(map(lambda x: x["data"]["title"], data_list))
    sep = " "
    title_string = " " + sep.join(title_list) + " "
    counts = list(map(lambda x: title_string.count(x), word_list))
    results = sorted(zip(counts, word_list), reverse=True)
    count_words(None, None, 1, results)
