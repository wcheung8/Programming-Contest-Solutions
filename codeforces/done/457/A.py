import datetime

x = int(input())
hh, mm = [int(i) for i in input().split()]

time = datetime.time(hh, mm, 0, 0)
count = 0

while '7' not in str(time):
    count += 1
    date = datetime.datetime.combine(datetime.datetime.today(), time) - datetime.timedelta(minutes=x)
    time = date.time()

print(count)
