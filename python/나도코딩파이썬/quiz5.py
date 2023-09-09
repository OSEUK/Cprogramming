from random import *
cnt = 0 # 총 탑승 승객 수
for i in range(1, 51):  # 1 ~ 50 이라는 수
    time = randrange(5, 51) # 5분 ~ 50분 소요 시간
    if 5 <= time <= 15: # 매칭 성공 시
        print("[O] {0}번째 손님 (소요시간 : {1}분)".format(i, time))
        cnt += 1
    else:   # 매칭 실패 시
        print("[ ] {0}번째 손님 (소요시간 : {1}분)".format(i, time))

print("총 탑승 승객 : {0}".format(cnt))