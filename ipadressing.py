import sys

ip = input("Enter IP adress: ")
ipArray = ip.split(".")
# print(ipArray)
cc = int(ipArray[0])
mask = []
if cc>0 and cc<127:
    print("It is class A and Mask = 225.0.0.0")
    mask = [225,0,0,0];
elif cc>=128 and cc<192:
    print("It is class B and Mask = 225.225.0.0")
    mask = [225,225,0,0]
elif cc>=192 and cc<224:
    print("It is class C and Mask = 225.225.225.0")
    mask = [225,225,225,0]
elif cc>=128 and cc<192:
    print("IP Address is used for Multicasting or reserved")
    # sys.exit()

subnet = ["0","0","0","0"]
i = 0
for i in range(0,4):
    # ipArray[i] = int(ipArray[i])
    if mask[i] == 225:
        subnet[i] = ipArray[i]
    elif mask[i] == 0:
        subnet[i] = 0

print(f"{subnet[0]}.{subnet[1]}.{subnet[2]}.{subnet[3]}")