# from naver_enc_search import searchWord

ct = "RGCTBHBYRDIDKRNPZUTWLDEDNRCCULEUMNUBYITCTEPLCNNYRNBTIKDKNKTWEMTFDIECDKNTWMUBTMLKBRCCULGCTBHKNYRNRMUKUBOMUCPCDIHULNTEUNYUMOKDIEBMPZNTEMRZYPURBYGCTBHBTINRDIKRBMPZNTEMRZYDBYRKYTWNYUZMUADTOKGCTBHRNDXUKNRXZRILNMRIKRBNDTILRNREUIUMRCCPMUZMUKUINULRKRXUMHCUNMUUFYUMULRNRITLUKRMUMUZMUKUINULGPCURWKNYUNDXUKNRXZZMTAUKNYRNNYUNMRIKRBNDTILRNRUJDKNULFYUINYUGCTBHFRKBMURNULKDIBUURBYGCTBHBTINRDIKDIWTMXRNDTIRGTONNYUGCTBHZMUADTOKNTDNNYUPUWWUBNDAUCPWTMXRBYRDIBTXZRMUCDIHULCDKNLRNRKNMOBNOMUFDNYURBYRLLDNDTIRCGCTBHCDIHDIENTNYUTIUKGUWTMUDNBTIKUSOUINCPGCTBHBYRDINMRIKRBNDTIKRMUDMMUAUMKDGCUDINYRNTIBUNYUPRMUMUBTMLULNYULRNRDIRIPEDAUIGCTBHBRIITNGURCNUMULMUNMTRBNDAUCPFDNYTONRCNUMDIERCCKOGKUSOUINGCTBHK"
upper = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
key = [i for i in upper]

count = []
for i in upper :
    count.append(ct.count(i))

def decode(key) :
    pt = ""
    for i in ct :
        pt += key[upper.find(i)]
    return pt

sorted_count = count.copy()
sorted_count.sort()
print(count.index(max(count)))
key[count.index(max(count))] = 'e'	# 가장 많은 빈도수 알파벳 e로 변경
print("Used key: " + str(key))
print(decode(key))
# key[count.index(sorted_count[-2])] = 't'
# print("Used key: " + str(key))
# print(decode(key))
# key[count.index(sorted_count[-3])] = 'a'
# print("Used key: " + str(key))
# print(decode(key))
# key[count.index(sorted_count[-4])] = 'o'
# print("Used key: " + str(key))
# print(decode(key))

def checkFrontBack(c) :
    decoded = decode(key)
    front = { i : 0 for i in key }
    for i in range(1, len(decoded)) :
        if (decoded[i] == c) :
            front[decoded[i - 1]] += 1
    back = { i : 0 for i in key }
    for i in range(0, len(decoded) - 1) :
        if (decoded[i] == c) :
            back[decoded[i + 1]] += 1
    print(front)
    print(back)

checkFrontBack('e')

# def isBlank(q) :
#     for i in q :
#         if (q != '?') :
#             return False
#     return True

# def recursive(idx, size) :
#     query = decode(key)[idx : idx + size]
#     for i in upper :
#         query.replace(i, '?')
#     if (isBlank(query)) :
#         recursive(idx=idx + 1, size=1)
#     words = searchWord(query=query)
#     if (len(words) == 0) :
#         return
#     for word in words :
#         tryDecrypt(idx, size, word)
