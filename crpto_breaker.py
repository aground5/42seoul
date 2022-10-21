from tkinter import N


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
    
def oneQuestion(query) :
    for i in range(0, len(query)) :
        if (query[i] == '?') :
            qidx = i
            break
    decoded = decode(key)
    freq = { i : 0 for i in key }
    for i in range(0, len(decoded) - len(query) + 1) :
        for j in range(0, len(query)) :
            if (qidx == j or decoded[i + j] == query[j]) :
                isMatch = True
            else :
                isMatch = False
                break
        if (isMatch) :
            freq[decoded[i + qidx]] += 1
    print("-"*10 + "Frequency Analyze " + query + "-"*10)
    print(dict(sorted(freq.items(), key=lambda x:x[1], reverse=True)))
    
def keySetting(index, c) :
    print("-"*10 + "Setting " + key[index] + " = " + c + "-"*10)
    key[index] = c	# 가장 많은 빈도수 알파벳 e로 변경
    print("Used key: " + str(key))
    print(decode(key))

def wordFreq(num) :
    decoded = decode(key)
    freq = {}
    for i in range(0, len(decoded) - num + 1) :
        if (decoded[i:i + num] in freq.keys()) :
            freq[decoded[i:i + num]] += 1
        else :
            freq[decoded[i:i + num]] = 1
    print("-"*10 + "Frequency Analyze {} word".format(num) + "-"*10)
    print(dict(sorted(freq.items(), key=lambda x:x[1], reverse=True)))

sorted_count = count.copy()
sorted_count.sort()
keySetting(count.index(max(count)), 'e')
oneQuestion('?e')       # M = r, s, t
oneQuestion('e?')
keySetting(upper.index('L'), 'd')
oneQuestion('?d')
oneQuestion('e?d')
wordFreq(1)
keySetting(upper.index('I'), 'n')
oneQuestion('?e')
oneQuestion('e?')
keySetting(upper.index('Y'), 'h')
wordFreq(3)
keySetting(upper.index('N'), 't')
oneQuestion('th?t')   #that
keySetting(upper.index('R'), 'a')
oneQuestion('thet?')
wordFreq(1)
wordFreq(2)
oneQuestion('a?')
keySetting(upper.index('D'), 'i')
wordFreq(5) #Bhain
keySetting(upper.index('B'), 'c')
wordFreq(5) #ctiTn
keySetting(upper.index('T'), 'o') #-ction
keySetting(upper.index('K'), 's')
wordFreq(6) #action
keySetting(upper.index('M'), 'r') #tMansaction
wordFreq(5) #GCocH -> block, frock
keySetting(upper.index('G'), 'b')
keySetting(upper.index('C'), 'l')
keySetting(upper.index('H'), 'k')

keySetting(upper.index('E'), 'g') #Eeneral
keySetting(upper.index('Z'), 'p') #reZresent
keySetting(upper.index('P'), 'y') #technologP
keySetting(upper.index('W'), 'f') #a type oW
keySetting(upper.index('F'), 'w') #groFing
keySetting(upper.index('O'), 'u') #secOrely
keySetting(upper.index('A'), 'v') #preAious
keySetting(upper.index('X'), 'm') #coXpare
keySetting(upper.index('S'), 'q') #conseSuently
keySetting(upper.index('J'), 'x') #eJist
