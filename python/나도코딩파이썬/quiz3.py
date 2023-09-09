strsite = "http://google.go.kr"
strsite = strsite.removeprefix("http://")
print(strsite)
print(strsite.index("."))
strsite = strsite[:strsite.index(".")]
print(strsite)
pwd = strsite[:3] + str(len(strsite)) + str(strsite.count("e")) + "!"
print(pwd)