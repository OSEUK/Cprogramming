def std_weight(height, gender):
    if(gender == "man"):
        return float(height * height * 22)
    else:
        return float(height * height * 21)

print("키 175 남자의 표준 체중은 %.2fkg입니다."%(std_weight(175, "man")/10000))