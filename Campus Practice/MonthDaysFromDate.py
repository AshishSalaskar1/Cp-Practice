ref = [ [],
    ["Jan",31],["Feb",28],["Mar",31],["Apr",30],["May",31],["Jun",30],["Jul",31],
    ["Aug",31],["Sep",30],["Oct",31],["Nov",30],["Dec",31]
 ]

def isLeap(year):
     if year%4==0:
         if year%100 == 0:
             if year%400 == 0:
                 return True
             else:
                 return False
         else:
             return True;
     else:
         return False

print(isLeap(1000))

date = "22-2-2020"

day,month,year = date.split('-')

month = int(month)
year = int(year)

if(isLeap(year) and month == 2):
    print("The month Feb has 29 days")
  
else:
    print("The month "+ ref[month][0] + " has "+ str(ref[month][1])+" days")
