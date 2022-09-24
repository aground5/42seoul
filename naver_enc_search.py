from operator import itemgetter
import requests
from bs4 import BeautifulSoup
import re

import requests

cookies = {
    'NNB': '7RDAMCUWL4DWG',
    'nx_ssl': '2',
    'IS_PLATFORM_ENKODICT_USER': 'true',
}

headers = {
    'Host': 'en.dict.naver.com',
    'Sec-Ch-Ua': '"Chromium";v="105", "Not)A;Brand";v="8"',
    'Accept': 'text/html, */*; q=0.01',
    'Alldict-Locale': 'ko',
    'X-Requested-With': 'XMLHttpRequest',
    'Sec-Ch-Ua-Mobile': '?0',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.5195.102 Safari/537.36',
    'Sec-Ch-Ua-Platform': '"macOS"',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-Fetch-Mode': 'cors',
    'Sec-Fetch-Dest': 'empty',
    'Referer': 'https://en.dict.naver.com/',
    # 'Accept-Encoding': 'gzip, deflate',
    'Accept-Language': 'ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7',
    # Requests sorts cookies= alphabetically
    # 'Cookie': 'NNB=7RDAMCUWL4DWG; nx_ssl=2; IS_PLATFORM_ENKODICT_USER=true',
}

params = {
    'query': 'a',
    'm': 'pc',
    'range': 'word',
    'page': '1',
    'lang': 'ko',
    'shouldSearchOpen': 'true',
    'hid': '166389899947153760',
}

def searchWord(query) :
	for i in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' :
		query.replace(i, '?')
	params['query'] = query
	res = requests.get('https://en.dict.naver.com/api3/enko/search', params=params, cookies=cookies, headers=headers)
	searchResult = res.json()
	items = searchResult["searchResultMap"]["searchResultListMap"]["WORD"]["items"]
	words = []
	for i in items :
		words.append(i["expEntry"])
	words = [re.sub('</strong>', '', re.sub('<strong>', '', i)) for i in words]
	return words

print(searchWord('_atata_aaa'))